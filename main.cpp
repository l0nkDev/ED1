#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#include <Vlista.h>
#include <Plista.h>
#include <Lpolinomio.h>
#include <Vconjunto.h>
#include <Lconjunto.h>
#include <Pconjunto.h>
#include <PLconjunto.h>
#include <SMconjunto.h>
using namespace std;

SMemoria mem;
Plista lisA;
Plista lisB;
Plista lisC;
PLconjunto A(lisA);
PLconjunto B(lisB);
PLconjunto C(lisC);

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
		cout << "Laboratorio\n\nSeleccione una operacion\n\n";
		cout <<	"1) Crear listas\n";
		cout <<	"2) Mostrar listas\n";
		cout <<	"3) Crear conj A\n";
		cout <<	"4) Crear conj B\n";
		cout <<	"5) Crear conj C\n";
		cout <<	"6) Insertar elemento\n";
		cout <<	"7) Mostrar conjunto\n";
		cout <<	"8) Unir A U B y poner en C el resultado\n";
		cout <<	"9) Intersectar A ^ B y poner en C el resultado\n";
		cout <<	"10) Salir\n";
		cout << "\n";
		switch (menu_sel()) {

			case 1: {
				lisA.crear();
				lisB.crear();
				lisC.crear();
				break;
			}

			case 2: {
				lisA.mostrar();
				cout << "Lista A\n\n";
				system("pause");
				lisB.mostrar();
				cout << "Lista B\n\n";
				system("pause");
				lisC.mostrar();
				cout << "Lista C\n\n";
				system("pause");

				break;
			}

			case 3: {
				A.crear();
				break;
			}

			case 4: {
				B.crear();
				break;
			}

			case 5: {
				C.crear();
				break;
			}

			case 6: {
				int ans;
				int e;
				system("CLS");
				cout << "Que dato desea insertar\n\n";
				cin >> e;
				cout << "\n\nSeleccione el conjunto A (1), B (2) o C (3).\n\n";
				cin >> ans;
				switch (ans) {

					default: {
						cout << "Selección inválida/n/n";
						system("pause");
						break;
					}

					case 1: {
						A.inserta(e);
						break;
					}

					case 2: {
						B.inserta(e);
						break;
					}
					case 3: {
						C.inserta(e);
						break;
					}
				}
				break;
			}

			case 7: {
				int ans;
				system("CLS");
				cout << "\n\nSeleccione el conjunto A (1), B (2) o C (3).\n\n";
				cin >> ans;
				switch (ans) {

					default: {
						cout << "Selección inválida/n/n";
						system("pause");
						break;
					}

					case 1: {
						A.mostrar();
						break;
					}

					case 2: {
						B.mostrar();
						break;
					}
					case 3: {
						C.mostrar();
						break;
					}
				}
				break;
			}

			case 8: {
				C.uni(A, B);
				break;
			}

			case 9: {
				C.inter(A, B);
				break;
			}

			case 10: {
				run = false;
				break;
			}

			case 6604: {
				mem.mostrar();
				system("pause");
				break;
			}

			case 6605: {
				A.suprime(5);
			}
		}
	}
}
