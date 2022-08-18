/*Registración de Repuestos por Rubro
Se desean registrar repuestos de distintos rubros: [A]utomotor, [M]otos, [N]autica, [V]arios en archivos de repuestos,
uno por cada rubro. De cada repuesto se cuenta con los siguientes datos: código [Alpha], descripción [50] y código_marca [10].
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
//definir un struct para datos 
struct repuestos
{
    char codigo[10];
    char descripcion[50];
    char marca[10];
};

void alta(char);


int main()
{

    char op, aux,resp;
    int ibande=0;
   do {
        //menu 
         cout<<endl;
         cout << "Ingrese una opcion " << endl;
         cout << "[A] automotor" << endl;
         cout << "[M] motos" << endl;
         cout << "[N] nautica" << endl;
         cout << "[V] varios" << endl;
         cout << "[S] salir" << endl;
		   cin >> op;
        //########################
        switch (toupper(op))
        {
        case 'A':
            alta(op);
            break;
        case 'M':
           alta(op);
            break;
        case 'N':
            alta(op);
            break;
        case 'V':
           alta(op);
            break;
        case 'S':
        	cout<<"Esta seguro que desea finalizar? S/N"<<endl;
        	cin>>resp;
        	
        	if( toupper(resp)=='S'){
        		cout<<"  Finalizando.."<<endl;
            cout<<"#################"<<endl;
            ibande=1;
        	}
            
            break;
        default:
        	cout<<"OPCION NO VALIDA"<<endl;
           break;
        }
    }while(ibande!=1); 
   
}

void alta(char opc)
{
    struct repuestos repuesto;
    ofstream arch;

    
    if (toupper(opc) == 'A')
    {

        arch.open("Automotor.dat", ios::app | ios::ate | ios::binary);
    }
    else if (toupper(opc) == 'M')
    {

        arch.open("Motos.dat", ios::app | ios::ate | ios::binary);
    }
    else if (toupper(opc) == 'N')
    {

        arch.open("Nautica.dat", ios::app | ios::ate | ios::binary);
    }
    else if (toupper(opc) == 'V')
    {

        arch.open("Varios.dat", ios::app | ios::ate | ios::binary);
    }
    

    cout << "Ingrese el codigo: " << endl;
    cin >> repuesto.codigo;
    cout << "Ingrese la descripcion: " << endl;
    cin.ignore();
    cin.getline(repuesto.descripcion,50);
    cout << "Ingrese la marca: " << endl;
    cin >> repuesto.marca;
    

    arch.write((char *)&repuesto, sizeof(repuesto));
    arch.close();
    cout << endl << "Cargado correctamente " << endl << endl;
    
}


