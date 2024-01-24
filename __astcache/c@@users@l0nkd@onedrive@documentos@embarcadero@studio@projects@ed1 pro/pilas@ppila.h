#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

struct NodoPil {
	int elemento;
	NodoPil* sig;
};

class Ppila {
	private:
		NodoPil* tope;
	public:

		void crear() {
			tope = NULL;
		}

		bool vacia() {
			return (tope == NULL);
        }

		void meter(int E) {
			NodoPil* aux = new NodoPil;
			if (aux != NULL) {
				aux->elemento = E;
				aux->sig = tope;
				tope = aux;
			}
		}

		void sacar(int &E) {
			if (!vacia()) {
				NodoPil* x = tope;
				E = tope->elemento;
				tope = tope->sig;
				delete x;
			}
		}

		void sacar() {
			if (!vacia()) {
				NodoPil* x = tope;
				tope = tope->sig;
				delete x;
			}
		}

		int cima() {
			if (!vacia()) {
				return tope->elemento;
			}
			return 0;
        }
};
