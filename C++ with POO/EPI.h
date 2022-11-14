#ifndef EPI_H
#define EPI_H

#include "Insumo.h"

class EPI : public Insumo
{
	public:
		EPI();
		EPI(std::string n, int q, float val, std::string venci, 
		std::string nomFab, int tipInsu, std::string t, std::string desc);
		
		int getQuant();
		float getValUni();
		std::string getTipo();
		std::string getDesc();
		void setQuant(int q);
		void getDescInsu();
		std::string getArq();
		
	protected:
		std::string tipo;
		std::string descricao;
};

#endif
