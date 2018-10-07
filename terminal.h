#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

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

	}while(salida != true);
}