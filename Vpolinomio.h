#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#pragma once
using namespace std;

class Vpolinomio {
	private:
		static const int MAX = 100;
		int VC[MAX];
		int VE[MAX];
		int nt;
		int nulo = -1;

	public:

		int pos(int n) {
			for (int i = 1; i <= nt; i++) {
				if (VE[i] == n) {
					return i;
				}
			}
			return nulo;
		}

		void eliminar(int dir) {
			for (int i = dir; i <= nt - 1; i++) {
				VC[i] = VC[i + 1];
				VE[i] = VE[i + 1];
			}
			nt --;
        }

		void crear() {
			nt = 0;
		}

		bool EsCero() {
			return (nt == 0);
		}

		int grado() {
			int max;
			if (nt > 0) {
				max = VE[1];
				for (int i = 1; i <= nt; i++) {
					if (VE[i] > max) {
						max = VE[i];
					}
				}
				return max;
			} else {
				cout << "grado: no existe terminos";
			}
		}

		void asignarcoeficiente(int coef, int exp) {
			int lug = pos(exp);
			if (lug != nulo) {
				VC[lug] = coef;
				if (VC[lug] == 0) {
					eliminar(lug);
				} else {
					cout << "asignarcoeficiente: error no existe termino con ese exponente";
				}
			}
		}

		void poner_termino(int coef, int exp) {
			int lug = pos(exp);
			if (lug != nulo) {
				VC[lug] = VC[lug] + coef;
				if (VC[lug] == 0) {
					eliminar(lug);
				}
			} else {
				nt ++;
				VC[nt] = coef;
				VE[nt] = exp;
			}

		}

		int numero_terminos() {
			return nt;
		}

		int coeficiente(int exp) {
			if (exp >= 0 && exp <= grado()) {
				for (int i = 1; i <= nt; i++) {
					if (VE[i] == exp) {
						return VC[i];
					}
				}
			}
			cout << "coeficiente: error no existe termino con ese exponente";
			return nulo;
		}

		int exponente(int nroter) {
			return VE[nroter];
		}

		void suma(Vpolinomio p1, Vpolinomio p2) {
			crear();
			int ex;
			int co;
			for (int i = 1; i < p1.numero_terminos(); i++) {
				ex = p1.exponente(i);
				co = p1.coeficiente(ex);
				poner_termino(co, ex);
			}
			for (int i = 1; i < p2.numero_terminos(); i++) {
				ex = p2.exponente(i);
				co = p2.coeficiente(ex);
				poner_termino(co, ex);
			}
		}

		void resta(Vpolinomio p1, Vpolinomio p2) {
			crear();
			int ex;
			int co;
			for (int i = 1; i < p1.numero_terminos(); i++) {
				ex = p1.exponente(i);
				co = p1.coeficiente(ex);
				poner_termino(co, ex);
			}
			for (int i = 1; i < p2.numero_terminos(); i++) {
				ex = p2.exponente(i);
				co = p2.coeficiente(ex)*(-1);
				poner_termino(co, ex);
			}
		}

		void multiplicacion(Vpolinomio p1, Vpolinomio p2) {
			int ex;
			int co;
			int ex1;
			int co1;
			int ex2;
			int co2;
			crear();
			for (int i = 1; i < p1.numero_terminos(); i++) {
				for (int j = 1; j < p2.numero_terminos(); j++) {
					ex1 = p1.exponente(i);
					ex2 = p2.exponente(j);
					co1 = p1.coeficiente(ex1);
					co2 = p2.coeficiente(ex2);
					ex = ex1 + ex2;
					co = co1 * co2;
					poner_termino(co, ex);
				}
			}
		}

		void mostrar() {
			int i = 1;
			string tmp = "";
			if (nt > 0) {
				while (i <= nt) {
					if (tmp != "" && VC[i] > 0) {
						tmp += "+";
					}
					if (VC[i] != 1 || VE[i] == 0) {
						tmp += to_string(VC[i]);
					}
					if (VE[i] > 0) {
						if (VE[i] == 1) {
							tmp += "x ";
						} else {
							tmp += "x^(" + to_string(VE[i]) + ") ";
						}
					}
					i++;
				}
			}
			system("CLS");
			cout << tmp << endl;
		}

        void derivar() {
			int i = 1;
			string tmp = "";
			if (nt > 0) {
				while (i <= nt) {
					if (tmp != "" && VC[i]*VE[i] > 0) {
						tmp += "+";
					}
					if (VC[i]*VE[i] != 1 || VE[i]-1 == 0) {
						if (VE[i] > 0) {
						tmp += to_string(VC[i]*VE[i]);
						}
						if (VE[i]-1 > 0) {
							if (VE[i]-1 == 1) {
								tmp += "x ";
							} else {
								tmp += "x^(" + to_string(VE[i]-1) + ") ";
							}
						}
					}
					i++;
				}
			system("CLS");
			cout << tmp << endl;;
			}
		}

		int evaluar(int x) {
			int i = 1;
			int sum = 0;
			int pow;
			while (i <= nt) {
				pow = x;
				if (VE[i] > 0) {
					for (int j = 1; j < VE[i]; j++) {
						pow *= x;
					}
				} else {
					pow = 1;
				}
				sum += VC[i]*pow;
				i++;
			}
            return sum;
		}

		void debug(){
			for (int i = 1; i < nt; i++) {
				cout << "(" << to_string(VC[i]) << ", " << to_string(VE[i]) << ") ";
			}
			cout << endl;
		}

};
