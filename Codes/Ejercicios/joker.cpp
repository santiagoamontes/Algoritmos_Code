#include <iostream>
#include <string>
using namespace std;

bool ordenado(int num){
    int prev = num % 10;
    num /= 10;
    bool crec = true;
    bool decr = true;
    while(num > 0){
        int digit = num % 10;
        if(digit >= prev)
            decr = false;
        if(digit <= prev)
            crec = false;
        prev = digit;
        num /= 10;
    }
    return crec || decr;
}

int main() {
    int casos;
    cout << "Ingrese la cantidad de casos: ";
    cin >> casos;
    for (int i = 0; i < casos; i++) {
        int num1, num2;
        cout << "Ingrese el primer número: ";
        cin >> num1;
        if(to_string(num1).length() != 7) {
            cout << "El primer número no tiene 7 dígitos, por favor ingrese un número válido" << endl;
            i--;
            continue;
        }
        cout << "Ingrese el segundo número: ";
        cin >> num2;
        if(to_string(num2).length() != 7) {
            cout << "El segundo número no tiene 7 dígitos, por favor ingrese un número válido" << endl;
            i--;
            continue;
        }
        if (ordenado(num1) && ordenado(num2)) cout << "Gana\n";
        else cout << "Pierde\n";
    }
    return 0;
}
