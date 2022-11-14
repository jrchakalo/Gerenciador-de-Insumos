#include "Vacina.h"

Vacina::Vacina(){
}

Vacina::Vacina(std::string n, int q, float val, std::string venci, 
std::string nomFab, int tipInsu, std::string tip, int qtD, int inter)
: Insumo(n, q, val, venci, nomFab, tipInsu)
{
	tipo = tip;
	quantDoses = qtD;
	intervalo = inter;
}

int Vacina::getQuant(){
	return quantidade;
}

float Vacina::getValUni(){
	return valorUnitario;
}

std::string Vacina::getTipo(){
	return tipo;
}
int Vacina::getQuatD(){
	return quantDoses;
}
int	Vacina::getInter(){
	return intervalo;
}

void Vacina::setQuant(int q){
	quantidade = q;
}

void Vacina::getDescInsu(){
	Insumo::getDescInsu();
	std::cout << "\t\t\t\tTecnologia da Vacina: " << tipo << std::endl;
	std::cout << "\t\t\t\tQuantidade de doses: " << quantDoses << std::endl;
	if(quantDoses > 1){
		std::cout << "\t\t\t\tIntervalo entre as doses: " << intervalo << std::endl;
	}			  
}

std::string Vacina::getArq(){
	std::string arq;
	arq = Insumo::getArq() + tipo + "," + std::to_string(quantDoses) + "," + std::to_string(intervalo) + ",";
	return arq;
}

