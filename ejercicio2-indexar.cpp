#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//un struct para marca(datos)
struct Marca
{
    char codigo[10];            // lo voy a usar de clave 
    char descripcion[20];
};
//un struct para el indice 
struct Indice
{
    char clave[10];//codigo 
    int posicion;
};

int main()
{

    

    struct Marca marcas;//defino una variable  struct marca(datos) para ir leyendo
    
    
//ABRo archivo para lectura 
    ifstream arch;
    arch.open("Marcas.dat", ios::binary);

    struct Indice indices;//defino  una variable  struct indice para escribir en archivo indice
//abro archivo indice para escritura
    ofstream archivoI;
    archivoI.open("Marcas.inx", ios::binary);

    while (!arch.read((char*)  &marcas,sizeof(marcas)).eof())//leo el archivo de datos 
    {

        indices.posicion = arch.tellg() ;
      
        indices.posicion -=  sizeof(marcas);
      
        strcpy(indices.clave  ,  marcas.codigo);//copio el codigo para usarlo como clave
    
        archivoI.write((char*) &indices, sizeof(Indice)  );//escribo en archivo indice 

    }
//cierro los dos archivos 
    archivoI.close();
    arch.close();
}
