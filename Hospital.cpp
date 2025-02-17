#include "ListaDobleEnla.h"
#include <stdio.h>

struct Paciente
{
    int idPaciente;
    int gravedad;

    Paciente() : idPaciente(0), gravedad(0) {}
    Paciente(int id, int grav) : idPaciente(id), gravedad(grav) {};
};

class Hospital
{
public:
    Hospital(int uci, int planta);
    void ingreso(Paciente p);
    void alta(Paciente p);
    void muerte(Paciente p);
    int pacientesUCI();
    int pacientesPlantes();
    int pacientesSegunGravedad(int g);
    ~Hospital();

private:
    int maxUCI, maxPlanta;
    Lista<Paciente> UCI, Planta;
    Lista<Paciente>::posicion menosGraveUCI();
    Lista<Paciente>::posicion menosGravePlanta();
    Lista<Paciente>::posicion buscarUCI(Paciente p);
    Lista<Paciente>::posicion buscarPlanta(Paciente p);
};

Hospital::Hospital(int uci, int planta) : maxUCI(uci), maxPlanta(planta) {};

Hospital::~Hospital()
{
    UCI.~Lista();
    Planta.~Lista();
}

Lista<Paciente>::posicion Hospital::menosGraveUCI()
{
    Lista<Paciente>::posicion posMenosGrave = UCI.primera();
    Lista<Paciente>::posicion posActual = UCI.primera();
    int gravedad = UCI.elemento(posMenosGrave).gravedad;
    while (posActual != UCI.fin())
    {

        if (UCI.elemento(posActual).gravedad > gravedad)
        {
            gravedad = UCI.elemento(posActual).gravedad;
            posMenosGrave = posActual;
        }

        posActual = UCI.siguiente(posActual);
    }

    return posMenosGrave;
}

Lista<Paciente>::posicion Hospital::menosGravePlanta()
{
    Lista<Paciente>::posicion posMenosGrave = Planta.primera();
    Lista<Paciente>::posicion posActual = Planta.primera();
    int gravedad = Planta.elemento(posMenosGrave).gravedad;
    while (posActual != Planta.fin())
    {

        if (Planta.elemento(posActual).gravedad > gravedad)
        {
            gravedad = Planta.elemento(posActual).gravedad;
            posMenosGrave = posActual;
        }

        posActual = Planta.siguiente(posActual);
    }

    return posMenosGrave;
}

Lista<Paciente>::posicion Hospital::buscarUCI(Paciente p)
{
    Lista<Paciente>::posicion posActual = UCI.primera();
    Lista<Paciente>::posicion posPaciente = nullptr;
    bool encontrado = false;
    while (posActual != UCI.fin() && !encontrado)
    {

        if (UCI.elemento(posActual).idPaciente == p.idPaciente)
        {
            posPaciente = posActual;
            encontrado = true;
        }
        posActual = UCI.siguiente(posActual);
    }

    return posPaciente;
}

Lista<Paciente>::posicion Hospital::buscarPlanta(Paciente p)
{
    Lista<Paciente>::posicion posActual = Planta.primera();
    Lista<Paciente>::posicion posPaciente = nullptr;
    bool encontrado = false;
    while (posActual != Planta.fin() && !encontrado)
    {

        if (Planta.elemento(posActual).idPaciente == p.idPaciente)
        {
            posPaciente = posActual;
            encontrado = true;
        }
        posActual = Planta.siguiente(posActual);
    }

    return posPaciente;
}

void Hospital::ingreso(Paciente p)
{
    if (p.gravedad < 6)
    {
        if (UCI.tama() == maxUCI)
        { // SI ESTA LLENA LA UCI MOVEMOS EL MENOS GRAVE
            Lista<Paciente>::posicion menosGravePos = menosGraveUCI();
            Paciente menoGrave = UCI.elemento(menosGravePos);
            UCI.eliminar(menosGravePos);
            UCI.insertar(p, UCI.fin());
            if (Planta.tama() == maxPlanta)
            {
                Lista<Paciente>::posicion menosGravePlt = menosGravePlanta();
                Planta.eliminar(menosGravePlt);
            }
            Planta.insertar(menoGrave, Planta.fin());
        }
    }
    else
    {
        if (Planta.tama() == maxPlanta)
        {
            Lista<Paciente>::posicion menosGravePlt = menosGravePlanta();
            Planta.eliminar(menosGravePlt);
        }
        Planta.insertar(p, Planta.fin());
    }
}

void Hospital::alta(Paciente p)
{
    Lista<Paciente>::posicion pacienteUbicacion = buscarUCI(p);
    if (pacienteUbicacion == nullptr)
    {
        pacienteUbicacion = buscarPlanta(p);
        Planta.eliminar(pacienteUbicacion);
    }
    else
    {
        UCI.eliminar(pacienteUbicacion);
        // BUSCO EL MAS GRAVE DE LA PLANTA Y QUE DEBERIA ESTAR EN LA UCI
        Lista<Paciente>::posicion posActual = Planta.primera();
        Lista<Paciente>::posicion posPaciente = nullptr;
        int gravedad = UCI.elemento(posActual).gravedad;
        while (posActual != Planta.fin() && UCI.elemento(posActual).gravedad < 6)
        {
            if (UCI.elemento(posActual).gravedad < gravedad)
            {
                posPaciente = posActual;
            }
            posActual = Planta.siguiente(posActual);
        }
        if (posPaciente != nullptr)
        {
            if (UCI.tama() != maxUCI)
            {
                Paciente mover = Planta.elemento(posPaciente);
                Planta.eliminar(posPaciente);
                UCI.insertar(mover, UCI.fin());
            }
        }
    }
}

void Hospital::muerte(Paciente p)
{
    p.gravedad=0;
    Lista<Paciente>::posicion pacienteUbicacion = buscarUCI(p);
    if (pacienteUbicacion == nullptr)
    {
        pacienteUbicacion = buscarPlanta(p);
        Planta.eliminar(pacienteUbicacion);
    }
    else
    {
        UCI.eliminar(pacienteUbicacion);
        // BUSCO EL MAS GRAVE DE LA PLANTA Y QUE DEBERIA ESTAR EN LA UCI
        Lista<Paciente>::posicion posActual = Planta.primera();
        Lista<Paciente>::posicion posPaciente = nullptr;
        int gravedad = UCI.elemento(posActual).gravedad;
        while (posActual != Planta.fin() && Planta.elemento(posActual).gravedad < 6)
        {
            if (Planta.elemento(posActual).gravedad < gravedad)
            {
                posPaciente = posActual;
            }
            posActual = Planta.siguiente(posActual);
        }
        if (posPaciente != nullptr)
        {
            if (UCI.tama() != maxUCI)
            {
                Paciente mover = Planta.elemento(posPaciente);
                Planta.eliminar(posPaciente);
                UCI.insertar(mover, UCI.fin());
            }
        }
    }
}

int Hospital::pacientesUCI()
{
    return UCI.tama();
}

int Hospital::pacientesPlantes()
{
    return Planta.tama();
}

int Hospital::pacientesSegunGravedad(int g)
{
    int cantidad = 0;
    //COMO PUEDE HABER GENTE CON GRAVEDAD EN DISTINTOS SITIOS

    Lista<Paciente>::posicion posActual = Planta.primera();
    while (posActual != Planta.fin())
    {
        if (Planta.elemento(posActual).gravedad == g)
        {
            cantidad++;
        }
        posActual = Planta.siguiente(posActual);
    }

    posActual = UCI.primera();
    while (posActual != UCI.fin())
    {
        if (UCI.elemento(posActual).gravedad == g)
        {
            cantidad++;
        }
        posActual = UCI.siguiente(posActual);
    }

    return cantidad;
}
