#ifndef LOCAL_H
#define LOCAL_H
#include <string>
#include <vector>
#include <iostream>
#include "Insumo.h"

class Local
{
	public:
		Local();
		Local(std::string n, int ti);
		
		std::string getNom();
		int getTipo();
		void adicionaInsu(Insumo *insu);
		int existInsuMS(std::string nome);
		Insumo* getInsumo(int pos);
		void getDescricao(int tip);
		int getTotQuant();
		float getTotVal();
		int getTotInsu();
		int getTotVEM(int tip);
		int getQuantVEM(int tip);
		int getValVEM(int tip);
		void printNomInsu(int tip);
		void mudaQuantMS(int quant, int indice);
		int getInsuQuant(int indice);
		void getTdInsu();
		
	private:
		std::string nome;
		int tipo;
		std::vector <Insumo*>insumosVec;
		Insumo *insumosArr[3];
};

#endif
