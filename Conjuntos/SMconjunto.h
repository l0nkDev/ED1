#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#pragma once
using namespace std;

class SMconjunto {
	private:
		int cant;
		int PtrConj;
		SMemoria& m;

	public:
		int nulo = m.nulo;

		SMconjunto(SMemoria& L): m(L) {
			srand((unsigned) time(NULL));
		}

		void crear() {
			cant = 0;
			PtrConj = nulo;
		}

		void inserta(int e) {
			int dir;
			if (!pertenece(e)) {
				dir = m.new_espacio("dato,sig");
				if (dir != nulo) {
					m.poner_dato(dir, "->dato", e);
					m.poner_dato(dir, "->sig", PtrConj);
					PtrConj = dir;
					cant++;
				}
			}
		}

		void suprime(int e) {
			int dir = nulo;
			int pc = PtrConj;
			int pa = nulo;
			if (pertenece(e)) {
				while (pc != nulo) {
					if (m.obtener_dato(pc, "->dato") == e) {
						cant--;
						if (cardinal() == 0) {
							PtrConj = nulo;
						} else {
							if (pc == PtrConj) {
							PtrConj = m.obtener_dato(pc, "->sig");
							}
						}
						dir = pc;
						m.poner_dato(pa, "->sig",m.obtener_dato(pc, "->sig"));
						pc = nulo;
						m.delete_espacio(dir);

					} else {
						pa = pc;
						pc = m.obtener_dato(pc, "->sig");
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
			int pc = PtrConj;
			while (pc != nulo) {
				if (m.obtener_dato(pc, "->dato") == e) {
					resp = true;
					pc = nulo;
				} else {
					pc = m.obtener_dato(pc, "->sig");
				}
			}
			return resp;
		}


		int ordinal(int e) {
			int cont = 0;
			int pc = PtrConj;
			int resp = 0;
			while (pc != nulo) {
				resp++;
				if (m.obtener_dato(pc, "->dato")) {
					return resp;
					pc = nulo;
				} else {
					pc = m.obtener_dato(pc, "->sig");
				}
			}
			return 0;
		}

		int muestrea() {
			int lugar = 0;
			int lugarBuscado;
			int pc = PtrConj;
			int elemento = nulo;
			if (cant > 0) {
				lugarBuscado = 1 + rand() % cant;
				while (pc != nulo) {
					lugar++;
					if (lugar == lugarBuscado) {
						elemento = m.obtener_dato(pc, "->dato");
						pc = nulo;
					} else {
						pc = m.obtener_dato(pc, "->sig");
					}
				}
			}
			return elemento;
		}

		void mostrar() {
			string tmp = "{ ";
			int ctd = 0;
			int num = 0;
			if (!vacio()) {
				while (ctd < cardinal()) {

					if (pertenece(num)) {
						if (tmp != "{ ") {
							tmp += ", ";
						}
						tmp += to_string(num);
						ctd++;
					}
					num++;
				}
			}
			system("CLS");
			cout << tmp << " } \n";
			system("pause");
		}

		void uni(SMconjunto& A, SMconjunto& B) {
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

		void inter(SMconjunto& A, SMconjunto& B) {
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
