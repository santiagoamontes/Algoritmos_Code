#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    set<int> digitos;
    cout << "Ingrese la cantidad de dígitos para buscar números reversibles (ingrese 0 para finalizar): ";
    cin >> n;
    while (n != 0){ 
        digitos.insert(n);
        cout << "Ingrese la cantidad de dígitos para buscar números reversibles (ingrese 0 para finalizar): ";
        cin >> n;
    }

    int contador = 0;
    set<int> reversibles;
    for(int i = 1; i < pow(10,*digitos.rbegin()); i++){
        if (i%10 > 0){
            int temp = i, reverse = 0;
            while(temp>0){
                reverse = reverse*10 + temp%10;
                temp /= 10;
            }
            int sum = i + reverse;
            temp = sum;
            int flag = true;
            while(temp>0){
                if (temp%2==0){
                    flag = false;
                    break;
                }
                temp = temp/10;
            }
            if (flag && digitos.count(to_string(i).length()) > 0) {
                contador++;
                reversibles.insert(i);
            }
        }
    }
    for (auto i : digitos) {
        cout << "Existen " << count_if(reversibles.begin(), reversibles.end(), [i](auto x){ return to_string(x).length() == i; }) << " números reversibles de " << i << " cifras." << endl;
    }

    return 0;
}
