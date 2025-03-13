#include <iostream>
#include <cmath>
#include <fstream>
using namespace std; 

int main () {
    int cantidad;
    cout << "INGRESE LA CANTIDAD DE LOS ASOCIADOS: ";
    cin >> cantidad;

    string nombres[cantidad];
    float estaturas[cantidad];
    float pesos[cantidad];
    float IMC[cantidad];

    // Ingresar los datos iniciales
    for (int i = 0; i < cantidad; i++) {
        cout << "CLIENTE [" << i + 1 << "] (NOMBRE): ";
        cin >> nombres[i];
        cout << "INGRESE EL PESO EN KG: ";
        cin >> pesos[i];
        cout << "INGRESE LA ESTATURA EN METROS (1.70): ";
        cin >> estaturas[i];
        IMC[i] = pesos[i] / (estaturas[i] * estaturas[i]);
    }

    // Calcular los estados de IMC
    int OMR = 0, OMD = 0, OBL = 0, SOBRE = 0, IDEAL = 0, BAJO = 0;

    for (int i = 0; i < cantidad; i++) {
        if (IMC[i] > 40) {
            OMR++;
        } else if (IMC[i] >= 35 && IMC[i] <= 39.9) {
            OMD++;
        } else if (IMC[i] >= 30 && IMC[i] <= 34.9) {
            OBL++;
        } else if (IMC[i] >= 25 && IMC[i] <= 29.9) {
            SOBRE++;
        } else if (IMC[i] >= 18.5 && IMC[i] <= 24.9) {
            IDEAL++;
        } else {
            BAJO++;
        }
    }

    // Generar el primer reporte y guardarlo en archivo
    ofstream archivoSalida("asociados.txt");
    archivoSalida << "REPORTE INICIAL: \n";
    float porcentaje;
    porcentaje = (OMR * 100) / cantidad;
    archivoSalida << "   NIVEL DE PESO            CANT | % \n";
    archivoSalida << "------------------------------------\n";
    archivoSalida << "  Obesidad morbida             " << OMR << " | " << porcentaje << "%\n";
    archivoSalida << "-------------------------------------\n";
    porcentaje = (OMD * 100) / cantidad;
    archivoSalida << " Obesidad moderada             " << OMD << " | " << porcentaje << "%\n";
    archivoSalida << "-------------------------------------\n";
    porcentaje = (OBL * 100) / cantidad;
    archivoSalida << " Obesidad leve                " << OBL << " | " << porcentaje << "%\n";
    archivoSalida << "-------------------------------------\n";
    porcentaje = (SOBRE * 100) / cantidad;
    archivoSalida << " Sobrepeso                    " << SOBRE << " | " << porcentaje << "%\n";
    archivoSalida << "-------------------------------------\n";
    porcentaje = (IDEAL * 100) / cantidad;
    archivoSalida << " Peso ideal                   " << IDEAL << " | " << porcentaje << "%\n";
    archivoSalida << "-------------------------------------\n";
    porcentaje = (BAJO * 100) / cantidad;
    archivoSalida << " Bajo peso                    " << BAJO << " | " << porcentaje << "%\n";
    archivoSalida << "-------------------------------------\n";
    archivoSalida.close();

    cout << "\nDatos iniciales guardados en el archivo asociados.txt\n";

    // Preguntar si deseas actualizar los datos
    char actualizar;
    cout << "¿Desea actualizar los datos de los asociados? (s/n): ";
    cin >> actualizar;

    if (actualizar == 's' || actualizar == 'S') {
        // Si elige 's', se actualizan los datos
        for (int i = 0; i < cantidad; i++) {
            cout << "ACTUALIZANDO CLIENTE [" << i + 1 << "] (NOMBRE): ";
            cin >> nombres[i];
            cout << "INGRESE EL NUEVO PESO EN KG: ";
            cin >> pesos[i];
            cout << "INGRESE LA NUEVA ESTATURA EN METROS (1.70): ";
            cin >> estaturas[i];
            IMC[i] = pesos[i] / (estaturas[i] * estaturas[i]);
        }

        // Calcular nuevamente los estados de IMC
        OMR = 0, OMD = 0, OBL = 0, SOBRE = 0, IDEAL = 0, BAJO = 0;
        for (int i = 0; i < cantidad; i++) {
            if (IMC[i] > 40) {
                OMR++;
            } else if (IMC[i] >= 35 && IMC[i] <= 39.9) {
                OMD++;
            } else if (IMC[i] >= 30 && IMC[i] <= 34.9) {
                OBL++;
            } else if (IMC[i] >= 25 && IMC[i] <= 29.9) {
                SOBRE++;
            } else if (IMC[i] >= 18.5 && IMC[i] <= 24.9) {
                IDEAL++;
            } else {
                BAJO++;
            }
        }

        // Generar el reporte actualizado y guardarlo en archivo
        ofstream archivoSalidaActualizado("asociados_actualizado.txt");
        archivoSalidaActualizado << "REPORTE ACTUALIZADO: \n";
        porcentaje = (OMR * 100) / cantidad;
        archivoSalidaActualizado << "   NIVEL DE PESO            CANT | % \n";
        archivoSalidaActualizado << "------------------------------------\n";
        archivoSalidaActualizado << "  Obesidad morbida             " << OMR << " | " << porcentaje << "%\n";
        archivoSalidaActualizado << "-------------------------------------\n";
        porcentaje = (OMD * 100) / cantidad;
        archivoSalidaActualizado << " Obesidad moderada             " << OMD << " | " << porcentaje << "%\n";
        archivoSalidaActualizado << "-------------------------------------\n";
        porcentaje = (OBL * 100) / cantidad;
        archivoSalidaActualizado << " Obesidad leve                " << OBL << " | " << porcentaje << "%\n";
        archivoSalidaActualizado << "-------------------------------------\n";
        porcentaje = (SOBRE * 100) / cantidad;
        archivoSalidaActualizado << " Sobrepeso                    " << SOBRE << " | " << porcentaje << "%\n";
        archivoSalidaActualizado << "-------------------------------------\n";
        porcentaje = (IDEAL * 100) / cantidad;
        archivoSalidaActualizado << " Peso ideal                   " << IDEAL << " | " << porcentaje << "%\n";
        archivoSalidaActualizado << "-------------------------------------\n";
        porcentaje = (BAJO * 100) / cantidad;
        archivoSalidaActualizado << " Bajo peso                    " << BAJO << " | " << porcentaje << "%\n";
        archivoSalidaActualizado << "-------------------------------------\n";
        archivoSalidaActualizado.close();

        cout << "\nDatos actualizados guardados en el archivo asociados_actualizado.txt\n";
    }

    return 0;
}



