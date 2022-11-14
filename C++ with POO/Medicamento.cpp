#include "Medicamento.h"

Medicamento::Medicamento(){
}

Medicamento::Medicamento(std::string n, int q, float val, std::string venci, 
std::string nomFab, int tipInsu, std::string dos, std::string admin, std::string disp)
: Insumo(n, q, val, venci, nomFab, tipInsu)
{
	dosagem = dos;
	administracao = admin;
	disponibilizacao = disp;
}
	
int Medicamento::getQuant(){
	return quantidade;
}

float Medicamento::getValUni(){
	return valorUnitario;
}	
		
std::string Medicamento::getDos(){
	return dosagem;
}
std::string Medicamento::getAdmin(){
	return administracao;
}
std::string Medicamento::getDisp(){
	return disponibilizacao;
}

void Medicamento::setQuant(int q){
	quantidade = q;
}

void Medicamento::getDescInsu(){
	Insumo::getDescInsu();
	std::cout << "\t\t\t\tDosagem: " << dosagem << "\n" <<
				 "\t\t\t\tAdministracao: " << administracao << "\n" <<
				 "\t\t\t\tDisponibilizacao: " << disponibilizacao << "\n" << std::endl;
}

std::string Medicamento::getArq(){
	std::string arq;
	arq = Insumo::getArq() + dosagem + "," + administracao + "," + disponibilizacao + ",";
	return arq;
}
