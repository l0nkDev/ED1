#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <Ppolinomio.h>
using namespace std;

// Nodo: Co, Ex, Next; Atributo: PPolRFV (Raúl Farell Vaca) = Nodo*;
//



polinomio poli;

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
		cout << "Segundo ensayo\n\nSeleccione una operacion\n\n";
		cout << "1) Crear polinomio\n";
		cout <<	"2) Poner termino\n";
		cout <<	"3) Mostrar grado\n";
		cout <<	"4) Mostrar Polinomio\n";
		cout <<	"5) Salir\n";
		cout << "\n";
		switch (menu_sel()) {

			case 1: {
				poli.crear();
				break;
			}

			case 2: {
				int exp;
				int coef;
				system("CLS");
				cout << "Que coeficiente desea insertar\n\n";
				cin >> coef;
				cout << "Que exponente desea insertar\n\n";
				cin >> exp;
				poli.poner_termino(coef, exp);
				break;
			}

			case 3: {
				system("CLS");
				cout << poli.grado() << endl;
				system("pause");
				break;
			}

			case 5: {
				run = false;
				break;
			}

			case 4: {
				poli.mostrar();
				system("pause");
				break;
			}

			case 6605: {
				break;
			}
		}
	}
}
