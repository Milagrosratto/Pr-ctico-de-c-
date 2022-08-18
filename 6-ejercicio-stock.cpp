#include <iostream>
#include <fstream>
#include <cstring>
#include<cstdlib>
/*alumna :Milagros Ratto*/
using namespace std;
//definir un struct para datos 
struct productos{
	char codigo[10];
	char descrip[30];
	int stock;
	int puntorepo;
	
};


//un struct para el indice 
struct Indice
{
    char clave[10];//codigo 
    int posicion;
};

void salir();
void alta();
void generar_indice();
void buscar();
void Altastock();
void listar();
bool validar(struct productos p);
int main()
{
    int *ibande=0;
    char op;
    
   do {
        //menu 
        
        cout<<endl;
         cout << "Ingrese una opcion " << endl;
         cout << "[A] Alta Producto " << endl;
         cout << "[B] Buscar Producto " << endl;
         cout << "[L] Listar Reposición " << endl;
         cout << "[T] Alta stock " << endl;
         cout << "[G] Generar indice "<<endl;
         cout << "[S] Salir" << endl;
		   cin >> op;
        //########################
        switch (toupper(op))
        {
        case 'A':
        	
        
        	
        	
        	alta();	
        	
        	
        	
        	
            
            break;
        case 'B':
             buscar();
            break;
        case 'L':
             listar();
            break;
        case 'G':
        	 generar_indice();
        	break;
         case 'T':
        
        	Altastock();
             
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
struct productos prod;
int canti_alta=0;
	ofstream arch;
	arch.open("Productos.dat",ios::ate|ios::app|ios::binary);
	cout<<"Ingrese datos del producto"<<endl;
	
	cout<<"Codigo:"<<endl;
	cin>>prod.codigo;
	
	
	if (validar(prod))
    {
        cout << endl;  "El codigo ingresado ya existe" ;
    }
    else
    {
	
    cout<<"Descripcion:"<<endl;
    cin>>prod.descrip;
   cout<<"Stock:"<<endl;
   cin>>prod.stock;
   cout<<"Punto de reposicion:"<<endl;
   cin>>prod.puntorepo;
   
   arch.write((char*) &prod, sizeof(prod));//escribo la struct en el archivo
    arch.close();
	}//se cierra archivo 
	canti_alta++;
    if(canti_alta  >=5 ){
    	 generar_indice();
    }
   
}
void generar_indice(){
	
	Indice ind;
  struct productos p;
	//abro archivo y leo 
	 ifstream fich;
	 fich.open("Productos.dat",ios::in|ios::binary);
	 //abro archivo indice para escritura
    ofstream fichI;
    fichI.open("Productos.inx", ios::binary);
    
	 while (!fich.read((char*)  &p,sizeof(p)).eof())//leo el archivo de datos 
    {

        ind.posicion = fich.tellg() ;
      
        ind.posicion -=  sizeof(p);
      
        strcpy(ind.clave  ,  p.codigo);
    
        fichI.write((char*) &ind, sizeof(ind)  );//escribo en archivo indice 

    }
//cierro los dos archivos 
    fichI.close();
    fich.close(); 
	  
}

void buscar() 

{
  struct   Indice ind;
   struct  Indice aux;
    char codigo_busqueda[10];
    fstream arch;

    arch.open("Productos.inx", ios::in | ios::out | ios::binary);


   cout<<"Ingrese codigo para buscar"<<endl;
   cin>>codigo_busqueda;


         
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

            
            if (strcmp(ind.clave,codigo_busqueda) ==0)
            {
                cout<<"Codigo:"<<ind.clave<<endl;
                cout<<"Posicion:"<<ind.posicion<<endl;
                encontrado = 1;
                fin = -1;
            }
             
            else
            {
                if ( strcmp(codigo_busqueda,ind.clave)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        
        if (encontrado!= 1){
          cout<<"no se encontro el codigo buscado"<<endl;	
          
        }
      

}


    
void listar(){
	
struct 	productos p;
	ifstream f;
	f.open("Productos.dat",ios::in|ios::binary);
	system("cls");
	cout<<endl<<endl;
	 while (!f.read((char*)  &p,sizeof(p)).eof())//leo el archivo de datos 
	 {
	 	if(p.stock <= p.puntorepo){
	 		
	 	cout<<"Codigo:"<<p.codigo<<endl;;
	 	cout<<"Descripcion:"<<p.descrip<<endl;;
        cout<<"Stock:"<<p.stock<<endl;
        cout<<"Punto reposicion:"<<p.puntorepo<<endl;
	 	}
	 	
        
	 }
	 f.close();
}



bool validar(struct productos p)
{
    
    struct Indice index;
    ifstream IProductos;
    IProductos.open("Productos.inx", ios::binary);

    while (IProductos.read((char*) &index, sizeof(index) ))
    {
        if (strcmp(index.clave, p.codigo)==0)
        {
            IProductos.close();
            return true;
        }
    }
    IProductos.close();
    return false;
}

	




void Altastock()
{

    
    struct productos p;

    cout << endl << "Ingrese codigo producto:";
    cin >> p.codigo;

    if (validar(p))
    {
        cout << endl << "ingrese la cantidad:";
        cin >> p.stock ; 

        ofstream AProductos;
        ifstream IProductos;
        
    ifstream IProducto;
    IProducto.open("Productos.inx", ios::binary);

    struct Indice inx;
    struct productos p;
    struct productos pOriginal;

  

         
        int n;
        int medio;
        int inicio = 0;
        int fin = (sizeof(IProducto)/sizeof(productos)) - 1;      
        int encontrado = 0;
        while (inicio <= fin)
        {
            
            medio = (fin + inicio) / 2;
            

            
            IProducto.seekg(medio * sizeof(productos));
            IProducto.read((char*) &inx, sizeof(inx));

            
            if (strcmp(inx.clave,p.codigo) ==0)
            {
                   
                ifstream AProductosLee;
                AProductosLee.open("Productos.dat", ios::binary);
                AProductosLee.seekg(inx.posicion);
                AProductosLee.read((char*) &pOriginal, sizeof(p));

                strcpy(p.descrip, pOriginal.descrip);
                p.stock = p.stock + pOriginal.stock;
                p.puntorepo = pOriginal.puntorepo;


                //ACTUALIZA CANTIDAD
                ofstream AProductosAct;
                AProductos.open("Productos.dat", ios::binary | ios::app | ios::ate);
                AProductos.seekp(inx.posicion);
                AProductos.write((char*) &p, sizeof(p) );
                AProductos.close();

                encontrado = 1;
                fin = -1;
            }
            
            else
            {
                if ( strcmp(p.codigo,inx.clave)==-1)
                    fin = medio - 1;
                else 
                    inicio = medio + 1;
            }
        }
        
        if (encontrado != 1)
            cout<< "No se encontro el codigo buscado" << endl;



    IProducto.close();
        


    }
    else
    {
        cout << endl <<" el codigo ingresado es inexistente";
    }
    

}




  
