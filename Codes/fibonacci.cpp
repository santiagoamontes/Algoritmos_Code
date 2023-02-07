#include<iostream>

using namespace std;

int main(){
    int n, a=0, b=1, c=1;


    cout<<"Digite el número de elementos a considerar en la serie: "; 
    cin>>n;

    cout<<a<<endl;
    cout<<b<<endl;
    for(int i=1; i<=n; i++){
        c= a+b;
        cout<<c<<endl;
        a=b;
        b=c;
    }


    return 0;
}