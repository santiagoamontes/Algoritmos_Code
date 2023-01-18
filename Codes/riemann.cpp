#include<iostream>
#include<math.h>
#include <vector>

using namespace std;

float Deltas(float, float, float);


int main(){
    float a,b,D,result;

    int n;

    cout<<"Límite inferior: ";
    cin>>a;
    cout<<"Límite superior: ";
    cin>>b;
    cout<<"Número de particiones: ";
    cin>>n;
    vector <double> areas;


    D = Deltas(a,b,n);

    cout<<"Cada partición será de a: "<<D<<endl;

    for(int j=0; j<n; j++){
        
        float x = (D*j + a);

        float func = x + 3*pow(x,2); 

        areas.push_back(func*D);   
    }

    double sum=0;

    for (int k=0; k<areas.size(); k++){
        sum += areas[k];
        }
    cout << "La sumatoria de Riemann dada es: " << sum << endl;
    
    return 0;  


}


float Deltas(float num1, float num2, float num3){
    float D = (num2-num1)/num3;

    return D;
}