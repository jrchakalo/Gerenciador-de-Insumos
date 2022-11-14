#include "Controler.h"

using namespace std;

Controler::Controler(){
}

Insumo* Controler::lerInsumosMS(int tipInsu){
	string n, venci, nomFab, nomeinsu; 
	int q;
	float val;
	
	system("cls");
	
	switch(tipInsu){
		case 1:
			nomeinsu = "Vacina";
			break;
		case 2:
			nomeinsu = "EPI";
			break;
		case 3:
			nomeinsu = "Medicacao";
			break;
	}
	
	
	Insumo *in;
	cout << "\t\t\t\tDigite o nome da " << nomeinsu << ": ";
	getline(cin, n);
	cout << "\t\t\t\tDigite o valor unitario dessa " << nomeinsu << ": R$";
	cin >> val;
	cout << "\t\t\t\tDigite a quantidade dessa " << nomeinsu << ": ";
	cin >> q;
	getchar();
	cout << "\t\t\t\tDigite a data de validade (dia/mes/ano): ";
	getline(cin, venci);
	cout << "\t\t\t\tDigite o nome do fabricante: ";
	getline(cin, nomFab);
	
	switch(tipInsu){
		case 1:
			{
			int doses, intervalo;
			string tip;
				
			cout << "\t\t\t\tDigite a tecnologia da vacina: ";
			getline(cin, tip);
					
			cout << "\t\t\t\tDigite quantas doses sao necessarias: ";
			cin >> doses;
			if (doses > 1){
				cout << "\t\t\t\tDigite o intervalo de dias entre as vacinas: ";
				cin >> intervalo;
			}
				
			in = new Vacina(n, q, val, venci, 
			nomFab, tipInsu, tip, doses, intervalo);
				
			break;
			}
		case 2:
			{
			string tipo, desc;
				
			cout << "\t\t\t\tDigite o tipo do item: ";
			getline(cin, tipo);
			cout << "\t\t\t\tDigite a descricao do item: ";
			getline(cin, desc);
				
			in = new EPI(n, q, val, venci, 
			nomFab, tipInsu, tipo, desc);
				
			break;
			}
		case 3:
			{
			string dos, admin, disp;
				
			cout << "\t\t\t\tDigite a dosagem (em mg): ";
			getline(cin, dos);
			cout << "\t\t\t\tDigite a administracao: ";
			getline(cin, admin);
			cout << "\t\t\t\tDigite a forma disponibilidade: ";
			getline(cin, disp);
				
			in = new Medicamento(n, q, val, venci, 
			nomFab, tipInsu, dos, admin, disp);
				
			break;		
			}	
	}
	return in;
}

int Controler::cadastraInsumosMS(Insumo *insu){
	int verif;
	
	verif = locais[0].existInsuMS(insu->getNome());
	
	if(verif < 0){
		locais[0].adicionaInsu(insu);
		return -1;	
	}
	
	return verif;
}

void Controler::cadastraInsumos(Insumo *insu, int indice){
	
	locais[indice].adicionaInsu(insu);
}

void Controler::consultaInsumos(int indice){
	system("cls");
	
	cout << "\t\t\t\tAtualmente existem " << locais[indice].getTotInsu() << " tipo(s) de Insumo(s) no estoque desse local, em um total de " << endl;
	cout << "\t\t\t\t" << locais[indice].getTotQuant() << " unidade(s), em um valor corresponde a R$" << locais[indice].getTotVal() << "." << endl;
	cout << "\t\t\t\tEsses tipos sao: " << endl;
	cout << endl;
	
	cout << "\t\t\t\t" << locais[indice].getTotVEM(1) << " Vacina(s) com " << locais[indice].getQuantVEM(1) << " unidades em um valor corresponde a R$" << locais[indice].getValVEM(1) << ":" << endl;
	locais[indice].printNomInsu(1);
	cout << endl;
	cout << "\t\t\t\t" << locais[indice].getTotVEM(2) << " EPI(s) com " << locais[indice].getQuantVEM(2) << " unidades em um valor corresponde a R$" << locais[indice].getValVEM(2) << ":" << endl;
	locais[indice].printNomInsu(2);
	cout << endl;
	cout << "\t\t\t\t" << locais[indice].getTotVEM(3) << " Medicamento(s) com " << locais[indice].getQuantVEM(3) << " unidades em um valor corresponde a R$" << locais[indice].getValVEM(3) << ":" << endl;
	locais[indice].printNomInsu(3);
	cout << endl;
	
	system("pause");
	system("cls");
}

void Controler::consultaInsumosDescricao(int indice){
	system("cls");
	
	cout << "\t\t\t\tAtualmente existem " << locais[indice].getTotInsu() << " tipo(s) de Insumo(s) no estoque desse local, em um total de " << endl;
	cout << "\t\t\t\t" << locais[indice].getTotQuant() << " unidade(s), em um valor corresponde a R$" << locais[indice].getTotVal() << "." << endl;
	cout << "\t\t\t\tEsses tipos sao: " << endl;
	cout << endl;
	
	cout << "\t\t\t\t" << locais[indice].getTotVEM(1) << " Vacina(s) com " << locais[indice].getQuantVEM(1) << " unidades em um valor corresponde a R$" << locais[indice].getValVEM(1) << ":" << endl;
	locais[indice].getDescricao(1);
	cout << endl;
	cout << "\t\t\t\t" << locais[indice].getTotVEM(2) << " EPI(s) com " << locais[indice].getQuantVEM(2) << " unidades em um valor corresponde a R$" << locais[indice].getValVEM(2) << ":" << endl;
	locais[indice].getDescricao(2);
	cout << endl;
	cout << "\t\t\t\t" << locais[indice].getTotVEM(3) << " Medicamento(s) com " << locais[indice].getQuantVEM(3) << " unidades em um valor corresponde a R$" << locais[indice].getValVEM(3) << ":" << endl;
	locais[indice].getDescricao(3);
	cout << endl;
	
	system("pause");
	system("cls");
}

void Controler::consultaInsumos(int indice, int tipoInsumo){
	string nomInsu;
	system("cls");
	
	switch(tipoInsumo){
		case 1:
			nomInsu = "Vacina(s)";
			break;
		case 2:
			nomInsu = "EPI(s)";
			break;
		case 3:
			nomInsu = "Medicamento(s)";
			break;
	}
	
	cout << "\t\t\t\tAtualmente existem " << locais[indice].getTotVEM(tipoInsumo) << " tipo(s) de " << nomInsu << " no estoque desse local, em um total de " << endl;
	cout << "\t\t\t\t" << locais[indice].getQuantVEM(tipoInsumo) << " unidade(s), em um valor corresponde a R$" << locais[indice].getValVEM(tipoInsumo) << "." << endl;
	cout << "\t\t\t\tEssas sao: " << endl;
	cout << endl;
	
	locais[indice].getDescricao(tipoInsumo);
	cout << endl;
	
	system("pause");
	system("cls");
}

void Controler::distribuiInsumo(int dest, int tip){
	system("cls");
	string nomInsu, transf, text;
	int exist, quant, aux;
	
	switch(tip){
		case 1:
			nomInsu = "Vacina";
			break;
		case 2:
			nomInsu = "EPI";
			break;
		case 3:
			nomInsu = "Medicamento";
			break;
	}
	
	cout << "\t\t\t\t" << nomInsu << "(s) disponiveis no estoque do Ministerio da saude:" << endl;
	cout << endl;
	
	locais[0].printNomInsu(tip);
	cout << endl;
	
	cout << "\t\t\t\tQual " << nomInsu << " deseja transferir: ";
	getline(cin, transf);
	
	exist = locais[0].existInsuMS(transf);
	
	if(exist != -1){
		cout << "\t\t\t\tQuantas unidades deseja transferir: ";
		cin >> quant;
		getchar();
		int x=0;
		
		if(quant > locais[0].getInsuQuant(exist)){
			x++;
			cout << "\t\t\t\t*Quantidade Invalida*" << endl;
			system("pause");
		}else{
			if(locais[dest].existInsuMS(transf) != -1){
				int ind = locais[dest].existInsuMS(transf);
				locais[dest].mudaQuantMS(locais[dest].getInsuQuant(ind)+quant, ind);
				locais[0].mudaQuantMS(locais[0].getInsuQuant(exist)-quant, exist);
			}else{
				aux = locais[0].getInsuQuant(exist) - quant;
			
				if(locais[0].getInsumo(exist)->getTipInsu() == 1){
					locais[dest].adicionaInsu(new Vacina());
					*((Vacina*) locais[dest].getInsumo(locais[dest].getTotInsu()-1)) = *((Vacina*) locais[0].getInsumo(exist));
					locais[0].mudaQuantMS(aux, exist);
					locais[dest].mudaQuantMS(quant, locais[dest].getTotInsu()-1);
				}else if(locais[0].getInsumo(exist)->getTipInsu() == 2){
					locais[dest].adicionaInsu(new EPI());
					*((EPI*) locais[dest].getInsumo(locais[dest].getTotInsu()-1)) = *((EPI*) locais[0].getInsumo(exist));
					locais[0].mudaQuantMS(aux, exist);
					locais[dest].mudaQuantMS(quant, locais[dest].getTotInsu()-1);	
				}else{
					locais[dest].adicionaInsu(new Medicamento());
					*((Medicamento*) locais[dest].getInsumo(locais[dest].getTotInsu()-1)) = *((Medicamento*) locais[0].getInsumo(exist));
					locais[0].mudaQuantMS(aux, exist);
					locais[dest].mudaQuantMS(quant, locais[dest].getTotInsu()-1);
					}
				}	
			}	
			
			cout << endl;
			if(x<1){
				cout << "\t\t\t\tTransferencia Concluida!" << endl;
			}
			x=0;
			system("pause");		
	}else{
		cout << "\t\t\t\t*O Insumo Nao Existe*" << endl;
		system("pause");	
	}	
}

void Controler::exibeHistorico(int indice){
	system("cls");
	
	if(locais[indice].getTotInsu() < 1){
		cout << "\t\t\t\t*Nao a nenhuma transferencia para " << estados[indice] << "." << endl; 
	}else{
		cout << "\t\t\t\tForam destribuidos um total de " << locais[indice].getTotInsu() << " Insumo(s) para " << estados[indice] << ", em um total de " << endl;
		cout << "\t\t\t\t" << locais[indice].getTotQuant() << " unidade(s), em um valor corresponde a R$" << locais[indice].getTotVal() << "." << endl;
		cout << "\t\t\t\tEsses insumos sao: " << endl;
		cout << endl;
	
		locais[indice].getTdInsu();	
	}
	
	system("pause");		
}

Local Controler::getLocal(int pos){
	return locais[pos];
}
