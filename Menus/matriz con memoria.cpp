#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "Matrices/SMmatrizCF.h"
#include "SMemoria.h"
using namespace std;

SMemoria mem;
SMmatrizCF matrizdispersa(mem);

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
		cout << "1) Crear memoria\n";
		cout << "2) Pedir espacio\n";
		cout << "3) Liberar espacio\n";
		cout << "4) Mostrar memoria\n";
		cout << "5) Crear matriz\n";
		cout << "6) Dimensionar matriz\n";
		cout << "7) Asignar valor por defecto\n";
		cout << "8) Poner dato\n";
		cout << "9) Mostrar matriz\n";
		cout << "10) salir\n";
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
				int tmp;
				system("CLS");
				cout << "Que espacios desea liberar?\n\n";
				cin >> tmp;
				mem.delete_espacio(tmp);
				break;
			}

			case 4: {
				mem.mostrar();
				system("pause");
				break;
			}

			case 5: {
				matrizdispersa.crear();
				break;
			}

			case 6: {
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

			case 7: {
				int valor;
				system("CLS");
				cout << "Cual valor será repetido?\n\n";
				cin >> valor;
				matrizdispersa.definir_valor_repetido(valor);
				break;
			}

			case 8: {
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

			case 9: {
				system("CLS");
				cout << mostrar() + "\n";
				system("pause");
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
