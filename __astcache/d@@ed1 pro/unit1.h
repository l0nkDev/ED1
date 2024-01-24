//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *btn_r;
	TButton *btn_l;
	TButton *btn_u;
	TButton *btn_d;
	TButton *load_lvl;
	TEdit *lvl_chooser;
	TButton *show_memory;
	TEdit *hi_lim;
	TEdit *low_lim;
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall btn_rClick(TObject *Sender);
	void __fastcall btn_lClick(TObject *Sender);
	void __fastcall btn_uClick(TObject *Sender);
	void __fastcall btn_dClick(TObject *Sender);
	void __fastcall load_lvlClick(TObject *Sender);
	void __fastcall show_memoryClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
