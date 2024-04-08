#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Murcia's Skyline UVA - 11790 

Version inspirada en el problema de longest subsequence

@author: leandro
"""

def buscarAnterior(j,h,w,arr):
    i=j-1
    maximo=0
    while i>=0:
        if h[i]<h[j] and maximo<arr[i]:
            maximo= arr[i]
        i-=1
    return maximo
    
    
def max_len(h,w):
    n= len(h)
    arr=[-1]*n
    
    for i in range(n):
        arr[i]= buscarAnterior(i,h,w,arr)+w[i]
    
    return arr  


h= [10, 100, 50, 30, 80, 10]
w= [50, 10, 10, 15, 20, 10]

res1=max_len(h, w)


h= [30, 20, 20, 10]
w= [20, 30, 40, 50]

res2=max_len(h, w)

h= [80, 80, 80]
w= [15, 25, 20]

res3=max_len(h, w)


h= [80]
w= [15]

