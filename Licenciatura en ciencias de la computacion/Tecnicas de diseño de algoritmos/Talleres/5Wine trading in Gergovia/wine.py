#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Taller 5 Wine trading in Gergovia SPOJ - GERGOVIA 

@author: leandro
"""
import queue

#l= [5,-4,1,-3,1]
l=[-1000,-1000,-1000,1000,1000,1000]

compradores= queue.Queue()
vendedores = queue.Queue()

for i in range(0,len(l)):
    if l[i]<0:
        vendedores.put((i,-l[i]))
    else:
        compradores.put((i,l[i]))
        

costo_total= 0

posComp, cantComp = compradores.get()
posVend, cantVend = vendedores.get()

while not compradores.empty() or not vendedores.empty():
    
    #si el comprador quiere mas de lo que puedo vender
    if cantComp>cantVend:
        costo_total += cantVend*abs(posComp-posVend)
        cantComp -= cantVend;
        posVend, cantVend = vendedores.get()        
        continue
    
    #si el vendedor puede vender más de lo que puede comprar el comprador
    if cantComp<cantVend:
        costo_total += cantComp*abs(posComp-posVend)
        cantVend -= cantComp
        posComp, cantComp = compradores.get()
        continue
    
    
    #caso se pueden vender la cantidad exacta
    if cantComp==cantVend:
        costo_total += cantComp*(posComp-posVend)
        posComp, cantComp = compradores.get()
        posVend, cantVend = vendedores.get()
        continue
    
#una útima iteración para calcular el ultimo caso
costo_total += cantVend*abs(posComp-posVend)
    
print(costo_total)


    
    
    


            
            
