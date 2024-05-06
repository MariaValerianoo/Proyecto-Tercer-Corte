
#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
ejercicio 4.
a, Sistema que permita llevar un orden en las impresiones en una oficina
b. Mostrar lo que imprime
c. Mostrar lo que falta por imprimir
*/

// Definición del struct para representar un documento a imprimir
struct Documento {
    string nombre;
    int numPaginas;
};

int main() {
    stack<Documento> pilaImpresion;

    int op;
    cout << "Bienvenido al sistema de gestión de impresiones en la oficina." << endl;

    do {
        //Menu principal
        cout << "\n¿Qué acción deseas realizar?\n";
        cout << "1) Agregar documento para imprimir\n";
        cout << "2) Mostrar lo que se está imprimiendo\n";
        cout << "3) Mostrar lo que falta por imprimir\n";
        cout << "4) Salir\n";
        cin >> op;

        switch (op) {
            case 1: {
                // Agregar documento para imprimir
                Documento nuevoDocumento;
                cout << "Ingrese el nombre del documento: ";
                cin >> nuevoDocumento.nombre;
                cout << "Ingrese el número de páginas del documento: ";
                cin >> nuevoDocumento.numPaginas;
                pilaImpresion.push(nuevoDocumento);
                cout << "Documento agregado a la cola de impresión.\n";
                break;
            }
            case 2: {
                // Mostrar lo que se está imprimiendo
                if (!pilaImpresion.empty()) {
                    cout << "Imprimiendo el siguiente documento:\n";
                    Documento documentoActual = pilaImpresion.top();
                    cout << "Nombre: " << documentoActual.nombre << "\n";
                    cout << "Número de páginas: " << documentoActual.numPaginas << "\n";
                    pilaImpresion.pop();
                } else {
                    cout << "No hay documentos en la cola de impresión.\n";
                }
                break;
            }
            case 3: {
                // Mostrar lo que falta por imprimir
                if (!pilaImpresion.empty()) {
                    cout << "Documentos que faltan por imprimir:\n";
                    stack<Documento> pilaAux = pilaImpresion; // Hacer copia de la pila para no alterar la original
                    while (!pilaAux.empty()) {
                        Documento documento = pilaAux.top();
                        cout << "Nombre: " << documento.nombre << ", ";
                        cout << "Número de páginas: " << documento.numPaginas << "\n";
                        pilaAux.pop();
                    }
                } else {
                    cout << "No hay documentos en la cola de impresión.\n";
                }
                break;
            }
            case 4: {
                cout << "Saliendo del sistema de gestión de impresiones...\n";
                break;
            }
            default:
                cout << "Opción no válida. Por favor, selecciona una opción válida.\n";
        }

    } while (op != 4);

    return 0;
}
