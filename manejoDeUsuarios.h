#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
//Definicion de procesos

void bienvenida (); //Menu de bienvenida al usuario
void registro(); //Menu de registro de usuarios
void login (); //Menu para iniciar sesion de usuarios

//Zona de Variables

bool control = false; //variable que controla la entrada al sistema

//Zona de procesos

/*Bienvenida*/

void bienvenida (){
	char decision;

 while (decision == 'a','A' or decision == 'b','B'){ //Bucle que hace que solo puedan usar dos opciones
 	system("clear");
 	cout << "\tPelusa OS 0.01" << endl << endl; //Mensaje del sistema

 	cout << "Elija una opcion"<< endl;
 	cout << "\ta) Usuario Registrado" << endl     //Opciones que puede elegir
 	     << "\tb) Usuario No Registrado" << endl;
 	cout << "=> "; cin >> decision;

 	if (decision == 'A' or decision == 'a'){ //En caso de que sea la primera
 		system("clear");
 		login (); break;
 	}

 	if (decision == 'B' or decision == 'b'){ //En caso que sea la segunda
 		system("clear");
 		registro (); break;
 	}
 }
 system("clear");
}

/*Registro*/

void registro(){
	ofstream archivo; //Libreria que maneja los archivos txt
	string usuario,contra,lectura_usuario; //Usuario y contraseña escritos por el usuario
	ifstream comprobador;
	bool user_doble;
	bool salida;

	system("clear");
	do{
	user_doble = false;
	salida = false;
	archivo.open("usuarios.txt",ios::app); //Crea el archvio sino existe y si existe solo lo abre
	comprobador.open("usuarios.txt"); //Comprobador de disponibilidad del nombre de usuario
	comprobador >> lectura_usuario;


    //Condicion por si falla el docuemento
	if (archivo.fail()){
		cout << "El archivo no se puedo abrir";
		exit (1);
	}

    cout << "Nota: El usuario y la contraseña no pueden tener espacios" << endl << endl;
	cout <<"\tEscriba un nombre de usuario: ";  //Ingresa su usuario y contraseña
	cin >> usuario;
	cin.ignore();
	cout << "\tEscriba una contraseña: "; 
	cin >> contra;
	cin.ignore ();

	while(!comprobador.eof()){  //Comprobador 
		if (lectura_usuario == usuario){ //Si existe ya el nombre manda mensaje de error
			system("clear");
			cout << "Aviso: El usuario ya esta en uso" << endl << endl;
			user_doble = true;

		}
		comprobador >> lectura_usuario;
	}

	if (user_doble == false){ //Si esta disponible guarda la informacion
		archivo << usuario << " " << contra << endl << endl;
		salida = true;
	}

	archivo.close();             //Se cierra el archivo
	comprobador.close();         //Se cierra el comprobador
    }while(user_doble != false);

   if (salida == true){
   	system("clear");
   cout << "Aviso: Usuario Registrado" << endl<< endl; //Mensaje del sistema
   return bienvenida ();    //Regresa al menu de bienvenida
   }                           
}

/*Login*/ 

void login (){
	bool validacion = false; //Valida el inicio de sesion 
	bool error_inicio = false;
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
		}else{
			error_inicio = true; //Manda error si esta mal el ususario io la contraseña
		}
		archivo >> lectura_usuario; //Lectura del usuario esta linea evita errores con las contraseña de los usuarios
	}

	if (error_inicio = true){ //Mensaje de error
		system("clear");
		cout << "Aviso: Usuario io contraseña incorrectos" << endl << endl;
	}

	archivo.close (); //Cierra el archivo
    }while(validacion != true); //Mantiene abierto el inicio de sesion hasta que entre datos correctos

    if (validacion == true){ //Valida la entrada al sistema
    	system("clear");
    	control = true;
    	
    }
}
