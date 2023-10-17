#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#pragma once
using namespace std;

struct nodoL {
	int elemento;
	nodoL* sig;
	int link;
};

class Plista {
	private:
		nodoL* ptr_elementos;
		int longitud;

	public:

		int nulo = -1;

		void crear() {
			ptr_elementos = NULL;
			longitud = 0;
		}

		bool vacia() {
			return (longitud == 0);
		}

		nodoL* fin() {
			nodoL* x;
			nodoL* PtrFin;
			if (vacia()) {
				cout << "fin: lista vacia";
			} else {
				x = ptr_elementos;
				while (x != NULL) {
					PtrFin = x;
					x = x->sig;
				}
				return PtrFin;
			}
		}

		nodoL* primero() {
			if (!vacia()) {
				return ptr_elementos;
			} else {
				cout << "primero: lista vacia";
			}
		}

		nodoL* siguiente(nodoL* p) {
			if (vacia() || p == NULL) {
				cout << "siguiente: lista vacia";
				return NULL;
			} else {
				if (p == fin()) {
					cout << "siguiente: DireccionErr";
					return NULL;
				} else {
					return p->sig;
				}
			}
		}

		nodoL* anterior(nodoL* p) {
			nodoL* x;
			nodoL* ant;
			if (vacia()) {
				cout << "anterior: lista vacia";
				return NULL;
			} else {
				if (p == primero()) {
					cout << "anterior: direccion primera err";
					return NULL;
				} else {
					x = ptr_elementos;
					ant = NULL;
					while (x != NULL) {
						if (x == p) {
							return ant;
						}
						ant = x;
						x = x->sig;
					}
				}
			}
		}

		int recupera(nodoL* p) {
			if (vacia()) {
				cout << "recupera: lista vacia";
				return nulo;
			} else return p->elemento;
		}

		int get_longitud() {
			return longitud;
		}

		nodoL* get_ptr_elementos() {
			return ptr_elementos;
		}

		void inserta(nodoL* p, int E) {
			nodoL* ant;
			nodoL* x = new nodoL;
			if (x != NULL) {
				x->elemento = E;
				x->sig = NULL;
				if (vacia()) {
					ptr_elementos = x;
					longitud = 1;
				} else {
					longitud ++;
					if (p == primero()) {
						x->sig = p;
						ptr_elementos = x;
					} else {
						ant = anterior(p);
						ant->sig = x;
						x->sig = p;
					}
				}
			} else {
				cout << "inserta: existe espacio memoria";
			}
		}

		void inserta_primero(int E) {
			nodoL* x = new nodoL;
			if (x != NULL) {
				x->elemento	= E;
				x-> sig	= ptr_elementos;
				longitud++;
				ptr_elementos = x;
			} else cout << "inserta_primero: existe espacio memoria";
		}

		void inserta_ultimo(int E) {
			nodoL* x = new nodoL;
			if (x != NULL) {
				x->elemento	= E;
				x->sig = NULL;
				if (longitud != 0) {
					fin()->sig = x;
				} else ptr_elementos = x;
				longitud ++;
			} else cout << "inserta_ultimo: existe espacio memoria";
		}

		void suprime(nodoL* p) {
			nodoL* x;
			nodoL* ant;
			if (longitud == 0) {
				cout << "suprime: lista vacia";
			}
			if (p == ptr_elementos) {
				x = ptr_elementos;
				ptr_elementos = ptr_elementos->sig;
			} else {
				ant = anterior(p);
				if (p == fin()) {
					ant->sig = NULL;
				} else {
					ant->sig = siguiente(p);
				}
			}
			longitud --;
			delete p;
		}

		void modifica(nodoL* p, int elemento) {
			if (vacia()) {
				cout << "modifica: lista vacia";
			}
			p->elemento	= elemento;
		}

		void mostrar() {
			string tmp = "<";
			nodoL* x = ptr_elementos;
			while (x != NULL) {
				tmp += to_string(x->elemento);
				x = x->sig;
				if (x != NULL) {
					tmp += ", ";
				}
			}
			tmp += ">\n\n";
			system("CLS");
			cout << tmp << endl << endl;
		}

		nodoL* localiza(int E) {
			nodoL* x = ptr_elementos;
			while (x != NULL) {
				if (x->elemento == E) {
					return x;
				}
				x = x->sig;
			}
			return NULL;
		}

		void elimina_dato(int E) {
			nodoL* x = ptr_elementos;
			nodoL* sig;
			while (x != NULL) {
				if (x->elemento == E) {
					sig = x->sig;
					suprime(x);
					x = sig;
				} else {
					x = x->sig;
				}
			}
		}

		void anula() {
			while (longitud != 0) {
				suprime(ptr_elementos);
			}
		}

		void debug() {

        }
};
