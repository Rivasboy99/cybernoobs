#include <iostream>
#include <vector>  //Para usar vectores
#include <iomanip> //Para usar static
using namespace std;

string verganador(int golesequipo, int golesequipo2, string equipo1, string equipo2); // Mi FUNCION DECLARADA

int main()
{
    const int n = 8;
    string equipos[n];
    int totalgoles[n] = {0};
    vector<string> rondaequipos;
    vector<int> posicionronda;

    cout << "Ingresa los nombres de los equipos: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Equipo [" << i + 1 << "]: ";
        cin >> equipos[i];
        rondaequipos.push_back(equipos[i]); // LoS PUSHBACK ES PARA AGREGAR CONTENIDO AL VECTOR PROFESORA
        posicionronda.push_back(i);
    }

    while (rondaequipos.size() > 1)
    {
        if (rondaequipos.size() == n)
        {
            cout << "\nRONDA DE ELIMINACION:\n"
                 << endl;
        }
        else if (rondaequipos.size() == n / 2)
        {
            cout << "\nSEMIFINALES: \n"
                 << endl;
        }
        else
        {
            cout << "\nGRAN FINAL:\n"
                 << endl;
        }

        vector<string> ganadoresderonda;
        vector<int> nuevaposicion;

        for (size_t i = 0; i < rondaequipos.size(); i += 2) // EL SIZE ES PARA SABER EL TAMAÑO DEL VECTORY Y ASI LO USAMOS EN EL FOR
        {
            cout << "Partido: " << rondaequipos[i] << " vs " << rondaequipos[i + 1] << endl;
            int golesequipo1, golesequipo2;
            cout << "Goles de " << rondaequipos[i] << ": ";
            cin >> golesequipo1;
            totalgoles[posicionronda[i]] += golesequipo1;

            cout << "Goles de " << rondaequipos[i + 1] << ": ";
            cin >> golesequipo2;
            totalgoles[posicionronda[i + 1]] += golesequipo2;

            string ganador = verganador(golesequipo1, golesequipo2, rondaequipos[i], rondaequipos[i + 1]);
            ganadoresderonda.push_back(ganador);

            if (ganador == rondaequipos[i])
            {
                nuevaposicion.push_back(posicionronda[i]);
            }
            else
            {
                nuevaposicion.push_back(posicionronda[i + 1]);
            }

            cout << "El ganador es: " << ganador << endl;

        
        }
            if (rondaequipos.size() == n )
            {
                cout << "\nEQUIPOS CLASIFICADOS(SEMIFINAL): " << endl;
                for (auto &c : ganadoresderonda)
                {                                     // Profesora ese foreach es para mostrar los equipos
                    cout << c << endl;
                }
            }
            else if (rondaequipos.size()==n/2)
            {
                cout << "\nEQUIPOS CLASIFICADOS(FINAL): " << endl;
                for (auto &c : ganadoresderonda)
                {
                    cout << c << endl;
                }
            }
            else
            {
                cout << "\nCAMPEON!!!\n";
            }

        rondaequipos = ganadoresderonda;
        posicionronda = nuevaposicion;
    }

    string finalganador = rondaequipos[0];
    cout << "******************************************" << endl;
    cout << "El ganador del torneo es: " << finalganador << endl;
    cout << "\nFELICITACIONES!!!" << endl;

    cout << " ESTADISTICA DE LOS EQUIPOS " << endl;

    int totalGoles = 0;
    for (int i = 0; i < n; i++)
    {
        totalGoles += totalgoles[i];
    }
    double promedio = static_cast<double>(totalGoles) / n; // Es una precision decimal profesora

    cout << "Promedio de goles por equipo: " << promedio << endl;

    int encimadepromedio = 0, singoles = 0;
    for (int i = 0; i < n; i++)
    {
        if (totalgoles[i] > promedio)
        {
            encimadepromedio++;
        }
        if (totalgoles[i] == 0)
        {
            singoles++;
        }
    }
    cout << "Cantidad de equipos con goles por encima del promedio: " << encimadepromedio << endl;
    cout << "Cantidad de equipos que no anotaron goles: " << singoles << endl;

    cout << "Goles por equipo : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << equipos[i] << " - " << totalgoles[i] << " goles" << endl;
    }
    return 0;
}

string verganador(int golesequipo, int golesequipo2, string equipo1, string equipo2) // MI FUNCION DEFINIDA
{
    if (golesequipo > golesequipo2)
        return equipo1;
    else
        return equipo2;
}