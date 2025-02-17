#include <cstdlib>
#include "iostream"

using namespace std;

int uniforme(int a,int b){
    return a+rand()%(b-a+1);
}

int main(){
    for(int i=0;i<10;i++)
        cout << "Nº aleatorio: " << uniforme(1,15) << "\n";
    
}