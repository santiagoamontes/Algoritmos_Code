#include<iostream>
#include<time.h>
#include<cstdlib>


using namespace std;

int main(){

    int lista[] = {1,2,3,4,5};
    int T;

    cout<<"Digite el número a encontrar: ";
    cin>>T;
    int L=0;
    int n=5;
    int R=n-1;
    int M=(L+R)/2;
    char band = 'F';

    //srand(time(NULL));

    //cout<<"Funcionando";

    while(L <= R){
        M = (L+R)/2;

        if(lista[M] == T){
            band = 'V';
            //cout<<"Encontrado";
            break;
         }

        else if(lista[M]>T){
            R = M+1;
            M=(L+R)/2;
         }

        else if(lista[M]<T){
            L = M-1;
            M=(L+R)/2;
        }
    }

    if(band =='V'){
        cout<<"Resultado encontrado en la posición: "<<M;
    }

    else{
        cout<<"Resultado no encontrado";
    }


    return 0;  
}
