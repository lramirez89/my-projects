#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Práctica 1 ejercicio 7 : Astrotrade

@author: leandro
"""

#mgn : máxima ganancia neta

import numpy as np

global menosinf
menosinf = -9999999 #un infinito no tan chico


#asterioides
global p
p= [3,6,10]

n = len(p)

global matriz
matriz= np.full((n+1)*(n+1),-1)
matriz = matriz.reshape(n+1, n+1)

#matriz es mi estr de datos de memo, p es la lista de asteroides
def mgn(j,c):
    if c<0 or c>j:
        return menosinf
    if j==0:
        return 0
    else:
        if matriz[(j,c)]==-1:
            matriz[(j,c)]= max(mgn(j-1,c-1)-p[j-1],mgn(j-1,c+1)+p[j-1],mgn(j-1,c) )
        
        return matriz[(j,c)]
    
print(mgn(n,0))






