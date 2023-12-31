#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMlista.h>
#pragma once
using namespace std;

class Lpolinomio {
	private:

		SMlista &Pol;

		int BuscarExponente(int exp) {
			int dir = Pol.siguiente(Pol.primero());
			int dirExp;
			if (dir != Pol.nulo) {
				dirExp = Pol.nulo;
				while (dir != Pol.nulo && dirExp == Pol.nulo) {
					if (Pol.recupera(dir) == exp) {
						dirExp = dir;
					}
					dir = Pol.siguiente(Pol.siguiente(dir));
				}
				return dirExp;
			} else {
				cout << "buscarexponente polinomio no tiene terminos";
				return Pol.nulo;
			}
		}

		int BuscarTerminoN(int I) {
			int dir = Pol.primero();
			int nt = 0;
			int dirTer;
			if (dir != Pol.nulo) {
				dirTer = Pol.nulo;
				while (dir != Pol.nulo && dirTer == Pol.nulo) {
					nt = nt + 1;
					if (nt == I) {
						dirTer = dir;
					}
					dir = Pol.siguiente(Pol.siguiente(dir));
				}
				return dirTer;
			} else {
				cout << "BuscarterminoN: polinomio no tiene termino";
				return Pol.nulo;
			}
		}

	public:

		Lpolinomio::Lpolinomio(SMlista& L) : Pol(L) {};

		void crear() {
			Pol.crear();
		}

		bool EsCero() {
			return Pol.get_longitud() == 0;
		}

		int grado() {
			int dir = Pol.siguiente(Pol.primero());
			int MaxG;
			if (dir != Pol.nulo) {
				MaxG = Pol.recupera(dir);
				while (dir != Pol.nulo) {
					if (Pol.recupera(dir) > MaxG) {
						MaxG = Pol.recupera(dir);
					}
					dir = Pol.siguiente(Pol.siguiente(dir));
				}
				return MaxG;
			} else {
				cout << "grado: Polinomio no tiene terminos";
				return Pol.nulo;
			}
		}

		int coeficiente(int exp) {
			int dir = BuscarExponente(exp);
			if (dir != Pol.nulo) {
				return Pol.recupera(Pol.anterior(dir));
			} else {
				cout << "Coeficiente: polinomio no tiene ese termino";
				return Pol.nulo;
			}
		}

		void asignarcoeficiente(int coef, int exp) {
			int dir = BuscarExponente(exp);
			int dirCoef;
			if (dir != Pol.nulo) {
				dirCoef = Pol.anterior(dir);
				Pol.modifica(dirCoef, coef);
				if (coef == 0) {
					Pol.suprime(dir);
					Pol.suprime(dirCoef);
				}
			} else {
				cout << "asignarcoeficiente polinomio no tiene ese termino";
			}
		}

		void poner_termino(int coef, int exp) {
			int dirExp = BuscarExponente(exp);
			int dirCoef;
			if (dirExp != Pol.nulo) {
				dirCoef = Pol.anterior(dirExp);
				Pol.modifica(dirCoef, Pol.recupera(dirCoef) + coef);
				if (Pol.recupera(dirCoef) == 0) {
					Pol.suprime(dirExp);
					Pol.suprime(dirCoef);
				}
			} else {
				if (coef != 0) {
					Pol.inserta_ultimo(exp);
					Pol.inserta(Pol.fin(), coef);
				}
			}
		}

		int numero_terminos() {
			return (Pol.get_longitud() / 2);
		}

		int exponente(int nroter) {
			int dir = BuscarTerminoN(nroter);
			if (dir != Pol.nulo) {
				return Pol.recupera(Pol.siguiente(dir));
			} else {
				cout << "exponente: no existe ese numero de termino";
				return Pol.nulo;
			}
		}

		void suma(Lpolinomio p1, Lpolinomio p2) {
			int ex;
			int co;
			crear();
			for (int i = 1; i < p1.numero_terminos(); i++) {
				ex = p1.exponente(i);
				co = p1.coeficiente(ex);
				poner_termino(co, ex);
			}
			for (int i = 1; i < p2.numero_terminos(); i++) {
				ex = p2.exponente(i);
				co = p2.coeficiente(i);
				poner_termino(co, ex);
			}
		}

		void resta(Lpolinomio p1, Lpolinomio p2) {
			int ex;
			int co;
			crear();
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

		void multiplicacion(Lpolinomio p1, Lpolinomio p2) {
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
			int co;
			int ex;
			string tmp = "";
			for (int i = 1; i <= numero_terminos(); i++) {
				ex = exponente(i);
				co = coeficiente(ex);
				if (tmp != "" && co > 0) {
					tmp += "+";
				}
				if (co != 1 || ex == 0) {
					tmp += to_string(co);
				}
				if (ex > 0) {
					if (ex == 1) {
						tmp += "x";
					} else {
						tmp += "x^(" + to_string(ex) + ")";
					}
				}
			}
			system("CLS");
			cout << tmp << endl;
		}

        void derivar() {
			int co;
			int ex;
			string tmp = "";
			for (int i = 1; i <= numero_terminos(); i++) {
				ex = exponente(i);
				co = coeficiente(ex);
				if (tmp != "" && co > 0) {
					tmp += "+";
				}
				if (co*ex != 1 || ex-1 == 0) {
					if (ex > 0) {
					tmp += to_string(co*ex);
					}
				}
				if (ex-1 > 0) {
					if (ex-1 == 1) {
						tmp += "x";
					} else {
						tmp += "x^(" + to_string(ex-1) + ")";
					}
				}
			}
			system("CLS");
			cout << tmp << endl;
		}

        int evaluar(int x) {
			int i = 1;
			int sum = 0;
			int pow;
			int ex;
			int co;
			while (i <= numero_terminos()) {
				pow = x;
				ex = exponente(i);
				co = coeficiente(ex);
				if (ex > 0) {
					for (int j = 1; j < ex; j++) {
						pow *= x;
					}
				} else {
					pow = 1;
				}
				sum += co*pow;
				i++;
			}
            return sum;
		}

};
