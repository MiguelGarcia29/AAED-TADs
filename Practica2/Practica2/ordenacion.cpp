#include "ordenacion.h"

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
