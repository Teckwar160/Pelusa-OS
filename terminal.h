/*Esta librería contiene a la terminal y los comandos que se pueden utilizar en ella, la función principal es la terminal y manda a llamar a los comandos solicitados. Existen distintos archivos de texto dentro de la carpeta llamada terminalComandos en donde cada archivo de texto corresponde a la respectiva descripción de un comando.*/

//Zona de prototipos

void help();
void createDir();
void deleteDir();
void helpCreateDir();
void createFile();
void deleteFile();
void helpCreateFile();
void clean();
void helpClean();
void helpDeleteFile();


//TODO: Hay que trabajar en la creación de directorios

//Variables globales (para esta librería)
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
		}else if (comando=="clean"){
			clean();
			cout << "\n";
		}else if (comando=="?clean"){
			helpClean();
			cout << "\n";
		}else if (comando == "?"){
			help();
			cout << "\n";
		}else if (comando == "createDir"){
			createDir();
			cout << "\n";
		}else if (comando == "deleteDir"){
			deleteDir();
			cout << "\n";
			cout << "\n";
		}else if (comando == "?createDir" || comando == "?deleteDir"){
			helpCreateDir();
			cout << "\n";
		}else if (comando == "createFile"){
			createFile();
			cout << "\n";
		}else if (comando == "deleteFile"){
			deleteFile();
			cout << "\n";
		}else if (comando == "?createFile"){
			helpCreateFile();
			cout << "\n";
		}else if(comando=="?deleteFile"){
			helpDeleteFile();
			cout << "\n";
		}else{
			cout << "\nEl comando no se reconoce, intente con '?' para obtener ayuda"<< endl;
			cout << "\n";
		}

	}while(salida != true);

	cout << "\n" << endl;
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

// Enlista los archivos y directorios
void list(){

}

//Limpia la pantalla
void clean(){
	system("clear");
}

void helpClean(){
	cout << "\n\tclean: Limpia la pantalla" << endl;
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
	string rutafichero;
	ofstream archivo;
	string nombre;
	string carpetaFichero = "ficheros/";

	cout << endl << "Ingresa el nombre del archivo: ";
	cin >> nombre;
	cin.ignore();

	rutafichero = carpetaFichero+nombre+".txt";
	archivo.open(rutafichero,ios::out);

	if (archivo.fail()){
		cout << "El archivo no se pudo abrir";
        exit(1);		
	}
	archivo.close();	
   
	if(!archivo.fail()){
		 system("clear");
		cout << endl<< "El archivo se creo con exito" << endl << endl;
	}


}

//Comando deleteFile permite eliminar un archivo 
void deleteFile(){
	string name;
    string rutaFichero;	
	string carpetaFichero = "ficheros/";
	cout << "Ingresa el nombre del archivo a eliminar: ";
    cin >> name; 
	cin.ignore();

	rutaFichero = carpetaFichero + name + ".txt";

   remove(rutaFichero.c_str());

   cout << "El archivo se elimino correctamente" << endl << endl;
}

//Comando ?createFile brinda información sobre la creación de archivos
void helpCreateFile(){
	cout << "\n\tcreateFile: Crea un archivo de texto plano" << endl;
}

void helpDeleteFile(){
	cout << "\n\tdeleteFile: Elimina un archivo de texto plano" << endl;
}


