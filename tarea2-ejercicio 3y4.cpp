#include<iostream>//estandar de c++
#include<fstream>//manejo archiv
using namespace std;
/*Ejercicio 3:
Utilizando los operadores cout/cin solicitar al usuario la cantidad de números a leer.
Solicitar al usuario el ingreso uno a uno de los números para ir registrando los mismos en
un archivo de tipo texto. Deberá almacenarse un número por fila.*/
int main(){
	
	int canti,i,num;
	int valor;
	int arr[30];
	cout<<"Ingrese cantidad de numeros :"<<endl;
	cin>>canti;
	ofstream archiv;//declaro archivo
	archiv.open("Archivo.php",ios::binary|ios::out);//abro mi archivo binario 
	//pruebo si abrio correctamente
	if(archiv.fail()){
		cout<<"NO SE PUDO ABRIR EL ARCHIVO";
		
	}
	cout<<"Ingrese numeros para guardar en archivo"<<endl;
	for(i=0;i<canti;i++){
	 cin>>num;
	 archiv<<num<<" "<<endl;	//escribo en archivo
	 
	 
	}

	archiv.close();//cierro archivo
	
	
	/*Realizamos la operación inversa al ejercicio 3.
Abrir el archivo de texto generado en ejercicio anterior y
cargar uno a uno los valores del archivo en un array
(considerar dimensionamiento dinámico).
Al finalizar la lectura desde el archivo, mostrar por pantalla la cantidad de elementos
leídos y el listado de los mismos.*/

  ifstream archiv2;
   archiv2.open("Archivo.php", ios::in);//abriendo en modo lectura
	//pruebo si abrio correctamente
	if(archiv2.fail()){
		cout<<"NO SE PUDO ABRIR EL ARCHIVO";
		
	}
	cout<<"Leyendo archivo"<<endl;
	while(!archiv2.eof()){//mientras no sea fin de archivo 
	archiv2>>valor;
	//cout<<valor;
	for(i=0;i<canti;i++){
		arr[i]=valor;
	}
	

    }
    cout<<"Cantidad de elementos leidos:"<<i<<endl;
	for(i=0;i<canti;i++){
		cout<<arr[i];
	}
    
	return 0;
}


