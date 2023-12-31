#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

class VmatrizCSR {
	private:

		static const int max = 30;
		int cant;
		int vf[max +1];
		int vc[max +1];
		int vd[max +1];
		int df, dc;
		int repe;
		int nt;

		int existe_elemento(int f, int c) {
			int existe_lugar = 0;
			int lug_antes = 0;
			for (int I = 1; I <= f - 1; I++) {
				lug_antes = lug_antes + (vf[I+1] - vf[I]);
			}
			int max_elem_fila = vf[f+1]-vf[f];
			for (int i = 1; i <= max_elem_fila; i++) {
				if (vc[lug_antes+i] == c) {
					existe_lugar = lug_antes + i;
				}
			}
			return existe_lugar;
		}

		int donde_insertar(int f, int c) {
			int lug_antes = 0;
			for (int I = 1; I <= f - 1; I++) {
				lug_antes = lug_antes + (vf[I+1] - vf[I]);
			}
			int nuevo_lugar = lug_antes;
			int lugar = lug_antes;
			for (int i = 1; i <= vf[f+1]-vf[f]; i++) {
				lugar = lug_antes + i;
				if (c > vc[lugar]) {
					nuevo_lugar = lugar;
				}
			}
			nuevo_lugar = nuevo_lugar + 1;
			return nuevo_lugar;
        }

	public:

		void crear() {
			df = 5;
			dc = 5;
			repe = 0;
			nt = 0;
			for (int k = 1; k <= df + 1; k++) {
				vf[k] = 1;
			}
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
			int lugar = existe_elemento(f, c);
			if (e != repe) {
				if (lugar != 0) {
					vd[lugar] = e;
				} else {
					lugar = donde_insertar(f, c);
					int i = nt + 1;
					while (i >= lugar + 1) {
						vd[i] = vd[i-1];
						vc[i] = vc[i-1];
						i--;
					}
					vd[lugar] = e;
					vc[lugar] = c;
					nt++;
					for (i = f + 1; i <= df + 1; i++) {
						vf[i] = vf[i] + 1;
					}
				}
			}
		}

		int elemento(int f, int c) {
			if ((f >= 1 && f <= df) && (c >= 1 && c <= dc)) {
				int lugar = existe_elemento(f, c);
				if (lugar > 0) {
					return vd[lugar];
				} else {
					return repe;
                }
			}
		return 0;
		}

		void definir_valor_repetido(int valor) {
			repe = valor;
        }

};
