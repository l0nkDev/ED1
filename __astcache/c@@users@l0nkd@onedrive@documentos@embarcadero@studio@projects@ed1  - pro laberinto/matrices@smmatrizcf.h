#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include "SMemoria.h"
#pragma once
using namespace std;

class SMmatrizCF {
	private:

		SMemoria& mem;
		int nulo = mem.nulo;
		int PtrFil;
		int rep;
		int dimf;
		int dimc;
		int nt;

		int buscarF(int f) {
			int auxF = PtrFil;
			while (auxF != nulo) {
				if (f == mem.obtener_dato(auxF, "->fila")) {
					break;
				}
				auxF = mem.obtener_dato(auxF, "->sigF");
			}
			return auxF;
		}

		int buscarC(int f, int c) {
			if (f == nulo) {
				return nulo;
			}
			int auxC = mem.obtener_dato(f, "->PtrCol");
			while (auxC != nulo) {
				if (c == mem.obtener_dato(auxC, "->col")) {
					break;
				}
				auxC = mem.obtener_dato(auxC, "->sigCol");
			}
			return auxC;
		}

		int anterior(int dirF, int dirC) {
			int aux = mem.obtener_dato(dirF, "->PtrCol");
			while (aux != nulo) {
				if (mem.obtener_dato(aux, "->sigCol") == dirC) {
					break;
				}
				aux = mem.obtener_dato(aux, "->sigCol");
			}
			return aux;
		}

		void suprime(int dirF, int dirC) {
			if (dirC != nulo) {
				if (dirC == mem.obtener_dato(dirF, "->PtrCol")) {
					mem.poner_dato(dirF, "->PtrCol", mem.obtener_dato(dirC, "->sigCol"));
				} else {
					mem.poner_dato(anterior(dirF, dirC), "->sigCol", mem.obtener_dato(dirC, "->sigCol"));
				}
				mem.delete_espacio(dirC);
				if (mem.obtener_dato(dirF, "->PtrCol") == nulo) {
					if (dirF == PtrFil) {
						PtrFil = mem.obtener_dato(dirF, "->sigF");
					} else {
						mem.poner_dato(mem.obtener_dato(dirF, "->antF"), "->sigF", mem.obtener_dato(dirF, "->sigF"));
					}
					mem.delete_espacio(dirF);
				}
				nt--;
			}
		}

	public:

		SMmatrizCF(SMemoria& M): mem(M) {};

		void crear() {
			PtrFil = nulo;
			dimf = 0;
			dimc = 0;
			rep = 0;
			nt = 0;
		}

		void dimensionar(int nf, int nc) {
			dimf = nf;
			dimc = nc;
		}

		int dimension_fila() {
			return dimf;
		}

		int dimension_columna() {
			return dimc;
		}

		void poner (int f, int c, int e) {
			int dirF = buscarF(f);
			int dirC = buscarC(dirF, c);
			if (dirC == nulo) {
				if (e != rep) {
					if (dirF == nulo) {
						dirF = mem.new_espacio("fila,sigF,antF,PtrCol");
						mem.poner_dato(dirF, "->fila", f);
						mem.poner_dato(dirF, "->sigF", PtrFil);
						mem.poner_dato(dirF, "->antF", nulo);
						mem.poner_dato(dirF, "->PtrCol", nulo);
						PtrFil = dirF;
						if (mem.obtener_dato(dirF, "->sigF") != nulo) {
							mem.poner_dato(mem.obtener_dato(dirF, "->sigF"), "->antF", dirF);
						}
					}
					dirC = mem.new_espacio("sigCol,col,dato,PtrCol");
					mem.poner_dato(dirC, "->sigCol", mem.obtener_dato(dirF, "->PtrCol"));
					mem.poner_dato(dirC, "->col", c);
					mem.poner_dato(dirC, "->dato", e);
					mem.poner_dato(dirF, "->PtrCol", dirC);
					nt++;
				}
			} else {
				mem.poner_dato(dirC, "->dato", e);
				if (mem.obtener_dato(dirC, "->dato") == rep) {
					suprime(dirF, dirC);
				}	
            }
        }

		int elemento(int f, int c) {
			if ((f >= 1 && f <= dimf) && (c >= 1 && c <= dimc)) {
				int dir = buscarC(buscarF(f), c);
				if (dir != nulo) {
					return mem.obtener_dato(dir, "->dato");
				}
			}
			return rep;
		}

		void definir_valor_repetido(int valor) {
			rep = valor;
			int auxF = PtrFil;
			int auxC = nulo;
			if (auxF != nulo) {
				auxC = mem.obtener_dato(auxF, "->PtrCol");
			}
			while (auxF != nulo) {
				while (auxC != nulo) {
					if (mem.obtener_dato(auxC, "->dato") == rep) {
                        suprime(auxF, auxC);
					}
					auxC = mem.obtener_dato(auxC, "->sigCol");
				}
				auxF = mem.obtener_dato(auxF, "->sigF");
				if (auxF != nulo) {
					auxC = mem.obtener_dato(auxF, "->PtrCol");
				}
			}
		}

};
