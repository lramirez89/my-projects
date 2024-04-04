#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

typedef struct Jugador{
    Jugador(){}
    Jugador(string nombre, int habilidadAtaque, int habilidadDefensa) : nombre(nombre), habilidadAtaque(habilidadAtaque),
    habilidadDefensa(habilidadDefensa) {}
    string nombre;
    int habilidadAtaque;
    int habilidadDefensa;
} Jugador;

int main(){

    //casos de test
    int t;
    cin>>t;

    //guardo los resultados en vectores
    vector<vector<string> > resAtacantes(t);
    vector<vector<string> > resDefensores(t);

    for(int i=0; i<t ;i++){
        vector<Jugador> jugadores(10);

        for(int j=0; j<10 ;j++){
            string nombre; int ataque; int defensa;
            cin>>nombre; cin>>ataque; cin>>defensa;

            jugadores[j] = Jugador(nombre,ataque,defensa);
        }

        //ordeno lexicograficamente 
        stable_sort(jugadores.begin(), jugadores.end(), [](const Jugador& a, const Jugador& b) {
            return a.nombre < b.nombre;
        });       
        
        //ordeno ascendentemente por habilidad de defensa
        stable_sort(jugadores.begin(), jugadores.end(), [](const Jugador& a, const Jugador& b) {
            return a.habilidadDefensa < b.habilidadDefensa;
        });

        //utilizo un algoritmo estable para ordenar por habilidad de ataque
        stable_sort(jugadores.begin(), jugadores.end(), [](const Jugador& a, const Jugador& b) {
            return a.habilidadAtaque > b.habilidadAtaque;
        });


        //ya tengo a mis 5 atacantes en los primeros 5 lugares (y los 5 defensores en los últimos)
        int k=0;

        //tomo los primeros 5 y los ordeno
        vector<string> atacantes(5);
        while(k<5){
            atacantes[k]= jugadores[k].nombre;
            k++;
        }

        //ordeno lexicograficamente 
        stable_sort(atacantes.begin(), atacantes.end(), [](const string& a, const string& b) {
            return a < b;
        }); 

        //tomo los últimos 5 y los ordeno
        vector<string> defensores(5);
        while(k<10){
            defensores[k-5]= jugadores[k].nombre;
            k++;
        }

        //ordeno lexicograficamente 
        stable_sort(defensores.begin(), defensores.end(), [](const string& a, const string& b) {
            return a < b;
        }); 

        //copio mis resultados en el vector de resultados
        resAtacantes[i]= atacantes;
        resDefensores[i]= defensores;
    }

    //imprimo el resultado

    for(int i=0; i<t ;i++){
        cout<<"Case "<<i+1<<":"<<endl;
        cout<<"(";
        for(int at=0; at<resAtacantes[i].size() ; at++){
            cout<<resAtacantes[i][at];
            if(at<4) cout<<", ";
        }
        cout<<")"<<endl;

        cout<<"(";
        for(int at=0; at<resDefensores[i].size() ; at++){
            cout<<resDefensores[i][at];
            if(at<4) cout<<", ";
        }
        cout<<")"<<endl;
    }


    return 0;
}