# -*- coding: utf-8 -*-
"""
Entregable 3

UVA - 1231

@author: leandro
"""

global bosque
#bosque= [ [1,4,10], [3,5,7,8,9,9], [3,4,5,6,9]  ]

H=10  #tamaño de los árboles

#mediante un algoritmo de counting guardo listas de tamaño H, donde indico can bellotas por altura
#bosque= [ [1,4,10], [3,5,7,8,9,9], [3,4,5,6,9]  ]
bosque= [ [0,1,0,0,1,0,0,0,0,0,1] ,
        [0,0,0,1,0,1,0,1,1,2,0],
        [0,0,0,1,1,1,1,0,0,1,0]]

global f
f=2

def mcorn(h,t):
    if h>=H+1:
        return 0
    else:
        #busco el maximo
        maximo= -1
        for arbol in range(len(bosque)):
            if arbol==t and mcorn(h+1,arbol)>maximo:
                maximo= mcorn(h+1,arbol)
            if arbol!=t and mcorn(h+f,arbol)>maximo:
                maximo= mcorn(h+f,arbol) 
                
        return bosque[t][h]+maximo
    
print( mcorn(0,0) )             








    
