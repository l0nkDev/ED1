#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
using namespace std;

string operator*(const string& s, unsigned int n) {
	stringstream out;
	while (n--) {
		out << s;
	}
	return out.str();
}

struct NodoM {
	int dato;
	string ID;
	int link;
};

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
			cout<<cadena_id;
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
			cout << "    DIR       DATO          ID       LINK\n";
			cout << "  +---------------------------------------+\n";
			for (int i = 0; i < MAX; i++) {
				if (dir_libre(i)) {
					cout << "  |";	
				} else cout << "DO|";
				sdir = space*(2 - (to_string(i).length() / 2));
				if (to_string(i).length() % 2 == 0) {
					sdir += " ";    
				}      
				sdir += to_string(i);
				sdir += space*(2 - (to_string(i).length() / 2)) + "|"; 
				
				
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

				
				cout << sdir << sdato << sid << slink << endl;
			}
			cout << "  +---------------------------------------+\n";
			cout << "LIBRE = " << Libre << "\n";
		}
};

class lista;

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
	CSMemoria Memoria;
	while (run) {
		system("CLS");
		cout << "Practica 1 de Laboratorio\nSeleccione una operacion\n1.- Crear\n2.- Pedir espacio";
		cout <<	"\n3.- Liberar espacio\n4.- Poner Dato\n5.- Mostrar Memoria\n6.-Salir\n";
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
			int dir;
			system("CLS");
			cout << "Que dir desea eliminar\n\n";
			cin >> dir;
			Memoria.delete_espacio(dir);
			break;
		}
		case 4: {
			int dir;
			int valor;
			string id_memoria;
			system("CLS");
			cout << "Desde que dir procesar\n\n";
			cin >> dir;
			cout << "\n\nQue se llama el valor a asignar [Formato: ->nombre]\n\n";
			cin >> id_memoria;
			cout << "\n\nQue valor desea asignar a esta dir\n\n";
			cin >> valor;
			Memoria.poner_dato(dir, id_memoria, valor);
			break;
		}
		case 5: {
			Memoria.mostrar();
			system("pause");
			break;
			}
		case 6: {
			run = false;
			break;
			}
		case 6604: {
			string tmp = "a";
			cout << tmp * 5 << endl;
			system("pause");
			break;
			}
		}
	}
}
