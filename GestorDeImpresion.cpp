#include "colaenla.h"
#include <iostream>
#include <string>

using namespace std;
typedef string codigo;

struct Trabajador{
    Cola<codigo> URGENTE;
    Cola<codigo> NO_URGENTE;
};

class Gestor{


private:
    Cola<Trabajador> imprimir;
}