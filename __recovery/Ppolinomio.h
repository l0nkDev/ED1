#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

struct Nodo {
	int Co;
	int Ex;
	Nodo* Next;
};

class polinomio {
	private:
		Nodo* PPolRFV;
		int nt;

		Nodo* BuscarExponente(int exp) {
			Nodo* dir = PPolRFV;
			Nodo* dirEx;
			if (dir != NULL) {
				dirEx = NULL;
				while (dir != NULL && dirEx == NULL) {
					if (dir->Ex == exp) {
						dirEx = dir;
					}
					dir = dir->Next;
				}
				return dirEx;
			} else {
				cout << "buscarexponente: no existe ese termino";
				return NULL;
			}
		}

		Nodo* BuscarTerminoN(int I) {
			Nodo* dir = PPolRFV;
			Nodo* dirTer;
			int nut;
			if (dir != NULL) {
				dirTer = NULL;
				nut = 0;
				while (dir != NULL && dirTer == NULL) {
					nut ++;
					if (nut == I) {
						dirTer = dir;
					}
					dir = dir->Next;
				}
				return dirTer;
			} else {
				cout << "buscarterminon: no existe terminos";
				return NULL;
			}
        }

	public:

		Nodo* fin() {
			Nodo* x;
			Nodo* PtrFin;
			if (EsCero()) {
				cout << "fin: lista vacia";
			} else {
				x = PPolRFV;
				while (x != NULL) {
					PtrFin = x;
					x = x->Next;
				}
				return PtrFin;
			}
		}

		Nodo* anterior(Nodo* p) {
			Nodo* x;
			Nodo* ant;
			if (EsCero()) {
				cout << "anterior: lista vacia";
			} else {
				if (p == PPolRFV) {
					cout << "anterior: direccion primera err";
				} else {
					x = PPolRFV;
					ant = NULL;
					while (x != NULL) {
						if (x == p) {
							return ant;
						}
						ant = x;
						x = x->Next;
					}
				}
			}
		}

		void suprime(Nodo* p) {
			Nodo* x;
			Nodo* ant;
			if (nt == 0) {
				cout << "suprime: lista vacia";
			}
			if (p == PPolRFV) {
				x = PPolRFV;
				PPolRFV = PPolRFV->Next;
			} else {
				ant = anterior(p);
				if (p == fin()) {
					ant->Next = NULL;
				} else {
					ant->Next = p->Next;
				}
			}
			nt --;
			delete p;
		}

		void crear() {
			nt = 0;
			PPolRFV = NULL;
		}

		bool EsCero() {
			return (nt == 0);
		}

		int grado() {
			Nodo* dir = PPolRFV;
			int MaxG;
			if (dir != NULL) {
				MaxG = dir->Ex;
				while (dir != NULL) {
					if (dir->Ex > MaxG) {
						MaxG = dir->Ex;
					}
					dir = dir->Next;
				}
				return MaxG;
			} else {
				cout << "grado: no existe ese termino";
				return NULL;
			}
		}

		int coeficiente(int exp) {
			Nodo* dir = BuscarExponente(exp);
			if (dir != NULL) {
				return dir->Co;
			} else {
				cout << "coeficiente: no existe ese termino";
				return NULL;
			}
		}

		void asignarcoeficiente(int coef, int exp) {
			Nodo* dir = BuscarExponente(exp);
			if (dir != NULL) {
				dir->Co = coef;
				if (coef == 0) {
					suprime(dir);
				}
			} else {
				cout << "asignarcoeficiente: no existe ese termino";
			}
		}

		void poner_termino(int coef, int exp) {
			Nodo* existe = BuscarExponente(exp);
			Nodo* aux;
			int nttmp = nt;
			if (existe == NULL) {
				aux = new Nodo;
				if (aux != NULL) {
					if (nt == 0 || PPolRFV->Ex < exp){
					aux->Co = coef;
					aux->Ex = exp;
					aux->Next = PPolRFV;
					PPolRFV = aux;
					nt ++;
					} else {
						Nodo* tmp = PPolRFV;
						Nodo* ant = PPolRFV;
						while (tmp != NULL) {
							if (tmp->Ex < exp && ant->Ex > exp) {
								ant->Next = aux;
								aux->Co = coef;
								aux->Ex = exp;
								aux->Next = tmp;
								nt++;
								tmp = NULL;
							} else {
							ant = tmp;
							tmp = tmp->Next;
							}
						}
						if (nttmp == nt) {
							fin()->Next = aux;
							aux->Ex = exp;
							aux->Co = coef;
							aux->Next = NULL;
							nt++;
						}
					}
				} else {
					cout << "poner_termino: error espacio memoria";
				}
			} else {
				int nuevocoef = existe->Co + coef;
				existe->Co = nuevocoef;
				if (nuevocoef == 0) {
					suprime(existe);
					nt--;
				}
			}
		}

		int numero_terminos() {
			return nt;
		}

		int exponente(int nroter) {
			Nodo* dir = BuscarTerminoN(nroter);
			if (dir != NULL) {
				return dir->Ex;
			} else {
				cout << "exponente: no existe ese termino";
				return NULL;
			}
		}

		void mostrar() {
			int ex;
			int co;
			Nodo* i = PPolRFV;
			string tmp = "";
			while (i != NULL) {
				ex = i->Ex;
				co = i->Co;
				i = i->Next;
				if (tmp != "" && co > 0) {
						tmp += "+";
				}
				if (co != 1 || ex == 0) {
					tmp += to_string(co);
				}
				if (ex > 0) {
					if (ex == 1) {
						tmp += "x ";
					} else {
						tmp += "x^(" + to_string(ex) + ") ";
					}
				}
			}
			system("CLS");
			cout << tmp << endl;
		}


};
