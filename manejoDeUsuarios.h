#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;
//Definicion de procesos
void bienvenida (); //Menu de bienvenida al usuario
void registro(); //Menu de registro de usuarios
void login (); //Menu para iniciar sesion de usuarios

//Zona de Variables

bool control = false; //variable que controla la entrada al sistema
char user_global[20];

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
 	cin.ignore();

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
	ifstream comprobador; //comprueba si ya exite el usuario
	char usuario[20],contra[20]; //Usuario y contraseña escritos por el usuario
	string lectura_usuario;
	bool user_doble;
	bool salida;
	short largo,i,a=0;
	short largo2,i2,a2=0;

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

   cout << "Aviso: Si utiliza espacios estos no se tomaran en cuenta" << endl << endl;
	cout <<"\tEscriba un nombre de usuario: ";  //Ingresa su usuario y contraseña

	std::cin.getline(usuario,20); //Lee el usuario
	largo = strlen(usuario); //calcula el tamaño del usuario
	while(usuario[a]!='\0'){  //bucle que quita los espacios si los hay
		if (usuario[a]==' '){

			for(i=a;i<largo;i++){
				usuario[i]=usuario[i+1];
			}
			largo--;
		}
		a++;
	}


	cout << "\tEscriba una contraseña: "; 
	std::cin.getline(contra,20);
	largo2 = strlen(contra);
	while(contra[a2]!='\0'){ //bucle que quita los espacios si los hay
		if (contra[a2]==' '){

			for(i2=a2;i2<largo2;i2++){
				contra[i2]=contra[i2+1];
			}
			largo2--;
		}
		a2++;
	}


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
    archivo >>user_global; //lectura del usuario global
	cout <<"\tUsuario: "; 
	cin >> usuario; 
	cin.ignore ();
	cout <<"\tContraseña: "; 
	cin >> contra; 
	cin.ignore ();

	while(!archivo.eof()){ //Bucle que mientras el archivo no se haya leido completamente haga
        archivo >> lectura_contra; //LEctura adelantada de la contraseña
		if (lectura_usuario == usuario and lectura_contra == contra){ //Si coinciden valida el inisio de sesion
			validacion = true; 
		}else{
			error_inicio = true; //Manda error si esta mal el ususario io la contraseña
		}
		archivo >> lectura_usuario; //Lectura del usuario esta linea evita errores con las contraseña de los usuarios
		archivo >>user_global;
	}

	if (error_inicio = true){ //Mensaje de error
		system("clear");
		cout << "Aviso: Usuario i/o contraseña incorrectos" << endl << endl;
	}

	archivo.close (); //Cierra el archivo
    }while(validacion != true); //Mantiene abierto el inicio de sesion hasta que entre datos correctos

    if (validacion == true){ //Valida la entrada al sistema
    	system("clear");
    	control = true;
    	
    }
}

