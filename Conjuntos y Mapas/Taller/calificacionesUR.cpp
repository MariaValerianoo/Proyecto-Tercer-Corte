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
    int op;
    
    do{
        cout<<"Bienvenido al sistema de notas Universidad del Rosario"<<endl;
        cout<<"Este es el menu de opciones que tenemos para ti: "<<endl;
        cout<<"1)Registro datos estudiante "<<endl;
        cout<<"2)Mostrar nota de un estudiante en asignatura especifica "<<endl;
        cout<<"3)Mostrar promedio general de un estudiante "<<endl;
        cout<<"4)Mostrar promedio en una materia de todos los estudiantes "<<endl;
        cout<<"5)Salir "<<endl;
        cin>>op;

        switch (op)
        {
        case 1:
        //Registrar estudiantes
        do
        {
            cout<<"Bienvenido "<<endl;
            cout<<"Ingresa tu nombre, sin espacios: "<<endl;
            cin>>nom;
            cout<<"Ingresa la materia: "<<endl;
            cin>>materia;
            cout<<"Ingresa la nota: "<<endl;
            cin>>nota;
            registrarNota(registro, nom, materia,nota);
            cout<<"Desea registrar otro usuario? \n 1)Si \n 2)No \n";
            cin>>op;
        } while (op!=2);
        break;
        case 2:
            // Mostrar la nota de un estudiante en una asignatura específica
            cout<<"Si deseas ver la nota de un estudiante"<<endl;
            cout<<"Ingresa el nombre: "<<endl;
            cin>>nom;
            cout<<"Ingresa la materia: "<<endl;
            cin>>materia;
            mostrarNota(registro, nom,materia);
            break;
        case 3:
            // Calcular el promedio de notas de un estudiante en todas las asignaturas
            cout<<"Para ver el promedio, dime el nombre del estudiante: "<<endl;
            cin>>nom;
            cout << "Promedio de notas de "<<nom <<" : " << promedioEstudiante(registro, nom) << endl;
            break;
        case 4:
        // Calcular el promedio de notas de una asignatura para todos los estudiantes
            cout<<"Dime la materia de la cual quieres ver el promedio: "<<endl;
            cin>>materia;
            cout << "Promedio de notas de "<<materia <<" : " << promedioAsignatura(registro, materia) << endl;


            break;
        default:
        cout<<"Opcion invalida vuelvelo a intentar:("<<endl;
        break;
        }

    }while(op!=5);


    return 0;
}
