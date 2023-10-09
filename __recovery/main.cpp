#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#include <Vlista.h>
#include <Lpolinomio.h>
#include <Vconjunto.h>
#include <Lconjunto.h>
#include <SMconjunto.h>
using namespace std;

SMemoria mem;
SMconjunto A(mem);
SMconjunto B(mem);
SMconjunto C(mem);

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
		cout << "Laboratorio\n\nSeleccione una operacion\n\n1) Crear memoria\n2) Reservar espacio memoria\n3) Crear conj A\n4) Crear conj B\n5) Crear conj C\n6) Insertar elemento\n7) Mostrar conjunto\n8) Unir A U B y poner en C el resultado";
		cout <<	"\n9) Intersectar A ^ B y poner en C el resultado\n10) Salir\n";
		switch (menu_sel()) {

			case 1: {
				mem.crear();
				break;
			}

			case 2: {
				string tmp;
				system("CLS");
				cout << "Que espacio desea reservar? [var1,var2,var3]\n\n";
				cin >> tmp;
				mem.new_espacio(tmp);
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
		}
	}
}
