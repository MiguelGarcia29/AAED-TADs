#include <cstdlib>
#include "iostream"

using namespace std;

int uniforme(int a,int b){
    return a+rand()%(b-a+1);
}

int main(){

    double n= 10000000;

    int a=0,b=0,c=0,d=0,e=0,f=0;

    for(int i=0;i<n;i++){
        switch(uniforme(1,6)){
            case 1:
            a++;break;
            case 2:
            b++;break;
            case 3:
            c++;break;
            case 4:
            d++;break;
            case 5:
            e++;break;
            case 6:
            f++;break;
        }
    }

    cout << "El nº 1 tiene una frecuencia relativa " << a/n << "\n";
    cout << "El nº 2 tiene una frecuencia relativa " << b/n << "\n";
    cout << "El nº 3 tiene una frecuencia relativa " << c/n << "\n";
    cout << "El nº 4 tiene una frecuencia relativa " << d/n << "\n";
    cout << "El nº 5 tiene una frecuencia relativa " << e/n << "\n";
    cout << "El nº 6 tiene una frecuencia relativa " << f/n << "\n";

}