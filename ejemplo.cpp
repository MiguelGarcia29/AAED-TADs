#include "pilanela.h"
#include <iostream>
using namespace std;


void imprimir(Pila<int> p){
    while(p.tama() > 0){
        cout << ' ' << p.tope();
        p.pop();
    }
    
}

Pila<int> fun(Pila<int> P){
    Pila<int> R(P);  //INICIALIZACION POR COPIA
    cout << "En fun()" <<endl;
    cout << "P:"; imprimir(P); cout << endl;
    cout << "R:"; imprimir(R); cout << endl;
    return R;

}
/*
int main()
{
    Pila<int> P,Q;
    for (int i=0; i<10;++i)
    {
        P.push(i);
    }
    Q = fun(P);
    cout << "En main()" <<endl;
    cout << "P:"; imprimir(P); cout << endl;
    cout << "Q:"; imprimir(Q); cout << endl;
}*/