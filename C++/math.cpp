#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void longitudcadena(char frase[], int n);
void reemplazarpalabra(char frase[], char frasenueva[],int n);

int main () {
int const n= 50;
char frase[n];
char frasenueva[n];

longitudcadena(frase, n);
reemplazarpalabra(frase,frasenueva,n);

}

void longitudcadena(char frase[], int n) {

  int largofrase;
  cout << "Ingrese una frase: ";
  cin.getline(frase,n);
  largofrase= strlen(frase);
  cout << "La longitud de la frase es : " << largofrase << endl;

}
void reemplazarpalabra(char frase[], char frasenueva[],int n) {
  char palabraareemplazar[50];
    char nuevapalabra[50];

  cout << "Frase Original: " << frase << endl;
  cout << "Ingrese palabra a reemplazar: ";
  cin >> palabraareemplazar;
  cout << "Ingrese la nueva palabra: ";
  cin >> nuevapalabra;
  char* pos = strstr(frase, palabraareemplazar); //strstr se encarga de verificar si esta la palabra a reemplazar
  if (pos != nullptr) { //es un tipo de puntero pero sin direccion osea es nulo 
  int i = 0;
  while (nuevapalabra[i] != '\0') {
    pos[i] = nuevapalabra[i];
       i++;
    }
    pos[i] = '\0';    // nos estamos asegurando que la cadena termine correctamente porque al final hay un nulo
    }
    cout << "Frase modificada: " << frase << endl;
}

 



  
  

