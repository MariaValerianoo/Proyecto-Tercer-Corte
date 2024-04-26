#include <iostream>
#include <stack>
#include <string>
#include <limits> 
using namespace std;
// Definición del struct para representar una película
struct Pelicula {
    string nombre;
    int numEstrellas;
};
// g++ pila.cpp -o pila
int main() {
    stack<Pelicula> pilaPeliculas;

    for (int i = 0; i < 3; i++) {
        Pelicula nuevaPelicula;
        cout << "Ingresa el nombre de la película " << (i + 1) << ": ";
        getline(cin, nuevaPelicula.nombre);
        cout << "Ingresa el número de estrellas para la película " << (i + 1) << ": ";
        cin >> nuevaPelicula.numEstrellas;

        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        // Agregar la película a la pila
        pilaPeliculas.push(nuevaPelicula);
    }

    // Mostrar las películas en la pila
    cout << "\nPelículas en la pila:\n";
    while (!pilaPeliculas.empty()) {
        Pelicula peliculaCima = pilaPeliculas.top();
        cout << "Nombre: " << peliculaCima.nombre << "\n";
        cout << "Número de estrellas: " << peliculaCima.numEstrellas << "\n\n";
        pilaPeliculas.pop();
    }

    return 0;
}
