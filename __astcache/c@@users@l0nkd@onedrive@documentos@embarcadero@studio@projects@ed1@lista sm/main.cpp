#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#include <SMlista.h>
#include <Vlista.h>
using namespace std;

SMemoria memoria;
Vlista lista;


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

int _tmain(int argc, _TCHAR* argv[])
{
	bool run = true;
	while (run) {
		system("CLS");
		cout << "Laboratorio 3\n\nSeleccione una operacion\n\n1) Crear Memoria\n2) Pedir espacio";
		cout <<	"\n3) Liberar espacio\n4) Crear lista\n5) Insertar primero\n6) Insertar siguiente primero\n7) Insertar anterior fin\n8) Mostrar memoria\n9) Mostrar lista\n";
		switch (menu_sel()) {
		case 1: {
			memoria.crear();
			break;
			}

		case 2: {
			string tmp;
			system("CLS");
			cout << "Que IDs va a reservar [Formato: var1,var2,var3,...]\n\n";
			cin >> tmp;
			memoria.new_espacio(tmp);
			break;
			}

		case 3: {
			int tmp;
			system("CLS");
			cout << "Que direccion desea eliminar\n\n";
			cin >> tmp;
			memoria.delete_espacio(tmp);
			break;
			}

		case 4: {
			lista.crear();
			break;
			}

		case 5: {
			int tmp;
			system("CLS");
			cout << "Que dato desea insertar\n\n";
			cin >> tmp;
			lista.inserta(lista.primero(), tmp);
			break;
			}

		case 6: {
			int tmp;
			system("CLS");
			if (lista.get_longitud() < 2) {
				cout << "Lista demasiado pequeña\n\n";
				system("pause");
				} else {
					cout << "Que dato desea insertar\n\n";
					cin >> tmp;
					lista.inserta(lista.siguiente(lista.primero()), tmp);
				}
			break;
			}

		case 7: {
			int tmp;
			system("CLS");
			if (lista.get_longitud() < 2) {
				cout << "lista demasiado pequeña\n\n";
				system("pause");
				} else {
					cout << "Que dato desea insertar\n\n";
					cin >> tmp;
					lista.inserta(lista.anterior(lista.fin()), tmp);
					}
			break;
			}

		case 8: {
			system("CLS");
			memoria.mostrar();
			system("pause");
			break;
			}

		case 9: {
			system("CLS");
			lista.mostrar();
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
