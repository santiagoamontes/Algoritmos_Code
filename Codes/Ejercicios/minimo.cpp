#include <iostream>
using namespace std;

int main() {
    int num, n;
    cout << "Cuantos numeros deseas ingresar (entre 1 y 1000)? ";
    cin >> num;
    if (num >= 1 && num <= 1000) {
        for (int i = 1; i <= num; i++) {
            cout << "Ingresa el numero " << i << ": ";
            cin >> n;
            int min_num = 0;
            int digit = 9;
            int min_num_temp = n;
            while (n > 0) {
                if (n>=digit){
                    min_num = min_num*10 + digit;
                    n -= digit;
                }
                digit--;
                if (n<digit) {
                    digit = n;
                }
                if (min_num <= min_num_temp) {
                    min_num_temp = min_num;
                }
            }
            cout << "El menor numero entero positivo cuya suma de cifras es " << n << " es: " << min_num << endl;
        }
    } else {
        cout << "El numero de elementos ingresado es invalido, el rango permitido es entre 1 y 1000" << endl;
    }
    return 0;
}
