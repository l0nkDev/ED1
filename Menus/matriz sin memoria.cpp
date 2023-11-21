#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "Matrices/VmatrizCSR.h"
using namespace std;

VmatrizCSR matrizdispersa;

string mostrar() {
	string str = "";
	for (int i = 1; i <= matrizdispersa.dimension_fila(); i++) {
		str += "| ";
		for (int j = 1; j <= matrizdispersa.dimension_columna(); j++) {
			str += to_string(matrizdispersa.elemento(i, j)) + " ";
		}
		str += "|\n";
	}
	return str;
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
		cout << "1) Crear matriz\n";
		cout << "2) Dimensionar matriz\n";
		cout << "3) Asignar valor por defecto\n";
		cout << "4) Poner dato\n";
		cout << "5) Mostrar matriz\n";
		cout << "6) salir\n";
		switch (menu_sel()) {

			case 1: {
				matrizdispersa.crear();
				break;
			}

			case 2: {
				int f;
				int c;
				system("CLS");
				cout << "Cuantas filas debe tener la matriz?\n\n";
				cin >> f;
				system("CLS");
				cout << "Cuantas columnas debe tener la matriz?\n\n";
				cin >> c;
				matrizdispersa.dimensionar(f, c);
				break;
			}

			case 3: {
				int valor;
				system("CLS");
				cout << "Cual valor será repetido?\n\n";
				cin >> valor;
				matrizdispersa.definir_valor_repetido(valor);
				break;
			}

			case 4: {
				int f;
				int c;
				int d;
				system("CLS");
				cout << "En que fila desea insertar el dato?\n\n";
				cin >> f;
				system("CLS");
				cout << "En que columna desea insertar el dato?\n\n";
				cin >> c;
				system("CLS");
				cout << "Que dato desea insertar?\n\n";
				cin >> d;
				matrizdispersa.poner(f, c, d);
				break;
			}

			case 5: {
				system("CLS");
				cout << mostrar() + "\n";
				system("pause");
				break;
			}

			case 6: {
				run = false;
				break;
            }


			case 6604: {
				break;
			}
		}
	}
}
