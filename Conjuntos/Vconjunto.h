#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

class Vconjunto {
	private:
		static const int max = 100;
		int cant;
		int v[max];

	public:

		Vconjunto() {
			srand((unsigned) time(NULL));
		}

		void crear() {
			for (int i = 0; i < max; i++) {
				v[i] = 0;
				cant = 0;
			}
		}

		void inserta(int e) {
			if (!pertenece(e)) {
				v[e] = 1;
				cant++;
			}
		}

		void suprime(int e) {
			if (pertenece(e)) {
				v[e] = 0;
				cant--;
			}
		}

		bool vacio() {
			return cant == 0;
		}

		int cardinal() {
			return cant;
		}

		bool pertenece(int e) {
			return v[e] == 1;
		}

		int ordinal(int e) {
			int resp = 0;
			for (int i = 0; i < max; i++) {
				if (v[i] != 0) {
					resp++;
					if (e == i) {
						return resp;
					}
				}
			}
			return resp;
		}

		int muestrea() {
			int resp = 0;
			int elemento = 0;
			int lug = 1 + rand() % cant;
			for (int i = 0; i < max; i++) {
				if (v[i] != 0) {
					resp++;
						if (resp == lug) {
						elemento = i;
					}
				}
			}
			return elemento;
		}

		void mostrar() {
			string tmp = "{ ";
			int ctd = 0;
			for (int i = 0; i < max; i++) {
				if (pertenece(i)) {
					if (ctd != 0) {
						tmp += ", ";
					}
					tmp += to_string(i);
					ctd++;
				}
			}
			system("CLS");
			cout << tmp << " } \n";
			system("pause");
		}

		void uni(Vconjunto& A, Vconjunto& B) {
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

		void inter(Vconjunto& A, Vconjunto& B) {
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
