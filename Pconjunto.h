#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

struct nodo {
	int dato;
	nodo* sig;
	int link;
};

class Pconjunto {
	private:
		int cant;
		nodo* PtrConj;

	public:

		void crear() {
			cant = 0;
			PtrConj = NULL;
		}

		void inserta(int e) {
			nodo* dir;
			if (!pertenece(e)) {
				dir = new nodo;
				if (dir != NULL) {
					dir->dato = e;
					dir->sig = PtrConj;
					PtrConj = dir;
					cant++;
				}
			}
		}

		void suprime(int e) {
			nodo* dir = NULL;
			nodo* pc = PtrConj;
			nodo* pa = pc;
			if (pertenece(e)) {
				while (pc != NULL) {
					if (pc->dato == e) {
						cant--;
						if (cardinal() == 0) {
							PtrConj == NULL;
						} else {
							if (pc == PtrConj) {
								PtrConj = pc->sig;
							}
						}
						dir = pc;
						pa->sig = pc->sig;
						pc = NULL;
						delete dir;
					} else {
						pa = pc;
						pc = pc->sig;;
					}
				}
			}
		}

		bool vacio() {
			return cant == 0;
		}

		int cardinal() {
			return cant;
		}

		bool pertenece(int e) {
			bool resp = false;
			nodo* pc = PtrConj;
			while (pc != NULL) {
				if (pc->dato == e) {
					resp = true;
					pc = NULL;
				} else {
					pc = pc->sig;
				}
			}
			return resp;
		}


		int ordinal(int e) {
			int cont = 0;
			nodo* pc = PtrConj;
			int resp = 0;
			while (pc != NULL) {
				resp++;
				if (pc->dato == e) {
					return resp;
					pc = NULL;
				} else {
					pc = pc->sig;
				}
			}
			return 0;
		}

		int muestrea() {
			int lugar = 0;
			int lugarBuscado;
			nodo* pc = PtrConj;
			int elemento = -1;
			if (cant > 0) {
				lugarBuscado = 1 + rand() % cant;
				while (pc != NULL) {
					lugar++;
					if (lugar == lugarBuscado) {
						elemento = pc->dato;
						pc = NULL;
					} else {
						pc = pc->sig;
					}
				}
			}
			return elemento;
		}

		void mostrar() {
			string tmp = "{ ";
			int ctd = 0;
			nodo* dir = PtrConj;
			if (!vacio()) {
				while (dir != NULL) {
					if (ctd != 0) {
						tmp += ", ";
					}
					tmp += to_string(dir->dato);
					ctd++;
					dir = dir->sig;
				}
			}
			system("CLS");
			cout << tmp << " } \n";
			system("pause");
		}

		void uni(Pconjunto& A, Pconjunto& B) {
			vaciar();
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

		void inter(Pconjunto& A, Pconjunto& B) {
			vaciar();
			int elem;
			while (A.cardinal() != 0) {
				elem = A.muestrea();
				if (B.pertenece(elem)) {
					inserta(elem);
					B.suprime(elem);
				}
			A.suprime(elem);
			}
			B.vaciar();
		}
};
