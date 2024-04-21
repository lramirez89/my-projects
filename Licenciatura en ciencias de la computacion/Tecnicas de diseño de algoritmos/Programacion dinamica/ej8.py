# -*- coding: utf-8 -*-
"""

Ejercicio 8 prática 1 : CortesEconomicos

@author: leand
"""
import numpy as np

infinito = 999999999 #un infinito no tan grande

#La vara que vamos a cortar
global r
r=[0,2,4,7,10]

n= len(r)

global memo
memo =  np.full(n*n,-1)
memo = memo.reshape(n, n)

def cm(i,j):
    if j==i+1:
        return 0
    else:
        if memo[(i,j)] == -1:
            minimo= infinito
            for k in range(i+1,j):
                sol= cm(i,k) + cm(k,j)
                if sol<minimo:
                    minimo= sol
            
            memo[(i,j)]= (r[j]-r[i]) + minimo
        return memo[(i,j)]

print(cm(0,len(r)-1))