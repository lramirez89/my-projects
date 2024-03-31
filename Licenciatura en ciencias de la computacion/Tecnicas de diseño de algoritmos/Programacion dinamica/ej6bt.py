#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Ejercicio 6 - optipago Backtracking
"""

#multiconjunto de billetes
B=[2,3,5,10,20,20]

#cantidad
c=14

##funcion auxiliar
def suma_tuplas(tupla1,tupla2):
    suma_tuplas = tuple(x + y for x, y in zip(tupla1, tupla2))
    return suma_tuplas

def cc(i,c):
    if c<=0:
        return (0,0)
    if i==0:
        return (float('inf'), float('inf'))
    
    return min(  suma_tuplas( cc(i-1,c-B[i-1]),(B[i-1],1) ), cc(i-1,c))

res= cc(len(B),c)

print("La solución es pagar ", res[0], " utilizando ", res[1], " billetes")

