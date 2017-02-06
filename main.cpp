#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <windows.h>

#define FILE_NAME "ficheroTexto.txt"

using namespace std;

string txtToString(){
    ifstream ficheroEntrada;
    string temp = "", s_txt = "";

    ficheroEntrada.open(FILE_NAME);
	while (!ficheroEntrada.eof()) {
		getline(ficheroEntrada, temp);
		s_txt += temp + "\n";
	}
	ficheroEntrada.close();
	return s_txt;
}

void escribir(){
    string frase;
    getline(cin, frase);
    string temp = txtToString();

    ofstream ficheroSalida;
    ficheroSalida.open(FILE_NAME);
    ficheroSalida << temp << frase;
    ficheroSalida.close();
    escribir();
}
void ver_mensajes(){
    string frase;
	frase = txtToString();
	cout << frase << "\n" << "-------------------------------------------------" << endl << "Decir: ";
}

int cambio = txtToString().length();

void up_mensajes(){// artualiza los mensajes
    for(;;){
        if(cambio != txtToString().length()){
            system("cls");
            ver_mensajes();
            cambio = txtToString().length();
        }
    }
}

int main () {
    ver_mensajes();
    //muestra los mensajes
    thread t1(up_mensajes);
    //captura nuevo mensaje
    thread t2(escribir);

    t1.join();

	return 0;
}
