#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

void bienvenida (); //Menu de bienvenida al usuario
void registro(); //Menu de registro de usuarios
void login (); //Menu para iniciar sesion de usuarios
void baseDeDatos(); //Preview de función que permite hacer conexión con la base de datos

using namespace std;


//Zona de Variables
bool control = false; //variable que controla la entrada al sistema


//Zona de procesos

/*Bienvenida*/

void bienvenida (){
	char decision;
  //FIXME: Hay que resolver esta variable, no me permite mostrar la cadena de texto completa
  //char version[6]='canary';
  int oportunidades=1, limiteO=3;

 while (oportunidades <=limiteO){ //Bucle que hace que solo puedan usar dos opciones, y da solamente 3 oportunidades

   //FIXME: Resolver variable version
	 	cout << "\nPelusa OS 0.01-canary"<< endl << endl; //Mensaje del sistema

	 	cout << "Elija una opcion"<< endl;
	 	cout << "\ta) Usuario Registrado" << endl     //Opciones que puede elegir
	 	     << "\tb) Usuario No Registrado" << endl;
	 	cout << "=> "; cin >> decision;

    /* He modificado el condicional para que tome en cuenta la posibilidad de que el usuario no introduzca una opción válida, devuelva un mensaje pidiendo que lo intente de nuevo, y poniendo un máximo de 3 oportunidades */
	 	if (decision == 'A' or decision == 'a'){
	 		login (); break;
	 	}else if(decision == 'B' or decision == 'b'){
      registro (); break;
    }else {

      if (oportunidades<limiteO) {
        cout << "Por favor, introduce una opción válida"<<endl;
        cout << "Intenta nuevamente \n" << endl;
        oportunidades+=1;
        cout << "Te quedan "<< limiteO-oportunidades << " oportunidades, después el sistema se bloqueará";
      }else {
        cout << "El límite de posibilidades se ha excedido, sistema bloqueado";
        oportunidades+=1;
      }

    }

  }

 system("clear");

}

/*Registro*/

void registro(){
	ofstream archivo; //Libreria que maneja los archivos txt
	string usuario,contra; //Usuario y contraseña escritos por el usuario

	system("clear");
	archivo.open("usuarios.txt",ios::app); //Crea el archvio sino existe y si existe solo lo abre

    //Condicion por si falla el docuemento
	if (archivo.fail()){
		cout << "El archivo no se puedo abrir";
		exit (1);
	}

	cout <<"\tEscriba un nombre de usuario: ";  //Ingresa su usuario y contraseña
	cin >> usuario;
	cin.ignore();
	cout << "\tEscriba una contraseña: ";
	cin >> contra;
	cin.ignore();

	archivo << usuario << " " << contra << endl << endl; //Los guarda en el txt
	archivo.close();                                     //Se cierra el archivo
   system("clear");
   cout << "Aviso: Usuario Registrado" << endl<< endl; //Mensaje del sistema
   return bienvenida ();                               //Regresa al menu de bienvenida
}

/*Login*/

void login (){
	bool validacion = false; //Valida el inicio de sesion
	ifstream archivo;
	string usuario,lectura_usuario,contra,lectura_contra; //variables de lectura adelantada y variables metidas por el usuario

	do{
    archivo.open("usuarios.txt",ios::out); //Abre el archivo en mode de lectura
    archivo >> lectura_usuario; //Lectura adelantada del usuario
	cout <<"\tUsuario: ";
	cin >> usuario;
	cin.ignore ();
	cout <<"\tContraseña: ";
	cin >> contra;
	cin.ignore ();

	while(!archivo.eof()){ //Bucle que mientras el archivo no se haya leido completamente haga
        archivo >> lectura_contra; //LEctura adelantada de la contraseña
		if (lectura_usuario == usuario and lectura_contra == contra){ //Si coinciden valida el inisio de sesion
			validacion = true; break;
		}
		archivo >> lectura_usuario; //Lectura del usuario esta linea evita errores con las contraseña de los usuarios
	}

	archivo.close (); //Cierra el archivo
    }while(validacion != true); //Mantiene abierto el inicio de sesion hasta que entre datos correctos

    if (validacion == true){ //Valida la entrada al sistema
    	system("clear");
    	control = true;

    }
}

/* baseDeDatos */

void baseDeDatos(/* parámetros de la conexión con MariaDB */) {
	/* code */
}
