#include<iostream>
#include<fstream>
#include<string.h>
/*Se desea desarrollar un programa para resguardar datos utilizando una estructura de
Persona. Entre los datos solicitados están: apellido[20], nombre[20], int edad, char sexo.
El sistema deberá consultar al usuario si desea Cargar un Persona o Finalizar.
Los datos ingresados en la carga deberán ser resguardados en el archivo.
Condiciones:

? Archivo tipo binario, nombre: personas.bin
? Grabar archivo por Write()
? Si contiene información previa, la misma deberá conservarse.
? La edad deberá estar comprendida entre 1 y 100 años
? El sexo podrá ser: F, M, O */
struct dato{
    char nombre[20];
	char apellido[20];
	int edad;
	char sexo;
}dato;
using namespace std;
int main(){
	struct dato persona;
	int num;
	
	//declaro archivo
	ofstream arch;
	//abro archivo
	arch.open("Personas.bin", ios::out|ios::app|ios::binary);
	//compruebo si abrió correctamente 
	if(arch.fail()){
		cout<<"No se pudo crear el archivo";
	//	exit(1);
	}
	//pido opcion al usuario 
	cout<<"Elija una opcion:"<<endl;
	cout<<"1_Cargar persona"<<endl;
	cout<<"2_Finalizar"<<endl;
	cin>>num;
	//""menu
	switch(num){
		case 1: 
		//pido datos
	    cout<<"Ingrese apellido:"<<endl;
	    cin>>persona.apellido;
		//cin.getline(persona.apellido,20 );
		
		
		cout<<"Ingrese nombre:"<<endl;
	    cin>>persona.nombre;
	     
		cout<<"Ingrese edad:"<<endl;
		cin>>persona.edad;
		if(persona.edad<1||persona.edad>100){
			cout<<"La edad ingresada no es correcta\nVuelva a ingresar su edad:"<<endl;
			cin>>persona.edad;
			
		}
		
		cout<<"Ingrese sexo: F, M, O"<<endl;
		cin>>persona.sexo;
		if(!(persona.sexo=='M'||persona.sexo=='F'||persona.sexo=='O')){
			cout<<"El sexo ingresado no es correcto\nVuelva a ingresar su sexo:"<<endl;
			cin>>persona.sexo;
			
		}
		
		
		//escribiendo en archivo
		arch.write((char*)&persona,sizeof(dato));
		arch.close();
		
		//VOLVER A COPIAR MENU
		//---------------------------------
		cout<<"Desea realizar otra operacion?"<<endl;
		              	cout<<"1_Cargar persona"<<endl;
	                     cout<<"2_Finalizar"<<endl;
	                     cin>>num;
		switch(num){
		case 1: 
		//pido datos
	    cout<<"Ingrese apellido:"<<endl;
	    cin>>persona.apellido;
		//cin.getline(persona.apellido,20 );
		
		
		cout<<"Ingrese nombre:"<<endl;
	    cin>>persona.nombre;
	     
		cout<<"Ingrese edad:"<<endl;
		cin>>persona.edad;
		if(persona.edad<1||persona.edad>100){
			cout<<"La edad ingresada no es correcta\nVuelva a ingresar su edad:"<<endl;
			cin>>persona.edad;
			
		}
		
		cout<<"Ingrese sexo: F, M, O"<<endl;
		cin>>persona.sexo;
		if(!(persona.sexo=='M'||persona.sexo=='F'||persona.sexo=='O')){
			cout<<"El sexo ingresado no es correcto\nVuelva a ingresar su sexo:"<<endl;
			cin>>persona.sexo;
			
		}
		
		
		//escribiendo en archivo
		arch.write((char*)&persona,sizeof(dato));
		arch.close();
		
		//VOLVER A COPIAR MENU
		
		break;
		case 2:
		//	exit(1);
		
		
		
			break;
	}
		
		
		break;
		case 2:
		//	exit(1);
		
		
		
			break;
	}
	
	
	return 0;
	
}
