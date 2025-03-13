#include <iostream>
#include <cmath>
#include <fstream>      //PROFESORA ESTA BIBLIOTECA, ES PARA PODER EXPORTAR ARCHIVOS
using namespace std;

int main()
{
    int cantidad;
    cout << "INGRESE LA CANTIDAD DE LOS ASOCIADOS: ";
    cin >> cantidad;
    string nombres[cantidad];
    float estaturas[cantidad];
    float pesos[cantidad];
    float IMC[cantidad];

    for (int i = 0; i < cantidad; i++)
    {
        cout << "CLIENTE [" << i + 1 << "](NOMBRE): ";
        cin >> nombres[i];
        cout << "INGRESE EL PESO EN KG: ";
        cin >> pesos[i];
        cout << "INGRESE LA ESTATURA EN METROS (1.70): ";
        cin >> estaturas[i];
        IMC[i] = pesos[i] / (pow(estaturas[i], 2));
    }
    int OMR = 0, OMD = 0, OBL = 0, SOBRE = 0, IDEAL = 0, BAJO = 0;

    for (int i = 0; i < cantidad; i++)
    {
        cout << nombres[i] << " tiene un IMC de: " << IMC[i] << endl;

        if (IMC[i] > 40)
        {
            cout << "ESTADO: OBESIDAD MORBIDA" << endl;
            OMR++;
        }
        else if (IMC[i] >= 35 && IMC[i] <= 39.9)
        {
            cout << "ESTADO: OBESIDAD MODERADA" << endl;
            OMD++;
        }
        else if (IMC[i] >= 30 && IMC[i] <= 34.9)
        {
            cout << "ESTADO: OBESIDAD leve" << endl;
            OBL++;
        }
        else if (IMC[i] >= 25 && IMC[i] <= 29.9)
        {
            cout << "ESTADO: SOBREPESO" << endl;
            SOBRE++;
        }
        else if (IMC[i] >= 18.5 && IMC[i] <= 24.9)
        {
            cout << "ESTADO: PESO IDEAL" << endl;
            IDEAL++;
        }
        else
        {
            cout << "ESTADO: BAJO PESO" << endl;
            BAJO++;
        }
    }
    ofstream archivo("asociados.txt"); //OFSTREAM PUEDO USARLO POR LA BIBLIOTECA FSTREAM
    float porcentaje, porcentaje1, porcentaje2, porcentaje3, porcentaje4, porcentaje5;
    cout << "\n************************************* " << endl;
    archivo << "REPORTE: " << endl;
    porcentaje = (OMR * 100) / cantidad;
    archivo << "   NIVEL DE PESO            " << "CANT" << " | " << " % " << endl;
    archivo << "    " << "------------------------------------" << endl;
    archivo << "  Obesidad morbida             " << OMR << " | " << porcentaje << endl;
    archivo << "    " << "-------------------------------------" << endl;
    porcentaje1 = (OMD * 100) / cantidad;
    archivo << " Obesidad moderada             " << OMD << " | " << porcentaje1 << endl;
    archivo << "    " << "-------------------------------------" << endl;
    porcentaje2 = (OBL * 100) / cantidad;
    archivo << "   Obesidad leve               " << OBL << " | " << porcentaje2 << endl;
    archivo << "    " << "-------------------------------------" << endl;
    porcentaje3 = (SOBRE * 100) / cantidad;
    archivo << "     Sobrepeso                 " << SOBRE << " | " << porcentaje3 << endl;
    archivo << "    " << "-------------------------------------" << endl;
    porcentaje4 = (IDEAL * 100) / cantidad;
    archivo << "     Peso ideal                " << IDEAL << " | " << porcentaje4 << endl;
    archivo << "    " << "-------------------------------------" << endl;
    porcentaje5 = (BAJO * 100) / cantidad;
    archivo << "     Bajo peso                 " << BAJO << " | " << porcentaje5 << endl;
    archivo << "    " << "-------------------------------------" << endl;

    archivo.close();
    cout << "SE EXPORTO " << endl;

    char actualizar;
    cout << "Desea actualizar los datos de los asociados? (s/n): ";
    cin >> actualizar;

    if (actualizar == 's' || actualizar == 'S')
    {
        for (int i = 0; i < cantidad; i++)
        {
            cout << "ACTUALIZANDO CLIENTE [" << i + 1 << "] (NOMBRE): ";
            cin >> nombres[i];
            cout << "INGRESE EL NUEVO PESO EN KG: ";
            cin >> pesos[i];
            cout << "INGRESE LA NUEVA ESTATURA EN METROS (1.70): ";
            cin >> estaturas[i];
            IMC[i] = pesos[i] / (estaturas[i] * estaturas[i]);
        }
        OMR = 0, OMD = 0, OBL = 0, SOBRE = 0, IDEAL = 0, BAJO = 0;
        for (int i = 0; i < cantidad; i++)
        {
            cout << nombres[i] << " tiene un IMC de: " << IMC[i] << endl;

            if (IMC[i] > 40)
            {
                cout << "ESTADO: OBESIDAD MORBIDA" << endl;
                OMR++;
            }
            else if (IMC[i] >= 35 && IMC[i] <= 39.9)
            {
                cout << "ESTADO: OBESIDAD MODERADA" << endl;
                OMD++;
            }
            else if (IMC[i] >= 30 && IMC[i] <= 34.9)
            {
                cout << "ESTADO: OBESIDAD leve" << endl;
                OBL++;
            }
            else if (IMC[i] >= 25 && IMC[i] <= 29.9)
            {
                cout << "ESTADO: SOBREPESO" << endl;
                SOBRE++;
            }
            else if (IMC[i] >= 18.5 && IMC[i] <= 24.9)
            {
                cout << "ESTADO: PESO IDEAL" << endl;
                IDEAL++;
            }
            else
            {
                cout << "ESTADO: BAJO PESO" << endl;
                BAJO++;
            }
        }
        ofstream archivoactualizado("asociadosactualizado.txt");
        archivoactualizado << "REPORTE ACTUALIZADO: " << endl;
        porcentaje = (OMR * 100) / cantidad;
        archivoactualizado << "   NIVEL DE PESO            CANT | % " << endl;
        archivoactualizado << "------------------------------------" << endl;
        archivoactualizado << "  Obesidad morbida             " << OMR << " | " << porcentaje << "%" << endl;
        archivoactualizado << "-------------------------------------" << endl;
        porcentaje = (OMD * 100) / cantidad;
        archivoactualizado << " Obesidad moderada             " << OMD << " | " << porcentaje << "%" << endl;
        archivoactualizado << "-------------------------------------" << endl;
        porcentaje = (OBL * 100) / cantidad;
        archivoactualizado << " Obesidad leve                " << OBL << " | " << porcentaje << "%" << endl;
        archivoactualizado << "-------------------------------------" << endl;
        porcentaje = (SOBRE * 100) / cantidad;
        archivoactualizado << " Sobrepeso                    " << SOBRE << " | " << porcentaje << "%" << endl;
        archivoactualizado << "-------------------------------------" << endl;
        porcentaje = (IDEAL * 100) / cantidad;
        archivoactualizado << " Peso ideal                   " << IDEAL << " | " << porcentaje << "%" << endl;
        archivoactualizado << "-------------------------------------" << endl;
        porcentaje = (BAJO * 100) / cantidad;
        archivoactualizado << " Bajo peso                    " << BAJO << " | " << porcentaje << "%" << endl;
        archivoactualizado << "-------------------------------------" << endl;
        archivoactualizado.close();

        cout << "DATOS ACTUALIZADOS";
    }

    return 0;
}