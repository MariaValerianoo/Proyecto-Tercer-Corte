#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

// Definición de un estructura para representar el clima de una ciudad
struct Clima {
    string ciudad;
    string clima;
    // Sobrecarga del operador < para comparar objetos Clima
    bool operator<(const Clima& otro) const {
        return ciudad < otro.ciudad;
    }
};

// Conjunto global para almacenar el clima de las capitales
set<Clima> climasCapitales;

// Función para inicializar los mapas y conjuntos con la información de los departamentos y capitales
void inicializarMapas(map<string, pair<string, string>>& mapaColombia) {
 // Agregar información de algunos departamentos y sus capitales con el clima
    mapaColombia["Amazonas"] = make_pair("Leticia", "Tropical");
    climasCapitales.insert({"Leticia", "Tropical"});    

    mapaColombia["Antioquia"] = make_pair("Medellin", "Templado");
    climasCapitales.insert({"Medellin", "Templado"});

    mapaColombia["Arauca"] = make_pair("Arauca", "Calido");
    climasCapitales.insert({"Arauca", "Calido"});

    mapaColombia["Atlantico"] = make_pair("Barranquilla", "Tropical");
    climasCapitales.insert({"Barranquilla", "Tropical"});
    
    mapaColombia["Bolivar"] = make_pair("Cartagena", "Tropical");
    climasCapitales.insert({"Cartagena", "Tropical"});

    mapaColombia["Boyaca"] = make_pair("Tunja", "Templado");
    climasCapitales.insert({"Tunja", "Templado"});

    mapaColombia["Caldas"] = make_pair("Manizales", "Templado");
    climasCapitales.insert({"Manizales", "Templado"});

    mapaColombia["Caqueta"] = make_pair("Florencia", "Calido");
    climasCapitales.insert({"Florencia", "Calido"});

    mapaColombia["Casanare"] = make_pair("Yopal", "Templado");
    climasCapitales.insert({"Yopal", "Templado"});

    mapaColombia["Cesar"] = make_pair("Valledupar", "Templado");
    climasCapitales.insert({"Valledupar", "Templado"});

    mapaColombia["Choco"] = make_pair("Quibdo", "Templado");
    climasCapitales.insert({"Quibdo", "Templado"});

    mapaColombia["Cordoba"] = make_pair("Monteria", "Templado");
    climasCapitales.insert({"Monteria", "Templado"});

    mapaColombia["Cundinamarca"] = make_pair("Bogotá", "Templado");
    climasCapitales.insert({"Bogotá", "Templado"});

    mapaColombia["Guainia"] = make_pair("Puerto Inirida", "Templado");
    climasCapitales.insert({"Puerto Inirida", "Templado"});

    mapaColombia["Guaviare"] = make_pair("San Jose del Guaviare", "Templado");
    climasCapitales.insert({"San José del Guaviare", "Templado"});

    mapaColombia["Huila"] = make_pair("Neiva", "Templado");
    climasCapitales.insert({"Neiva", "Templado"});

    mapaColombia["La guajira"] = make_pair("Riohacha", "Templado");
    climasCapitales.insert({"Riohacha", "Templado"});

    mapaColombia["Magdalena"] = make_pair("Santa Marta", "Templado");
    climasCapitales.insert({"Santa Marta", "Templado"});

    mapaColombia["Meta"] = make_pair("Villavicencio", "Templado");
    climasCapitales.insert({"Villavicencio", "Templado"});

    mapaColombia["Nariño"] = make_pair("Pasto", "Templado");
    climasCapitales.insert({"Pasto", "Templado"});

    mapaColombia["Norte de Santander"] = make_pair("Cucuta", "Templado");
    climasCapitales.insert({"Cucuta", "Templado"});

    mapaColombia["Valle del cauca"] = make_pair("Cali", "Templado");
    climasCapitales.insert({"Cali", "Templado"});
}

// Función para obtener ciudades que tienen un clima específico
void obtenerCiudadesPorClima(const string& clima) {
    cout << "Ciudades con clima " << clima << ":\n";
    for (const auto& ciudad : climasCapitales) {
        if (ciudad.clima == clima) {
            cout << "- " << ciudad.ciudad << "\n";
        }
    }
}

// Función para obtener la capital y el clima de un departamento dado
void obtenerInfoDepartamento(const map<string, pair<string, string>>& mapaColombia, const string& departamento) {
    if (mapaColombia.find(departamento) != mapaColombia.end()) {
        auto info = mapaColombia.at(departamento);
        cout << "La capital de " << departamento << " es " << info.first << " y tiene clima " << info.second << ".\n";
    } else {
        cout << "No se encontró información para el departamento de " << departamento << ".\n";
    }
}

int main() {
    // Mapa para asociar nombres de departamentos con sus capitales y el clima                                                                                                                                              
    map<string, pair<string, string>> mapaColombia;

    // Inicializar los mapas y conjuntos con la información de los departamentos y capitales
    inicializarMapas(mapaColombia);

    int op;
    string dep;
    string clim;
    do
    {
        cout<<"Bienvenido a esta app para conocer cosas de colombia"<<endl;
        cout<<"Que deseas hacer? \n";
        cout<<"1)Obtener informacion de un departamento(obtendras la capital y el clima de esta) \n";
        cout<<"2)Obtener las capitales con climas igual \n";
        cout<<"3)Salir \n";
        cin>>op;
        if (op==1)
        {
            cout<<"En esta opcion podras conocer la capital de un departamento y su clima \n";
            cout<<"De que departamento deseas tener informacion? (Por favor pon la primera letra en mayuscula) \n";
            cin>>dep;
            obtenerInfoDepartamento(mapaColombia, dep);
        }else if(op==2){
            cout<<"En esta opcion podras conocer las ciudades con clima igual \n";
            cout<<"De cual clima deseas obtener informacion? (Por favor pon la primera letra en mayuscula) \n";
            cout<<"Los climas son: Tropical, templado, frio, calido \n";
            cin>>clim;
            obtenerCiudadesPorClima(clim);
        }else if (op!=3){
            cout<<"Opcion invalida, vuelve a intentar \n";
        }
        

    } while (op!=3);
    cout<<"Saliendo del programa..."<<endl;
    return 0;
}
