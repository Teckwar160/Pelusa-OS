#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sys/stat.h>
using namespace std;


#include "manejoDeUsuarios.h"
#include "terminal.h"

int main (){

	if (control == false){ //Si no se a iniciado sesion entra al menu de bienvenida
		bienvenida();
	}

	cout << "Bienvenido a Pelusa OS" << endl; //En caso contrario ya entra al sistema

	terminal(); 
	
}