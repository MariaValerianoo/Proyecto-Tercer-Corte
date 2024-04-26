#include <iostream>
#include <map>
#include <string>

using namespace std;

// Definición del tipo para representar las notas de cada asignatura
typedef map<string, double> NotasAsignaturas;

// Definición del tipo para representar el registro de notas de cada estudiante
typedef map<string, NotasAsignaturas> RegistroNotas;

// Función para registrar una nota
void registrarNota(RegistroNotas& registro, const string& estudiante, const string& asignatura, double nota) {
    registro[estudiante][asignatura] = nota;
}

// Función para mostrar la nota de un estudiante en una asignatura específica
void mostrarNota(const RegistroNotas& registro, const string& estudiante, const string& asignatura) {
    if (registro.count(estudiante) && registro.at(estudiante).count(asignatura)) {
        cout << "Nota de " << estudiante << " en " << asignatura << ": " << registro.at(estudiante).at(asignatura) << endl;
    } else {
        cout << "No se encontró la nota para el estudiante " << estudiante << " en la asignatura " << asignatura << endl;
    }
}

// Función para calcular el promedio de notas de un estudiante en todas las asignaturas
double promedioEstudiante(const RegistroNotas& registro, const string& estudiante) {
    double sumaNotas = 0.0;
    int numAsignaturas = 0;

    if (registro.count(estudiante)) {
        for (const auto& par : registro.at(estudiante)) {
            sumaNotas += par.second;
            numAsignaturas++;
        }
        return sumaNotas / numAsignaturas;
    } else {
        cout << "No se encontraron notas para el estudiante " << estudiante << endl;
        return 0.0;
    }
}

// Función para calcular el promedio de notas de una asignatura para todos los estudiantes
double promedioAsignatura(const RegistroNotas& registro, const string& asignatura) {
    double sumaNotas = 0.0;
    int numEstudiantes = 0;

    for (const auto& parEstudiante : registro) {
        if (parEstudiante.second.count(asignatura)) {
            sumaNotas += parEstudiante.second.at(asignatura);
            numEstudiantes++;
        }
    }

    if (numEstudiantes > 0) {
        return sumaNotas / numEstudiantes;
    } else {
        cout << "No se encontraron notas para la asignatura " << asignatura << endl;
        return 0.0;
    }
}

int main() {
    RegistroNotas registro;
    double nota;
    string materia, nom;
    
    do{
        cout<<"Bienvenido al sistema de notas Universidad del Rosario"<<endl;
        cout<<"Este es el menu de opciones que tenemos para ti: "<<endl;
        cout<<"1)Registro datos estudiante "<<endl;
        cout<<"2) "<<endl;
        cout<<"3)Registro datos estudiante "<<endl;
        cout<<"4)Salir "<<endl;


    }while(!=4)

    // Registrar algunas notas
    registrarNota(registro, "Juan", "Matemáticas", 4.5);
    registrarNota(registro, "Juan", "Física", 3.8);
    registrarNota(registro, "María", "Matemáticas", 4.0);
    registrarNota(registro, "María", "Física", 4.2);
    registrarNota(registro, "Pedro", "Matemáticas", 3.9);
    registrarNota(registro, "Pedro", "Química", 4.1);

    // Mostrar la nota de un estudiante en una asignatura específica
    mostrarNota(registro, "Juan", "Matemáticas");

    // Calcular el promedio de notas de un estudiante en todas las asignaturas
    cout << "Promedio de notas de Juan: " << promedioEstudiante(registro, "Juan") << endl;

    // Calcular el promedio de notas de una asignatura para todos los estudiantes
    cout << "Promedio de notas de Matemáticas: " << promedioAsignatura(registro, "Matemáticas") << endl;

    return 0;
}
