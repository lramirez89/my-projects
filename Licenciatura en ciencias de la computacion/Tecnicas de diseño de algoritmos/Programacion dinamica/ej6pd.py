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


# Crear el array bidimensional
array_tuplas = np.empty((n+1,c+1), dtype=object)
for i in range(n+1):
    for j in range(c+1):
        array_tuplas[i,j] = (-1,-1)


##funcion auxiliar, sumar tuolas termino a termino (la funcion + las concatena)
def suma_tuplas(tupla1,tupla2):
    suma_tuplas = tuple(x + y for x, y in zip(tupla1, tupla2))
    return suma_tuplas

def cc(i,c):
    if c<=0:
        return (0,0)
    if i==0:
        return (float('inf'), float('inf'))
    
    #si el valor es -1,-1 está indefinido
    if array_tuplas[i,c]==(-1,-1) :
        array_tuplas[i,c]= min(  suma_tuplas( cc(i-1,c-B[i-1]),(B[i-1],1) ), cc(i-1,c))
    
    return array_tuplas[i,c]

res= cc(n,c)

print("La solución es pagar ", res[0], " utilizando ", res[1], " billetes")

