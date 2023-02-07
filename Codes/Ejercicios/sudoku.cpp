#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, cont;
    cout << "¿Cuántos sudokus se evaluarán? " ;
    cin >> n;
    cont = 0;
    srand(time(0));
    while (cont < n){
        int sudoku[9][9];
        
        for(int i=0; i < 9; i++ ){
            for (int j=0; j<9; j++){
                sudoku[i][j] = rand()%20+1;
                cout << sudoku[i][j] << " ";
                if (j==2 or j==5){
                    cout << "| ";
                }
            }
            cout << endl;
            
            if (i==2 or i==5){
                cout << "--------------------"<< endl;

            }
        }


        vector <int> lin1, lin2, lin3; 
        for(int m = 1; m < 4; m++){ 
            for(int n = 1; n < 4; n++){
                for(int i=3*(n-1); i<3*n ;  i++){
                    lin1.push_back(sudoku[3*(m-1)][i]);
                    lin2.push_back(sudoku[3*(m-1)+1][i]);
                    lin3.push_back(sudoku[3*(m-1)+2][i]); 
                }
                for(int j=0; j<3; j++){
                    for(int k=0; k<3; k++){
                    if(lin1[j] == lin2[k] or lin1[j] == lin3[k] or lin2[j] == lin3[k]){
                        cout << "El sudoku tiene una repetición en un bloque." << endl;
                        
                    }}
                    }
                lin1.clear();
                lin2.clear();
                lin3.clear();
            }
        }

        cont++;
    }
    

}
