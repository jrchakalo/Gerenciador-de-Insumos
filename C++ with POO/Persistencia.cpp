#include "Persistencia.h"

Persistencia::Persistencia(){
}

int Persistencia::lerInsumos(Controler *contr){
	std::string insu, comp;
	std::ifstream arq;
	
	arq.open("insumos.txt", std::ios::in);
	

	if(arq.is_open()){
		
		for(int i=0; i < 27; i++){
			
			do{
				std::getline(arq, insu);
				
				if(insu == "PROX"){
					break;
				}
				
				std::vector<std::string> val;
				std::string info;
				for(int j=0; j < insu.size(); j++){
					if(insu[j] != ','){
						info.push_back(insu[j]);
					}else{
						val.push_back(info);
						info.clear();
					}				
				}
				
				int local = stoi(val[0]);
				std::string nome = val[1];
				int quantidade = stoi(val[2]);
				float valorUnitario = stof(val[3]);
				std::string vencimento = val[4];
				std::string fabricante = val[5];
				int tipoInsumo = stoi(val[6]);
				
				switch(tipoInsumo){
					case 1:
						{
						std::string tipo = val[7];
						int quantDoses = stoi(val[8]);
						int intervalo = stoi(val[9]);
						contr->cadastraInsumos(new Vacina(nome, quantidade, valorUnitario, vencimento, fabricante, tipoInsumo, tipo, quantDoses, intervalo), local);
						break;
						}
					case 2:
						{
						std::string tipo = val[7];
						std::string descricao = val[8];
						contr->cadastraInsumos(new EPI(nome, quantidade, valorUnitario, vencimento, fabricante, tipoInsumo, tipo, descricao), local);
						break;
						}
					case 3:
						{
						std::string dosagem = val[7];
						std::string administracao = val[8];
						std::string disponibilidade = val[9];
						contr->cadastraInsumos(new Medicamento(nome, quantidade, valorUnitario, vencimento, fabricante, tipoInsumo, dosagem, administracao, disponibilidade), local);
						break;
						}		
				}	
			}while(1);
		
		}
		arq.close();
		return 1;	
	}else{
		std::cout << "*Não Foi Possivel Abrir o Arquivo!*" << std::endl;
		return 0;
	}
	
}

void Persistencia::salvarInsumos(Controler contr){
	std::ofstream arq;
	
	arq.open("insumos.txt", std::ios::out);
	
	for(int i=0; i < 27; i++){
		for(int j=0; j < contr.getLocal(i).getTotInsu(); j++){
			arq << std::to_string(i) + "," + contr.getLocal(i).getInsumo(j)->getArq() << std::endl;
		}
		arq << "PROX" << std::endl;	
	}
	
	arq.close();	
}
