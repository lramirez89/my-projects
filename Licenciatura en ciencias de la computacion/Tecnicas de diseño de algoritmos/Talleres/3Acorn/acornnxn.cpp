#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int MENOSINF = -1;

/* Expreso cada árbol como una tupla (altura, cantBellotas) , cantidad de bellotas en la atura <0>
*/
vector<tuple<int,int> > contarBellotas(vector<int> arbol){
    vector<tuple<int,int> > res;

    int i=0;
    while(i<arbol.size()){
        int elem = arbol[i];
        int cantApariciones = 1;
        i++;
        while(i<arbol.size() && arbol[i]==elem){
            cantApariciones++;
            i++;
        }
        
        res.push_back(make_tuple(elem,cantApariciones));
    }
    return res;
}


int mcorn(vector<vector<int> > lisBellotas){
    vector< vector<tuple<int,int> > >bosque;

    for(vector<int> bellotas : lisBellotas)
        bosque.push_back( contarBellotas(bellotas) );
    
    int cantArbol= bosque.size();
    int cantMaxBellotas= 0;

    for(vector<tuple<int,int> > arbol : bosque){
    if(cantMaxBellotas<arbol.size())
        cantMaxBellotas= arbol.size();
    }

    int memo[][];



 

    vector< vector<int> > memo = vector<vector<int> >(cantArbol, vector<int>(cantMaxBellotas, MENOSINF));



}




int main(){
    //numero de datasets
    int c;
    cin>> c;

    //los resultados de todos los casos de test
    vector<int> resultados(c);

    for(int i=0; i<c ;i++){
        int T; int H; int F;
        cin>> T; cin>> H; cin>> F;

        memo= vector( H+1, vector(T, -1) );

        vector< vector<int> > bosque(T);

        for(int j=0; j<T ;j++){
            int cantBellotas;
            cin>>cantBellotas;

            bosque[j] = vector<int> (cantBellotas);
            for(int k=0; k<cantBellotas ;k++){
                int bellotas;
                cin>> bellotas;
                bosque[j][k]= bellotas;
            }
            
        }

        int reciboUnCero; cin>> reciboUnCero;

        //considero terminar a altura 0 en todos los árboles
        int maximo= -1;
        for(int arbol=0; arbol<bosque.size() ;arbol++){
            int res= mcorn(0,arbol,F,bosque);
            if(maximo<res)
                maximo= res;
        }

        resultados[i]= maximo;

    }

    for(int elem : resultados)
        cout<<elem<<endl;

    return 0;
}