
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct repuesto
{
    char codigo[10];
    char descrip[50];
    char marca[10];
};

struct indice
{
    char clave[10];
    int posicion;
};

int main()
{
    struct repuesto rep;
    struct indice ind;
    //####### AUTOMOTOR #######
    ifstream arch;
    ofstream archh;
    arch.open("Automotor.dat",ios::binary|ios::in);
    archh.open("Automotor.inx",ios::binary|ios::app|ios::ate);
    
     while (!arch.read((char*)  &rep,sizeof(rep)).eof())//leo el archivo de datos 
    {

        ind.posicion = arch.tellg() ;
      
        ind.posicion -=  sizeof(rep);
      
        strcpy(ind.clave  ,  rep.codigo);//copio el codigo para usarlo como clave
    
        archh.write((char*) &ind, sizeof(ind));//escribo en archivo indice 

    }
    
    //####### NAUTICA #######
    ifstream arch1;
    ofstream archh1;
    arch1.open("Nautica.dat",ios::binary|ios::in);
    archh1.open("Nautica.inx",ios::binary|ios::app|ios::ate);
    
     while (!arch1.read((char*)  &rep,sizeof(rep)).eof())//leo el archivo de datos 
    {

        ind.posicion = arch.tellg() ;
      
        ind.posicion -=  sizeof(rep);
      
        strcpy(ind.clave  ,  rep.codigo);//copio el codigo para usarlo como clave
    
        archh1.write((char*) &ind, sizeof(ind));//escribo en archivo indice 

    }
    
     
    //####### MOTOS #######
    ifstream arch2;
    ofstream archh2;
    arch2.open("Motos.dat",ios::binary|ios::in);
    archh2.open("Motos.inx",ios::binary|ios::app|ios::ate);
    
      while (!arch2.read((char*)  &rep,sizeof(rep)).eof())//leo el archivo de datos 
    {

        ind.posicion = arch.tellg() ;
      
        ind.posicion -=  sizeof(rep);
      
        strcpy(ind.clave  ,  rep.codigo);//copio el codigo para usarlo como clave
    
        archh2.write((char*) &ind, sizeof(ind));//escribo en archivo indice 

    }
    
    //####### VARIOS #######
    ifstream arch3;
    ofstream archh3;
    arch3.open("Varios.dat",ios::binary|ios::in);
    archh3.open("Varios.inx",ios::binary|ios::app|ios::ate);
    
      while (!arch3.read((char*)  &rep,sizeof(rep)).eof())//leo el archivo de datos 
    {

        ind.posicion = arch.tellg() ;
      
        ind.posicion -=  sizeof(rep);
      
        strcpy(ind.clave  ,  rep.codigo);//copio el codigo para usarlo como clave
    
        archh3.write((char*) &ind, sizeof(ind));//escribo en archivo indice 

    }
    arch.close(); archh.close();
    arch1.close(); archh1.close();
    arch2.close(); archh2.close();
    arch3.close(); archh3.close();
    
}
