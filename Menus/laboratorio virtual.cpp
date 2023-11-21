#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "Pconjunto.h"
using namespace std;

Pconjunto A;
Pconjunto B;
Pconjunto C;

void inter(Pconjunto &A, Pconjunto &B, Pconjunto &C) {
	int elem;
	while (A.cardinal() != 0) {
		elem = A.muestrea();
		if (B.pertenece(elem)) {
			C.inserta(elem);
			B.suprime(elem);
		}
		A.suprime(elem);
	}
}

int main()
{
    A.crear();
    B.crear();
    C.crear();
	bool insA = true;
	bool insB = true;
	string elem;
	while (insA) {
	    #ifdef _WIN32
            system("CLS");
        #else
            system("clear");
		#endif
		cout << "Laboratorio Virtual\n\n" << "Conjunto A: ";
		A.mostrar();
		cout << endl << "Conjunto B: ";
		B.mostrar();
		cout << endl;
		cout << "Introduzca un numero a insertar al conjunto A o 'sig' para continuar la ejecución.\n\n";
		cin >> elem;
		cin.sync();
		cin.clear();
		if (elem == "sig") {
			insA = false;
		} else {
			A.inserta(stoi(elem));
		}
	}
	while (insB) {
	    #ifdef _WIN32
            system("CLS");
        #else
            system("clear");
		#endif
		cout << "Laboratorio Virtual\n\n" << "Conjunto A: ";
		A.mostrar();
		cout << endl << "Conjunto B: ";
		B.mostrar();
		cout << endl;
		cout << "Introduzca un numero a insertar al conjunto B o 'sig' para continuar la ejecución.\n\n";
		cin >> elem;
		cin.sync();
		cin.clear();
		if (elem == "sig") {
			insB = false;
		} else {
			B.inserta(stoi(elem));
		}
	}
	#ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
	cout << "Laboratorio Virtual\n\n";
	cout << "Conjunto A: ";
	A.mostrar();
	cout << endl;
	cout << "Conjunto B: ";
	B.mostrar();
	cout << endl;
	inter(A, B, C);
	cout << endl << "Interseccion de A y B en el conjunto C: ";
	C.mostrar();
	cout << "\n\n";
	int c = getchar();
	return 0;
}
