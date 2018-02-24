#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <pulse/simple.h>
#include <pulse/error.h>
#include <math.h>
#include "fir.h"
#define BUFSIZE  1024


SampleFilter sf;


int main(int argc, char*argv[]) {
    SampleFilter_init(&sf);
    int last_peak = 0;


    /* The Sample format to use */
    static const pa_sample_spec ss = {
        .format = PA_SAMPLE_S16LE,
        .rate = 44100,
        .channels = 1 
    };
    pa_simple *s = NULL;
    int ret = 1;
    int error;
    /* replace STDIN with the specified file if needed */
    if (argc > 1) {
        int fd;
        if ((fd = open(argv[1], O_RDONLY)) < 0) {
            fprintf(stderr, __FILE__": open() failed: %s\n", strerror(errno));
            goto finish;
        }
        if (dup2(fd, STDIN_FILENO) < 0) {
            fprintf(stderr, __FILE__": dup2() failed: %s\n", strerror(errno));
            goto finish;
        }
        close(fd);
    }
    /* Create a new playback stream */
    if (!(s = pa_simple_new(NULL, argv[0], PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, &error))) {
        fprintf(stderr, __FILE__": pa_simple_new() failed\n");
        goto finish;
    }
    for (;;) {
        int16_t buf[BUFSIZE];
        ssize_t r;
        int i;
#if 0
        pa_usec_t latency;
        if ((latency = pa_simple_get_latency(s, &error)) == (pa_usec_t) -1) {
            fprintf(stderr, __FILE__": pa_simple_get_latency() failed: %s\n", pa_strerror(error));
            goto finish;
        }
        fprintf(stderr, "%0.0f usec    \r", (float)latency);
#endif
        /* Read some data ... */
        if ((r = read(STDIN_FILENO, buf, sizeof(buf))) <= 0) {
            if (r == 0) /* EOF */
                break;
            fprintf(stderr, __FILE__": read() failed: %s\n", strerror(errno));
            goto finish;
        }

        /* Apply filter */
        int peak = 0;
        char bar[33];
        bar[32] = 0;
        for(i=0;i<BUFSIZE;i++) {
            int16_t v;
            SampleFilter_put(&sf, buf[i]);
            buf[i] = SampleFilter_get(&sf);
            v = abs(buf[i]);

            if(v>peak)
                peak = v;
        }

        peak = (log10(peak+500)-2.6f)*32/(4.5f-2.5f);
        if(peak>32) peak=32;
        if(peak<last_peak) {
            peak = --last_peak;
        }else 
        last_peak = peak;

        for(i=0;i<33;i++)
            bar[i] = ' ';
        for(i=0;i<peak;i++)
            bar[i] = '=';
        printf("  %s\n", bar);


        /* ... and play it */
        if (pa_simple_write(s, buf, (size_t) r, &error) < 0) {
            fprintf(stderr, __FILE__": pa_simple_write() failed\n");
            goto finish;
        }
    }
    /* Make sure that every single sample was played */
    if (pa_simple_drain(s, &error) < 0) {
        fprintf(stderr, __FILE__": pa_simple_drain() failed\n");
        goto finish;
    }
    ret = 0;
finish:
    if (s)
        pa_simple_free(s);
    return ret;
}


