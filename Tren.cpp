#include "pilanela.h"
struct Vagon{

};
class Tren{
public:
    Tren();
    void desplazarIzq();
    void desplazarDer();
    void eliminarVagon();
    void insertarVagon(Vagon& v);
    Vagon observarVagon();
    bool trenVacio();

private:
    Pila<Vagon> izq;
    Pila<Vagon> der;
    Vagon activo;
    bool vacio;
};

Tren::Tren(){
    vacio=true;
}

void Tren::insertarVagon(Vagon& v){
    activo = v;
    while(!izq.vacia()){
        Vagon va= izq.tope();
        der.push(va);
        izq.pop();
    }
    vacio=false;
}

void Tren::desplazarIzq(){
    if(!der.vacia()){
        izq.push(activo);
        activo = der.tope();
        der.pop();
    }
}

void Tren::desplazarDer(){
    if(!izq.vacia()){
        der.push(activo);
        activo = izq.tope();
        izq.pop();
    }
}

void Tren::eliminarVagon(){
    if(der.vacia()&&izq.vacia()){
        vacio=true;
    }
    else{
        if(!der.vacia()){
            activo = der.tope();
            der.pop();
        }else{
            activo = izq.tope();
            izq.pop();
        }

    }
}

bool Tren::trenVacio(){
    return vacio;
}