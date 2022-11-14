#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include "Insumo.h"

class Medicamento : public Insumo
{
	public:
		Medicamento();
		Medicamento(std::string n, int q, float val, std::string venci, 
		std::string nomFab, int tipInsu, std::string dos, std::string admin, std::string disp);
		
		int getQuant();
		float getValUni();
		std::string getDos();
		std::string getAdmin();
		std::string getDisp();
		void setQuant(int q);
		void getDescInsu();
		std::string getArq();
		
	protected:
		std::string dosagem;
		std::string administracao;
		std::string disponibilizacao;
};

#endif
