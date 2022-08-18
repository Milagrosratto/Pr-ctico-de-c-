#include <iostream>
#include <fstream>
#include <cstring>
#include<cstdlib>
/*alumna :Milagros Ratto*/
using namespace std;
//definir un struct para datos 
struct cliente{
	char cuil[11];
	char razon_social[30];
    char fech_alta[8];
    char localidad[20];
    char dire[50];

	
};


//un struct para el indice 
struct Indice
{
    char clave[11];//cuil
    int posicion;
};

void salir();
void alta();
void generar_indice();
void buscar_cuil();
void buscar_razon();
bool validar(struct cliente p);
int main()
{
    
    char op;
    int opp=0;
   do {
        //menu 
        
        cout<<endl;
         cout << "Ingrese una opcion " << endl;
         cout << "[A] Alta cliente " << endl;
         cout << "[B] Buscar  " << endl;
         cout << "[S] Salir" << endl;
		   cin >> op;
        //########################
        switch (toupper(op))
        {
        case 'A':
        	
        
        	
        	
        	alta();	
        	
        	
        	
        	
            
            break;
        case 'B':
        	system("cls");
		 cout << "Ingrese opcion " << endl;
         cout << "1_buscar por cuil  " << endl;
         cout << "2_Buscar por razon social " << endl;
         cin >> opp;
        	switch(opp){
        		case 1: //buscar por cuil
        		buscar_cuil();
        		break;
        		case 2: //buscar por razon social
        		buscar_razon();
        		break;
        		default: 
        		 cout << "Opcion no valida" << endl;
        		 break;
        	}
            
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


void alta(){
struct cliente persona;

	ofstream arch;
	arch.open("Clientes.dat",ios::ate|ios::app|ios::binary);
	cout<<"Ingrese sus datos "<<endl;
	
	cout<<"Cuil:"<<endl;
	cin>>persona.cuil;
	
	
	if (validar(persona))
    {
        cout << endl;  "El cuil ingresado ya existe" ;
    }
    else
    {
//          pido datos 
    cout<<"Razon social::"<<endl;
    cin>>persona.razon_social;
   cout<<"fecha:"<<endl;
   cin>>persona.fech_alta;
   cout<<"Localidad:"<<endl;
   cin>>persona.localidad;
   cout<<"Direccion:"<<endl;
   cin>>persona.dire;
   
   
   arch.write((char*) &persona, sizeof(persona));//escribo la struct en el archivo
    arch.close();
	}
	
    	 generar_indice();
    
   
}
void generar_indice(){
	
	Indice ind;
  struct cliente persona;
	//abro archivo y leo 
	 ifstream fich;
	 fich.open("Clientes.dat",ios::in|ios::binary);
	 //abro archivo indice para escritura
    ofstream fichI;
    fichI.open("Clientes.inx", ios::binary);
    
	 while (!fich.read((char*)  &persona,sizeof(persona)).eof())//leo el archivo de datos 
    {

        ind.posicion = fich.tellg() ;
      
        ind.posicion -=  sizeof(persona);
      
        strcpy(ind.clave  ,  persona.cuil);
    
        fichI.write((char*) &ind, sizeof(ind)  );//escribo en archivo indice 

    }
//cierro los dos archivos 
    fichI.close();
    fich.close(); 
	  
}

void buscar_cuil() 

{
  struct   Indice ind;
   struct  Indice aux;
    char cuil_busqueda[11];
    fstream arch;

    arch.open("Clientes.inx", ios::in | ios::out | ios::binary);


   cout<<"Ingrese cuil para buscar"<<endl;
   cin>>cuil_busqueda;


         
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

            
            if (strcmp(ind.clave,cuil_busqueda) ==0)
            {
                cout<<"Cuil:"<<ind.clave<<endl;
                cout<<"Posicion:"<<ind.posicion<<endl;
                encontrado = 1;
                fin = -1;
            }
             
            else
            {
                if ( strcmp(cuil_busqueda,ind.clave)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        
        if (encontrado!= 1){
          cout<<"no se encontro el cuil"<<endl;	
          
        }
      

}

void buscar_razon() 

{
  struct   cliente pers ;
   struct  cliente aux;
    char rsocial_busqueda[11];
    fstream arch;

    arch.open("Clientes.dat", ios::in | ios::out | ios::binary);


   cout<<"Ingrese razon social para buscar"<<endl;
   cin>>rsocial_busqueda;


         
        int n;
        int medio;
        int inicio = 0;
        int fin = arch.tellg()/sizeof(pers);        
        int encontrado = 0;
        while (inicio <= fin)
        {
           
            medio = (fin + inicio) / 2;
            

             arch.seekg(medio*sizeof(pers));        
             arch.read((char*) &pers, sizeof(pers));

            
            if (strcmp(pers.razon_social,rsocial_busqueda) ==0)
            {
                cout<<"Razon social:"<<pers.razon_social<<endl;
                cout<<"Cuil:"<<pers.cuil<<endl;
                cout<<"fecha:"<<pers.fech_alta<<endl;
                cout<<"Localidad:"<<pers.localidad <<endl;
                cout<<"Direccion:"<<pers.dire<<endl;
  
   
   
                
                encontrado = 1;
                fin = -1;
            }
             
            else
            {
                if ( strcmp(rsocial_busqueda,pers.razon_social)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        
        if (encontrado!= 1){
          cout<<"no se encontro el cuil"<<endl;	
          
        }
      

}


   



bool validar(struct cliente p)
{
    
    struct Indice index;
    ifstream IProductos;
    IProductos.open("Clientes.inx", ios::binary);

    while (IProductos.read((char*) &index, sizeof(index) ))
    {
        if (strcmp(index.clave, p.cuil)==0)
        {
            IProductos.close();
            return true;
        }
    }
    IProductos.close();
    return false;
}

	




  
