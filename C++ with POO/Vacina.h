#ifndef VACINA_H
#define VACINA_H

#include "Insumo.h"

class Vacina : public Insumo
{
	public:
		Vacina();
		Vacina(std::string n, int q, float val, std::string venci, 
		std::string nomFab, int tipInsu, std::string tip, int qtD, int inter);
		
		int getQuant();
		float getValUni();
		std::string getTipo();
		int getQuatD();
		int	getInter();
		void setQuant(int q);
		void getDescInsu();
		std::string getArq();
				
	protected:
		std::string tipo;
		int quantDoses;
		int intervalo;
};

#endif
