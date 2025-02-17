#include "colaenla.h"
#include <iostream>
using namespace std;

enum Direccion{
    ARR,ABJ,IZQ,DER
};

class Simbolo{
public:
    Simbolo(){};
    void aniadirUnTrazo(Direccion d);
    void deshacerTrazo(int n);
    Simbolo simetriaX();
    Simbolo simetriaY();
    Simbolo simetriaXY();
    Cola<Direccion> gettrazo();

private:
    Cola<Direccion> trazo;
};



void Simbolo::aniadirUnTrazo(Direccion d){
    trazo.push(d);
};

void Simbolo::deshacerTrazo(int n){
    for(int i=0;i<n&&trazo.vacia();++i){
        trazo.pop();
    }
};

Cola<Direccion> Simbolo::gettrazo(){
    return trazo;
};

Simbolo Simbolo::simetriaY(){
    Cola<Direccion> copia = trazo;
    Simbolo nuevo;
    while(!copia.vacia()){
        if(copia.frente()==IZQ){
            nuevo.aniadirUnTrazo(DER);
        }else if(copia.frente()==DER){
             nuevo.aniadirUnTrazo(IZQ);
        }else{
             nuevo.aniadirUnTrazo(copia.frente());
        }
        copia.pop();
    }

    return nuevo;
};

Simbolo Simbolo::simetriaX(){
    Cola<Direccion> copia = trazo;
    Simbolo nuevo;
    while(!copia.vacia()){
        if(copia.frente()==ARR){
            nuevo.aniadirUnTrazo(ABJ);
        }else if(copia.frente()==ABJ){
            nuevo.aniadirUnTrazo(ARR);
        }else{
            nuevo.aniadirUnTrazo(copia.frente());
        }
        copia.pop();
    }
    return nuevo;
};

Simbolo Simbolo::simetriaXY(){
    Cola<Direccion> copia = trazo;
    Simbolo nuevo;
    while(!copia.vacia()){
        switch(copia.frente()){
            case ARR:
                nuevo.aniadirUnTrazo(ABJ);
            break;
            case ABJ:
                nuevo.aniadirUnTrazo(ARR);
            break;
            case IZQ:
                nuevo.aniadirUnTrazo(DER);
            break;
            case DER:
                nuevo.aniadirUnTrazo(IZQ);
            break;
        }
        copia.pop();
    }
    return nuevo;
};

void mostrarSimbolo(Simbolo S){
    Cola<Direccion> cola = S.gettrazo();
    while(!cola.vacia()){
        switch(cola.frente()){
            case ARR:
                cout<<"ARRIBA-";
            break;
            case ABJ:
                cout<<"ABAJO-";
            break;
            case IZQ:
                cout<<"IZQUIERDA-";
            break;
            case DER:
                cout<<"DERECHA-";
            break;
        }
        cola.pop();
    }
    cout<<endl;
};

int main(){
    Simbolo S;
    S.aniadirUnTrazo(IZQ);
    S.aniadirUnTrazo(ABJ);
    S.aniadirUnTrazo(ABJ);
    S.aniadirUnTrazo(DER);
    S.aniadirUnTrazo(ARR);
    S.aniadirUnTrazo(IZQ);

    mostrarSimbolo(S);
    cout<<endl;
    mostrarSimbolo(S.simetriaX());
    cout<<endl;
    mostrarSimbolo(S.simetriaY());
    cout<<endl;
    mostrarSimbolo(S.simetriaXY());

};
