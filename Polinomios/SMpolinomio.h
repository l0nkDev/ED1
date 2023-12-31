#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#pragma once
using namespace std;

class SMpolinomio {
	private:
		SMemoria& mem;
		int ptr_poli;
		int nt;

		int BuscarExponente(int exp) {
			int dir = ptr_poli;
			int dirEx;
			if (dir != nulo) {
				dirEx = nulo;
				while (dir != nulo && dirEx == nulo) {
					if (mem.obtener_dato(dir, "->exp") == exp) {
						dirEx = dir;
					}
					dir = mem.obtener_dato(dir, "->sig");
				}
				return dirEx;
			} else {
				cout << "buscarexponente: no existe ese termino";
				return nulo;
            }
		}

		int BuscarTerminoN(int I) {
			int dir = ptr_poli;
			int dirTer;
			int nt;
			if (dir != nulo) {
				dirTer = nulo;
				nt = 0;
				while (dir != nulo && dirTer == nulo) {
					nt ++;
					if (nt == I) {
						dirTer = dir;
					}
					dir = mem.obtener_dato(dir, "->sig");
				}
				return dirTer;
			} else {
				cout << "buscarterminon: no existe terminos";
				return nulo;
			}
        }

	public:
		int nulo = mem.nulo;

		SMpolinomio(SMemoria& M): mem(M) {};

        int fin() {
			int x;
			int PtrFin;
			if (EsCero()) {
				cout << "fin: lista vacia";
			} else {
				x = ptr_poli;
				while (x != nulo) {
					PtrFin = x;
					x = mem.obtener_dato(x,"->sig");
				}
				return PtrFin;
			}
		}

        int anterior(int p) {
			int x;
			int ant;
			if (EsCero()) {
				cout << "anterior: lista vacia";
			} else {
				if (p == ptr_poli) {
					cout << "anterior: direccion primera err";
				} else {
					x = ptr_poli;
					ant = nulo;
					while (x != nulo) {
						if (x == p) {
							return ant;
						}
						ant = x;
						x = mem.obtener_dato(x,"->sig");
					}
				}
			}
		}

        void suprime(int p) {
			int x;
			int ant;
			if (nt == 0) {
				cout << "suprime: lista vacia";
			}
			if (p == ptr_poli) {
				x = ptr_poli;
				ptr_poli = mem.obtener_dato(ptr_poli,"->sig");
			} else {
				ant = anterior(p);
				if (p == fin()) {
					mem.poner_dato(ant,"->sig",nulo);
				} else {
					mem.poner_dato(ant,"->sig",(mem.obtener_dato(p,"->sig")));
				}
			}
			nt --;
            mem.delete_espacio(p);
		}

		void crear() {
			nt = 0;
			ptr_poli = nulo;
		}

		bool EsCero() {
			return (nt == 0);
		}

		int grado() {
			int dir = ptr_poli;
			int MaxG;
			if (dir != nulo) {
				MaxG = mem.obtener_dato(dir, "->exp");
				while (dir != nulo) {
					if (mem.obtener_dato(dir, "->exp") > MaxG) {
						MaxG = mem.obtener_dato(dir, "->exp");
					}
					dir = mem.obtener_dato(dir, "->sig");
				}
				return MaxG;
			} else {
				cout << "grado: no existe ese termino";
				return nulo;
			}
		}

		int coeficiente(int exp) {
			int dir = BuscarExponente(exp);
			if (dir != nulo) {
				return mem.obtener_dato(dir, "->coef");
			} else {
				cout << "coeficiente: no existe ese termino";
				return nulo;
			}
		}

		void asignarcoeficiente(int coef, int exp) {
			int dir = BuscarExponente(exp);
			if (dir != nulo) {
				mem.poner_dato(dir, "->coef", coef);
				if (coef == 0) {
					suprime(dir);
				}
			} else {
				cout << "asignarcoeficiente: no existe ese termino";
			}
		}

		void poner_termino(int coef, int exp) {
			int existe = BuscarExponente(exp);
			int aux;
			if (existe == nulo) {
				aux = mem.new_espacio("coef,exp,sig");
				if (aux != nulo) {
					mem.poner_dato(aux,"->coef",coef);
					mem.poner_dato(aux,"->exp",exp);
					mem.poner_dato(aux,"->sig",ptr_poli);
					ptr_poli = aux;
					nt ++;
				} else {
					cout << "poner_termino: error espacio memoria";
				}
			} else {
				int nuevocoef = mem.obtener_dato(existe,"->coef") + coef;
				mem.poner_dato(existe,"->coef",nuevocoef);
				if (nuevocoef == 0) {
					suprime(existe);
				}
			}
		}

		int numero_terminos() {
			return nt;
		}

		int exponente(int nroter) {
			int dir = BuscarTerminoN(nroter);
			if (dir != nulo) {
				return mem.obtener_dato(dir, "->exp");
			} else {
				cout << "exponente: no existe ese termino";
				return nulo;
            }
		}

		void suma(SMpolinomio p1, SMpolinomio p2) {
			mem.crear();
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

		void resta(SMpolinomio p1, SMpolinomio p2) {
			mem.crear();
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

        void multiplicacion(SMpolinomio p1, SMpolinomio p2) {
			int ex;
			int co;
			int ex1;
			int co1;
			int ex2;
			int co2;
			mem.crear();
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
			int ex;
			int co;
			int i = ptr_poli;
			string tmp = "";
			while (i != nulo) {
				ex = mem.obtener_dato(i, "->exp");
				co = mem.obtener_dato(i, "->coef");
				i = mem.obtener_dato(i, "->sig");
				if (tmp != "" && co > 0) {
						tmp += "+";
				}
				if (co != 1 || ex == 0) {
					tmp += to_string(co);
				}
				if (ex > 0) {
					if (ex == 1) {
						tmp += "x ";
					} else {
						tmp += "x^(" + to_string(ex) + ") ";
					}
				}
			}
			system("CLS");
			cout << tmp << endl;
		}

		void derivar() {
			int ex;
			int co;
			int i = ptr_poli;
			string tmp = "";
			while (i != nulo) {
				ex = mem.obtener_dato(i, "->exp");
				co = mem.obtener_dato(i, "->coef");
				i = mem.obtener_dato(i, "->sig");
				if (tmp != "" && co*ex > 0) {
						tmp += "+";
				}
				if (co*ex != 1 || ex-1 == 0) {
					if (ex > 0) {
						tmp += to_string(co*ex);
					}
				}
				if (ex-1 > 0) {
					if (ex-1 == 1) {
						tmp += "x ";
					} else {
						tmp += "x^(" + to_string(ex-1) + ") ";
					}
				}
			}
			system("CLS");
			cout << tmp << endl;
		}

        int evaluar(int x) {
			int i = ptr_poli;
			int sum = 0;
			int pow;
			while (i != nulo) {
				pow = x;
				if (mem.obtener_dato(i, "->exp") > 0) {
					for (int j = 1; j < mem.obtener_dato(i, "->exp"); j++) {
						pow *= x;
					}
				} else {
					pow = 1;
				}
				sum += mem.obtener_dato(i, "->coef")*pow;
				i = mem.obtener_dato(i, "->sig");
			}
            return sum;
		}


};
