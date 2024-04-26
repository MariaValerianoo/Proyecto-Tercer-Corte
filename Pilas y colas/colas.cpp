#include <iostream>
#include <queue>
#include <string>
#include <limits> 
using namespace std;
// Definición del struct para representar una película
struct Pelicula {
    string nombre;
    int numEstrellas;
};

int main() {
    queue<Pelicula> colaPeliculas;

    for (int i = 0; i < 3; i++) {
        Pelicula nuevaPelicula;
        cout << "Ingresa el nombre de la película " << (i + 1) << ": ";
        getline(cin, nuevaPelicula.nombre);
        cout << "Ingresa el número de estrellas para la película " << (i + 1) << ": ";
        cin >> nuevaPelicula.numEstrellas;

        // Limpieza de Buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // Agregar la película a la cola
        colaPeliculas.push(nuevaPelicula);
    }

    // Mostrar las películas en la cola en el orden en que se ingresaron
    cout << "\nPelículas en la cola (orden de entrada):\n";
    while (!colaPeliculas.empty()) {
        Pelicula peliculaFrente = colaPeliculas.front();
        cout << "Nombre: " << peliculaFrente.nombre << "\n";
        cout << "Número de estrellas: " << peliculaFrente.numEstrellas << "\n\n";
        colaPeliculas.pop();
    }

    return 0;
}