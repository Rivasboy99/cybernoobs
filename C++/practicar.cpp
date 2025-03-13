#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int jugadores = 24;

void verjugadores(string nombres[], int edades[], string puestos[], int minutosjugados[], int cantidad);
void ordenarxminutos(int minutosjugados[], string nombres[], int edades[], string puestos[], int cantidad, bool ascendente = true);
void ordenarxedad(int edades[], string nombres[], int minutosjugados[], string puestos[], int cantidad, bool ascendente = true);
void promedioedad(int edades[], int cantidad);

int main()
{
  int cantidad;
  cout << "Ingrese la cantidad de jugadores (maximo 24): ";
  cin >> cantidad;
  if (cantidad > jugadores)
  {
    cout << "El número máximo de jugadores es 24. Ajustando la cantidad a 24." << endl;
    cantidad = jugadores;
  }

  string nombres[jugadores];
  int edades[jugadores];
  string puestos[jugadores];
  int minutosjugados[jugadores];

  for (int i = 0; i < cantidad; ++i)
  {
    cout << "Jugador #" << i + 1 << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombres[i]);
    cout << "Edad: ";
    cin >> edades[i];
    cout << "Puesto (A: Arquero, D: Defensa, VM: Volante, E: Delantero): ";
    cin >> puestos[i];
    cout << "Minutos Jugados: ";
    cin >> minutosjugados[i];
  }

  verjugadores(nombres, edades, puestos, minutosjugados, cantidad);
  ordenarxminutos(minutosjugados, nombres, edades, puestos, cantidad, true);
  cout << endl;
  cout << "Jugadores ordenados por minutos jugados (ascendente):\n" << endl;
  verjugadores(nombres, edades, puestos, minutosjugados, cantidad);
  ordenarxminutos(minutosjugados, nombres, edades, puestos, cantidad, false);
  cout << endl;
  cout << "Jugadores ordenados por minutos jugados (descendente):\n" << endl;
  verjugadores(nombres, edades, puestos, minutosjugados, cantidad);
  ordenarxedad(edades, nombres, minutosjugados, puestos, cantidad, true);
  cout << endl;
  cout << "Jugadores ordenados por edad (ascendente):\n" << endl;
  verjugadores(nombres, edades, puestos, minutosjugados, cantidad);
  ordenarxedad(edades, nombres, minutosjugados, puestos, cantidad, false);
  cout << endl;
  cout << "Jugadores ordenados por edad (descendente):\n" << endl;
  verjugadores(nombres, edades, puestos, minutosjugados, cantidad);
  promedioedad(edades, cantidad);

  return 0;
}

void verjugadores(string nombres[], int edades[], string puestos[], int minutosjugados[], int cantidad)
{
  cout << "\nListado de jugadores:\n";
  for (int i = 0; i < cantidad; ++i)
  {
    cout << "Nombre: " << nombres[i]
         << ", Puesto: " << puestos[i]
         << ", Minutos Jugados: " << minutosjugados[i]
         << ", Edad: " << edades[i] << endl;
  }
}

void ordenarxminutos(int minutosjugados[], string nombres[], int edades[], string puestos[], int cantidad, bool ascendente)
{
  for (int i = 0; i < cantidad - 1; ++i)
  {
    for (int j = i + 1; j < cantidad; ++j)
    {
      if ((ascendente && minutosjugados[i] > minutosjugados[j]) || (!ascendente && minutosjugados[i] < minutosjugados[j]))
      {
        swap(minutosjugados[i], minutosjugados[j]);
        swap(nombres[i], nombres[j]);
        swap(edades[i], edades[j]);
        swap(puestos[i], puestos[j]);
      }
    }
  }
}

void ordenarxedad(int edades[], string nombres[], int minutosjugados[], string puestos[], int cantidad, bool ascendente)
{
  for (int i = 0; i < cantidad - 1; ++i)
  {
    for (int j = i + 1; j < cantidad; ++j)
    {
      if ((ascendente && edades[i] > edades[j]) || (!ascendente && edades[i] < edades[j]))
      {
        swap(edades[i], edades[j]);
        swap(nombres[i], nombres[j]);
        swap(minutosjugados[i], minutosjugados[j]);
        swap(puestos[i], puestos[j]);
      }
    }
  }
}
void promedioedad(int edades[], int cantidad)
{
  if (cantidad == 0)
    return;

  float sumadeedades = 0;
  for (int i = 0; i < cantidad; ++i)
  {
    sumadeedades += edades[i];
  }

  float promedio = sumadeedades / cantidad;
  int mayores = 0, menores = 0;

  for (int i = 0; i < cantidad; ++i)
  {
    if (edades[i] > promedio)
      mayores++;
    else if (edades[i] < promedio)
      menores++;
  }

  cout << "Edad promedio: " << promedio << endl;
  cout << "Jugadores mayores que el promedio: " << mayores << endl;
  cout << "Jugadores menores que el promedio: " << menores << endl;
}
