#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include "Listas/Vlista.h"
#pragma once
using namespace std;

class Lpila {
	private:
		Vlista& L;
	public:

		Lpila(Vlista& lis): L(lis) {};

		void crear() {
			L.crear();
		}

		bool vacia() {
			return L.vacia();
        }

		void meter(int E) {
			L.inserta(L.primero(), E);
		}

		int sacar() {
			int E = L.recupera(L.primero());
			L.suprime(L.primero());
			return E;
		}

		int cima() {
			return L.recupera(L.primero());
        }
};
