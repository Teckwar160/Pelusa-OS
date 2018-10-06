//#include "includes.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include <dirent.h>
#include <ncurses.h>

using namespace std;

#include "manejoDeUsuarios.h"
#include "sistemaDeArchivos.h"

int main (){
	if (control == false){ //Si no se a iniciado sesion entra al menu de bienvenida
		bienvenida();
	}else {
		cout << "Bienvenido a Pelusa OS" << endl; //En caso contrario ya entra al sistema
	}
	
	//Solamente quiero hacer un comentario para confirmar que todo esté bien configurado en git
	
	return 0;
}
