#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;
int main() {
    int n;
    cout << "Ingrese el número de casos a probar: ";
    cin >> n;

    for (int caso = 0; caso<n; caso++){

        int num;
        cout << "Ingrese un número: ";
        cin >> num;
        vector <int> digitos;
        int cont = 0;
        int num_temp = num;
        while(num_temp>0){
            digitos.push_back(num_temp%10);
            num_temp = num_temp/10;
            cont++;
        }

        if(digitos.size()%2 != 0){
            cout << "El número debe tener una cantidad par de digitos.";
            break;
        }

        std::sort(digitos.begin(), digitos.end());
        int prueba = 0;
        do
        {
            vector <int> colmillo1, colmillo2;
            std::vector<int>::iterator middleItr(digitos.begin() + digitos.size() / 2); 
            for (auto it = digitos.begin(); it != digitos.end(); ++it)
            {
                if (std::distance(it, middleItr) > 0) {
                    colmillo2.push_back(*it);
                }
                else {
                    colmillo1.push_back(*it);
                }
            }
            int num1=0, num2=0;

            for(int i=0; i<colmillo1.size(); i++){
                num1 = 10*num1 + colmillo1[i];
                num2 = 10*num2 + colmillo2[i];

            }
            if (num1*num2 == num){
                cout << "El número " << num << " es un número vampiro con raíces " << num1 << " y " << num2 <<"." << endl;
                prueba ++;
                break;
            }

        } while (std::next_permutation(digitos.begin(), digitos.end()));
        if (prueba == 0) {
            cout << "El número " << num << " no es un número vampiro."<<endl;
            }
    }
}
