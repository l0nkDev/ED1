#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

struct NodoC {
	int col;
	int dato;
	NodoC* sigCol;
};

struct NodoF {
	int fila;
	NodoF* sigF;
	NodoF* antF;
	NodoC* PtrCol;
};



class PmatrizCF {
	private:

		NodoF* PtrFil;
		int rep;
		int dimf;
		int dimc;
		int nt;

		NodoF* buscarF(int f) {
			NodoF* auxF = PtrFil;
			while (auxF != NULL) {
				if (f == auxF->fila) {
					break;
				}
				auxF = auxF->sigF;
			}
			return auxF;
		}

		NodoC* buscarC(NodoF* f, int c) {
			if (f == NULL) {
				return NULL;
			}
			NodoC* auxC = f->PtrCol;
			while (auxC != NULL) {
				if (c == auxC->col) {
					break;
				}
				auxC = auxC->sigCol;
			}
			return auxC;
		}

		NodoC* anterior(NodoF* dirF, NodoC* dirC) {
			NodoC* aux = dirF->PtrCol;
			while (aux != NULL) {
				if (aux->sigCol == dirC) {
					break;
				}
				aux = aux->sigCol;
			}
			return aux;
		}

		void suprime(NodoF* dirF, NodoC* dirC) {
			if (dirC != NULL) {
				if (dirC == dirF->PtrCol) {
					dirF->PtrCol = dirC->sigCol;
				} else {
					anterior(dirF, dirC)->sigCol = dirC->sigCol;
				}   
				delete dirC;
				if (dirF->PtrCol == NULL) {
					if (dirF == PtrFil) {
						PtrFil = dirF->sigF;
					} else { 
						dirF->antF->sigF = dirF->sigF;
					}
					delete dirF;
				}
				nt--;
			}
		}

	public:

		void crear() {
			PtrFil = NULL;
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
			NodoF* dirF = buscarF(f);
			NodoC* dirC = buscarC(dirF, c);
			if (dirC == NULL) {
				if (e != rep) {
					if (dirF == NULL) {
						dirF = new NodoF;
						dirF->fila = f;
						dirF->sigF = PtrFil;
						dirF->antF = NULL;
						dirF->PtrCol = NULL;
						PtrFil = dirF;
						if (dirF->sigF != NULL) {
							dirF->sigF->antF = dirF;
						}
					}
					dirC = new NodoC;
					dirC->sigCol = dirF->PtrCol;
					dirC->col = c;
					dirC->dato = e;
					dirF->PtrCol = dirC;
					nt++;
				}
			} else {
				dirC->dato = e;
				if (dirC->dato == rep) {
					suprime(dirF, dirC);
				}	
            }
        }

		int elemento(int f, int c) {
			if ((f >= 1 && f <= dimf) && (c >= 1 && c <= dimc)) {
				NodoC* dir = buscarC(buscarF(f), c);
				if (dir != NULL) {
					return dir->dato;
				}
			}
			return rep;
		}

		void definir_valor_repetido(int valor) {
			rep = valor;
			NodoF* auxF = PtrFil;
			NodoC* auxC = NULL;
			if (auxF != NULL) {
				auxC = auxF->PtrCol;
			}
			while (auxF != NULL) {
				while (auxC != NULL) {
					if (auxC->dato == rep) {
                        suprime(auxF, auxC);
					}
					auxC = auxC->sigCol;
				}
				auxF = auxF->sigF;       
				if (auxF != NULL) {
					auxC = auxF->PtrCol;
				}
			}
		}

};
