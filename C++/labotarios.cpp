#include <iostream>
#include <cctype>             //Para usar tolower profesora
#include <cstring>
using namespace std;

string convertirminusculas(string frase);  
void contador(int& contadorU, string frase2); 

int main () {
 string frase, frase2;
 cout << "Ingresa tu frase: ";
 getline(cin, frase);
 frase2 = convertirminusculas(frase);
 cout << "Frase en minusculas: " << frase2 << endl;
 int contadorU = 0;
 contador(contadorU, frase2);              //Llamo a la funcion definida 
 cout << "La vocal 'u' aparece " << contadorU << " veces." << endl;
    
return 0;
}

string convertirminusculas(string frase) {                 //decidi crear esta funcion para que si alguna vocal
    for (char& c : frase) {                                 // esta en mayuscula se convierta en minuscula y el contador aumente
     
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
         c = tolower(c);
     }
    }
    return frase;
}

void contador(int& contadorU, string frase2) {
    for (size_t i = 0; i < frase2.size(); i++) {            //mediante un for contare, escogi la vocal U.
        if (frase2[i] == 'u') {
            contadorU++; 
        }
    }
}
