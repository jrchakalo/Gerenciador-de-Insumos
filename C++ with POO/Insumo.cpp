#include "Insumo.h"

Insumo::Insumo(){
	quantidade = 0;
}

Insumo::Insumo(std::string n, int q, float val, std::string venci, 
std::string nomFab, int tipInsu){
	nome = n;
	quantidade = q;
	valorUnitario = val;
	dtVencimento = venci;
	nomeFabricante = nomFab;
	tipoInsumo = tipInsu;
}

Insumo::~Insumo(){
	
}

std::string Insumo::getNome(){
	return nome;
}
int Insumo::getQuant(){
	return quantidade;
}
float Insumo::getValUni(){
	return valorUnitario;
}
std::string Insumo::getDtVen(){
	return dtVencimento;
}
std::string Insumo::getNomFab(){
	return nomeFabricante;
}
int Insumo::getTipInsu(){
	return tipoInsumo;
}

void Insumo::setQuant(int q){
	quantidade = q;
}

void Insumo::getDescInsu(){
	std::cout << "\t\t\t\tNome: " << nome << "\n" <<
				 "\t\t\t\tQuantidade: " << quantidade << "\n" <<
				 "\t\t\t\tValor Unitario: R$" << valorUnitario << "\n" <<
				 "\t\t\t\tValor Total: R$" << valorUnitario*quantidade << "\n" <<
				 "\t\t\t\tData de Vencimento: " << dtVencimento << "\n" <<
				 "\t\t\t\tNome do Fabricante: " << nomeFabricante << std::endl;			
}

std::string Insumo::getArq(){
	std::string arq;
	arq = nome + "," + std::to_string(quantidade) + "," + std::to_string(valorUnitario) + "," + dtVencimento + "," + nomeFabricante + "," + std::to_string(tipoInsumo) + ",";
	return arq;
}
