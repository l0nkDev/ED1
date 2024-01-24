#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

struct NodoMat1 {
	int fila;
	int col;
	int dato;
    NodoMat1* sig;
};

class Pmatriz1D {
	private:

		NodoMat1* PtrMatD;
		int rep;
		int dimf;
		int dimc;
		int nt;

		NodoMat1* buscar(int f, int c) {
			NodoMat1* aux = PtrMatD;
			while (aux != NULL) {
				if (f == aux->fila && c == aux->col) {
					break;
				}
				aux = aux->sig;
			}
			return aux;
		}

		NodoMat1* anterior(NodoMat1* dir) {
			NodoMat1* aux = PtrMatD;
			while (aux != NULL) {
				if (aux->sig == dir) {
					break;
				}
				aux = aux->sig;
			}
			return aux;
		}

		void suprime(NodoMat1* dir) {
			if (dir != NULL) {
				if (dir == PtrMatD) {
					PtrMatD = dir->sig;
					delete dir;
				} else {
					anterior(dir)->sig = dir->sig;
					delete dir;
				}
				nt--;
			}
		}

	public:

		void crear() {
			PtrMatD = NULL;
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
			NodoMat1* dir = buscar(f, c);
			if (dir == NULL) {
				NodoMat1* x = new NodoMat1;
				if (x != NULL) {
					if (e != rep) {
						x->fila = f;
						x->col = c;
						x->dato = e;
						x->sig = PtrMatD;
						PtrMatD = x;
						nt ++;
					}
				}
			} else {
				dir->dato = e;
				if (e == rep) {
					suprime(dir);
				}
            }
		}

		int elemento(int f, int c) {
			if ((f >= 1 && f <= dimf) && (c >= 1 && c <= dimc)) {
				NodoMat1* dir = buscar(f, c);
				if (dir != NULL) {
					return dir->dato;
				}
			}
			return rep;
		}

		void definir_valor_repetido(int valor) {
			rep = valor;
            NodoMat1* aux = PtrMatD;
			while (aux != NULL) {
				if (valor == aux->dato) {
					suprime(aux);
				}
				aux = aux->sig;
			}
		}

};
