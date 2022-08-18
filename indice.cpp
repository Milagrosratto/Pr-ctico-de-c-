#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;
struct Alumno{
	float doc[8];
	char nombre[50];
	char ape[50];
};
struct materia{
	float doc[8];
	int codigo;
	char descrip[50];
};

struct ind{
  float clave[8];//documento
  int indice;
};
struct ind2{
  float clave[8];//documento
  int indice;
};
void listar();
void salir();
void cargar();
void cargar_materia();
void generar_indice();
void generar_indice2();
void buscar();
void buscar2(float documento_buscar[8]);
int main (){
	char op;
    
   do {
        //menu 
        
         cout<<endl;
         cout << "Ingrese una opcion " << endl;
         cout << "[A] Cargar Alumnos" << endl;
         cout << "[M] Cargar alumno-materia " << endl;
         cout << "[L] Listar " << endl;
        cout<<"[B] Buscar"<<endl;
         cout << "[S] salir" << endl;
		   cin >> op;
        //########################
        switch (toupper(op))
        {
        case 'A':
        	
        	cargar();
        
        	
        	
        	
            
            break;
        case 'M':
             cargar_materia();
            break;
        case 'L':
             listar();
            break;
        case 'B':
        	//BUSCAR
        	break;
        
        case 'S':
        
        	salir();
             
            break;
        default:
        	cout<<"OPCION NO VALIDA"<<endl;
           break;
        }
    }while(1<2); 
   
}
void salir(){
	char resp;
	
	cout<<"Esta seguro que desea finalizar? S/N"<<endl;
        	cin>>resp;
        	
        	if( toupper(resp)=='S'){
        		cout<<"  Finalizando.."<<endl;
            cout<<"#################"<<endl;
           exit(0);
	}
	
	
	

	
}

void cargar(){
	 struct Alumno alumno; 
	ofstream arch;
	arch.open("Alumno.dat",ios::ate|ios::app|ios::binary);
	cout<<"Ingrese datos del alumno"<<endl;
	
	cout<<"Documento:"<<endl;
   	cin>>alumno.doc;
    cout<<"Nombre:"<<endl;
    cin>>alumno.nombre;
   cout<<"Apellido:"<<endl;
   cin>>alumno.ape;
   
   
   arch.write((char*) &alumno, sizeof(alumno));//escribo la struct en el archivo
    arch.close();//se cierra archivo
      generar_indice();
   
}
void cargar_materia(){
 struct	materia mate; 
	ofstream arch1;
	arch1.open("Materias.dat",ios::ate|ios::app|ios::binary);
	cout<<"Ingrese datos del alumno"<<endl;
	
	cout<<"Documento:"<<endl;
	cin>>mate.doc;
    cout<<"Codigo:"<<endl;
    cin>>mate.codigo;
   cout<<"Descrpcion:"<<endl;
   cin>>mate.descrip;
   
   
   arch1.write((char*) &mate, sizeof(mate));//escribo la struct en el archivo
    arch1.close();//se cierra archivo
    generar_indice2;
  
   
}

void generar_indice(){
	
struct	ind indice;
struct	Alumno alumno;
	
	//abro archivo y leo 
	 ifstream fich;
	 fich.open("Alumnos.dat",ios::in|ios::binary);
	 //abro archivo indice para escritura
    ofstream fichI;
    fichI.open("Ind1.inx", ios::binary);
    
	 while (!fich.read((char*)  &alumno,sizeof(alumno)).eof())//leo el archivo de datos 
    {

        indice.posicion = fich.tellg() ;
      
        indice.posicion -=  sizeof(alumno);
      
        strcpy(indice.clave  ,  alumno.doc);
    
        fichI.write((char*) &indice, sizeof(indice)  );//escribo en archivo indice 

    }
//cierro los dos archivos 
    fichI.close();
    fich.close(); 
	  
}
void generar_indice2(){
	
struct	ind2 indice;
struct	materia mate;
	
	//abro archivo y leo 
	 ifstream fich;
	 fich.open("Materias.dat",ios::in|ios::binary);
	 //abro archivo indice para escritura
    ofstream fichI;
    fichI.open("Ind2.inx", ios::binary);
    
	 while (!fich.read((char*)  &mate,sizeof(mate)).eof())//leo el archivo de datos 
    {

        indice.posicion = fich.tellg() ;
      
        indice.posicion -=  sizeof(mate);
      
        strcpy(indice.clave  ,  mate.doc);
    
        fichI.write((char*) &indice, sizeof(indice)  );//escribo en archivo indice 

    }
//cierro los dos archivos 
    fichI.close();
    fich.close(); 
	  
}


void buscar() 

{
   struct ind indice;
   struct ind aux;
    float documento_buscar[8];
    fstream arch;

    arch.open("Ind1.inx", ios::in | ios::out | ios::binary);


   cout<<"Ingrese documento para buscar"<<endl;
   cin>>documento_buscar;


         
        int n;
        int medio;
        int inicio = 0;
        int fin = arch.tellg()/sizeof(indice);        
        int encontrado = 0;
        while (inicio <= fin)
        {
            //Medio será igual a la mitad de la dimensión delarreglo.
            medio = (fin + inicio) / 2;
            

            //POSICIONO EN EL MEDIO DEL ARCHIVO
             arch.seekg(medio*sizeof(indice));            //me posiciono en lamitad de los elementos
             arch.read((char*) &ind, sizeof(indice));

            //Si variable medio es similar a la clave de búsqueda despliega mensaje de encontrado.
            if (strcmp(indice.clave,documento_buscar) ==0)
            {
                cout<<"Documento:"<<indice.clave<<endl;
                cout<<"Posicion:"<<indice.posicion<<endl;
                encontrado = 1;
                fin = -1;
                buscar2(&documento_buscar);
            }
             
            else
            {
                if ( strcmp(documento_buscar,indice.clave)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        //Si no  encuentra la clave  mensaje de noencontrado. 
        if (encontrado!= 1){
          cout<<"no se encontro el documento buscado"<<endl;	
          
        }
      

}


void buscar2(float documento_buscar[8]) 

{
struct	materias mate;
  struct  ind indice;
  struct  ind aux;
    float documento_buscar[8];
    fstream arch;

    arch.open("Ind2.inx", ios::in | ios::out | ios::binary);


   strcpy(doc,documento_buscar):


         
        int n;
        int medio;
        int inicio = 0;
        int fin = arch.tellg()/sizeof(indice);        
        int encontrado = 0;
        while (inicio <= fin)
        {
            //Medio será igual a la mitad de la dimensión delarreglo.
            medio = (fin + inicio) / 2;
            

            //POSICIONO EN EL MEDIO DEL ARCHIVO
             arch.seekg(medio*sizeof(indice));            //me posiciono en lamitad de los elementos
             arch.read((char*) &ind, sizeof(indice));
             //################################33
             fstream f;
             
             f.open("Materias.dat",ios::binary);
             f.read((char*)&mate,sizeof(mate));
             cout<<"Codigo:"<<mate.codigo<<endl;
             cout<<"Descripcion::"<<mate.descrip<<endl;
             //########################
            //Si variable medio es similar a la clave de búsqueda despliega mensaje de encontrado.
            if (strcmp(indice.clave,doc) ==0)
            {
            	cout<<"INDICE MATERIAS:"<<endl;
               
                cout<<"Documento:"<<indice.clave<<endl;
                cout<<"Posicion:"<<indice.posicion<<endl;
                
                encontrado = 1;
                fin = -1;
              
            }
             -_
            else
            {
                if ( strcmp(doc,indice.clave)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        
        if (encontrado!= 1){
          cout<<"no tiene materias inscriptas"<<endl;	
          
        }
     
	  }


 f.close();
	arch.close();
	
}
void listar(){
	struct Alumno alum;
	float doc[8];
	fstream fich;
	fich.open("Alumnos.dat",ios::in|ios::binary);
	fstream fich;
system("cls");
	cout<<endl<<endl;
	 while (!fich.read((char*)  &alum,sizeof(alum)).eof())//leo el archivo de datos 
	 {
	 	cout<<"Documento:"<<alum.doc<<endl;;
	 	
        
        cout<<"NOMBRE:"<<alum.nombre<<endl;
        cout<<"Apellido:"<<alum.ape<<endl;
        strcpy(doc,alum.doc);
        buscar2(&doc);
        
	 }
	 fich.close();
}
