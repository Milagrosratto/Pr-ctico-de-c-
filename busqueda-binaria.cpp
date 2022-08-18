#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;
struct repuesto
{
    char codigo[10];
    char descrip[50];
    char marca[10];
};

struct indice{
	char clave[10];
	int posicion;
};
void busqueda();

int main(){
	
	 busqueda();
}

void busqueda() 

{
    indice ind;
    indice aux;
    char codigobusqueda[10];
    fstream arch;

    arch.open("repuestosindicecompleto.inx", ios::in | ios::out | ios::binary);


   cout<<"Ingrese codigo para buscar"<<endl;
   cin>>codigobusqueda;


       
        int n;
        int medio;
        int inicio = 0;
        int fin = arch.tellg()/sizeof(ind);        
        int encontrado = 0;
        while (inicio <= fin)
        {
            
            medio = (fin + inicio) / 2;
            

             arch.seekg(medio*sizeof(ind));           
             arch.read((char*) &ind, sizeof(ind));

            
            if (strcmp(ind.clave,codigobusqueda) ==0)
            {
                cout<<"Codigo del producto:"<<ind.clave<<endl;
                cout<<"Posicion:"<<ind.posicion<<endl;
                encontrado = 1;
                fin = -1;
            }
            
            else
            {
                if ( strcmp(codigobusqueda,ind.clave)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        
        if (encontrado!= 1){
          cout<<"no se encontro el codigo buscado"<<endl;	
          
        }
   

}
    
