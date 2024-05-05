#include <iostream>
#include <queue>
#include <string>
#include <limits> 
using namespace std;
/*
Ejercicio 2;
a. Crear una lista de mercado 
b. Permitir ver la lista e ir sacando los elementos del mercado desde el 1 hasta el ultimo
*/


// Definición del struct para representar un elemento del mercado
struct Mercado {
    string nombre;
    int numElement;
};

int main() {
    queue<Mercado> colaMercado;
    int op;
    cout<<"Bienvenido esta es tu APP para tener tu lista de mercado "<<endl;
    cout<<"Empecemos por qué quieres hacer? \n";
    cout<<"1)Hacer una lista de mercado \n";
    cout<<"2)Salir de la app \n";
    cin>>op;

    if (op == 1) {
        cout<<"Para crear tu lista de mercado primero dinos de cuántos elementos será: \n";
        int numElementos;
        cin >> numElementos;

        // Limpieza de Buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < numElementos; i++) {
            Mercado nuevoElemento;
            cout << "Ingresa el nombre del elemento que añadirás " << (i + 1) << ": ";
            getline(cin, nuevoElemento.nombre);
            cout << "Ingresa la cantidad que necesitas " << (i + 1) << ": ";
            cin >> nuevoElemento.numElement;

            // Limpieza de Buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Agregar el elemento a la cola
            colaMercado.push(nuevoElemento);
        }
        cout << "Lista creada con éxito. " << endl;

        do {
            cout << "Ahora, ¿qué quieres hacer? \n";
            cout << "1) Ver la lista \n";
            cout << "2) Borrar un elemento de la lista \n";
            cout << "3) Salir \n";
            cin >> op;

            // Limpieza de Buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (op) {
                case 1: {
                    // Mostrar la lista de mercado
                    if (!colaMercado.empty()) {
                        queue<Mercado> colaAux = colaMercado; // Hacemos una copia de la cola para no alterar la original y asi simplemente poder mostrarla
                        while (!colaAux.empty()) {
                            Mercado mercadoFrente = colaAux.front();
                            cout << "Nombre: " << mercadoFrente.nombre << "\n";
                            cout << "Cantidad que necesitas: " << mercadoFrente.numElement << "\n\n";
                            colaAux.pop();
                        }
                    } else {
                        cout << "La lista de mercado está vacía.\n";
                    }
                    break;
                }
                case 2: {
                    // Borrar un elemento de la lista
                    if (!colaMercado.empty()) {
                        cout << "Ingresa que numero de elemento que deseas borrar (empieza desde 1): ";
                        int indice;
                        cin >> indice;

                        if (indice >= 1 && indice <= colaMercado.size()) {
                            // Eliminar el elemento en el índice especificado
                            for (int i = 1; i < indice; ++i) {
                                colaMercado.push(colaMercado.front()); // Mover los elementos anteriores al frente
                                colaMercado.pop(); // Eliminar los elementos anteriores
                            }
                            colaMercado.pop(); // Eliminar el elemento en el índice especificado
                            cout << "Elemento eliminado exitosamente.\n";
                        } else {
                            cout << "Índice inválido. Por favor, ingresa un índice válido.\n";
                        }
                    } else {
                        cout << "La lista de mercado está vacía.\n";
                    }
                    break;
                }
                case 3: {
                    cout << "Saliendo de la app...\n";
                    break;
                }
                default:
                    cout << "Opción no válida, por favor selecciona una opción válida.\n";
            }
        } while (op != 3);
    }

    return 0;
}
