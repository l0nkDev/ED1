#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

struct NodoM {
	int dato;
	string ID;
	int link;
};

string operator*(const string& s, unsigned int n) {
	stringstream out;
	while (n--) {
		out << s;
	}
	return out.str();
}

class SMemoria {
	private:
		int MAX = 15;
		NodoM MEM[15];
		int Libre;
	public:

		SMemoria() {

        }

		int Numero_Ids(string Cadena) {
			int c = 1;
			for (int i = 0; i < Cadena.length()-1; i++) {
				if (Cadena[i] == ","[0]) {
					c++;
				}
			}
			return c;
		}

		string Obtener_Id(string Cadena, int cant) {
			string cad;
			int i;
			int j;
			for (i = 0; i < Cadena.length(); i++) {
				if (Cadena[i] == ","[0]) {
					cant--;
					i++;
				}
				if (cant == 1) {
					for (j = i; j < Cadena.length(); j++) {
						if (Cadena[j] == ","[0]) {
						return Cadena.substr(i, j-i);
						}
					}
					return Cadena.substr(i, j-i);
				}
			}
		}

		void Eliminar_flecha(string &cadena_id) {
			cadena_id = cadena_id.substr(2,cadena_id.length() - 2);
		}

		void crear() {
			for (int i = 0; i < MAX; i++) {
				MEM[i].dato = 0;
				MEM[i].ID = "";
				MEM[i].link = i + 1;
			}
			MEM[MAX].link = -1;
			Libre = 0;
		}

		int new_espacio(string Cadena) {
			int dir = Libre;
			int d = Libre;
			int cant;
			for (cant = Numero_Ids(Cadena); cant > 1; cant--) {
				MEM[d].ID = Obtener_Id(Cadena, Numero_Ids(Cadena) - cant + 1);
				d = MEM[d].link;
			}
			Libre = MEM[d].link;
			MEM[d].link = -1;
			MEM[d].ID = Obtener_Id(Cadena, Numero_Ids(Cadena) - cant + 1);
			return dir;
		}

		void delete_espacio(int dir) {
			int x = dir;
			while (MEM[x].link != -1) {
				x=MEM[x].link;
			}
			MEM[x].link = Libre;
			Libre = dir;
		}

		int espacio_disponible() {
			int x = Libre;
			int c = 0;
			while (x != -1) {
				c++;
				x = MEM[x].link;
			}
			return c;
		}

		bool dir_libre(int dir) {
			int x = Libre;
			bool c = false;
			while ((x != -1) && !c) {
				if (x == dir) {
					c = true;
				}
				x = MEM[x].link;
			}
			return c;
		}

		int obtener_dato(int dir, string cadena_id) {
			int z = dir;
			bool ex = false;
			Eliminar_flecha(cadena_id);
			while (z != -1) {
				if (MEM[z].ID == cadena_id) {
					return MEM[z].dato;
				}
				z = MEM[z].link;
			}
		}

		void poner_dato(int dir, string cadena_id, int valor) {
			int z = dir;
			Eliminar_flecha(cadena_id);
			while (z != -1) {
				if (MEM[z].ID == cadena_id) {
					MEM[z].dato = valor;
				}
				z = MEM[z].link;
			}
		}

		int espacio_ocupado() {
			int c = (MAX + 1) - espacio_disponible();
			return c;
		}

		void mostrar() {
			string space = " ";
			string sdir;
			string sdato;
			string sid;
			string slink;
			system("CLS");
			cout << "  | DIR |E|     DATO    |     ID      | LINK|\n";
			cout << "  +-----+-+-------------+-------------+-----+\n";
			for (int i = 0; i < MAX; i++) {
				cout << "  |";

				sdir = space*(2 - (to_string(i).length() / 2));
				if (to_string(i).length() % 2 == 0) {
					sdir += " ";
				}
				sdir += to_string(i);
				sdir += space*(2 - (to_string(i).length() / 2)) + "|";

				cout << sdir;

				if (dir_libre(i)) {
					cout << " |";
				} else {
					cout << "O|";
				}

				sdato = space*(6 - (to_string(MEM[i].dato).length() / 2));
				if (to_string(MEM[i].dato).length() % 2 == 0) {
					sdato += " ";
				}
				sdato += to_string(MEM[i].dato);
				sdato += space*(6 - (to_string(MEM[i].dato).length() / 2)) + "|";


				sid = space*(6 - (MEM[i].ID.length() / 2));
				if (MEM[i].ID.length() % 2 == 0) {
					sid += " ";
				}
				sid += MEM[i].ID;
				sid += space*(6 - (MEM[i].ID.length() / 2)) + "|";


				slink = space*(2 - (to_string(MEM[i].link).length() / 2));
				if (to_string(MEM[i].link).length() % 2 == 0) {
					slink += " ";
				}
				slink += to_string(MEM[i].link);
				slink += space*(2 - (to_string(MEM[i].link).length() / 2)) + "|";


				cout << sdato << sid << slink << endl;
			}
			cout << "  +-----+-+-------------+-------------+-----+\n";
			cout << "LIBRE = " << Libre << "\n";
		}
};
