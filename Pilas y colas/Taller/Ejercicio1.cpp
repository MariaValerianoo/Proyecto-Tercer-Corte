#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <limits> 
using namespace std;

/*
Ejercicio 1:a. Realizar un programa que le permita al usuario crear una lista de llamadas telefonicas recientes
b. Muestra esa lista de llamadas desde la más reciente a la más antigua
*/

// Definición del struct para representar una llamada telefónica
struct Llamada {
    string numero;
    string fecha;
    string hora;
};

int main() {
    queue<Llamada> colaLlamadas;

    int op;
    
    do {
        cout << "Bienvenido al registro de llamadas telefónicas recientes\n";
        cout << "¿Qué deseas hacer?\n";
        cout << "1) Registrar una llamada\n";
        cout << "2) Mostrar la lista de llamadas\n";
        cout << "3) Salir\n";
        cout << "Ingrese la opción: ";
        cin >> op;

        // Limpieza de Buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (op) {
            case 1: {
                // Registrar una llamada
                Llamada nuevaLlamada;
                cout << "Ingrese el número de teléfono: ";
                getline(cin, nuevaLlamada.numero);
                cout << "Ingrese la fecha (DD/MM/AAAA): ";
                getline(cin, nuevaLlamada.fecha);
                cout << "Ingrese la hora (HH:MM): ";
                getline(cin, nuevaLlamada.hora);
                colaLlamadas.push(nuevaLlamada);
                cout << "Llamada registrada exitosamente.\n";
                break;
            }
            case 2: {
                // Mostrar la lista de llamadas desde la más reciente a la más antigua
                if (!colaLlamadas.empty()) {
                    cout << "Lista de llamadas telefónicas recientes:\n";
                    int size = colaLlamadas.size();
                    for (int i = 0; i < size; ++i) {
                        Llamada llamada = colaLlamadas.front();
                        cout << "Número: " << llamada.numero << endl;
                        cout << "Fecha: " << llamada.fecha << endl;
                        cout << "Hora: " << llamada.hora << endl;
                        colaLlamadas.push(colaLlamadas.front());
                        colaLlamadas.pop();
                    }
                } else {
                    cout << "No hay llamadas registradas.\n";
                }
                break;
            }
            case 3: {
                cout << "Saliendo del programa..\n";
                break;
            }
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (op != 3);

    return 0;
}