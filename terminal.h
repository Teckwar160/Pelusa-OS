/*Esta librería contiene a la terminal y los comandos que se pueden utilizar en ella, la función principal es la terminal y manda a llamar a los comandos solicitados. Existen distintos archivos de texto dentro de la carpeta llamada terminalComandos en donde cada archivo de texto corresponde a la respectiva descripción de un comando.*/

//Zona de prototipos

void help();
void createDir();
void deleteDir();
void helpCreateDir();
void createFile();
void deleteFile();

//TODO: Hay que trabajar en la creación de directorios

//Variables globales
	//Esta variables permite modificar la ruta del archivo sin tener que modificar en todo el programa ruta por ruta
	string rutaComando = "terminalComandos/comandos.txt";

//Función principal
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
		}else if (comando == "?"){
			help();
		}else if (comando == "createDir"){
			createDir();
		}else if (comando == "deleteDir"){
			deleteDir();
		}else if (comando == "?createDir" || comando == "?deleteDir"){
			helpCreateDir();
		}else if (comando == "createFile"){
			createFile();
		}else if (comando == "deleteFile"){
			deleteFile();
		}else {
			cout << "\nEl comando no se reconoce, intente con '?' para obtener ayuda"<< endl;
			cout << "\n";
		}

	}while(salida != true);
}

void help(){
	ifstream archivo;
	string texto;
	archivo.open(rutaComando,ios::in);
	if(archivo.fail()){
		cout << endl << "No se pudo abrir el archivo" << endl << endl;
	}
	while(!archivo.eof()){
		getline(archivo,texto);
		cout << texto << endl;
	}
	archivo.close();
}

//Comando createrDir permite crear un directorio
void createDir(){

	//Variables
	string comando;
	//bool salida=false;

	//salida = false;
	string directorio; 

		cout << "pelusa@pelusa:~ Por favor, ingresa el directorio que quieres crear:" << endl;
		cout << "\npelusa@pelusa:~ ";
		cin >> directorio; 


}

//Comando ?createDir brinda información sobre el manejo de directorios
void helpCreateDir(){

}

//Comando deleteDir permite eliminar un directorio
void deleteDir(){

}

//Comando createFile permite crear un archivo
void createFile(){

}

//Comando deleteFile permite eliminar un archivo 
void deleteFile(){

}
