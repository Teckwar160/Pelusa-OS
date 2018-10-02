#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "manejoDeUsuarios.h"

using namespace std;
//Definicion de procesos




//Aquí empieza el main
int main (){
	if (control == false){ //Si no se a iniciado sesion entra al menu de bienvenida
		bienvenida();
	}

	cout << "Bienvenido a Pelusa OS" << endl; //En caso contrario ya entra al sistema

}
//Aquí termina el main
