#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

class Vlista {
	private:
		static const int max = 100;
		int longitud;
		int elementos[max];
	public:

		int nulo = 0;

		void crear() {
			longitud = 0;
		}

		bool vacia() {
			return (longitud == 0);
        }

		int fin() {
			if (!vacia()) {
				return longitud;
			} else {
				cout << "fin_error";
			}
		}

		int primero() {
			if (!vacia()) {
				return 1;
			} else {
				cout << "primero_listavacia";
				return 1;
			}
		}

		int siguiente(int p) {
			if (vacia() || p == nulo) {
				cout << "siguiente_listavacia";
				return nulo;
			} else {
				if (p == longitud) {
					cout << "siguiente_direccionerr";
					return nulo;
				} else {
					return (p + 1);
				}
			}
		}

		int anterior(int p) {
			if (vacia() || p == nulo) {
				cout << "anterior_listavacia";
			} else {
				if (p == 1) {
					cout << "anterior_direccionprimeraerr";
				} else {
					return (p - 1);
                }
            }
		}

		int recupera(int p) {
			if (vacia()) {
				cout << "recupera_listavacia";
				return nulo;
			} else {
				if (p < 1 || p > longitud) {
					cout << "recupera_direccionerr";
					return nulo;
				} else {
					return elementos[p];
				}
            }
		}

		int get_longitud() {
			return longitud;
		}

		void inserta(int p, int elemento) {
			if (longitud == max) {
				cout << "inserta_listallena";
			} else {
				if (!(p >= 1 && p <= longitud)) {
					cout << "inserta_direccionerr";
				}
				for (int i = longitud + 1; i > p; i--) {
					elementos[i] = elementos[i-1];
				}
				elementos[p] = elemento;
			   	longitud ++;
			}
		}

		void inserta_primero(int elemento) {
			if (longitud == max) {
				cout << "inspri_listallena";
			} else {
				for (int i = longitud + 1; i >= 2; i--) {
					elementos[i] = elementos[i-1];
				}
				elementos[1] = elemento;
				longitud ++;
			}
		}

		void inserta_ultimo(int elemento) {
			if (longitud == max) {
				cout << "insulp_listallena";
			} else {
				longitud ++;
				elementos[longitud] = elemento;
			}
		}

		void suprime(int p) {
			if (longitud == 0) {
				cout << "suprime_listavacia";
			} else {
				if (p < 1 || p > longitud) {
					cout << "suprime_direccionerr";
				} else {
					for (int i = p; i <= longitud - 1; i++) {
						elementos[i] = elementos [i + 1];
					}
					longitud --;
				}
			}
		}

		void modifica(int p, int elemento) {
			if (longitud == 0) {
				cout << "modifica_listavacia";
			} else {
				if (p < 1 || p > longitud) {
					cout << "modifica_direccionerr";
				} else {
					elementos[p] = elemento;
                }
			}
		}

		void mostrar() {
			string tmp = "<";
			for (int i = 1; i <= longitud; i++) {
				tmp += to_string(elementos[i]);
				if (i != longitud) {
					tmp += ", ";
				}
			}
			cout << tmp << ">\n\n";
		}

		int localiza(int e) {
			for (int i = 1; i <= longitud; i++) {
				if (elementos[i] == e) {
					return i;
				}
			}
			return nulo;
		}

		void elimina_dato(int e) {
			for (int i = 1; i <= longitud; i++) {
				if (elementos[i] == e) {
					suprime(i);
					i--;
				}
			}
		}

		void anula() {
			while (longitud > 0) {
				suprime(1);
            }
		}
};
