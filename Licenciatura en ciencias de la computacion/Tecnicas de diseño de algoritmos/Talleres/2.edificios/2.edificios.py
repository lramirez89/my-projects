#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Murcia's Skyline UVA - 11790 

@author: leandro
"""


def max_len(i,A,h,w):
    if i==0:
        return 0
    if h[i-1]<A:
        #primer llamada recursiva: decido no poner el elemento i-1
        #segudnda: decido ponerlo (en ambos casos puedo, se cumplen las restricciones)
        return max(max_len(i-1, A, h, w), max_len(i-1, h[i-1], h, w)+w[i-1] )
    else:
        return max_len(i-1, A, h, w)
    
def max_len_decrec(i,A,h,w):
    if i==0:
        return 0
    if h[i-1]>A:
        #primer llamada recursiva: decido no poner el elemento i-1
        #segudnda: decido ponerlo (en ambos casos puedo, se cumplen las restricciones)
        return max(max_len_decrec(i-1, A, h, w), max_len_decrec(i-1, h[i-1], h, w)+w[i-1] )
    else:
        return max_len_decrec(i-1, A, h, w)
    
    
h= [10, 100, 50, 30, 80, 10]
w= [50, 10, 10, 15, 20, 10]

res1= max_len(len(h), max(h)+1, h, w)
res1asc= max_len_decrec(len(h), min(h)-1, h, w)

h= [30, 20, 20, 10]
w= [20, 30, 40, 50]

res2= max_len(len(h), max(h)+1, h, w)
res2asc= max_len_decrec(len(h), min(h)-1, h, w)


h= [80, 80, 80]
w= [15, 25, 20]

res3= max_len(len(h), max(h)+1, h, w)
res3= max_len_decrec(len(h), min(h)-1, h, w)

h= [80]
w= [15]

res4= max_len(len(h), max(h)+1, h, w)
res4asc= max_len_decrec(len(h), min(h)-1, h, w)



