#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*Una estación de servicios desea actualizar sus sistemas,
almacenando las ventas en archivos.
Hasta el momento la estación cuenta con:
? 7 surtidores (del 1 al 7)
? 4 tipos de combustibles (Nafta Premium [Np], Nafta común [Nc], GasOil Premium
[Gp], GasOil común [Gc])
? 5 playeros (del 1 al 5).
El programa deberá consultar si desea iniciar una venta (V) o Finalizar (F), cualquier otra
opción deberá informar: Opción incorrecta, ingrese Venta (V) o Finalización (F).
Por cada venta deberá solicitar: Nro de playero, Nro de Surtidor, Tipo de combustible y
cantidad (litros) vendidos, almacenando temporalmente en una estructura {Venta} los
datos de la misma antes de ser volcados al archivo.
De ingresarse un playero o el tipo de combustible inválidos deberá informar al operador y
solicitar valores correctos. La venta en Litros No podrá ser 0 (cero).
Para guardar los datos en el archivo, deberá utilizarse la función Guardar() que reciba
como parámetro la Venta{} realizada.
Condiciones:

? Archivo tipo binario, nombre: estacion.dat
? Grabar archivo por Write()
? Si contiene información previa, la misma deberá conservarse.
? Las validaciones de Surtidor, Playero, tipo de Combustible y Litros deberá
realizar utilizan funciones INDEPENDIENTES que reciban la {Venta} como
parámetro.*/
 struct ventas {
		int nro_playero;
		int nro_surtidor;
		char combustible[2];
		int canti_litrosV;
		
	}ventas;
void vali_Player(struct ventas venta1);
void vali_surt(struct ventas venta1);
void guardar(struct ventas venta);
void validacion(struct ventas venta1);

int main(){
	char letra;
	char aux[2];
    int ibandera=0,num=0;
	struct ventas venta1;
	cout<<"Desea"<<endl;
	cout<< "Opcion(ventas) v"<<endl;
	cout<<"Opcion(Finalizar) f"<<endl;
	cin>>letra;
	switch(letra){
		case 'v':
			while(ibandera==0){
			//ingreso ventas
			cout<<"Ingrese numero de playero:"<<endl;
			cin>>venta1.nro_playero;
			vali_Player(venta1);
			
			
			cout<<"Ingrese numero de surtidor:"<<endl;
			cin>>venta1.nro_surtidor;
			vali_surt(venta1);
			
			cout<<"Ingrese tipo de combustible:"<<endl;
			cin>>venta1.combustible;
			validacion(venta1);
			
		
			
			cout<<"\nIngrese cantidad de litros vendidos:"<<endl;
			cin>>venta1.canti_litrosV;
			
			//cout<<"Ventas";
			guardar(venta1);
			cout<<"Desea ingresar otra venta?"<<endl;
			cout<<"1_Si\n2_No"<<endl;
			cin>>num;
			if(num==1){
				ibandera=0;
			}
			else{
				ibandera=1;
			}	
				
				
			}
			
			break;
			//----------------------------
		case 'f':
		cout<<"Finaliza";
	//	exit(1);
		break;
		default: cout<<"opcion incorrecta";
		
			
	}

	
	return 0;
}
void vali_Player(struct ventas venta1){
	if((venta1.nro_playero>=1&&venta1.nro_playero<=5)){
				
			}else{
				cout<<"Numero de playero incorrecto, ingrese playero del 1 al 5"<<endl;
				cin>>venta1.nro_playero;
			}
}

void vali_surt(struct ventas venta1){
		if((venta1.nro_surtidor>=1&&venta1.nro_surtidor<=7)){
				
			}else{
				cout<<"Numero de surtidor incorrecto, ingrese surtidor del 1 al 7"<<endl;
				cin>>venta1.nro_playero;
			}
}

void guardar(struct ventas venta1){
		//declaro archivo
	ofstream arch;
	//abro archivo
	arch.open("estacion.dat", ios::out|ios::app|ios::binary);
	//compruebo si abrió correctamente 
	if(arch.fail()){
		cout<<"No se pudo crear el archivo";
	//	exit(1);
	}
	//escribiendo en archivo
		arch.write((char*)&venta1,sizeof(ventas));
		arch.close();
}
void validacion(struct ventas venta1){
	char c1[2];
	char c2[2];
	char c3[2];
	char c4[2];
	int ibandera=0;
	strcpy(c1,"Np");
	strcpy(c2,"Nc");
	strcpy(c3,"Gp");
	strcpy(c4,"Gc");
	if(ibandera==0){
		ibandera=1;
		if (strcmp ( venta1.combustible,c1)==0){
		cout<<"combustible correcto";
		ibandera=0;
	}
	if (strcmp ( venta1.combustible,c2)==0){
		cout<<"combustible correcto";
		ibandera=0;
	}
	if (strcmp ( venta1.combustible,c3)==0){
		cout<<"combustible correcto";
		ibandera=0;
	}
	if (strcmp ( venta1.combustible,c4)==0){
		cout<<"combustible correcto";
		ibandera=0;
	}	
	
	}

	if(ibandera==1){
		cout<<"Opcion incorrecta ingrese tipo de combustible:"<<endl;
		cout<<"Nafta Premium [Np]\nNafta comun [Nc]\nGasOil Premium[Gp]\nGasOil comun [Gc]"<<endl;
		cin>>venta1.combustible;
	}
	
}
