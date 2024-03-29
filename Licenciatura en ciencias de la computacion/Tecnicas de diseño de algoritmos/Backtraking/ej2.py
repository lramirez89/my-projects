#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
MagiCuadrados
"""

import numpy as np

#cuadrado mágico de orden n
global n
n=4

#los valores que pueden tomar los casilleros
valores = [n for n in range(1,n*n+1)]

#solucion parcial
matriz = np.full(n*n, -1)

#un vector para saber si ya tengo en elemento en la solución parcial
enSolucion= np.full(n*n , 0)


#funcion para saber si un cuadrado de n*n es mágico
def esMagico(sol):
    res1= 0
    for j in range(n):
        res1+= sol[j]
    
    #verifico las filas
    for i in range(n):
        res2=0
        for j in range(n):
            res2+= sol[i*n+j]
        if res1!=res2:
            return False
        
    #verifico las columnas
    for j in range(n):
        res2=0
        for i in range(n):
            res2+= sol[i*n+j]
        if res1!=res2:
            return False
    
    #verifico diagolal 1
    res2=0
    i=0
    while i<n*n:
        res2+= sol[i]
        i+= n+1
    if res2!=res1:
        return False
    
    #verifico diagolal 2
    res2=0
    i=n-1
    while i<2*n+1:
        res2+= sol[i]
        i+= n-1
    if res2!=res1:
        return False
    
        
    return True



##para calcular la suma parcial hasta i-esimo elemento y hacer podas
##suma parcial hasta el i-esimo elemento inclusive (en la misma fila)
def suma_parcial(sol,i,sumar_filas):    
    suma_hasta_i = 0
    
    if sumar_filas:
        if i<n:
            for indice in range(i+1):
                suma_hasta_i+= sol[indice]
        else:
            for indice in range((i//n)*n,i+1):
                suma_hasta_i+= sol[indice]
        return suma_hasta_i
    
    #hacer la suma sobre las columnas
    else:
        while i>=0:
            suma_hasta_i+= sol[i]
            i-=n
        return suma_hasta_i


#requiere haber calculado la primera fila
def numero_magico(sol):
    return suma_parcial(sol, n-1, True)


suma= suma_parcial([2,7,6,9,5,1,4,3,8],3,True)
print(suma)
    
esMagico([2,7,6,9,5,1,4,3,8])


    

## defino la funcion recursiva. Recibo una solución parcial por referencia
    # y el i-ésimo elemento de la matriz

def magiCuadrados(sol, i):

    
 
    
    if i==n*n:
        if esMagico(sol):
            print(sol)
            return 1
        else:
            return 0
    else:
        numero_magico = (n**3+n)//2
        cond_corte= suma_parcial(sol, i-1, True)>numero_magico or suma_parcial(sol, i-1, False)>numero_magico
       
        if cond_corte:
            return 0
        
        res = 0;
      
        for elem in valores:
            #si no está en la solucion parcial lo agrego
            if enSolucion[elem-1]==0:
                enSolucion[elem-1]=1
                sol[i]= elem
                res+= magiCuadrados(sol, i+1)
                
                ##saco a elem de la matriz
                enSolucion[elem-1]=0
        
        return res
                        
                        
    
#llamado que resuelve el problema
res= magiCuadrados(matriz, 0)
print("Hay ", res, " cuadrados mágicos de orden ", n)
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    