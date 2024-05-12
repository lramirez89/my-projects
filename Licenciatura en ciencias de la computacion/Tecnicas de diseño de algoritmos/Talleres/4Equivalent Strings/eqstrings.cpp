#include <string>
#include <iostream>
using namespace std;

/* Devuelvo verdadero sin la sublista [i,j) es equivalente
*/
bool sonEquovalentes(string &s1,  int i1, int j1, string &s2, int i2, int j2){

    //si ambos substrigs son vacios, son iguales
    if(j1-i1== 0 && j2-i2==0)
        return true;
    
    //si ambas sublistas tienen largo 1
    if(j1==i1+1 && j2==i2+1){
        if(s1[i1]==s2[i2])
            return true;
        else
            return false;
    }

    if(j1-i1 != j2-i2)
        return false;

    //me quedo con el caso donde ambas sublistas son de longitud iguales pero no son vacias
    int k= 0;
    while( k+i1<j1 && s1[k+i1]==s2[k+i2])
        k++;
    
    //caso: ambos strings son iguales
    if(k+i1==j1)
        return true;

    //si no son iguales veo si ambas mitades son equivalentes
    if(j1-i1 % 2 == 1)
        return false;

    bool res1 =  sonEquovalentes(s1, i1, (i1+j1)/2, s2, i2, (i2+j2)/2);

    if(res1){
        bool res2 =  sonEquovalentes(s1, (i1+j1)/2, j1,s2, (i2+j2)/2, j2);

        if(res2) return true;
    }

    //si llego hasta acá no es cierto que a1=b1 y a2=b2 . Veo el otro caso
    
    res1 =  sonEquovalentes(s1, i1, (i1+j1)/2, s2, (i2+j2)/2, j2);

    if(res1){
        bool res2 =  sonEquovalentes(s1, (i1+j1)/2, j1, s2, i2, (i2+j2)/2);

        if(res2) return true;
    }
    
    //si llego hasta acá no se cumple ninguno de los dos casos
    return false;

}

int main(){

    string s1;
    string s2;

    cin>>s1; cin>>s2;

    bool res = sonEquovalentes(s1, 0, s1.size(), s2, 0, s2.size());
    if(res)
        cout<<"YES";
    else 
        cout<<"NO";

    cout<<endl;

    return 0;
}