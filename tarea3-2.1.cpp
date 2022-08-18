#include<iostream>
#include<fstream>
#include<string.h>



/*Desarrollar el programa que permite buscar las ventas
por Playero, por surtidor o por tipo de combustible y
muestre por pantalla la cantidad de ventas y el total de
litros.
Condiciones:

? Utilizar el archivo binario: estacion.dat
? Leer archivo por Read()*/

	

using namespace std;
struct ventas {
		int nro_playero;
		int nro_surtidor;
		char combustible[2];
		int canti_litrosV;
		
	}ventas;

int main(){
	int num;
     int aux1;
	struct ventas venta;
	struct ventas aux;
	
	
	
	cout<<"Buscar por \n 1_ Numero de playero\n 2_Numero de surtidor\n3_Tipo de combustible"<<endl;
	cin>>num;
	switch(num){
		case 1: //buscar por playero
			ifstream fich;
        	fich.open("estacion.dat", ios::in|ios::binary);
	        if(fich.fail()){
	     	cout<<"El archivo no pudo abrirse correctamente";
		
	            }
            	cout<<"Ingrese un playero para buscar"<<endl;
               	cin>>aux.nro_playero;
             	while(!fich.eof()){
		
	        	fich.read((char*)&venta,sizeof(ventas));
               	
	            if (strcmp ( venta.nro_playero , aux.nro_playero )==0)
                {
                   /* cout << "Playero: " << venta.nro_playero <<endl;
                    cout << "Surtidor: " << venta.nro_surtidor<<endl;
                    cout << "Combustible: " << venta.combustible <<endl;
                    cout << "Cantidad de litros: " << venta.canti_litrosV <<endl;*/
                    aux+=venta.canti_litrosV;
                } }
  
               fich.close();
        
	

		
		break;
		case 2:// buscar ppor surtidor
		ifstream fich;
	    fich.open("estacion.dat", ios::in|ios::binary);
        if(fich.fail()){
		cout<<"El archivo no pudo abrirse correctamente";
		
          }
			cout<<"Ingrese un surtidor para buscar"<<endl;
               	cin>>aux.nro_surtidor;
             	while(!fich.eof()){
		
	        	fich.read((char*)&venta,sizeof(ventas));
               
	            if (strcmp ( venta.nro_surtidor, aux.nro_playero)==0)
                {
                   
                    aux+=venta.canti_litrosV;
                }}
               fich.close();
         
		break;
		case 3: //nuscar por tipo de combustible
		ifstream fich;
     	fich.open("estacion.dat", ios::in|ios::binary);
	    if(fich.fail()){
		cout<<"El archivo no pudo abrirse correctamente";
		
        	}
			cout<<"Ingrese un combustible para buscar"<<endl;
               	cin>>aux.combustible;
             	while(!fich.eof()){
		
	        	fich.read((char*)&venta,sizeof(ventas));
               
	            if (strcmp ( venta.combustible, aux.combustible)==0)
                {
                    aux+=venta.canti_litrosV;
                }
               }
		fich.close();
         
		break;
		cout<<"Total de litros vendidos:"<<aux1<<endl;
		
	}
	
		fich.close();
	
	return 0;
}
