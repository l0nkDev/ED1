#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include "SMemoria.h"
#pragma once
using namespace std;

struct NodoPil {
	int elemento;
	NodoPil* sig;
};

class SMpila {
	private:
		SMemoria& mem;
		int tope;
		static const int nulo = -1;
	public:

		SMpila(SMemoria& M): mem(M) {};

		void crear() {
			tope = nulo;
		}

		bool vacia() {
			return (tope == nulo);
        }

		void meter(int E) {
			int aux = mem.new_espacio("elemento,sig");
			if (aux != nulo) {
				mem.poner_dato(aux, "->elemento", E);
				mem.poner_dato(aux, "->sig", tope);
				tope = aux;
			}
		}

		int sacar() {
			if (!vacia()) {
				int x = tope;
				int E = mem.obtener_dato(tope, "->elemento");
				tope = mem.obtener_dato(tope, "->sig");
				mem.delete_espacio(x);
                return E;
			}
			return 0;
		}

		int cima() {
			if (!vacia()) {
				return mem.obtener_dato(tope, "->elemento");
			}
			return 0;
        }
};
