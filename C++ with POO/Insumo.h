#ifndef INSUMO_H
#define INSUMO_H
#include <string>
#include <iostream>

#define SIZE 100

class Insumo
{
	public:
		Insumo();
		Insumo(std::string n, int q, float val, std::string venci, 
		std::string nomFab, int tipInsu);
		virtual ~Insumo();
		
		std::string getNome();
		virtual int getQuant();
		virtual float getValUni();
		std::string getDtVen();
		std::string getNomFab();
		int getTipInsu();
		virtual void setQuant(int q);
		virtual void getDescInsu();
		virtual std::string getArq();
		
	protected:
		std::string nome;
		int quantidade;
		float valorUnitario;
		std::string dtVencimento;
		std::string nomeFabricante;
		int tipoInsumo;
};

#endif
