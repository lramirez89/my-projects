# -*- coding: utf-8 -*-
"""
Entregable 3

UVA - 1231

@author: leandro
"""

global indefinido
indefinido= -1 #indefinido de un índice de una lista

global bosque
#bosque= [ [1,4,10], [3,5,7,8,9,9], [3,4,5,6,9]  ]

H=10  #tamaño de los árboles

#mediante un algoritmo de counting guardo listas de tamaño H, donde indico can bellotas por altura
bosque= [ [1,4,10], [3,5,7,8,9,9], [3,4,5,6,9]  ]
global ibosque
ibosque = [0]*len(bosque)

global f
f=2

#devuelvo el primer indice mayor que i que iguale o supere a elem. Si no hay ninguno devuelvo infinito
#en este problema lista está ordenada y puede usarse búsqueda binaria
def primerValorQeIguale(elem, i, lista):
    while i<len(lista) and lista[i]<elem:
        i+=1
    if i<len(lista):
        return i
    else:
        return indefinido
    
    

def mcorn(b,t):
    if b==indefinido or b>=len(bosque[t]):
        return 0
    else:
        #busco el maximo
        maximo= -1
        for arbol in range(len(bosque)):
            if arbol==t and mcorn(b+1,arbol)>maximo:
                maximo= mcorn(b+1,arbol)
            if arbol!=t and mcorn( primerValorQeIguale( bosque[t][b]+f, 0, bosque[arbol]),arbol)>maximo:
                maximo= mcorn( primerValorQeIguale( bosque[t][b]+f, 0, bosque[arbol]),arbol)
                
        return 1+maximo
    
print( mcorn(0,0) )             








    
