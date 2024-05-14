#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long int;

ll costoMinimo(queue< tuple<ll,ll> > &compradores, queue< tuple<ll,ll> > &vendedores){
    ll costoTotal=0;

    ll posComp = get<0>(compradores.front());
    ll cantComp = get<1>(compradores.front());

    ll posVend = get<0>(vendedores.front());
    ll cantVend = get<1>(vendedores.front());

    vendedores.pop(); compradores.pop();

    while(!compradores.empty() || !vendedores.empty()){
        //si el comprador quiere más de lo que puedo vender
        if(cantComp>cantVend){
            costoTotal += cantVend*abs(posComp-posVend);
            cantComp -= cantVend;

            posVend = get<0>(vendedores.front());
            cantVend = get<1>(vendedores.front());
            vendedores.pop();
            continue;
        }

        //si el vendedor puede vender más de lo que puede el comprador
        if(cantComp<cantVend){
            costoTotal += cantComp*abs(posComp-posVend);
            cantVend -= cantComp;
            posComp = get<0>(compradores.front());
            cantComp = get<1>(compradores.front());
            compradores.pop();
            continue;
        }

        //caso se puede vender la cantida exacta
        if(cantComp==cantVend){
            costoTotal += cantComp*abs(posComp-posVend);
            posVend = get<0>(vendedores.front());
            cantVend = get<1>(vendedores.front());
            posComp = get<0>(compradores.front());
            cantComp = get<1>(compradores.front());
            compradores.pop() ; vendedores.pop();
            continue;
        }
    }

    //útlima iteración para calcular el último caso
    costoTotal += cantVend*abs(posComp-posVend);
    
    return costoTotal;
}

int main(){
    queue<ll> resultados;

    ll cantHabitantes;
    cin>> cantHabitantes;

    while(cantHabitantes!=0){
        queue< tuple<ll,ll> > compradores;
        queue< tuple<ll,ll> > vendedores;

        for(int j=0; j<cantHabitantes ;j++){
            ll habitante;
            cin>>habitante;

            //si es comprador
            if(habitante>0)
                compradores.push(make_tuple(j,habitante));
            else
                vendedores.push(make_tuple(j,-habitante));
        }
        ll minimo = costoMinimo(compradores,vendedores);
        resultados.push(minimo);

        cin>>cantHabitantes;
    }

    //imprimo el resultado
    while(!resultados.empty()){
        ll res= resultados.front();
        cout<<res<<endl;
        resultados.pop();
    }

    return 0;
}