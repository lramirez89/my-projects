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
p= [3,2,5,6]

n = len(p)

#nota: cuando se hable de mgn en los comentarios se hará referencia a la mgn funcion recursiva
#en la que se basa la implementación, no la mng de python implementada como bottom up

def mgn(p):
    n= len(p)
    arr= [menosinf]*(n+1)
    arr[0]= 0
    
    for j in range(1, n+1):
        temp= arr[0]
        
        arr[0]= max(arr[0], arr[1]+p[j-1] )
        
        for i in range(1,n):
            #mgn(j-1,c-1) ya mo modifiqué, por eso me guardé este valor en temp
            
            #guardo arr[i] porque es el valor que necesito tener para temp en la sig iteracion
            temp2= arr[i]
            
            arr[i]= max(arr[i], arr[i+1]+p[j-1], temp-p[j-1])
            
            temp= temp2
            
        arr[n] = max( arr[n], temp-p[j-1] )

            
    return arr[0]
    
    
print(mgn(p))






