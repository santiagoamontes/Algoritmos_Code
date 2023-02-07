#include<iostream>
using namespace std;
    int main(){
        int n, valor;;
        double prom, result=0;
        cout<<"Digite la cantidad de números: "; cin>>n;

        for(int i=1; i<=n; i++){
            cout<<"Digite un valor: ";cin>>valor;
            result += valor; 
        }
        prom = result/n; 
        cout<<"El promedio es: "<<prom;
        return 0;
        }