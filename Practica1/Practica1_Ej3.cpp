    #include <cstdlib>
    #include "iostream"

    using namespace std;

    double aleatorio(int a,int b){

        double entero = a+rand()%(b-a); //ELIGE UN Nº entre a y b-1
        double decimal = rand()%101;    //LE SUMA AL nº de [0,1]

        return entero+(decimal/100);
        
    }

    int main(){
            cout << "Nº aleatorio: " << aleatorio(3,5) << "\n";
    }