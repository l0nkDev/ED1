#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

class VmatrizCOO {
	private:

		static const int max = 30;
		int cant;
		int vf[max +1];
		int vc[max +1];
		int vd[max +1];
		int df, dc;
		int repe;
		int nt;

		int buscar(int f, int c) {
			for (int i = 1; i < max; i++) {
				if (vf[i] == f && vc[i] == c) {
					return i;
				}
			}
			return 0;
		}

		void suprime(int p) {
			if (nt == 0) {
			} else {
				if (p < 1 || p > nt) {
				} else {
					for (int i = p; i <= nt; i++) {
						vd[i] = vd[i + 1];
						vf[i] = vf[i + 1];
						vc[i] = vc[i + 1];
					}
					vd[nt] = 0;
					vf[nt] = 0;
					vc[nt] = 0;
					nt --;
				}
			}
		}

	public:

		void crear() {
			df = 0;
			dc = 0;
			repe = 0;
			nt = 0;
		}

		void dimensionar(int nf, int nc) {
			df = nf;
			dc = nc;
		}

		int dimension_fila() {
			return df;
		}

		int dimension_columna() {
			return dc;
		}


		void poner(int f, int c, int e) {
			int lug = buscar(f, c);
			if (lug > 0) {
				if (e == repe) {
					suprime(lug);
				} else {
					vd[lug] = e;
				}
			} else {
				if (nt < max && repe != e) {
					nt++;
					vd[nt] = e;
					vf[nt] = f;
					vc[nt] = c;
				}
            }
		}

		int elemento(int f, int c) {
			if ((f >= 1 && f <= df) && (c >= 1 && c <= dc)) {
				int lug = buscar(f, c);
				if (lug > 0) {
					return vd[lug];
				} else {
					return repe;
                }
			}
		return 0;
		}

		void definir_valor_repetido(int valor) {
			repe = valor;
			for (int i = 1; i < max; i++) {
				if (vd[i] == repe) {
					suprime(i);
				}
			}
		}

};
