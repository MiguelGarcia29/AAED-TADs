#include "pilanela.h"

struct tCubo{
    bool posicion; //TRUE ABAJO FALSE ARRIBA
    int tama;

    tCubo(int t=0,bool pos=true):tama(t),posicion(pos){};

};

void juego(Pila<tCubo> cubos){
    Pila<tCubo> resultado;
    tCubo cubilete;

    while(!cubos.vacia()){

        cubilete = cubos.tope();
        cubos.pop();
        if(!cubilete.posicion)
            cubilete.posicion=true; //LE DOY LA VUELTA

        while(!resultado.vacia()&&resultado.tope().tama< cubilete.tama){ //LO Q HACE ESQUE SI EL CUBILETE ACTUAL ES EL MAS GRANDE DE LOS QUE ESTAN EN RESULTADO SACA TODO LO DE RESULTADO HASTA LLEGAR AL MAS GRANDE QUE EL ACTUAL Y LOS DEJA EN CUBOS Y SE VUELVE A COMPARAR AHORA TODO
            cubos.push(resultado.tope());
            resultado.pop();
        }
        resultado.push(cubilete);
    }


}