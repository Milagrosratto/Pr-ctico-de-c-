#include <iostream>
#include <fstream>
#include <string.h>
void ordenamiento();

using namespace std;

struct indice{
	char clave[10];
	int posicion;
};


int main(){
	
	ordenamiento();
}

void ordenamiento() 

{
    indice ind;
    indice aux;
    fstream arch;

    arch.open("repuestosindicecompleto.inx", ios::in | ios::out | ios::binary);

    // Ordenamiento piedra
    int i, j;
    arch.seekg(0, ios::end);                        // me posiciono en el final del archivo
    int ielementos = arch.tellg() / sizeof(ind); // ielementos contiene la cantidad de elementos del indice
    for (i = 1; i < ielementos; i++)               // primer bucle piedra
    {
        for (j = 0; j < ielementos - i; j++) // segundo bucle piedra
        {
            arch.seekg(j * sizeof(ind));                 // se posiciona el elemento nro j
            arch.read((char *)&aux, sizeof(ind)); // guarda el elemento nro j en struct auxiliar
            arch.read((char *)&ind, sizeof(ind));     // lee el elemento nro j+1 y guarda en struct indice

            if (aux.clave < ind.clave) // Compara claves, si el segundo elemento es mayor, invierte posiciones
            {
                arch.seekp(j * sizeof(ind)); // se posiciona el elemento nro j

                arch.write((char *)&ind, sizeof(ind));
                arch.write((char *)&aux, sizeof(ind));
            }
        }
    }
    arch.close();
}

