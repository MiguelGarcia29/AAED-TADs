#include "ejercicio1.h"


int main()
{

    cout << hola << "\n";

    int v[] = {2, 4, 3, 1};
    intercambioDirecto(v, v + 4);

    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << " ";
    }
}
