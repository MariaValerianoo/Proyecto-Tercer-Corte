#include<iostream>>
using namespace std;
#include<map>
#include<set>

//Utilizamos la clase map
//Clave:Valor
int main(){
    map<int, string> frutas;
    frutas[1]="arandanos";
    frutas[2]="uvas";
    frutas[3]="cerezas";
    frutas[4]="sandia";

    for (const auto& par:frutas)
    {
        int clave = par.first();
        string valor = par.second();
        cout<<"Clave: "<<clave<<"Valor: "<<valor<<endl;

    }
     /*
    Operaciones comunes
    insert(): Agregar elemento al mapa.
    erase(): Eliminar un elemnto del mapa.
    find(): Buscar un elemento en el mapa.
    add():
    */

    string nombre="cerezas";
    auto it =frutas.find(nombre);
    if (it!=frutas.end())
     {
        cout<<"Se encontró el elemento "<<nombre<<" en el conjunto de frutas";
     }else{
        cout<<"No se encontró el elemento "<<nombre<<" en el conjunto de frutas";
     }
     

    
    return 0;
}
