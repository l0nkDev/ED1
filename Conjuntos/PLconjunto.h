#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <Plista.h>
#pragma once
using namespace std;

class PLconjunto {
	private:
		Plista& elem;

	public:
		int nulo = elem.nulo;

		PLconjunto(Plista& L): elem(L) {
			srand((unsigned) time(NULL));
		}

		void crear() {
			elem.crear();
		}

		void inserta(int e) {
			if (!pertenece(e)) {
				elem.inserta(elem.primero(), e);
			}
		}

		void suprime(int e) {
			nodoL* dir;
			nodoL* p;
			int ele;
			if (pertenece(e)) {
				dir = NULL;
				p = elem.primero();
				while (p != NULL) {
					ele = elem.recupera(p);
					if (ele == e) {
						dir = p;
						p = NULL;
					} else {
						p = elem.siguiente(p);
					}
				}
				if (dir != NULL) {
					elem.suprime(dir);
				}
			}
		}

		bool vacio() {
			return elem.get_longitud() == 0;
		}

		int cardinal() {
			return elem.get_longitud();
		}

		bool pertenece(int e) {
			nodoL* p;
			int ele;
			if (!elem.vacia()) {
				p = elem.primero();
				while (p != NULL) {
					ele = elem.recupera(p);
					if (ele == e) {
						return true;
					}
					p = elem.siguiente(p);
				}
			}
			return false;
		}


		int ordinal(int e) {
			int cont = 0;
			nodoL* p = elem.primero();
			int ele;
			if (!elem.vacia()) {
				while (p != NULL) {
					cont++;
					ele = elem.recupera(p);
					if (e == ele) {
						return cont;
					}
					p = elem.siguiente(p);
				}
			}
			return 0;
		}

		int muestrea() {
			int lug = 1 + rand() % elem.get_longitud();
			nodoL* dir = elem.primero();
			nodoL* direlem = NULL;
			int cont = 0;
			for (int i = 0; i < elem.get_longitud(); i++) {
				cont++;
				if (cont == lug) {
					direlem = dir;
				}
				dir = elem.siguiente(dir);
			}
			return elem.recupera(direlem);
		}

		void mostrar() {
			string tmp = "{ ";
			int ctd = 0;
			nodoL* dir = elem.primero();
			if (!vacio()) {
				while (dir != NULL) {
					if (ctd != 0) {
						tmp += ", ";
					}
					tmp += to_string(elem.recupera(dir));
					ctd++;
					dir = elem.siguiente(dir);
				}
			}
			system("CLS");
			cout << tmp << " } \n";
			system("pause");
		}

		void uni(PLconjunto& A, PLconjunto& B) {
			crear();
			int elem;
			while (A.cardinal() != 0) {
				elem = A.muestrea();
				inserta(elem);
				A.suprime(elem);
			}
			while (B.cardinal() != 0) {
				elem = B.muestrea();
				inserta(elem);
				B.suprime(elem);
			}
		}

		void vaciar() {
			int elem;
			while (cardinal() != 0) {
				elem = muestrea();
				suprime(elem);
			}
		}

		void inter(PLconjunto& A, PLconjunto& B) {
			vaciar();
			int elem;
			while (A.cardinal() != 0) {
				elem = A.muestrea();
				if (B.pertenece(elem)) {
					inserta(elem);
				}
			A.suprime(elem);
			B.suprime(elem);
			}
			B.vaciar();
		}
};
