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
	}else if (control==true) {
		cout << "Has accedido al sistema" << endl;
		cout << "Bienvenido a Pelusa OS" << endl;
	}else {
		cout << "La validación ha fallado";
	}


}
//Aquí termina el main
