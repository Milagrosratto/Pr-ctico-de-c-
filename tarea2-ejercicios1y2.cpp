#include<iostream>
/*Mostrar por pantalla el mensaje: Hola mundo C++
? Mostrar por pantalla un número con 3 decimales
? Mostrar por pantalla un número de legajo completando con ceros a la izquierda
hasta 10 posiciones.
? Mostrar por pantalla una letra completando con espacios a la derecha hasta 20
posiciones.*/
using namespace std;
int main(){
	int num;
	char letra;
	string cadena;
	
	
	cout<<"Hola mundo c++"<<endl;
	
	cout.precision(4);
	cout<<3.1415167<<endl;
	
	cout.width (10);
	cout.fill('0');
	cout.setf(ios::right);
	cout<<15730<<endl;
	
	cout.width(20);
	cout.fill(0);
	cout<<left<<"M"<<endl;
	
	/*Ejercicio 2:
? Solicitar al usuario el ingreso de una variable numérica y mostrar el valor ingresado
? Solicitar al usuario el ingreso de una variable carácter y mostrar el valor ingresado
? Solicitar al usuario el ingreso de una oración con espacios y mostrar el valor
ingresado*/
cout<<"Ingrese un numero:"<<endl;
cin>>num;
cout<<"Su valor ingresado es:"<<num<<endl;

cout<<"Ingrese una letra:"<<endl;
cin>>letra;
cout<<"Su valor ingresado es:"<<letra<<endl;

cin.ignore();

cout<<"Ingrese una cadena con espacios:"<<endl;
getline(cin,cadena);
cout<<"Su valor ingresado es:"<<cadena<<endl;

	return 0;
}
