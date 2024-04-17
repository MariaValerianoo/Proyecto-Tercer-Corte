#include <iostream>
#include<set>
using namespace std;

/*Estructuras de datos fundamentales en programacion.
Permiten almacenar y organizar datos de manera eficiente.
Conjuntos: Coleccione de elementos únicos sun un orden definido.
Mapas: Asocian claves únicas con valores.

Utilizamos la clase set
*/
int main(){
    //Declaramos el conjunto
    set<string> frutas;
    /* Operaciones comunes
    insert(): Agregar elemento al conjunto.
    erase(): Eliminar un elemnto del conjunto.
    find(): Buscar un elemento en el conjunto.
    add():
    */
    frutas.insert("arandanos");
    frutas.insert("Uvas");
    frutas.insert("cerezas");
    frutas.insert("sandia");
    //Impresion del conjunto
    cout<<"Conjunto de frutas: "<<endl;
    for (const string& fruta: frutas)
    {
        cout<<fruta<<endl;
    }
    frutas.insert("mango");
    //Impresion del conjunto
    cout<<"Conjunto de frutas: "<<endl;
    for (const string& fruta: frutas)
    {
        cout<<fruta<<endl;
    }
    frutas.erase("cerezas");
    //Impresion del conjunto
    cout<<"Conjunto de frutas: "<<endl;
    for (const string& fruta: frutas)
    {
        cout<<fruta<<endl;
    }
     string buscar="arandanos";
     string buscar2="cerezas";
     //Buscar elemento
     auto iterador=frutas.find(buscar);
     auto iterador2=frutas.find(buscar2);
     //Verificar si existe el elemento
     if (iterador!=frutas.end())
     {
        cout<<"Se encontró el elemento "<<buscar<<" en el conjunto de frutas";
     }else{
        cout<<"No se encontró el elemento "<<buscar<<" en el conjunto de frutas";
     }
     
     if (iterador2!=frutas.end())
     {
        cout<<"Se encontró el elemento "<<buscar2<<" en el conjunto de frutas";
     }else{
        cout<<"No se encontró el elemento "<<buscar2<<" en el conjunto de frutas";
     }
     //Tamaño del conjunto
     frutas.size();
     //Limpiar el conjunto
     frutas.clear();
     //Vaciar el conjunto
     frutas.empty();
     //Conjunto de canciones de reproduccion van a tener 3 canciones y luego agregar una mas, eliminan dos y buscan una.
     set<string> canciones;

    canciones.insert("hola");

    canciones.insert("luna");

    canciones.insert("perro");
    //Impresion del conjunto
    cout<<"Conjunto de canciones: "<<endl;
    for (const string& cancion: canciones)
    {
        cout<<cancion<<endl;
    }

    string cancion;

    cout<<"Ingrese una cancion para agregar al conjunto: ";

        cin>>cancion;

    canciones.insert(cancion);

    cout<<"Ingrese una cancion para buscar del conjunto: ";

        cin>>cancion;

    

    if (canciones.find(cancion) != canciones.end()) {

        cout<<"La cancion "<<cancion<<" se encuentra en el conjunto."<<endl;

    } else {

        cout<<"La cancion "<<cancion<<" no se encuentra en el conjunto."<<endl;

    }
    canciones.erase("luna");
    //Impresion del conjunto
    cout<<"Conjunto de canciones: "<<endl;
    for (const string& cancion: canciones)
    {
        cout<<cancion<<endl;
    }
    //Operaciones de interseccion, union y diferencia
    set<int> conjuntoA = {1,2,3,4,5};
    set<int> conjuntoB= {3,4,5,6,7};
    //INTERSECCION
    set<int> interseccion;
    for(int elemento: conjuntoA){
        if(conjuntoB.count(elemento)){
            interseccion.insert(elemento);
        }
        cout<<elemento<< " ";
    }
    for(int elemento: interseccion){
        cout<<elemento<< " ";
    }
    //UNION
    set<int> union= conjuntoA;
    union.insert(conjuntoB.begin(),conjuntoB.end());
    cout<<"Union: ";
    for(int elemento: union){
        cout<<elemento<< " ";
    }
    //Diferencia conjunto A-conjunto B
    set <int> diferencia;
    set_difference(conjuntoA.begin(),conjuntoA.end(),conjuntoB.begin(),conjuntoB.end(),inserter(diferencia,diferencia.begin()));
    //Imprimir conjunto de la diferencia
    for(auto it = diferencia.begin(); it !=diferencia.end(); ++it){
        cout<<*it<< " ";
    }


    return 0; 
    


}



//miembro de la familia, la fecha el destino y las actividades que voy a hacer