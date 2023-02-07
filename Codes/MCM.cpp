#include <iostream>
using namespace std;

int mcm(int a, int b) {
    int mcm = a * b;
    int mayor = max(a, b);
    int menor = min(a, b);
    for (int i = mayor; i <= mcm; i += mayor) {
        if (i % menor == 0) {
            return i;
        }
    }
    return mcm;
}

int main() {
    int num1, num2;
    cout << "Introduce el primer número: ";
    cin >> num1;
    cout << "Introduce el segundo número: ";
    cin >> num2;
    cout << "El MCM de " << num1 << " y " << num2 << " es: " << mcm(num1, num2) << endl;
    return 0;
}

