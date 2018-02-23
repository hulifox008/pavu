#!/usr/bin/env python

import math
bands = 10
freq_start = 0
freq_end = 22050
exp_start  = 1
exp_stop = 2
exp_step = (exp_stop-exp_start)/bands
exp = exp_start
sum = 0
for x in range(0,10):
    print(10**exp)
    sum = sum + 10**exp
    exp = exp + exp_step

exp = exp_start;
band_start = 0 
print("sum : %f" % sum);
for x in range(0,10):
    width = (freq_end-freq_start)*(10**exp)/sum
    gap = width*0.2
    band_stop = band_start + (width - gap)
    print("%d - %d gap: %d" % (band_start, band_stop, gap))
    exp = exp + exp_step
    band_start = band_start + width
    
