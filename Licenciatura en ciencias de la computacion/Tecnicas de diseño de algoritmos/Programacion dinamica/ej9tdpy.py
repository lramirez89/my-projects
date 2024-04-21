# -*- coding: utf-8 -*-
"""
Práctica 1 ejercicio 9 : Tavesia vital . Top-down

@author: leandro
"""
import numpy as np

global infinito
infinito = 999999999 #un unfinito no tan grande

global n
n= 3

global grilla
grilla= np.arange(n*n)
grilla = grilla.reshape(n, n)

grilla[(0,0)]= -2
grilla[(0,1)]= -3
grilla[(0,2)]= 3
grilla[(1,0)]= -5
grilla[(1,1)]= -10
grilla[(1,2)]= 1
grilla[(2,0)]= 10
grilla[(2,1)]= 30
grilla[(2,2)]= -5


#la estructura de memoizacion
global memo
memo= np.full(n*n,-1)
memo = memo.reshape(n, n)

def mvn(i,j):
    if i==j and i==n-1 and grilla[(i,j)]<=0:
        return grilla[(i,j)]*(-1)+1
    if i==j and i==n-1 and grilla[(i,j)]>0:
        return 1
    else:
        if memo[(i,j)]==-1:
            el_de_la_izquierda= infinito
            if i+1<n:
                el_de_la_izquierda= mvn(i+1,j)
            
            el_de_abajo = infinito
            if j+1<n:
                el_de_abajo= mvn(i,j+1)
                
            res= min(el_de_la_izquierda,el_de_abajo)- grilla[(i,j)]
            
            if res>0:
                memo[(i,j)]= res
            else:
                memo[(i,j)]= 1
        return memo[(i,j)]
            
        
print(mvn(0,0))



## Version sin memo
# =============================================================================
# def mvn(i,j):
#     if i==j and i==n-1 and grilla[(i,j)]<=0:
#         return grilla[(i,j)]*(-1)+1
#     if i==j and i==n-1 and grilla[(i,j)]>0:
#         return 1
#     else:
#         el_de_la_izquierda= infinito
#         if i+1<n:
#             el_de_la_izquierda= mvn(i+1,j)
#         
#         el_de_abajo = infinito
#         if j+1<n:
#             el_de_abajo= mvn(i,j+1)
#             
#         res= min(el_de_la_izquierda,el_de_abajo)- grilla[(i,j)]
#         
#         if res>0:
#             return res
#         else:
#             return 1
#         
# print(mvn(0,0))
# =============================================================================
            
            
            
            
        
        
        
        