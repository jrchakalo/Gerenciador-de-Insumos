#include "EPI.h"

EPI::EPI(){
}

EPI::EPI(std::string n, int q, float val, std::string venci, 
std::string nomFab, int tipInsu, std::string t, std::string desc)
: Insumo(n, q, val, venci, nomFab, tipInsu)
{
	tipo = t;
	descricao = desc;
}

int EPI::getQuant(){
	return quantidade;
}

float EPI::getValUni(){
	return valorUnitario;
}
		
std::string EPI::getTipo(){
	return tipo;
}
std::string EPI::getDesc(){
	return descricao;
}

void EPI::setQuant(int q){
	quantidade = q;
}

void EPI::getDescInsu(){
	Insumo::getDescInsu();
	std::cout << "\t\t\t\tTipo da EPI: " << tipo << std::endl;
	std::cout << "\t\t\t\tDescricao: " << descricao << std::endl;
}

std::string EPI::getArq(){
	std::string arq;
	arq = Insumo::getArq() + tipo + "," + descricao + ",";
	return arq;
}
