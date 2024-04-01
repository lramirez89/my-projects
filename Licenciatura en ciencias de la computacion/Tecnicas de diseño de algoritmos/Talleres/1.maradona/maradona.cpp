#include<iostream>
using namespace std;

class Jugador{
    public:
        Jugador(){}

        Jugador(string nombre, int habilidadAtaque, int habilidadDefensa){
            this->nombre = nombre;
            this->hablidadAtaque= habilidadAtaque;
            this->habilidadDefensa= habilidadDefensa;
        }
        string nombre;
        int hablidadAtaque;
        int habilidadDefensa;
};

int main(){

    //casos de test
    int t;
    cin>>t;
    for(int i=0; i<t ;i++){
        Jugador jugadores[10];
        for(int j=0; j<10 ;j++){
            string nombre; int ataque; int defensa;
            cin>>nombre; cin>>ataque; cin>>defensa;

            jugadores[j] = Jugador(nombre,ataque,defensa);
        }

        for(Jugador j: jugadores)
            cout<<j.nombre<<endl;
    }


    return 0;
}