#include <cstdlib>
#include "iostream"

using namespace std;

int uniforme(int a, int b)
{
    return a + rand() % (b - a + 1);
}

bool ordenado(int a[], int b[])
{

    bool ord = true;

    for (int i = 0; i < 6 && ord; i++)
    {
        if (a[i] != b[i])
            ord = false;
    }

    return ord;
}

int main()
{
    int veca[] = {1, 2, 3, 4, 5, 6};
    int vecrnd[6];
    int ordenados = 0;

    for (int i = 0; i < 10000000; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            vecrnd[j] = uniforme(1, 6);
        }

        if (ordenado(veca, vecrnd))
        {
            ordenados++;
        }
    }

    cout << "Veces ordenados: " << ordenados << "\n";
}