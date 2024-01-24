#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include "SMemoria.h"
#pragma once
using namespace std;

class SMmatriz1D {
	private:

		SMemoria& mem;
		int nulo = mem.nulo;
		int PtrMatD;
		int rep;
		int dimf;
		int dimc;
		int nt;

		int buscar(int f, int c) {
			int aux = PtrMatD;
			while (aux != nulo) {
				if (f == mem.obtener_dato(aux, "->fila") && c == mem.obtener_dato(aux, "->col")) {
					break;
				}
				aux = mem.obtener_dato(aux, "->sig");
			}
			return aux;
		}

		int anterior(int dir) {
			int aux = PtrMatD;
			while (aux != nulo) {
				if (mem.obtener_dato(aux, "->sig") == dir) {
					break;
				}
				aux = mem.obtener_dato(aux, "->sig");
			}
			return aux;
		}

		void suprime(int dir) {
			if (dir != nulo) {
				if (dir == PtrMatD) {
					PtrMatD = mem.obtener_dato(dir, "->sig");
					mem.delete_espacio(dir);
				} else {
					mem.poner_dato(anterior(dir), "->sig", mem.obtener_dato(dir, "->sig"));
					mem.delete_espacio(dir);
				}
				nt--;
			}
		}

	public:

		SMmatriz1D(SMemoria& M): mem(M) {};

		void crear() {
			PtrMatD = nulo;
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
			int dir = buscar(f, c);
			if (dir == nulo) {
				int x = mem.new_espacio("fila,col,dato,sig");
				if (x != nulo) {
					if (e != rep) {
						mem.poner_dato(x, "->fila", f);
						mem.poner_dato(x, "->col", c);
						mem.poner_dato(x, "->dato", e);
						mem.poner_dato(x, "->sig", PtrMatD);
						PtrMatD = x;
						nt ++;
					}
				}
			} else {
				mem.poner_dato(dir, "->dato", e);
				if (e == rep) {
					suprime(dir);
				}
            }
		}

		int elemento(int f, int c) {
			if ((f >= 1 && f <= dimf) && (c >= 1 && c <= dimc)) {
				int dir = buscar(f, c);
				if (dir != nulo) {
					return mem.obtener_dato(dir, "->dato");
				}
			}
			return rep;
		}

		void definir_valor_repetido(int valor) {
			rep = valor;
			int aux = PtrMatD;
			while (aux != nulo) {
				if (valor == mem.obtener_dato(aux, "->dato")) {
					suprime(aux);
				}
				aux = mem.obtener_dato(aux, "->sig");
			}
		}

};
