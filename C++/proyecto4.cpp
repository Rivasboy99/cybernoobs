#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

void ordenadoAZ(string nombres[], int n);
void ordenadoZA(string nombres[], int n);
void ordenadoedad(int edades[], int n, string nombres[], int añosexp[],int aspecon[], char sexo[]);
void ordenadoSexo();
void ordenadoaspie(int edades[], int n, string nombres[], int añosexp[],int aspecon[], char sexo[]);
void ordenadoañosexp(int edades[], int n, string nombres[], int añosexp[],int aspecon[], char sexo[]);

int main () {
    int n;
    cout << "Ingrese el numero de personas a evaluar: ";
    cin >> n;
    string nombres[n];
    int edades[n];
    int aspecon[n];
    int añosexp[n];
    int mujeres=0, hombres=0, rango1=0,rango2=0,rango3=0;
    char sexo[n];

    for (int i = 0; i < n ; i++)
    {
        cout << "Ingrese el nombre ["<<i+1<<"]: ";
        cin >> nombres[i];
        cout << "Edad de " << nombres[i] << ": ";
        cin >> edades[i];
        if (edades[i] >= 18 && edades[i] <=25)
        {
            rango1++;
        } else if (edades[i] >= 26 && edades[i] <= 45)
        {
            rango2++;
        } else
        {
            rango3++;
        }
        cout << "Sexo de " << nombres[i] << "(F/M): ";
        cin >> sexo[i];
        if (sexo[i]=='M' || sexo[i]=='m')
        {
            hombres++;
        } else
        {
            mujeres++;
        }
        cout << "Años de experiencia de " << nombres[i] << ": ";
        cin >> añosexp[i];
        cout << "Aspiraciones Economicas de " << nombres[i] << ": ";
        cin >> aspecon[i];
    }
    int opcion, porcentajeM, porcentajeF, porran1,porran2,porran3;

    while (true) {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Ordenar por nombre (A-Z)" << endl;
        cout << "2. Ordenar por nombre (Z-A)" << endl;
        cout << "3. Ordenar por edad" << endl;
        cout << "4. Ordenar por años de experiencia" << endl;
        cout << "5. Ordenar por aspiraciones economicas" << endl;
        cout << "6. Ver porcentaje de generos" << endl;
        cout << "7. Ver porcentajes de edades" << endl;
        cout << "8. Salir" << endl;

        cout << "Opcion: ";
        cin >> opcion;

    switch (opcion) {
        case 1:
            ordenadoAZ(nombres,n);
            break;
        case 2:
            ordenadoZA(nombres,n);
            break;
        case 3:
            ordenadoedad(edades, n, nombres, añosexp, aspecon, sexo);
            break;
        case 4:
            ordenadoañosexp(edades, n, nombres, añosexp, aspecon, sexo);
            break;
        case 5:
            ordenadoaspie(edades, n, nombres, añosexp, aspecon, sexo);
            break;
        case 6:
            porcentajeM= (hombres*100) / n;
            porcentajeF= (mujeres*100) / n;
            cout << "Porcentaje de hombres: " << porcentajeM << "%" << endl;
            cout << "Porcentaje de mujeres: " << porcentajeF << "%" << endl;
            break;
        case 7:
            porran1= (rango1*100) / n;
            porran2= (rango2*100) / n;
            porran3= (rango3*100) / n;
            cout << "RANGO (18-25): " << porran1 << "%" << endl;
            cout << "RANGO (26-45): " << porran2 << "%" << endl;
            cout << "RANGO (45+): " << porran3 << "%" << endl;
            
            break;
        case 8:
            cout << "Saliendo del programa" << endl;
            return 0;
        default:
            cout << "Opcion incorrecta." << endl;
            break;
    }
}



}
void ordenadoAZ(string nombres[], int n) {

    sort(nombres, nombres + n);

    for (int i = 0; i < n; i++)
    {
        cout << nombres[i] << endl;
    }
    
}

void ordenadoZA(string nombres[], int n) {
    
    sort(nombres, nombres + n, greater<string>());

    for (int i = 0; i < n; i++)
    {
        cout << nombres[i] << endl;
    }
    

}

void ordenadoedad(int edades[], int n, string nombres[], int añosexp[],int aspecon[], char sexo[]) {


    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (edades[j] > edades[j+1])
            {
                swap(edades[j], edades[j+1]);
                swap(nombres[j], nombres[j+1]);
                swap(sexo[j], sexo[j+1]);
                swap(aspecon[j], aspecon[j+1]);
                swap(añosexp[j], añosexp[j+1]);
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout << edades[i]<<" - "<<nombres[i]<<" - "<< sexo[i]<<" - " << aspecon[i]<<" - "<<añosexp[i] << endl;
    }
    
    
}

void ordenadoañosexp (int edades[], int n, string nombres[], int añosexp[],int aspecon[], char sexo[]) {

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++) {

            if (añosexp[j] > añosexp[j+1])
            {   
                swap(añosexp[j], añosexp[j+1]);
                swap(edades[j], edades[j+1]);
                swap(nombres[j], nombres[j+1]);
                swap(sexo[j], sexo[j+1]);
                swap(aspecon[j], aspecon[j+1]);
                
            }
            
        }
    }  
    for (int i = 0; i < n; i++)
    {
        cout << añosexp[i]<<" - "<<nombres[i]<<" - "<< sexo[i]<<" - " << aspecon[i]<<" - "<<edades[i] << endl;
    }  
}

void ordenadoaspie(int edades[], int n, string nombres[], int añosexp[],int aspecon[], char sexo[]){

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++) {

            if (aspecon[j] > aspecon[j+1])
            {   
                swap(aspecon[j], aspecon[j+1]);
                swap(añosexp[j], añosexp[j+1]);
                swap(edades[j], edades[j+1]);
                swap(nombres[j], nombres[j+1]);
                swap(sexo[j], sexo[j+1]);
                
                
            }
            
        }
    } 
    for (int i = 0; i < n; i++)
    {
        cout << aspecon[i]<<" - "<<nombres[i]<<" - "<< sexo[i]<<" - " << añosexp[i]<<" - "<<edades[i] << endl;
    }   
}





