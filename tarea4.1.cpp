#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
/*almacenados en una estructura de Personas. Entre los datos est�n: Documento, apellido
y nombre.
Desarrollar un men� que permita: Cargar, Listar, Mostrar, Buscar y Salir del programa
seg�n el usuario lo desee.
Opci�n Cargar: una vez registrados los datos en el archivo deber� indicarse la posici�n
del registro. Ej: registro guardado en posici�n: 3
Opci�n Listar: deber�n mostrarse todos los datos de las personas almacenadas en el
archivo adem�s de la posici�n del registro dentro del archivo.
Opci�n Mostrar: solicitar al usuario el registro (posici�n) de la persona que desea
mostrar por pantalla. De no encontrarse indicar que el registro no existe.
Opci�n Buscar: solicitar al usuario el Documento de la persona, buscarlo en el archivo y
mostrar su posici�n. De no encontrarse indicar que el documento no existe.
Opci�n Salir: consultar al usuario si est� seguro de querer finalizar el programa.*/
struct datos{
	double doc;
	char apellido[30];
	char nombre[30];
}datos;//struct datos

int main(){
	int num=0, num2=0;
	int ibandera=0;
	int busqueda;
	double doc;
 struct datos persona;
 struct datos personaL;
struct datos p;
	do{
	cout<<"Ingrese una opcion\n1_Cargar.\n2_Listar.\n3_Mostrar.\n4_Buscar.\n5_Finalizar."<<endl;
	cin>>num;
	 switch(num){
	 	
	 	case 1://cargar
	 	//creo archivo modo escritura
	 	ofstream archivo;
	 	archivo.open("Personas.dat",ios::binary|ios::app);
	 	if(archivo.fail()){
	 		cout<<"No se abrio el archivo correctamente"<<endl;
	 		
	 	}
	 	else{
	 	cout<<"posicion actual:"<<archivo.tellp()<<endl;
	 	cout<<"Ingrese datos:"<<endl<<"Nombre:"<<endl;
	 	cin>>persona.nombre;
	 	cout<<"Apellido:"<<endl;
	 	cin>>persona.apellido;
	 	cout<<"Documento:"<<endl;
	 	cin>>persona.doc;   
	 	//volcando en archivo binario
	 	archivo.write((char*)&persona,sizeof(datos));
	 	cout<< "Posicion:"<<archivo.tellp();
		 cout<<" en registro"<<archivo.tellp()/sizeof(persona);	
		 
	 	archivo.close();
	 	}
	 	
	 	break;
	 		
	   case 2: //Listar
	   ifstream archivo2;
	   archivo2.open("Personas.dat",ios::in|ios::binary);
	   while(!(archivo2.eof())){
	   	archivo2.read((char *)&personaL, sizeof(datos));
	   	cout<<"Nombre:"<< personaL.nombre<<endl;
	   	cout<<"Apellido:"<< personaL.apellido<<endl;
	   	cout<<"Documento:"<< personaL.doc<<endl;
	   	cout<<"Posicion:"<<archivo2.tellg()<<endl;
	   	cout<<"Registro:"<<archivo2.tellg()/sizeof(personaL);
	   
	   }
	   
	 	archivo2.close();
	 		break;
	   case 3://Opci�n Mostrar: solicitar al usuario el registro (posici�n) de la persona que desea
               //mostrar por pantalla. De no encontrarse indicar que el registro no existe.
               cout<<"Ingrese registro(posicion) a buscar"<<endl;
               cin>>busqueda;
               ifstream archivo2;
	   archivo2.open("Personas.dat",ios::in|ios::binary);
	   while(!(archivo2.eof)){
	   	archivo2.read((char *)&personaL, sizeof(datos));
	   	if(archivo2.tellg()==busqueda){//si posicion actual es igual a busqueda, es la persona
	   	cout<<"Nombre:"<< personaL.nombre<<endl;
	   	cout<<"Apellido:"<< personaL.apellido<<endl;
	   	cout<<"Documento:"<< personaL.doc<<endl;
	   
	   	}
	   	archivo2.close;
           }
	 		break; 
	 		case 4://buscar 
	 		ifstream fich;
	 		fich.open("Personas.dat", ios::in|ios::binary);
	 		cout<<"Ingrese documento a buscar:"<<endl;
	 		cin>>doc;
	 		while(!(fich.eof)){
	 			fich.read((char*)&p,sizeof(datos));
	 			if(p.doc==doc){
	 				cout<<"Documento:"<<p.doc;
	 				cout<<"Posicion:"<<fich.tellg()<<endl;
	 				cout<<"Registro"<<fich.tellg()/sizeof(p)<<endl;
	 				
	 			}
	 		}
	 		fich.close();
	 			break;
	    
    	default:
	   	cout<<"Esta seguro que desea finalizar?"<<endl<<"1_Si\n2_No"<<endl;
	   	cin>>num2;
	   	if(num2==1){
	   		cout<<"Finalizando"<<endl;
	   		ibandera=1;
	   	//	exit(0);
	   	}
	 		break;
			 	
	 }
	
	
	}while(ibandera==0);
	
	

	
}
