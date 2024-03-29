﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "SMemoria.h"
#include "Matrices/SMmatrizCF.h"
#include "Matrices/PmatrizCF.h"
#include "Pilas/Ppila.h"
#include "juego.h"
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
fstream *f;
Ppila pil;
SMemoria mem;
SMmatrizCF mat(mem);
Juego juego(mat);
int mem_max = 1000;


void print() {
}

void __fastcall TForm1::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (true) {
		switch (Key) {
			case "w"[0]: juego.mv_u(Form1->Canvas); break;
			case "a"[0]: juego.mv_l(Form1->Canvas); break;
			case "s"[0]: juego.mv_d(Form1->Canvas); break;
			case "d"[0]: juego.mv_r(Form1->Canvas); break;
		}
		juego.draw_map(Form1->Canvas);
	}
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	mem.crear();
	mat.crear();
	mat.definir_valor_repetido("f"[0]);
	pil.crear();
	randomize();
	juego.load_map(StrToInt(Form1->lvl_chooser->Text));
	Form1->Repaint();
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
	juego.draw_map(Form1->Canvas);
}

void __fastcall TForm1::btn_rClick(TObject *Sender)
{
	juego.mv_r(Form1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_lClick(TObject *Sender)
{
	juego.mv_l(Form1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_uClick(TObject *Sender)
{
	juego.mv_u(Form1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_dClick(TObject *Sender)
{
	juego.mv_d(Form1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::load_lvlClick(TObject *Sender)
{
	juego.load_map(StrToInt(Form1->lvl_chooser->Text));
	Form1->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::show_memoryClick(TObject *Sender)
{
	int low_lim = StrToInt(Form1->low_lim->Text);
	int hi_lim = StrToInt(Form1->hi_lim->Text) + 1;
	int i;
	AnsiString str = mem.mostrar().c_str();
	Form1->Canvas->Font->Name = "Consolas";
	for (i = 0; i < 50; i++) {
		Form1->Canvas->TextOut(1050, 10+(15*i), "                                           ");
	}
	Form1->Canvas->TextOut(1050, 10, "+-----+-+-------------+-------------+-----+");
	Form1->Canvas->TextOut(1050, 25, str.SubString(0,43));
	Form1->Canvas->TextOut(1050, 40, str.SubString(44,43));
	for (i = 0; i < hi_lim - low_lim; i++) {
		Form1->Canvas->TextOut(1050, 55+(15*i), str.SubString((low_lim+i)*43+87,43));
		if (i == 44 || i == mem_max+1) {break;}
	}
	Form1->Canvas->TextOut(1050, 55+(15*i), str.SubString((mem_max+3)*43+1,43));
	Form1->Canvas->TextOut(1050, 55+(15*(i+1)), str.SubString((mem_max+4)*43+1,43));

}
//---------------------------------------------------------------------------

