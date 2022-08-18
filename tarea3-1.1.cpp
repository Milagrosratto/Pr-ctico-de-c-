#include<iostream>
#include<fstream>
#include<string.h>

/*Ejercicio 1.1) Personas
Desarrollar en un nuevo programa la búsqueda de personas de tal manera que al
iniciarse el programa nos permite ingresar el apellido de la persona a buscar y nos liste
por pantalla todas las personas encontradas para dicho apellido.
Condiciones:

? Utilizar el Archivo binario: personas.bin
? Leer archivo por Read()*/
   
using namespace std;
struct dato{
    char nombre[20];
	char apellido[20];
	int edad;
	char sexo;
    }dato;
    
int main(){
	
	struct dato persona;//para usar con archivo
    struct dato aux;
  
	
	ifstream arch;
	arch.open("Personas.bin", ios::in|ios::binary);
		//compruebo si abrió correctamente 
	if(arch.fail()){
		cout<<"No se pudo crear el archivo";
	//	exit(1);
	}
	
	
	
	
	//recordar comparar las dos
	cout<<"Ingrese un apellido para buscar"<<endl;
	cin>>aux.apellido;
	//cout<<"apellido:"<<aux.apellido<<endl;
	while(!arch.eof()){
		
		arch.read((char*)&persona,sizeof(dato));
	//cout<<"Nombre:"<<persona.nombre<<"Apellido:"<<persona.apellido<<endl;
	if (strcmp ( persona.apellido, aux.apellido)==0)
                {
                    cout << "Apellido: " << persona.apellido <<endl;
                    cout << "Nombre: " << persona.nombre <<endl;
                    cout << "Sexo: " << persona.sexo <<endl;
                    cout << "Edad: " << persona.edad <<endl;
                }

   }
	arch.close();
	
	return 0;
	
}

