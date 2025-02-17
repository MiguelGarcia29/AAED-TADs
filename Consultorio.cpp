#include <iostream>
#include "ListaDobleEnla.h"
#include "colaenla.h"
/*
struct Paciente{
    int idPaciente;
    Paciente(int id):idPaciente(id){};
};

struct Medico{
    int idMedico;
    Cola<Paciente> atender;
    Medico(int id):idMedico(id){};
};

class Consultorio{
    Consultorio();
    void altaMedico(Medico m);
    void bajaMedico(Medico m);
    void pacienteListaEsp(Medico m, Paciente p);
    Paciente turno(Medico m);
    void atenderPaciente(Medico m);
    bool pacientesPendientes(Medico m);

private:
    Lista<Medico> medicos;
    Lista<Medico>::posicion buscar(Medico M);//FUNCIO PRIVADA
};


Consultorio::Consultorio(){};

Lista<Medico>::posicion Consultorio::buscar(Medico M){
    Lista<Medico>::posicion ubicacion;
    Lista<Medico>::posicion posActual = medicos.primera();
    bool encontrado=false;
    while(posActual!=medicos.fin()&&!encontrado){

        if(medicos.elemento(posActual)==M){
            ubicacion=posActual;
            encontrado=true;
        }
        posActual=medicos.siguiente(posActual);
    }
    return ubicacion;
}

void Consultorio::altaMedico(Medico m){
    medicos.insertar(m,medicos.fin());
}

void Consultorio::bajaMedico(Medico m){
    medicos.eliminar(buscar(m));
}

void Consultorio::pacienteListaEsp(Medico m, Paciente p){
    medicos.elemento(buscar(m)).atender.push(p);
}

Paciente Consultorio::pacienteListaEsp(Medico m){
    return medicos.elemento(buscar(m)).atender.frente();
}

void Consultorio::atenderPaciente(Medico m){
    medicos.elemento(buscar(m)).atender.pop();
}

bool Consultorio::pacientesPendientes(Medico m){
    return medicos.elemento(buscar(m)).atender.vacia();
}