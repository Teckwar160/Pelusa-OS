#include "manejoDeUsuarios.h"
#include "terminal.h"

int main (){
	if (control == false){ //Si no se a iniciado sesion entra al menu de bienvenida
		bienvenida();
	}

	cout << "Bienvenido a Pelusa OS" << endl; //En caso contrario ya entra al sistema

	terminal();
}


