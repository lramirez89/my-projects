#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > memo;

vector<int> contarBellotas(vector<int> arbol, int H){
    vector<int> res(H+1,0);
    for(int bellota : arbol)
        res[bellota]++;

    return res;
}

int mcorn(int h, int t, int f, vector< vector<int> > &bosque){
    int H= bosque[0].size()-1;
    if(h>=H+1)
        return 0;
    else{

        if(memo[h][t]==-1){
            //busco el máximo
            int maximo= -1;
            for(int arbol=0; arbol<bosque.size() ;arbol++){
                if(arbol==t && mcorn(h+1,arbol, f,bosque)>maximo)
                    maximo= mcorn(h+1,arbol,f,bosque);
                if(arbol!=t && mcorn(h+f,arbol,f,bosque)>maximo)
                    maximo = mcorn(h+f,arbol,f,bosque);
            }

            memo[h][t]= bosque[t][h]+maximo;
        }

        return memo[h][t];
    }
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

        //Hago counting con las bellotas
        for(int i=0; i<T ;i++)
            bosque[i]= contarBellotas( bosque[i], H ); 

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