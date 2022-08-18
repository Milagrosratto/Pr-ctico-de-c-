#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
int mian(){
	struct datos{
		double doc;
		char apellido[30];
		char nombre[30];
	};
	int posicion;
	int registro;
	struct datos persona;
	ifstream fichero;
	fichero.open("Personas.dat",ios::in);
	if(fichero.fail()){
	cout<<"El archivo no se abrio correctamente"<<endl;
	
	}
	else{
		while(!fichero.eof()){
			
			posicion=fichero.tellg();
		cout<<"Posicion:"<<posicion<<endl;
		fichero>>persona.nombre;
		cout<<"Nombre:"<<persona.nombre<<endl;
		fichero>>persona.apellido;
		cout<<"Apellido:"<<persona.apellido<<endl;
	
		fichero>>persona.doc;
		cout<<"Documento:"<<persona.doc;
		registro=fichero.tellg()/sizeof(persona);
		cout<<"Registro:"<<registro<<endl;
		}
		
	 
	}
	
	return 0;
	
}
