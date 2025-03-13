#include <iostream> 
using namespace std;

int main () {
    string nombre[2]= {"Luis" , "alberto"};
    string  *pnombre= nombre;
    
    cout << *pnombre;

} 
