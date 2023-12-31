#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#include <SMemoria.h>
#pragma once
using namespace std;

class SMlista {
	private:
		int ptr_elementos;
		int longitud;
		SMemoria& Memoria;

	public:

		int nulo = -1;

		SMlista::SMlista(SMemoria& M) : Memoria(M) {};

		void crear() {
			ptr_elementos = nulo;
			longitud = 0;
		}

		bool vacia() {
			return (longitud == 0);
		}

		int fin() {
			int x;
			int PtrFin;
			if (vacia()) {
				cout << "fin: lista vacia";
			} else {
				x = ptr_elementos;
				while (x != nulo) {
					PtrFin = x;
					x = Memoria.obtener_dato(x,"->sig");
				}
				return PtrFin;
			}
		}

		int primero() {
			if (!vacia()) {
				return ptr_elementos;
			} else {
				cout << "primero: lista vacia";
			}
		}

		int siguiente(int p) {
			if (vacia() || p == nulo) {
				cout << "siguiente: lista vacia";
				return nulo;
			} else {
				if (p == fin()) {
					cout << "siguiente: DireccionErr";
					return nulo;
				} else {
					return (Memoria.obtener_dato(p,"->sig"));
				}
			}
		}

		int anterior(int p) {
			int x;
			int ant;
			if (vacia()) {
				cout << "anterior: lista vacia";
				return nulo;
			} else {
				if (p == primero()) {
					cout << "anterior: direccion primera err";
                    return nulo;
				} else {
					x = ptr_elementos;
					ant = nulo;
					while (x != nulo) {
						if (x == p) {
							return ant;
						}
						ant = x;
						x = Memoria.obtener_dato(x,"->sig");
					}
				}
			}
		}

		int recupera(int p) {
			if (vacia()) {
				cout << "recupera: lista vacia";
				return nulo;
			} else return Memoria.obtener_dato(p,"->elemento");
		}

		int get_longitud() {
			return longitud;
		}

		int get_ptr_elementos() {
			return ptr_elementos;
		}

		void inserta(int p, int E) {
			int ant;
			int x = Memoria.new_espacio("elemento,sig");
			if (x != nulo) {
				Memoria.poner_dato(x,"->elemento",E);
				Memoria.poner_dato(x,"->sig",nulo);
				if (vacia()) {
					ptr_elementos = x;
					longitud = 1;
				} else {
					longitud ++;
					if (p == primero()) {
						Memoria.poner_dato(x,"->sig",p);
						ptr_elementos = x;
					} else {
						ant = anterior(p);
						Memoria.poner_dato(ant,"->sig",x);
						Memoria.poner_dato(x,"->sig",p);
					}
				}
			} else {
				cout << "inserta: existe espacio memoria";
			}
		}

		void inserta_primero(int E) {
			int x = Memoria.new_espacio("elemento,sig");
			if (x != nulo) {
				Memoria.poner_dato(x,"->elemento",E);
				Memoria.poner_dato(x,"->sig",ptr_elementos);
				longitud++;
				ptr_elementos = x;
			} else cout << "inserta_primero: existe espacio memoria";
		}

		void inserta_ultimo(int E) {
			int x = Memoria.new_espacio("elemento,sig");
			if (x != nulo) {
				Memoria.poner_dato(x,"->elemento",E);
				Memoria.poner_dato(x,"->sig",nulo);
				if (longitud != 0) {
					Memoria.poner_dato(fin(),"->sig",x);
				} else ptr_elementos = x;
				longitud ++;
			} else cout << "inserta_ultimo: existe espacio memoria";
		}

		void suprime(int p) {
			int x;
			int ant;
			if (longitud == 0) {
				cout << "suprime: lista vacia";
			}
			if (p == ptr_elementos) {
				x = ptr_elementos;
				ptr_elementos = Memoria.obtener_dato(ptr_elementos,"->sig");
			} else {
				ant = anterior(p);
				if (p == fin()) {
					Memoria.poner_dato(ant,"->sig",nulo);
				} else {
					Memoria.poner_dato(ant,"->sig",siguiente(p));
				}
			}
			longitud --;
            Memoria.delete_espacio(p);
		}

		void modifica(int p, int elemento) {
			if (vacia()) {
				cout << "modifica: lista vacia";
			}
			Memoria.poner_dato(p,"->elemento",elemento);
		}

		void mostrar() {
			string tmp = "<";
			int x = ptr_elementos;
			while (x != nulo) {
				tmp += to_string(Memoria.obtener_dato(x,"->elemento"));
				x = Memoria.obtener_dato(x,"->sig");
				if (x != nulo) {
					tmp += ", ";
				}
			}
			tmp += ">\n\n";
			system("CLS");
			cout << tmp << endl << endl;
		}

		int localiza(int E) {
			int x = ptr_elementos;
			while (x != nulo) {
				if (Memoria.obtener_dato(x,"->elemento") == E) {
					return x;
				}
				x = Memoria.obtener_dato(x,"->sig");
			}
			return nulo;
		}

		void elimina_dato(int E) {
			int x = ptr_elementos;
			int sig;
			while (x != nulo) {
				if (Memoria.obtener_dato(x,"->elemento") == E) {
					sig = Memoria.obtener_dato(x,"->sig");
					suprime(x);
					x = sig;
				} else {
					x = Memoria.obtener_dato(x,"->sig");
				}
			}
		}

		void anula() {
			while (longitud != 0) {
				suprime(ptr_elementos);
			}
		}

		void debug() {

        }
};
