#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <Vlista.h>
#pragma once
using namespace std;

class Lconjunto {
	private:
		Vlista& elem;

	public:
		int nulo = elem.nulo;

		Lconjunto(Vlista& L): elem(L) {
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
			int dir;
			int p;
			int ele;
			if (pertenece(e)) {
				dir = nulo;
				p = elem.primero();
				while (p != nulo) {
					ele = elem.recupera(p);
					if (ele == e) {
						dir = p;
						p = nulo;
					} else {
						p = elem.siguiente(p);
					}
				}
				if (dir != nulo) {
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
			int p;
			int ele;
			if (!elem.vacia()) {
				p = elem.primero();
				while (p != nulo) {
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
			int p = elem.primero();
			int ele;
			if (!elem.vacia()) {
				while (p != nulo) {
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
			int dir = elem.primero();
			int direlem = nulo;
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
			int dir = elem.primero();
			if (!vacio()) {
				while (dir != nulo) {
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

		void uni(Lconjunto& A, Lconjunto& B) {
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

		void inter(Lconjunto& A, Lconjunto& B) {
			crear();
			int elem;
			while (A.cardinal() != 0) {
				elem = A.muestrea();
				if (B.pertenece(elem)) {
					inserta(elem);
				}
			A.suprime(elem);
			B.suprime(elem);
			}
		}
};
