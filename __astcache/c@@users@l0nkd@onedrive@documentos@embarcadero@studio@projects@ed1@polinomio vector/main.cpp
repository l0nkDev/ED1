#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <Vpolinomio.h>
using namespace std;

Vpolinomio pol;

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
		cout << "Proyecto 4 (Lista)\n\nSeleccione una operacion\n\n1) Crear polinomio\n2) Poner termino";
		cout <<	"\n3) Mostrar polinomio\n4) Derivar\n5) Salir\n";
		switch (menu_sel()) {

		case 1: {
			pol.crear();
			break;
			}

		case 2: {
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

		case 3: {
			pol.mostrar();
			system("pause");
			break;
			}

		case 4: {
			pol.derivar();
			system("pause");
			break;
			}

		case 5: {
			run = false;
			break;
			}

		case 6604: {
			system("CLS");
            pol.debug();
			system("pause");
			break;
			}
		}
	}
}
