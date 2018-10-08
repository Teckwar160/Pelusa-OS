/*Esta librería contiene a la terminal y los comandos que se pueden utilizar en ella, la función principal es la terminal y manda a llamar a los comandos solicitados. Existen distintos archivos de texto dentro de la carpeta llamada terminalComandos en donde cada archivo de texto corresponde a la respectiva descripción de un comando.*/

//TODO: Hay que conectar las funciones con los archivos dentro de la carpeta terminalComandos

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

//Zona de prototipos

void comandos();
void createDir();
void deleteDir();
void createFile();
void deleteFile();



//Función principal
void terminal(){


	//Variables
	string comando;
	bool salida;

	do{
		salida = false;

		cout << "pelusa@pelusa:~ ";
		cin >> comando;

		if (comando == "exit"){
			salida = true;
		}

		if (comando == "list"){
			comandos();
		}

	}while(salida != true);
}

void comandos(){
	ifstream archivo;
	string texto;
	archivo.open("comandos.txt",ios::in);
	if(archivo.fail()){
		cout << endl << "No se pudo abrir el archivo" << endl << endl;
	}
	while(!archivo.eof()){
		getline(archivo,texto);
		cout << texto << endl;
	}
	archivo.close();
}

//Comando createrDir permite crear un directorio
void createDir(){

}

//Comando deleteDir permite eliminar un directorio
void deleteDir(){

}

//Comando createFile permite crear un archivo
void createFile(){

}

//Comando deleteFile() permite eliminar un archivo 
void deleteFile(){

}
