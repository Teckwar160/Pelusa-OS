#include "includes.h"
#include "manejoDeUsuarios.h"
#include "sistemaDeArchivos.h"

int main (){
	if (control == false){ //Si no se a iniciado sesion entra al menu de bienvenida
		bienvenida();
	}else {
		cout << "Bienvenido a Pelusa OS" << endl; //En caso contrario ya entra al sistema
	}


	return 0;
}
