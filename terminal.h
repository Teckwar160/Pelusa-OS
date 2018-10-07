#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void terminal(){
	//Variables
	bool exit = false;
	char comand[50];
	do{
		cout << user_global << "@" <<"pelusa: ";
		std::cin.getline(comand,50);

		if (comand == "exit"){
			exit = true;
		}

	}while (exit == false);
}