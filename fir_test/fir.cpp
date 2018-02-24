#include "fir.h"

static int filter_taps[SAMPLEFILTER_TAP_NUM] = {
  169,
  11,
  11,
  11,
  11,
  10,
  10,
  9,
  9,
  8,
  7,
  5,
  4,
  2,
  0,
  -2,
  -5,
  -7,
  -10,
  -13,
  -16,
  -20,
  -24,
  -28,
  -32,
  -36,
  -40,
  -45,
  -50,
  -55,
  -60,
  -65,
  -71,
  -76,
  -82,
  -87,
  -93,
  -98,
  -104,
  -110,
  -115,
  -121,
  -126,
  -132,
  -137,
  -142,
  -147,
  -151,
  -155,
  -159,
  -163,
  -166,
  -169,
  -172,
  -174,
  -176,
  -177,
  -178,
  -178,
  -178,
  -177,
  -175,
  -173,
  -170,
  -167,
  -163,
  -158,
  -152,
  -146,
  -139,
  -132,
  -124,
  -115,
  -105,
  -95,
  -83,
  -72,
  -59,
  -46,
  -32,
  -18,
  -3,
  13,
  29,
  46,
  64,
  81,
  100,
  118,
  137,
  157,
  176,
  196,
  217,
  237,
  257,
  278,
  299,
  319,
  340,
  360,
  380,
  400,
  420,
  439,
  458,
  477,
  495,
  513,
  530,
  546,
  562,
  577,
  591,
  605,
  618,
  630,
  641,
  651,
  660,
  668,
  676,
  682,
  687,
  692,
  695,
  697,
  698,
  698,
  697,
  695,
  692,
  687,
  682,
  676,
  668,
  660,
  651,
  641,
  630,
  618,
  605,
  591,
  577,
  562,
  546,
  530,
  513,
  495,
  477,
  458,
  439,
  420,
  400,
  380,
  360,
  340,
  319,
  299,
  278,
  257,
  237,
  217,
  196,
  176,
  157,
  137,
  118,
  100,
  81,
  64,
  46,
  29,
  13,
  -3,
  -18,
  -32,
  -46,
  -59,
  -72,
  -83,
  -95,
  -105,
  -115,
  -124,
  -132,
  -139,
  -146,
  -152,
  -158,
  -163,
  -167,
  -170,
  -173,
  -175,
  -177,
  -178,
  -178,
  -178,
  -177,
  -176,
  -174,
  -172,
  -169,
  -166,
  -163,
  -159,
  -155,
  -151,
  -147,
  -142,
  -137,
  -132,
  -126,
  -121,
  -115,
  -110,
  -104,
  -98,
  -93,
  -87,
  -82,
  -76,
  -71,
  -65,
  -60,
  -55,
  -50,
  -45,
  -40,
  -36,
  -32,
  -28,
  -24,
  -20,
  -16,
  -13,
  -10,
  -7,
  -5,
  -2,
  0,
  2,
  4,
  5,
  7,
  8,
  9,
  9,
  10,
  10,
  11,
  11,
  11,
  11,
  169
};

