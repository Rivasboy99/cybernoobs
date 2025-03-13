#include <iostream>
#include <iomanip>     //salida de flujo para los salarios
using namespace std; 

void Nombretrabajdor(string nombre[], int n);   //declarar funciones 
void horastrabajadas(int horastrabajadas[], int n, string nombre[]);
void salarios(double salario[], int n, double pagohoras, string nombres[], int horastrabajada[]);

int main () {
 int  n;    
 double pagohoras;
 cout <<"INGRESE LA CANTIDAD DE TRABAJADORES: ";
 cin >> n;
 cout << "INGRESE EL PAGO POR HORA ACTUAL :";
 cin >> pagohoras;
 string nombres[n];   //
 int horastrabajada[n];
 double salario[n]; 
  cout << "Los trabajadores son: " << endl;
Nombretrabajdor(nombres,n);  
horastrabajadas(horastrabajada,n,nombres);
salarios(salario,n,pagohoras,nombres,horastrabajada); 

    return 0;
}
void Nombretrabajdor(string nombre[], int n) {  //FUNCIONES DEFINIDAS
    
    for (int i = 0; i < n; i++)
    {   cout << "Ingrese el trabajor " << "["<<i+1<<"]: ";
        cin >> nombre[i];       
    }
}
void horastrabajadas(int horastrabajada[], int n, string nombres[]) { 
     for (int i = 0; i < n; i++) {
     
        cout << "Las horas de trabajo a la semana de " << nombres[i] << " son: ";
        cin >> horastrabajada[i];
     } 
}
void salarios(double salario[], int n, double pagohoras, string nombres[], int horastrabajada[]){   
     
    for (  int i = 0; i < n; i++)
    {
         salario[i]= horastrabajada[i] * pagohoras;
    }
    cout << fixed << setprecision(2);
     for (  int i = 0; i < n; i++)
    {
        cout << "El salario de " << nombres[i] << " es de " << salario[i] << " NUEVOS SOLES" << endl;
    }
    auto mayorsalario= [&]() {      
        double mayor= salario[0];   
        int trabajadormasalto=0;   

        for (int i = 0; i < n; i++)
        {
            if (mayor < salario[i])
            {
                mayor=salario[i];
                trabajadormasalto=i;
            }
            
        }
        cout << "El trabajador con el salario mas alto es " << nombres[trabajadormasalto] 
             << " con un salario de " << salario[trabajadormasalto] << " NUEVOS SOLES." << endl;
    };
    mayorsalario();
}