    #include <cstdlib>
    #include "iostream"
    #include "math.h"

    using namespace std;

    double aleatorio(int a,int b){

        double entero = a+rand()%(b-a); //ELIGE UN Nº entre a y b-1
        double decimal = rand()%101;    //LE SUMA AL nº de [0,1]

        return entero+(decimal/100);
        
    }

    int main(){

        int n= 10000000;
        double sumy =0;
        for (int i=0;i<n;i++){
            double x=aleatorio(0,1);
            double y = 4*sqrt(1-pow(x,2));
            sumy += y;
        }


            cout << "La media es: " << sumy/n << "\n";
    }