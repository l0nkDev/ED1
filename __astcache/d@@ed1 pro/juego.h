﻿#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "SMmatrizCF.h"
#include <iostream>
#include <tchar.h>
#include <fstream>
#include <sstream>
#include <string>
#pragma once
using namespace std;

class Juego {
	private:
		Graphics::TBitmap* bichoBMP = new Graphics::TBitmap;
		Graphics::TBitmap* paredBMP = new Graphics::TBitmap;
		Graphics::TBitmap* fondoBMP = new Graphics::TBitmap;
		Graphics::TBitmap* fruta1BMP = new Graphics::TBitmap;
		Graphics::TBitmap* fruta2BMP = new Graphics::TBitmap;
		string mapas = "../../maps/plano.txt";
		static const char bicho = "b"[0];
		static const char fondo = "f"[0];
		static const char pared = "p"[0];
		static const char fruta1 = "g"[0];
		static const char fruta2 = "q"[0];
		static const char blanco = " "[0];
		static const int DimPieza = 32;
		SMmatrizCF& mat;
		int score = 0;
		int Cx = 0;
		int Cy = 0;
		int Df = 0;
		int Dc = 0;
		int Bx = 0;
		int By = 0;

	public:

		Juego(SMmatrizCF& m): mat(m) {
			bichoBMP->LoadFromFile("../../assets/bicho.bmp");
			paredBMP->LoadFromFile("../../assets/pared.bmp");
			fondoBMP->LoadFromFile("../../assets/fondo.bmp");
			fruta1BMP->LoadFromFile("../../assets/fruta1.bmp");
			fruta2BMP->LoadFromFile("../../assets/fruta2.bmp");

		}


		void load_map(int lvl) {
			bool lvl_found = false; bool lvl_loaded = false; score = 0;
			string str = " ";
			ifstream file(mapas);
			for (int i = 1; i <= Df; i++) {
				for (int j = 0; j <= Dc; j++) {
					mat.poner(i, j, fondo);
                }
			}
			while (std::getline(file, str)) {
				if (lvl_found && !lvl_loaded) {
					if (str[0] == "{"[0]) {
						lvl_loaded = true;
					} else {
						Dc = str.length() > Dc ? str.length() : Dc;
						Df++;
						mat.dimensionar(Df, Dc);
						for (int i = 0; i < str.length(); i++) {
							Bx = str[i] == bicho ? i+1 : Bx;
							By = str[i] == bicho ? Df  : By;
							mat.poner(Df, i+1, str[i]);
						}
                    }
				}
				if ( !lvl_found && str[0] == "{"[0] &&  lvl == stoi(str.substr(1, str.length() - 1))) {
					lvl_found = true;
					std::getline(file, str);
					for (int i = 0; i < str.length(); i++) {
						if (str[i] == ","[0]) {
							Cy = stoi(str.substr(0, i));
							Cx = stoi(str.substr(i+1, str.length()-i));
						}
					}
					Df = 0;
					Dc = 0;
				}
			}
		}

		void draw_tile(int f, int c, TCanvas* pant) {
			char tile = mat.elemento(f, c);
			Graphics::TBitmap* fig = NULL;
			switch (tile) {
				case bicho: fig = bichoBMP; break;
				case pared: fig = paredBMP; break;
				case fondo: fig = fondoBMP; break;
				case fruta1: fig = fruta1BMP; break;
				case fruta2: fig = fruta2BMP; break;
			}
			int xR = Cx + (c - 1)*DimPieza;
			int yR = Cy + (f - 1)*DimPieza;
			pant->Draw(xR, yR, fig);
		}

		void draw_map(TCanvas* pant) {
			for (int i = Df != 0 ? 1 : 0; i <= Df; i++) {
				for (int j = Dc != 0 ? 1 : 0; j <= Dc; j++) {
					draw_tile(i, j, pant);
				}
			}
			pant->Font->Name = "Segoe UI";
			pant->TextOut(Cx, Cy-20, ("Score: " + to_string(score)).c_str());
		}

		int get_score() {
			return score;
        }

		void mv_u(TCanvas* pant) {
			char obj_in_next_tile = mat.elemento(By-1, Bx);
			if (obj_in_next_tile != pared) {
				switch (obj_in_next_tile) {
					case fruta1: score += 100; break;
					case fruta2: score += 200; break;
				}
				mat.poner(By, Bx, fondo);
				draw_tile(By, Bx, pant);
				mat.poner(By-1, Bx, bicho);
				draw_tile(By-1, Bx, pant);
				pant->Font->Name = "Segoe UI";
				pant->TextOut(Cx, Cy-20, ("Score: " + to_string(score)).c_str());
				By--;
			}
		}

		void mv_d(TCanvas* pant) {
			char obj_in_next_tile = mat.elemento(By+1, Bx);
			if (obj_in_next_tile != pared) {
				switch (obj_in_next_tile) {
					case fruta1: score += 100; break;
					case fruta2: score += 200; break;
				}
				mat.poner(By, Bx, fondo);
				draw_tile(By, Bx, pant);
				mat.poner(By+1, Bx, bicho);
				draw_tile(By+1, Bx, pant);
				pant->Font->Name = "Segoe UI";
				pant->TextOut(Cx, Cy-20, ("Score: " + to_string(score)).c_str());
				By++;
			}
		}

		void mv_l(TCanvas* pant) {
			char obj_in_next_tile = mat.elemento(By, Bx-1);
			if (obj_in_next_tile != pared) {
				switch (obj_in_next_tile) {
					case fruta1: score += 100; break;
					case fruta2: score += 200; break;
				}
				mat.poner(By, Bx, fondo);
				draw_tile(By, Bx, pant);
				mat.poner(By, Bx-1, bicho);
				draw_tile(By, Bx-1, pant);
				pant->Font->Name = "Segoe UI";
				pant->TextOut(Cx, Cy-20, ("Score: " + to_string(score)).c_str());
				Bx--;
			}
		}

		void mv_r(TCanvas* pant) {
			char obj_in_next_tile = mat.elemento(By, Bx+1);
			if (obj_in_next_tile != pared) {
				switch (obj_in_next_tile) {
					case fruta1: score += 100;;break;
					case fruta2: score += 200; break;
				}
				mat.poner(By, Bx, fondo);
				draw_tile(By, Bx, pant);
				mat.poner(By, Bx+1, bicho);
				draw_tile(By, Bx+1, pant);
				pant->Font->Name = "Segoe UI";
				pant->TextOut(Cx, Cy-20, ("Score: " + to_string(score)).c_str());
				Bx++;
			}
		}
};