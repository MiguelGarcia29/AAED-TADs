#include <iostream>
#include <algorithm>

using namespace std;

void intercambioDirecto(int *p, int *f)
{
    for (int *i = p; i != f; ++i)
    {
        for (int *j = p; j < f - (i - p) - 1; ++j)
        { 
            if (*j > *(j + 1))
            {                            
                swap(*j, *(j + 1));
            }
        }
    }
}


void seleccionDirecta(int *p, int *f)
{
    for (int *i = p; i != f; ++i)
    {
        int *menor = min_element(i,f);
        
        /*for (int *j = i; j != f; ++j)
        { 

            min_element

            if(*i>*j)
                menor = j;
        }*/

        swap(*menor,*i);
    }
}

void inserccionDirecta(int *p, int *f)
{
    for (int *i = p+1; i != f; ++i)
    {
        for(int *j=i;j!=p; --j){
            if(*j<*(j-1))
                swap(*j,*(j-1));
        }
    }
}

int main()
{
    int v[] = {2, 4, 3, 1};
    inserccionDirecta(v, v + 4);

    for (int i = 0; i < 4; i++)
    {
        cout << v[i] << " ";
    }
}
