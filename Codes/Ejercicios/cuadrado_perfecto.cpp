#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Por favor ingrese el número al que desea calcular el factor para obtener un cuadrado perfecto, en caso de colocar más de una sepárelos por un espacio:" << endl;
    int number;
    while (cin >> number) {
        if(sqrt(number) == (int)sqrt(number)){
            cout<<"El factor minimo para obtener un cuadrado perfecto es 1"<<endl;
        }
        else{
        for (int i = 2; i <= number; i++) {
            if (number % i == 0) {
                int product = number / i;
                if (sqrt(product) == (int)sqrt(product)) {
                    cout << "El factor minimo para obtener un cuadrado perfecto es: " << i << endl;
                    break;
                }
            }
        }
        }
    }
    return 0;
}
