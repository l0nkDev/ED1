#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

class Vcola {
	private:
		static const int max = 100;
		int V[max + 1];
		int ini;
		int fin;
	public:

		void crear() {
			fin = -1;
			ini = 0;
			for (int i = 0; i <= max; i++) {
				V[i] = 0;
			}
		}

		bool vacia() {
			return (ini > fin);
        }

		void poner(char E) {
			if (fin < max) {
				fin++;
				V[fin] = E;
			}
		}

		void sacar() {
			if (!vacia()) {
				ini++;
			}
		}

		void sacar(int &E) {
			if (!vacia()) {
				E = V[ini];
				ini++;
			}
		}

		int primero() {
			if (!vacia()) {
				return V[ini];
			}
        }
};
