#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Ejercicio 6 - optipago Backtracking
"""

import numpy as np

#multiconjunto de billetes
B=[2,3,5,10,20,20]
n= len(B)

#cantidad
c=14



##funcion auxiliar, sumar tuolas termino a termino (la funcion + las concatena)
def suma_tuplas(tupla1,tupla2):
    suma_tuplas = tuple(x + y for x, y in zip(tupla1, tupla2))
    return suma_tuplas

def cc(B,c):
    n= len(B)
    
    # Crear el array bidimensional
    array_tuplas = np.empty((n+1,c+1), dtype=object)
            
    array_tuplas[0,0]= (0,0)
    for j in range(1,c+1):
        array_tuplas[0,j] = (float('inf'),float('inf'))
        
    for i in range(1,n+1):
        for j in range(c+1):
            res1= array_tuplas[i-1,j]
            res2= (0,0)
            if j-B[i-1]>=0:
                res2= array_tuplas[i-1,j-B[i-1]]
            res2= suma_tuplas( res2 , (B[i-1],1) )
            
            array_tuplas[i,j]= min( res1, res2)
            
    return array_tuplas[n,c]
        
    

res= cc(B,c)

print("La solución es pagar ", res[0], " utilizando ", res[1], " billetes")

