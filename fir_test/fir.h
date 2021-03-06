#ifndef SAMPLEFILTER_H_
#define SAMPLEFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 44100 Hz

fixed point precision: 16 bits

* 0 Hz - 400 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 600 Hz - 22050 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = n/a

*/

#define SAMPLEFILTER_TAP_NUM 512
static int filter_taps[SAMPLEFILTER_TAP_NUM] = {
  -158,
  70,
  58,
  49,
  43,
  38,
  35,
  33,
  31,
  31,
  31,
  31,
  32,
  32,
  33,
  34,
  36,
  37,
  38,
  40,
  41,
  43,
  44,
  46,
  47,
  49,
  50,
  52,
  53,
  55,
  57,
  58,
  60,
  61,
  63,
  64,
  66,
  67,
  69,
  70,
  72,
  73,
  74,
  75,
  77,
  78,
  79,
  80,
  81,
  82,
  83,
  84,
  85,
  86,
  86,
  87,
  88,
  88,
  88,
  89,
  89,
  89,
  89,
  89,
  89,
  89,
  89,
  89,
  88,
  88,
  87,
  86,
  86,
  85,
  84,
  83,
  82,
  81,
  79,
  78,
  76,
  75,
  73,
  71,
  69,
  67,
  65,
  63,
  61,
  59,
  56,
  54,
  51,
  48,
  46,
  43,
  40,
  37,
  34,
  31,
  28,
  25,
  22,
  19,
  15,
  12,
  9,
  5,
  2,
  -1,
  -5,
  -8,
  -12,
  -15,
  -19,
  -22,
  -25,
  -29,
  -32,
  -36,
  -39,
  -42,
  -45,
  -49,
  -52,
  -55,
  -58,
  -61,
  -64,
  -67,
  -69,
  -72,
  -74,
  -77,
  -79,
  -81,
  -83,
  -85,
  -87,
  -89,
  -90,
  -92,
  -93,
  -94,
  -95,
  -96,
  -97,
  -97,
  -98,
  -98,
  -98,
  -98,
  -97,
  -97,
  -96,
  -95,
  -94,
  -93,
  -91,
  -89,
  -88,
  -85,
  -83,
  -81,
  -78,
  -75,
  -72,
  -69,
  -65,
  -62,
  -58,
  -54,
  -50,
  -45,
  -41,
  -36,
  -31,
  -26,
  -20,
  -15,
  -9,
  -3,
  3,
  9,
  15,
  22,
  28,
  35,
  42,
  49,
  56,
  63,
  71,
  78,
  86,
  93,
  101,
  109,
  117,
  125,
  133,
  141,
  149,
  157,
  165,
  173,
  182,
  190,
  198,
  206,
  214,
  222,
  231,
  239,
  247,
  254,
  262,
  270,
  278,
  285,
  293,
  300,
  308,
  315,
  322,
  329,
  335,
  342,
  349,
  355,
  361,
  367,
  373,
  378,
  383,
  389,
  394,
  398,
  403,
  407,
  411,
  415,
  419,
  422,
  425,
  428,
  430,
  433,
  435,
  437,
  438,
  440,
  441,
  442,
  442,
  442,
  442,
  442,
  442,
  441,
  440,
  438,
  437,
  435,
  433,
  430,
  428,
  425,
  422,
  419,
  415,
  411,
  407,
  403,
  398,
  394,
  389,
  383,
  378,
  373,
  367,
  361,
  355,
  349,
  342,
  335,
  329,
  322,
  315,
  308,
  300,
  293,
  285,
  278,
  270,
  262,
  254,
  247,
  239,
  231,
  222,
  214,
  206,
  198,
  190,
  182,
  173,
  165,
  157,
  149,
  141,
  133,
  125,
  117,
  109,
  101,
  93,
  86,
  78,
  71,
  63,
  56,
  49,
  42,
  35,
  28,
  22,
  15,
  9,
  3,
  -3,
  -9,
  -15,
  -20,
  -26,
  -31,
  -36,
  -41,
  -45,
  -50,
  -54,
  -58,
  -62,
  -65,
  -69,
  -72,
  -75,
  -78,
  -81,
  -83,
  -85,
  -88,
  -89,
  -91,
  -93,
  -94,
  -95,
  -96,
  -97,
  -97,
  -98,
  -98,
  -98,
  -98,
  -97,
  -97,
  -96,
  -95,
  -94,
  -93,
  -92,
  -90,
  -89,
  -87,
  -85,
  -83,
  -81,
  -79,
  -77,
  -74,
  -72,
  -69,
  -67,
  -64,
  -61,
  -58,
  -55,
  -52,
  -49,
  -45,
  -42,
  -39,
  -36,
  -32,
  -29,
  -25,
  -22,
  -19,
  -15,
  -12,
  -8,
  -5,
  -1,
  2,
  5,
  9,
  12,
  15,
  19,
  22,
  25,
  28,
  31,
  34,
  37,
  40,
  43,
  46,
  48,
  51,
  54,
  56,
  59,
  61,
  63,
  65,
  67,
  69,
  71,
  73,
  75,
  76,
  78,
  79,
  81,
  82,
  83,
  84,
  85,
  86,
  86,
  87,
  88,
  88,
  89,
  89,
  89,
  89,
  89,
  89,
  89,
  89,
  89,
  88,
  88,
  88,
  87,
  86,
  86,
  85,
  84,
  83,
  82,
  81,
  80,
  79,
  78,
  77,
  75,
  74,
  73,
  72,
  70,
  69,
  67,
  66,
  64,
  63,
  61,
  60,
  58,
  57,
  55,
  53,
  52,
  50,
  49,
  47,
  46,
  44,
  43,
  41,
  40,
  38,
  37,
  36,
  34,
  33,
  32,
  32,
  31,
  31,
  31,
  31,
  33,
  35,
  38,
  43,
  49,
  58,
  70,
  -158
};


typedef struct {
  int history[SAMPLEFILTER_TAP_NUM];
  unsigned int last_index;
} SampleFilter;

void SampleFilter_init(SampleFilter* f) {
  int i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

inline void SampleFilter_put(SampleFilter* f, int input) {
  f->history[(f->last_index++) & 511] = input;
}

inline int SampleFilter_get(SampleFilter* f) {
  long long acc = 0;
  int index = f->last_index, i;
  for(i = 0; i < SAMPLEFILTER_TAP_NUM; ++i) {
    acc += (long long)f->history[(index--) & 511] * filter_taps[i];
  };
  return acc >> 16;
}


#endif

