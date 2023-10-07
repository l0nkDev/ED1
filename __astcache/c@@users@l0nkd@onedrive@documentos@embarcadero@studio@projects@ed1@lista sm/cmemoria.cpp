﻿#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
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

class CSMemoria {
	private:
		int MAX = 15;
		NodoM MEM[15];
		int Libre;
	public:

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

	CSMemoria Memoria;

class lista {
	private:
		int ptr_elementos;
		int longitud;
	public:
		void crear() {
			ptr_elementos = -1;
			longitud = 0;
		}

		bool vacia() {
			return (longitud == 0);
		}

		int fin() {
			int x;
			int PtrFin;
			if (vacia()) {
				cout << "lista vacia";
			} else {
				x = ptr_elementos;
				while (x != -1) {
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
				cout << "lista vacia";
			}
		}

		int siguiente(int p) {
			if (vacia()) {
				cout << "lista vacia";
			} else {
				if (p == fin()) {
					cout << "DireccionErr";
				} else {
					return (Memoria.obtener_dato(p,"->sig"));
				}
			}
		}

		int anterior(int p) {
			int x;
			int ant;
			if (vacia()) {
				cout << "lista vacia";
			} else {
				if (p == primero()) {
					cout << "direccion primera err";
				} else {
					x = ptr_elementos;
					ant = -1;
					while (x != -1) {
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
				cout << "lista vacia";
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
			if (x != -1) {
				Memoria.poner_dato(x,"->elemento",E);
				Memoria.poner_dato(x,"->sig",-1);
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
				cout << "existe espacio memoria";
			}
		}

		void inserta_primero(int E) {
			int x = Memoria.new_espacio("elemento,sig");
			if (x != -1) {
				Memoria.poner_dato(x,"->elemento",E);
				Memoria.poner_dato(x,"->sig",ptr_elementos);
				longitud++;
				ptr_elementos = x;
			} else cout << "existe espacio memoria";
		}

		void inserta_ultimo(int E) {
			int x = Memoria.new_espacio("elemento,sig");
			if (x != -1) {
				Memoria.poner_dato(x,"->elemento",E);
				Memoria.poner_dato(x,"->sig",-1);
				if (longitud != 0) {
					Memoria.poner_dato(fin(),"->sig",x);
				} else ptr_elementos = x;
				longitud ++;
			} else cout << "existe espacio memoria";
		}

		void suprime(int p) {
			int x;
			int ant;
			if (longitud == 0) {
				cout << "lista vacia";
			}
			if (p == ptr_elementos) {
				x = ptr_elementos;
				ptr_elementos = Memoria.obtener_dato(ptr_elementos,"->sig");
			} else {
				ant = anterior(p);
				if (p == fin()) {
					Memoria.poner_dato(ant,"->sig",-1);
				} else {
					Memoria.poner_dato(ant,"->sig",siguiente(p));
				}
			}
			longitud --;
		}

		void modifica(int p, int elemento) {
			if (vacia()) {
				cout << "lista vacia";
			}
			Memoria.poner_dato(p,"->elemento",elemento);
		}

		void mostrar() {
			string tmp = "<";
			int x = ptr_elementos;
			while (x != -1) {
				tmp += to_string(Memoria.obtener_dato(x,"->elemento"));
				x = Memoria.obtener_dato(x,"->sig");
				if (x != -1) {
					tmp += ", ";
				}
			}
			tmp += ">\n\n";
			system("CLS");
			cout << tmp << endl << endl;
		}

		int localiza(int E) {
			int x = ptr_elementos;
			while (x != -1) {
				if (Memoria.obtener_dato(x,"->elemento") == E) {
					return x;
				}
				x = Memoria.obtener_dato(x,"->sig");
			}
			return -1;
		}

		void elimina_dato(int E) {
			int x = ptr_elementos;
			int sig;
			while (x != -1) {
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
};

	lista SMlista;

int menu_sel() {
	int sel;
	cout << "\nRealice su seleccion...\n";
	while (true) {
	if (cin >> sel) {
		break;
	}
	cout << "Entrada invalida, intente de nuevo...\n";
	cin.sync();
	cin.clear();
	}
	return sel;
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool run = true;
	while (run) {
		system("CLS");
		cout << "Laboratorio 3\n\nSeleccione una operacion\n\n1) Crear Memoria\n2) Pedir espacio";
		cout <<	"\n3) Liberar espacio\n4) Crear lista\n5) Insertar primero\n6) Insertar siguiente primero\n7) Insertar anterior fin\n8) Mostrar memoria\n9) Mostrar lista\n";
		switch (menu_sel()) {
		case 1: {
			Memoria.crear();
			break;
			}

		case 2: {
			string tmp;
			system("CLS");
			cout << "Que IDs va a reservar [Formato: var1,var2,var3,...]\n\n";
			cin >> tmp;
			Memoria.new_espacio(tmp);
			break;
			}

		case 3: {
			int tmp;
			system("CLS");
			cout << "Que direccion desea eliminar\n\n";
			cin >> tmp;
			Memoria.delete_espacio(tmp);
			break;
			}

		case 4: {
			SMlista.crear();
			break;
			}

		case 5: {
			int tmp;
			system("CLS");
			cout << "Que dato desea insertar\n\n";
			cin >> tmp;
			SMlista.inserta(SMlista.primero(), tmp);
			break;
			}

		case 6: {
			int tmp;
			system("CLS");
			if (SMlista.get_longitud() < 2) {
				cout << "Lista demasiado pequeña\n\n";
				system("pause");
				} else {
					cout << "Que dato desea insertar\n\n";
					cin >> tmp;
					SMlista.inserta(SMlista.siguiente(SMlista.primero()), tmp);
				}
			break;
			}

		case 7: {
			int tmp;
			system("CLS");
			if (SMlista.get_longitud() < 2) {
				cout << "lista demasiado pequeña\n\n";
				system("pause");
				} else {
					cout << "Que dato desea insertar\n\n";
					cin >> tmp;
					SMlista.inserta(SMlista.anterior(SMlista.fin()), tmp);
					}
			break;
			}

		case 8: {
			system("CLS");
			Memoria.mostrar();
			system("pause");
			break;
			}

		case 9: {
			system("CLS");
			SMlista.mostrar();
			system("pause");
			break;
			}

		case 10: {
			run = false;
			break;
			}

		case 6604: {
			int tmp;
			cout << SMlista.fin() << endl << SMlista.primero() << "\n\n";
			system("pause");
			break;
			}
		}
	}
};