#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "SMemoria.h"
#include "Pilas/Vpila.h"
using namespace std;

Vpila pila;

void mostrar() {
	Vpila tmp;
	string space = " ";
	string aux;
	string str;
	tmp.crear();
	if (!pila.vacia()) {
		str = "-------\n | ";
        while (!pila.vacia()) {
			aux = to_string(pila.cima());
			tmp.meter(pila.cima());
			str += pila.sacar() + space*(1) + "|\n |---|\n";
			if (!pila.vacia()) {
				str += " | ";
			}
		}
		while (!tmp.vacia()) {
			pila.meter(tmp.sacar());
        }
	} else {
		str = "Pila vacia...\n\n";
	}
	system("CLS");
	cout << endl << str;
	system("pause");
}

int menu_sel() {
	int sel;
	cout << "\nRealice su seleccion...\n";
	while (true) {
	if (cin >> sel) {
		break;
	}
	cout << "Entrada invalida, intente de nuevo...\n";
	cin.sync();
	cin.clear();
	}
	return sel;
}

int main()
{
	bool run = true;
	while (run) {
		system("CLS");
		cout << "Laboratorio\n\nSeleccione una operacion\n\n";
		cout << "1) Crear pila\n";
		cout << "2) Poner pila\n";
		cout << "3) Mostrar pila\n";
		cout << "4) salir\n";
		switch (menu_sel()) {

			case 1: {
				pila.crear();
				break;
			}

			case 2: {
				char e;
				system("CLS");
				cout << "Que elemento insertar a la pila?\n\n";
				cin >> e;
				pila.meter(e);
				break;
			}

			case 3: {
				mostrar();
				break;
			}

			case 4: {
				run = false;
				break;
			}

			case 6604: {
				break;
			}
		}
	}
}
