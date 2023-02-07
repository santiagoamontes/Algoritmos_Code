#include<iostream>
#include<math.h>
#include <fstream>
#include <sstream>
#include <vector>

#include <omp.h>


using namespace std;
int main(){

    cout<<"Número de hilos: "<<omp_get_num_threads()<<endl;
    omp_get_num_threads(); 
    double inicio, fin;

    inicio = omp_get_wtime();

    #pragma omp parallel for num_threads(4) reduction(+:sum)

//Parámetros iniciales
    int n=200;
    float v_0 = 100, g = 9.8; 
    float theta = M_PI/6;
    float v_y, delta;

//Tiempo máximo de vuelo y sus respectivas particiones 
    float max_time = (2*v_0*sin(theta)) / g;
    delta = max_time / n;


    cout<<endl;
    cout<<"A continuación las velocidades verticales: "<<endl;
    cout<<endl;

    for(int i=0; i<n;i++){
        v_y = v_0*sin(theta) - g*(delta*i);
        cout<<"En el instante: "<<delta*i<<" la velocidad vertical es:"<<v_y<<endl;
    }


    cout<<endl;
    cout<<"A continuación las posiciones de la trayectoria: "<<endl;
    cout<<endl;

    std::vector<double> vy, x, y;


    for(int i=0; i<n;i++){

        x.push_back(v_0*cos(theta)*(delta*i));
        y.push_back(v_0*sin(theta)*(delta*i) - (g*pow((delta*i),2))/2);
        vy.push_back(v_0*sin(theta) - g*(delta*i));
    }

//Exportación de datos 

    ofstream file;
    file.open("Velocidades_vertical.txt");
    file << "Tiempo" << " , " << "Velocidad" << " , " << "X" << " , " << "Y" << endl;
    for (int i=0; i<n; i++){
        file << i << " , " << vy[i] << " , " << x[i] << " , " << y[i] << endl;
    }

    return 0;
}