#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

//defino los tipos a usar para más declarabilidad
using Altura = int; using Ancho = int; using Indice = int;

//defino el diccionario que voy a usar (se puede cambiar si se descubre que otra implementacion es mas eficiente)
using Dic =  map<Indice,Altura>;


/*
Semantica de la función: el ancho máximo que puedo sacar de una secuencia hasta el i-esimo 
edificio exlusive. Solamente me quedo con los valores que superan una cota
Si es una cota superior, los vaores que son estrictamente menores que ella
si es una cota inferior, los valores que son estrictamente superiores que esta
*/
int maxLen(int i, int cota, vector<int> &alturas, vector<int> &anchuras, bool esCreciente){
    if(i==0) return 0;
    
    //decido si cota es una cota superior o inferior
    bool noSuperaCota;
    if(esCreciente)
        noSuperaCota= alturas[i-1]<cota;
    else
        //y etonces considero solamente valores crecienes en altura
        noSuperaCota= alturas[i-1]>cota;
    
    if(noSuperaCota)
        return max(maxLen(i-1,cota,alturas,anchuras, esCreciente),maxLen(i-1,alturas[i-1],alturas,anchuras,esCreciente)+anchuras[i-1] );
    else
        return maxLen(i-1,cota,alturas,anchuras,esCreciente);

}

int main(){
    //casos de test
    int t; cin>>t;

    vector<int> increasing(t); vector<int>decreasing(t);

    for(int contTes=0; contTes<t ;contTes++){
        //cantidad de edificios
        int n; cin>>n;

        vector<int> alturas(n); vector<int> anchuras(n);

        for(int k=0; k<n ;k++ )
            cin>>alturas[k];
        for(int k=0; k<n ;k++ )
            cin>>anchuras[k];

        increasing[contTes]= maxLen(n,1000,alturas,anchuras,true);
        decreasing[contTes]= maxLen(n,0,alturas,anchuras,false);
    }

    //imprimo el resultado
    for(int k=0; k<t ;k++){
        if(increasing[k]>decreasing[k])
            cout<<"Case "<<k+1<<". "<<"Increasing ("<<increasing[k]<<"). Decreasing ("<<decreasing[k]<<")."<<endl;
        else
            cout<<"Case "<<k+1<<". "<<"Decreasing ("<<decreasing[k]<<"). Increasing ("<<increasing[k]<<")."<<endl;

    }

    return 0;
}