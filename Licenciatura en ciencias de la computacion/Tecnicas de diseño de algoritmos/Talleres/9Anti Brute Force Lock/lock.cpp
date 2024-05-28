#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using ll = long long;
ll INF = 1e18;
using namespace std;
using Nodo= ll; using Costo= ll; 

using Vecino = struct Vecino{
    Nodo nodo;
    Costo costo;
    Vecino(Nodo v, Costo c){nodo= v; costo= c;}
};

using Grafo = vector< vector<Vecino>> ;


int primn2(int origen, Grafo& g){
    Costo res=0;

    //distancia de cada nodo al AGM
    const int n = g.size();
    vector<Costo> distancia = vector<Costo>(n,INF);
    vector<bool> enArbol = vector<bool>(n, false);

    distancia[origen] = INF; enArbol[origen]= true;
    for(Vecino v : g[origen])
        distancia[v.nodo] = v.costo; 
    
    
    for(int cantNodos=1; cantNodos<n  ;cantNodos++){
        //busco el nodo vecino con la aristsa de menor costo
        Nodo minimo= 0;
        for(int j=0; j<n ;j++){
            if(!enArbol[j] && distancia[j]<distancia[minimo])
                minimo = j;
        }

        //actualizo el minimo como visitado
        enArbol[minimo] = true;
        res+= distancia[minimo];

        //ahora que minimo está en el arbol, veo si puedo llegar a los nodos adyacentes al árbol con una distancia menor
        for(Vecino v : g[minimo]){
            if(!enArbol[v.nodo] && distancia[v.nodo]>v.costo)
                distancia[v.nodo] = v.costo;
        }
     
    }

    return res;
}

int calcularCosto(int n1, int n2){
    int costo=0;
    for(int i=0; i<4 ;i++){
        int cifra1 = n1%10;
        int cifra2 = n2%10;    

        costo+= min(abs(cifra1-cifra2), min(cifra1,cifra2)+ abs(10-max(cifra1,cifra2)));
        
        n1/= 10;
        n2/= 10;
    }
    return costo;
}

int main(){
    int t;
    cin>>t;

    vector<int> resultados;

    for(int j=0; j<t ;j++){
        vector<int> claves;
        int c;
        cin>>c;

        for(int i=0; i<c ;i++){
            int clave;
            cin>>clave;
            claves.push_back(clave);
        }

        Grafo g = vector<vector<Vecino>>(c);
        for(int i=0; i<c ;i++){
            for(int j=0; j<c; j++){
                if(i!=j)
                    g[i].push_back(Vecino(j,calcularCosto(claves[i],claves[j])));
            }
        }

        int costoArbol = primn2(0,g);

        //agrego el costo de desde 0000 hasta el grafo
        Costo min= INF;
        for(Costo num : claves){
            Costo costo = calcularCosto(num,0000);
            if(costo<min)
                min= costo;
        }

        resultados.push_back(costoArbol+min);
    
    }

    for(int resultado : resultados)
        cout<<resultado<<endl;  
    
    return 0;
}











