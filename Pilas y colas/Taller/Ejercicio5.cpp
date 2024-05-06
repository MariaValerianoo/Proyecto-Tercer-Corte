
#include <iostream>
#include <queue>
#include <string>
using namespace std;
/*
Ejercicio 5:
a.Ingresa al sistema y lo pone en fila
b. mostrar en que posicion esta y cuanto se demora
c. mostrar cuando llegue para comprar boleta
*/
// Definición del struct para representar un usuario
struct Usuario {
    string nombre;
};

int main() {
    queue<Usuario> filaUsuarios;

    int op;
    cout << "Bienvenido al sistema de gestión de usuarios.\n";

    do {
        cout << "\n¿Qué acción deseas realizar?\n";
        cout << "1) Ingresar un nuevo usuario al sistema\n";
        cout << "2) Mostrar la fila de usuarios\n";
        cout << "3) Llegar para comprar una boleta\n";
        cout << "4) Salir\n";
        cin >> op;

        switch (op) {
            case 1: {
                // Ingresar un nuevo usuario al sistema
                Usuario nuevoUsuario;
                cout << "Ingrese el nombre del usuario: ";
                cin >> nuevoUsuario.nombre;
                filaUsuarios.push(nuevoUsuario);
                cout << "Usuario ingresado a la fila.\n";
                break;
            }
            case 2: {
                // Mostrar la fila de usuarios
                if (!filaUsuarios.empty()) {
                    cout << "Fila de usuarios:\n";
                    queue<Usuario> filaAux = filaUsuarios; // Hacer una copia de la cola para no alterar la original
                    int posicion = 1;
                    while (!filaAux.empty()) {
                        cout << posicion << ". " << filaAux.front().nombre << "\n";
                        filaAux.pop();
                        posicion++;
                    }
                } else {
                    cout << "La fila de usuarios está vacía.\n";
                }
                break;
            }
            case 3: {
                // Llegar para comprar una boleta
                if (!filaUsuarios.empty()) {
                    Usuario usuarioActual = filaUsuarios.front();
                    double tiempoEspera = 0.0;
                    queue<Usuario> filaAux = filaUsuarios; // Hacer una copia de la cola para no alterar la original
                    while (!filaAux.empty() && filaAux.front().nombre != usuarioActual.nombre) {
                        tiempoEspera += 2.0; // Se asume 2 minutos de espera por usuario
                        filaAux.pop();
                    }
                    cout << "El usuario " << usuarioActual.nombre << " está siendo atendido.\n";
                    cout << "Se demorará " << tiempoEspera << " minutos en ser atendido.\n";
                    filaUsuarios.pop(); // El usuario es atendido y se retira de la fila
                } else {
                    cout << "No hay usuarios en la fila.\n";
                }
                break;
            }
            case 4: {
                cout << "Saliendo del sistema de gestión de usuarios...\n";
                break;
            }
            default:
                cout << "Opción no válida. Por favor, selecciona una opción válida.\n";
        }

    } while (op != 4);

    return 0;
}
