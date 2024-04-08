#include<iostream>
#include<vector>
using namespace std;

/*
Implementacion bottom-up. Trabajo con un arreglo |arr|=|h|=|w| donde el i-esimo elemento de arreglo representa el máximo
subarreglo que puedo obtener desde el inicio hasta el i-esimo elemento
*/

/*Devuelvo el máximo valor de arr[0..j], con las restricciones de altura de edificioes del problema*/
int buscarAnterior(int j, vector<int> &h, vector<int> &w, vector<int> &arr, bool esAscendente){
     int i=j-1;

    //decido si quedarme con el  más grande que h[j] desde [0..j] en arr o con el mas chico
    bool condicion;
    int maximo= 0;
    if(esAscendente){
        while(i>=0){
            if(h[i]<h[j]&& maximo<arr[i])
                maximo= arr[i];
            i--;
        }   
    }
    else{
        while(i>=0){
            if(h[i]>h[j] && maximo<arr[i])
                maximo= arr[i];
            i--;
        }
    }

    return maximo;
}

int maxLen(vector<int> &h, vector<int> &w, bool esAscendente){
    int n= h.size();
    vector<int> arr(n,-1);

    for(int i=0; i<n ;i++)
        arr[i]= buscarAnterior(i,h,w,arr, esAscendente)+w[i];

    int max= arr[0];
    for(int elem: arr){
        if(elem>max)
            max= elem;
    }
    return max;
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

        increasing[contTes]= maxLen(alturas, anchuras, true);
        decreasing[contTes]= maxLen(alturas, anchuras, false);
    }

    //imprimo el resultado
    for(int k=0; k<t ;k++){
        if(increasing[k]>=decreasing[k])
            cout<<"Case "<<k+1<<". "<<"Increasing ("<<increasing[k]<<"). Decreasing ("<<decreasing[k]<<")."<<endl;
        else
            cout<<"Case "<<k+1<<". "<<"Decreasing ("<<decreasing[k]<<"). Increasing ("<<increasing[k]<<")."<<endl;

    }

    return 0;
}