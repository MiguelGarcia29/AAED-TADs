#include "ListaDobleEnla.h"
#include <iostream>
using namespace std;

typedef Lista<char> Linea;

class Texto
{
public:
    Texto() {};
    void insertarLinea(Linea linea);
    void mostrarTexto();

private:
    Lista<Linea> t;
};

// SI AL FINAL HAY # SE ELIMINA LA FRASE
// SI DESPUES DE UN CARACTER X HAY UN @ SE BORRA EL ANTERIOR, SI HAY VARIOS @ SE LA PELA
void Texto::mostrarTexto()
{
    Lista<Linea>::posicion lineaActual = t.primera();
    Linea::posicion posLetra;
    Lista<char> textoActual;

    while (lineaActual != t.fin())
    {
        textoActual = t.elemento(lineaActual);
        // MIRO QUE EL ULTIMO CARACTER NO SEA #
        if (textoActual.elemento(textoActual.anterior(textoActual.fin())) != '#')
        {
            posLetra = textoActual.primera();
            while (posLetra != textoActual.fin())
            {
                if (posLetra != textoActual.anterior(textoActual.fin()) && 
                    textoActual.elemento(textoActual.siguiente(posLetra)) == '@')
                //if (textoActual.elemento(textoActual.siguiente(posLetra)) == '@')
                {

                    textoActual.eliminar(posLetra);
                    while (posLetra != textoActual.fin() && 
                    textoActual.elemento(posLetra) == '@')
                    {
                        textoActual.eliminar(posLetra);
                    }
                }
                else
                    posLetra = textoActual.siguiente(posLetra);
            }
            
            posLetra = textoActual.primera();

            while (posLetra != textoActual.fin())
            {
                cout << textoActual.elemento(posLetra);
                posLetra = textoActual.siguiente(posLetra);
            }
             cout << endl;
        }

        lineaActual = t.siguiente(lineaActual);
    }
};

void Texto::insertarLinea(Linea linea)
{
    t.insertar(linea, t.fin());
};
/*
int main()
{
    Texto t;
    Linea L1, L2, L3;
    // Inicializar Lineas
    L1.insertar('b', L1.fin());
    L1.insertar('e', L1.fin());
    L1.insertar('a', L1.fin());
    L1.insertar('t', L1.fin());
    L1.insertar('t', L1.fin());
    L1.insertar('@', L1.fin());
    L1.insertar('r', L1.fin());
    L1.insertar('i', L1.fin());
    L1.insertar('z', L1.fin());
    L2.insertar('i', L2.fin());
    L2.insertar('s', L2.fin());
    L2.insertar('a', L2.fin());
    L2.insertar('@', L2.fin());
    L2.insertar('@', L2.fin());
    L2.insertar('b', L2.fin());
    L2.insertar('e', L2.fin());
    L2.insertar('l', L2.fin());
    L2.insertar('@', L2.fin());
    L3.insertar('b', L3.fin());
    L3.insertar('e', L3.fin());
    L3.insertar('a', L3.fin());
    L3.insertar('t', L3.fin());
    L3.insertar('t', L3.fin());
    L3.insertar('r', L3.fin());
    L3.insertar('i', L3.fin());
    L3.insertar('h', L3.fin());
    L3.insertar('#', L3.fin());
    // Inicializar texto
    t.insertarLinea(L1);
    t.insertarLinea(L2);
    t.insertarLinea(L3);
    // Mostrar texto
    t.mostrarTexto();
    return 0;
}
*/