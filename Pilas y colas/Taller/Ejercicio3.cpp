
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
Ejercicio 3:
a.Crear un sistema que permita introducir texto
b. Que permita hacer modificaciones
c. que el sistema pueda mostrar la anterior modificacion o volver a la misma
*/

// Definición de la estructura para almacenar las versiones del texto
struct VersionTex {
    string texto;
};

int main() {
    stack<VersionTex> historialTex;
    string texto;
    int op;

    cout << "Bienvenido al sistema de gestión de texto." << endl;

    do {
        //menu principal
        cout << "\n1) Introducir texto\n";
        cout << "2) Hacer una modificación\n";
        cout << "3) Mostrar la versión actual del texto\n";
        cout << "4) Mostrar la versión anterior del texto\n";
        cout << "5) Salir\n";
        cout << "Seleccione una opción: ";
        
        cin >> op;

        switch (op) {
            case 1: {
                cout << "Introduce el texto: ";
                cin.ignore(); // Limpiar el buffer
                getline(cin, texto);
                
                // Guardar la versión actual del texto en el historial
                historialTex.push({texto});
                break;
            }
            case 2: {
                if (!historialTex.empty()) {
                    cout << "Introduce la modificación: ";
                    cin.ignore(); // Limpiar el buffer
                    getline(cin, texto);
                    
                    // Guardar la modificación en el historial
                    historialTex.push({texto});
                } else {
                    cout << "Primero debes introducir un texto inicial." << endl;
                }
                break;
            }
            case 3: {
                if (!historialTex.empty()) {
                    cout << "Versión actual del texto:\n" << historialTex.top().texto << endl;
                } else {
                    cout << "No hay texto disponible." << endl;
                }
                break;
            }
            case 4: {
                if (historialTex.size() > 1) {
                    historialTex.pop(); // Eliminar la versión actual
                    cout << "Versión anterior del texto:\n" << historialTex.top().texto << endl;
                } else {
                    cout << "No hay una versión anterior del texto disponible." << endl;
                }
                break;
            }
            case 5: {
                cout << "Saliendo del sistema...\n";
                break;
            }
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
        }

    } while (op!= 5);

    return 0;
}
