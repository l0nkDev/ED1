#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#include <SMlista.h>
#include <SMLpolinomio.h>
using namespace std;

SMemoria memoria;
SMlista lis(memoria);
SMLpolinomio pol(lis);

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
		cout << "Laboratorio\n\nSeleccione una operacion\n\n1) Crear memoria\n2) Pedir espacio\n3) Liberar espacio\n4) Crear lista\n5) Poner dir inicio\n6) Mostrar lista";
		cout <<	"\n7) Mostrar memoria\n8) Crear polinomio\n9) Poner termino\n10) Mostrar polinomio\n11) Evaluar\n12) Salir\n";
		switch (menu_sel()) {

		case 1: {
			memoria.crear();
			break;
			}

		case 2: {
			string tmp;
			system("CLS");
			cout << "Que espacio desea reservar? [var1,var2,var3]\n\n";
			cin >> tmp;
			memoria.new_espacio(tmp);
			break;
			}

		case 3: {
			int tmp;
			system("CLS");
			cout << "Que dir desea liberar?\n\n";
			cin >> tmp;
			memoria.delete_espacio(tmp);
			break;
			}

		case 4: {
			lis.crear();
			break;
			}

		case 5: {
			int tmp;
			system("CLS");
			cout << "Que dato desea insertar?\n\n";
			cin >> tmp;
			lis.inserta(lis.primero(), tmp);
			break;
			}

		case 6: {
			system("CLS");
			lis.mostrar();
			system("pause");
			break;
			}

		case 7: {
			system("CLS");
			memoria.mostrar();
			system("pause");
			break;
			}

		case 8: {
			pol.crear();
			memoria.crear();
			break;
			}

		case 9: {
			int co;
			int ex;
			system("CLS");
			cout << "Coeficiente del termino que desea insertar\n\n";
			cin >> co;
			cout << "Exponente del termino que desea insertar\n\n";
			cin >> ex;
			pol.poner_termino(co, ex);
			break;
			}

		case 10: {
			pol.mostrar();
			system("pause");
			break;
			}

		case 11: {
			int tmp;
			string temP;
			system("CLS");
			cout << "que x desea evaluar\n\n";
			cin >> tmp;
			temP = to_string(pol.evaluar(tmp));
			system("CLS");
			cout << endl << endl << temP << endl;
			system("pause");
			break;
			}

		case 12: {
			run = false;
			break;
			}

		case 6604: {
			int tmp;
			string temP;
			system("CLS");
			memoria.mostrar();
			system("pause");
			lis.mostrar();
			cout << "que x desea evaluar\n\n";
			cin >> tmp;
			temP = to_string(pol.evaluar(tmp));
			system("CLS");
			cout << endl << endl << temP << endl;
			system("pause");
			break;
			}
		}
	}
}
