#include <iostream>
#include <fstream>
using namespace std;
//se define el struct marca 
struct Marca
{
    char codigo[10];
    char descripcion[20];
};

int main()
{

    struct Marca marcas; //variable para almacenar tipo struct marca
// se piden los datos
    cout <<endl << "ingreso rubro:" ;
    cin >> marcas.codigo;
    cout <<endl << "ingreso descripcion:" ;
    cin >> marcas.descripcion;
//abro archivo para escritura y agregado
    ofstream archivo;
    archivo.open("Marcas.dat", ios::app | ios::ate | ios::binary);

    archivo.write((char*) &marcas, sizeof(marcas));//escribo la struct en el archivo
    archivo.close();//se cierra archivo

}

