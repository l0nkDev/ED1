#include <iostream>
#include <sstream>
#include <string>
#include <tchar.h>
#pragma once
using namespace std;

class Vpila {
	private:
		static const int max = 100;
		char elementos[max+1];
		int tope;
	public:

		void crear() {
			tope = 0;
			for (int i = 0; i <= max; i++) {
				elementos[i] = 0;
			}
		}

		bool vacia() {
			return (tope == 0);
        }

		void meter(char E) {
			if (tope < max) {
				tope++;
				elementos[tope] = E;
			}
		}

		char sacar() {
			if (!vacia()) {
				tope--;
				return elementos[tope+1];
			}
			return -1;
		}

		char cima() {
			if (!vacia()) {
				return elementos[tope];
			}
            return -1;
        }
};
