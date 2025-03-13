#include <iostream>
using namespace std;

void ingresarnotas(string cursos[], int notasM[], int notasC[], int notasQ[], int n,  //Son mis FUNCIONES declaradas
                   int notasajustadasM[], int notasajustadasC[], int notasajustadasQ[]);
void promedios(int n, int notasajustadasM[], int notasajustadasC[], int notasajustadasQ[]); //Mas no estan definidas

int main () {

int n;
cout << "Ingrese la cantidad de alumnos evaluados: ";
cin >> n;
int notasM[n], notasC[n], notasQ[n]; //ARREGLOS PARA ALMACENAR LAS NOTAS
int notasajustadasM[n];
int notasajustadasC[n]; //ARREGLOS PARA ALMACENAS LOS AJUSTES DE NOTAS Y LAS NOTAS NO AJUSTADAS
int notasajustadasQ[n];
string cursos[]= {"matematica","comuniacion", "quimica"};
ingresarnotas(cursos,notasM,notasC,notasQ,n, notasajustadasM,notasajustadasC,notasajustadasQ); //estoy llamando
promedios(n,notasajustadasM,notasajustadasC,notasajustadasQ); //a las funciones dentro de funcion principal.
return 0;
}

void ingresarnotas(string cursos[], int notasM[], int notasC[], int notasQ[], int n, //PRIMER FUNCION DEFINIDA
                   int notasajustadasM[], int notasajustadasC[], int notasajustadasQ[]){

    for (int i = 0; i < n; i++)
    {
        cout << "Curso de " << cursos[0] << " nota del alumno ["<<i+1<<"]: ";
        cin >> notasM[i];
        cout << "Curso de " << cursos[1] << " nota del alumno ["<<i+1<<"]: ";
        cin >> notasC[i];
        cout << "Curso de " << cursos[2] << " nota del alumno ["<<i+1<<"]: ";
        cin >> notasQ[i];
    }
     auto corregirparametros= [&](){   //esta es una funcion anonima(se utiliza para hacer anidado de funciones)
       for (int i = 0; i < n; i++)   //el operado '&' es para que todas las variables de la funcion ORIGINALMENTE
       {                              //apliquen en la funcion anonima CORREGIRPARAMETROS.
          if (notasM[i] < 6)
          {
           notasajustadasM[i]=6;
           cout << "Nota sin ajustar de "<< cursos[0] <<": " << notasM[i] << endl;
           cout << "Nota ajustada: " << notasajustadasM[i] << endl;
          }
          else {
            notasajustadasM[i]= notasM[i];
          }
          if (notasC[i] < 6)
          {
            notasajustadasC[i]=6;
            cout << "Nota sin ajustar de "<< cursos[1]<<": "  << notasC[i] << endl;
           cout << "Nota ajustada: " << notasajustadasC[i] << endl;
          } else {
            notasajustadasC[i]= notasC[i];
          }
          
          if (notasQ[i] < 6)
          {
            notasajustadasQ[i]=6;
            cout << "Nota sin ajustar de "<< cursos[2]<<": "  << notasQ[i]<< endl;
           cout << "Nota ajustada: " << notasajustadasQ[i];
          }else {
            notasajustadasQ[i]= notasQ[i];
          }
          }  
       
       };
       corregirparametros();    //estoy llevando los datos de mi funcion anonima a mi funcion definida

     }
  void promedios(int n, int notasajustadasM[], int notasajustadasC[], int notasajustadasQ[]) { //segunda funcion
     for (int i = 0; i < n; i++) {
        double promedio = (notasajustadasM[i] + notasajustadasC[i] + notasajustadasQ[i]) / 3.0;
        cout << "Promedio del alumno " << i + 1 << " con notas ajustadas: " << promedio << endl;
    }
}
      

























//Enunciado:
//En una escuela, se está llevando a cabo una evaluación de desempeño académico de los estudiantes en sus materias principales. Se requiere un programa que permita lo siguiente:

//Ingreso de calificaciones: Se ingresa un arreglo con las calificaciones de los estudiantes en una asignatura.
//Ajuste de calificaciones: Si alguna calificación es inferior a 6, el sistema debe "ajustarla" automáticamente a 6. Para esto, se usará paso de parámetros por referencia.
//Promedio de calificaciones: Crear una función que calcule y devuelva el promedio de las calificaciones del arreglo.
//Mostrar resultados: Mostrar las calificaciones ajustadas y el promedio final de la clase.
