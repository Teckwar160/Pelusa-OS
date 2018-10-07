#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;



void comandos();

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