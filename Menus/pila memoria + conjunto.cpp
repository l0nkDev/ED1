#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "SMemoria.h"
#include "Pilas/SMpila.h"
#include "Conjuntos/SMconjunto.h"
using namespace std;

SMemoria mem;
SMconjunto conj(mem);
SMpila pila(mem);

void mostrar() {
	SMpila tmp(mem);
	string space = " ";
	string aux;
	string str;
	tmp.crear();
	if (!pila.vacia()) {
		str = "---------\n |";
        while (!pila.vacia()) {
			aux = to_string(pila.cima());
			tmp.meter(pila.cima());
			str += to_string(pila.sacar()) + space*(5 - aux.length()) + "|\n |-----|\n";
			if (!pila.vacia()) {
				str += " |";
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
		cout << "1) Crear memoria\n";
		cout << "2) Pedir espacio\n";
		cout << "3) Crear pila\n";
		cout << "4) Poner pila\n";
		cout << "5) Mostrar memoria\n";
		cout << "6) Crear conjunto\n";
		cout << "7) Poner elemento\n";
		cout << "8) Mostrar conjunto\n";
		cout << "9) Mostrar pila\n";
		cout << "10) Salir\n";
		switch (menu_sel()) {

			case 1: {
				mem.crear();
				break;
			}

			case 2: {
				string tmp;
				system("CLS");
				cout << "Que espacios desea reservar? [var1,var2,var3]\n\n";
				cin >> tmp;
				mem.new_espacio(tmp);
				break;
			}

			case 3: {
				pila.crear();
				break;
			}

			case 4: {
				int e;
				system("CLS");
				cout << "Que elemento insertar a la pila?\n\n";
				cin >> e;
				pila.meter(e);
				break;
			}

			case 5: {
				mem.mostrar();
				system("pause");
				break;
			}

			case 6: {
				conj.crear();
				break;
			}

			case 7: {
				int e;
				system("CLS");
				cout << "Que elemento insertar al conjunto?\n\n";
				cin >> e;
				conj.inserta(e);
				break;
			}

			case 8: {
				conj.mostrar();
				break;
			}

			case 9: {
				mostrar();
				break;
			}

			case 10: {
				run = false;
				break;
			}


			case 6604: {
				break;
			}
		}
	}
}
