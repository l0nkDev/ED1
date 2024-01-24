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

		void desplazar(int dir) {
			while (dir < fin) {
				V[dir] = V[dir+1];
				dir++;
            }
        }

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
				desplazar(0);
				fin--;
			}
		}

		void sacar(int &E) {
			if (!vacia()) {
				E = V[0];
				desplazar(0);
				fin--;
			}
		}

		int primero() {
			if (!vacia()) {
				return V[0];
			}
        }
};
