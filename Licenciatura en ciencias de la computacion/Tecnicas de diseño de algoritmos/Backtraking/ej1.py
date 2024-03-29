# -*- coding: utf-8 -*-
"""
sumaSubconjutosBT
"""
sol=["nada","nada","nada"]

def subset_sum(c,i,j):
    #pongo el i-ésimo elemento
    
    
    #regla de factibilidad
    if j<0:
        return False;
    if i==0:
        return j==0
    else:
        #si entro acá pongo el i-ésimo elemento en sol
        sol[i-1]= 1
        res1= subset_sum(c, i-1, j-c[i-1])
        
        if res1:
            return res1
        else:3
        
            #si entro acá no pongo el i-ésimo elemento en sol
            sol[i-1]= 0 
            res0= subset_sum(c, i-1, j)
            
            return res0
        
    
    
    
c= [6,12,6]
k= 24



res= subset_sum(c, len(c), k)

print(res)
print(sol)
