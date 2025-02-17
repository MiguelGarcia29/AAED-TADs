#include "pilanela.h"
#include <cassert>

class Cursor{
    Cursor();
    void avanzarCursor();
    void borrarCaracter();
    void retrasarCursor();
    void borrarAnterior();
    void irFinal();
    void insertarCaracter(char a);
    void irPrincio();
    void sobreescribirCaracter(char a);
    ~Cursor();

private:
    Pila<char> izq;
    Pila<char> der;
    //EL CURSOR ESTA EN EL TOPE DE LA IZQ
};

Cursor::Cursor(){}

void Cursor::avanzarCursor(){
    if(!der.vacia()){
        izq.push(der.tope());
        der.pop();
    }
}

void Cursor::borrarCaracter(){
    assert(!izq.vacia());
    izq.pop();    
}

void Cursor::retrasarCursor(){
    assert(!izq.vacia());
    der.push(izq.tope());
    izq.pop();
}

void Cursor::borrarAnterior(){
    retrasarCursor();
    borrarCaracter();
    avanzarCursor();
}

void Cursor::irFinal(){
    while(!der.vacia()){
        izq.push(der.tope());
        der.pop();
    }
}

void Cursor::insertarCaracter(char x){
    izq.push(x);
}

void Cursor::irPrincio(){
    while(!izq.vacia()){
        der.push(izq.tope());
        izq.pop();
    }
}

void Cursor::sobreescribirCaracter(char x){
    borrarCaracter();
    insertarCaracter(x);
}

Cursor::~Cursor(){
    der.~Pila();
    izq.~Pila();
}