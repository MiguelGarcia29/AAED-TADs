#include "ListaDobleEnla.h"
#include <iostream>

struct mueble
{
    double anchura, pos;
};

class Cocina
{
    Cocina(double longitud);
    bool esColocable(mueble m);
    void aniadirMueble(mueble m);
    mueble mueblePos(double pos);
    void eliminarMueblePos(double pos);
    void moverMuebleIzq(double pos);

private:
    Lista<mueble> muebles;
    int nMuebles;
    double longitud;
};

Cocina::Cocina(double l) : nMuebles(0), longitud(l) {};

bool Cocina::esColocable(mueble m)
{
    bool valido = true;

    if (m.anchura + m.pos > longitud)
    {
        valido = false;
    }
    else
    {
        Lista<mueble>::posicion posC = muebles.primera();
        while (posC != muebles.fin() && valido)
        {

            // COMPRUEBO QUE ESA POSICION NO ESTÉ OCUPADA
            if (m.pos == muebles.elemento(posC).pos)
            {
                valido = false;
                // QUE LA ANCHUURA Y SU POSICION NO SOBREPONGA AL MUEBLE SIGUIENTE
            }
            else if (m.pos < muebles.elemento(posC).pos && m.pos + m.anchura > muebles.elemento(posC).pos)
            {
                valido = false;
                // QUE NO LO SOPERPONGA
            }
            else if (m.pos > muebles.elemento(posC).pos && m.pos < muebles.elemento(posC).pos + muebles.elemento(posC).anchura)
                valido = false;

            posC = muebles.siguiente(posC);
        }
    }
    return valido;
};

void Cocina::aniadirMueble(mueble m)
{
    bool colocable = esColocable(m);
    if (colocable)
    {
        Lista<mueble>::posicion pos = muebles.primera();
        while (pos != muebles.fin() && m.pos < muebles.elemento(pos).pos)
        {
            pos = muebles.siguiente(pos);
        }
        nMuebles++;
    }
};

mueble Cocina::mueblePos(double pos)
{
    mueble mueb;
    Lista<mueble>::posicion posi = muebles.primera();
    while (posi != muebles.fin() && pos <= muebles.elemento(posi).pos)
    {
        if (pos == muebles.elemento(posi).pos)
            mueb = muebles.elemento(posi);
        posi = muebles.siguiente(posi);
    }
    return mueb;
};

void Cocina::eliminarMueblePos(double pos)
{
    Lista<mueble>::posicion posi = muebles.primera();
    while (posi != muebles.fin() && pos <= muebles.elemento(posi).pos)
    {
        if (pos == muebles.elemento(posi).pos)
            muebles.eliminar(posi);
        posi = muebles.siguiente(posi);
    }
};

void Cocina::moverMuebleIzq(double pos)
{
    Lista<mueble>::posicion posi = muebles.primera();
    Lista<mueble>::posicion posMover;
    while (posi != muebles.fin() && pos <= muebles.elemento(posi).pos)
    {
        if (pos == muebles.elemento(posi).pos)
            posMover = posi;
        posi = muebles.siguiente(posi);
    }
    if (posMover != nullptr)
    {
        mueble anterior = muebles.elemento(muebles.anterior(posMover));
        double nuevaPos = anterior.anchura + anterior.pos;
        muebles.elemento(posMover).pos = nuevaPos;
    }
};