#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#include <Vlista.h>
#include <Lpolinomio.h>
#include <Vconjunto.h>
#include <Lconjunto.h>
using namespace std;

Vlista lisA;
Vlista lisB;
Vlista lisC;
Lconjunto A(lisA);
Lconjunto B(lisB);
Lconjunto C(lisC);

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
		cout << "Laboratorio\n\nSeleccione una operacion\n\n1) Crear conj A\n2) Crear conj B\n3) Crear conj C\n4) Insertar elemento\n5) Mostrar conjunto\n6) Unir A U B y poner en C el resultado";
		cout <<	"\n7) Intersectar A ^ B y poner en C el resultado\n8) Salir\n";
		switch (menu_sel()) {

			case 1: {
				A.crear();
				break;
			}

			case 2: {
				B.crear();
				break;
			}

			case 3: {
				C.crear();
				break;
			}

			case 4: {
				int ans;
				int e;
				string A_ans = "A";
				string B_ans = "B";
				string C_ans = "C";
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

			case 5: {
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

			case 6: {
				C.uni(A, B);
				break;
			}

			case 7: {
				C.inter(A, B);
				break;
			}

			case 8: {
				run = false;
				break;
			}

			case 6604: {
				break;
			}
		}
	}
}
