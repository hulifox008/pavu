#include <stdio.h>
#include <pulse/pulseaudio.h>
#include <pulse/simple.h>

int main()
{
    struct pa_simple *s;
    struct pa_sample_spec ss;

    ss.format = PA_SAMPLE_S16NE;
    ss.channels = 2;
    ss.rate = 44100;

    s = pa_simple_new(NULL, 
                    "pauv",
                    PA_STREAM_RECORD,
                    "alsa_output.pci-0000_00_1b.0.analog-stereo.monitor",
                    "monitor",
                    &ss,
                    NULL, 
                    NULL,
                    NULL);
    printf("s: %p\n", s);

    u_int16_t data[4096];

    for(;;) {
        int i;
        int ret;
        ret = pa_simple_read(s, data, sizeof(data), NULL);
        printf("read %d\n", ret);
        
    }

                    
}
