#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
//Definicion de procesos

void bienvenida ();
void registro();
void login ();

//Zona de Variables

bool control = false;
//char pelusaOSVersion = '0.01-canary';

//Aquí empieza el main
int main (){
	if (control == false){
		bienvenida();
	}

	cout << "Bienvenido a Pelusa OS" << endl;
}
//Aquí termina el main

//Zona de procesos

/*Bienvenida*/

void bienvenida (){
	char decision;

 while (decision == 'a','A' or decision == 'b','B'){
 	cout << "\t 0.01-canary" << endl << endl;

 	cout << "Elija una opcion"<< endl;
 	cout << "\ta) Usuario Registrado" << endl
 	     << "\tb) Usuario No Registrado" << endl;
 	cout << "=> "; cin >> decision;

 	if (decision == 'A' or decision == 'a'){
 		login (); break;
 	}

 	if (decision == 'B' or decision == 'b'){
 		registro (); break;
 	}
 }
}

/*Registro*/

void registro(){
	ofstream archivo;
	string usuario,contra;
	string pausa;

	system("clear");
	archivo.open("usuarios.txt",ios::app);

    //Condicion por si falla el docuemento
	if (archivo.fail()){
		cout << "El archivo no se puedo abrir";
		exit (1);
	}

	cout <<"\tEscriba un nombre de usuario: ";
	cin >> usuario;
	cin.ignore();
	cout << "\tEscriba una contraseña: ";
	cin >> contra;
	cin.ignore ();

	archivo << usuario << " " << contra << endl << endl;
	archivo.close();
   system("clear");
   cout << "Aviso: Usuario Registrado" << endl<< endl;
   return bienvenida ();
}

/*Login*/

void login (){
	bool validacion = false;
	ifstream archivo;
	string usuario,lectura_usuario,contra,lectura_contra;

	do{
    archivo.open("usuarios.txt",ios::out);
    archivo >> lectura_usuario;
	cout <<"\tUsuario: ";
	cin >> usuario;
	cin.ignore ();
	cout <<"\tContraseña: ";
	cin >> contra;
	cin.ignore ();

	while(!archivo.eof()){
        archivo >> lectura_contra;
		if (lectura_usuario == usuario and lectura_contra == contra){
			validacion = true; break;
		}
		archivo >> lectura_usuario;
	}

	archivo.close ();
    }while(validacion != true);

    if (validacion == true){
    	system("clear");
    	control = true;

    }
}
