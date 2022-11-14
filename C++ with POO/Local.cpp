#include "Local.h"

using namespace std;

Local::Local(){
	tipo = 0;
}

Local::Local(std::string n, int ti){
	nome = n;
	tipo = ti;
}
		
std::string Local::getNom(){
	return nome;
}
int Local::getTipo(){
	return tipo;
}

void Local::adicionaInsu(Insumo *insu){
	insumos.push_back(insu);
}

int Local::existInsuMS(std::string nome){
	int result = -1;
	
	for(int i=0; i < insumos.size(); i++){
		if(insumos[i]->getNome() == nome){
			result = i;
			break;
		}
	}
	
	return result;
}

Insumo* Local::getInsumo(int pos){
	return insumos[pos];
}

void Local::getDescricao(int tip){
	for(int i=0; i < insumos.size(); i++){
		if(insumos[i]->getTipInsu() == tip){
			insumos[i]->getDescInsu();
			std::cout << "\n";
		}
	}
}

int Local::getTotQuant(){
	int quant=0, vac=0, epi=0, med=0;	
	
	for(int i=0; i < insumos.size(); i++){
		if(insumos[i]->getTipInsu() == 1){
			vac += insumos[i]->getQuant();
		}		
	}
	
	for(int i=0; i < insumos.size(); i++){
		if(insumos[i]->getTipInsu() == 2){
			epi += insumos[i]->getQuant();
		}		
	}
	
	for(int i=0; i < insumos.size(); i++){
		if(insumos[i]->getTipInsu() == 3){
			med += insumos[i]->getQuant();
		}		
	}
	
	quant = vac+epi+med;
	
	return quant;
}

float Local::getTotVal(){
	float val;
	
	for(int i=0; i < insumos.size(); i++){
		val += insumos[i]->getValUni()*insumos[i]->getQuant();
	}
	
	return val;	
}

int Local::getTotInsu(){
	return insumos.size();
}

int Local::getTotVEM(int tip){
	int vac=0, epi=0, med=0;
	
	for(int i=0; i < insumos.size(); i++){
		switch(insumos[i]->getTipInsu()){
			case 1:
				vac++;
				break;
			case 2:
				epi++;
				break;
			case 3:
				med++;
				break;
		}
	}
	
	switch(tip){
		case 1:
			return vac;
			break;
		case 2:
			return epi;
			break;
		case 3:
			return med;
			break;
	}
	
}

int Local::getQuantVEM(int tip){
	int vac=0, epi=0, med=0;
	
	for(int i=0; i < insumos.size(); i++){
		switch(insumos[i]->getTipInsu()){
			case 1:
				vac += insumos[i]->getQuant();
				break;
			case 2:
				epi += insumos[i]->getQuant();
				break;
			case 3:
				med += insumos[i]->getQuant();
				break;
		}
	}
	
	switch(tip){
		case 1:
			return vac;
			break;
		case 2:
			return epi;
			break;
		case 3:
			return med;
			break;
	}	
}

int Local::getValVEM(int tip){
	int vac=0, epi=0, med=0;
	
	for(int i=0; i < insumos.size(); i++){
		switch(insumos[i]->getTipInsu()){
			case 1:
				vac += insumos[i]->getQuant()*insumos[i]->getValUni();
				break;
			case 2:
				epi += insumos[i]->getQuant()*insumos[i]->getValUni();
				break;
			case 3:
				med += insumos[i]->getQuant()*insumos[i]->getValUni();
				break;
		}
	}
	
	switch(tip){
		case 1:
			return vac;
			break;
		case 2:
			return epi;
			break;
		case 3:
			return med;
			break;
	}		
}

void Local::printNomInsu(int tip){
	for(int i=0; i < insumos.size(); i++){
		if(insumos[i]->getTipInsu() == tip){
			std::cout << "\t\t\t\t" << insumos[i]->getNome() << " com " << insumos[i]->getQuant() << " unidades a R$" << insumos[i]->getValUni() << " cada." << std::endl;
		}
	}
}

void Local::mudaQuantMS(int quant, int indice){
	insumos[indice]->setQuant(quant);
}

int Local::getInsuQuant(int indice){
	return insumos[indice]->getQuant();
}

void Local::getTdInsu(){
	for(int i=0; i < insumos.size(); i++){
		std::cout << "\t\t\t\t" << insumos[i]->getNome() << " com " << insumos[i]->getQuant() << " unidades a R$" << insumos[i]->getValUni() << " cada." << std::endl;	
	}
}
