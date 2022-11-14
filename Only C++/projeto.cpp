#include <string>
#include <iostream>
#include <string.h>
#include "projeto.h"

using namespace std;

#define SIZE 200

typedef struct Vacina{
	string tecnologia;
	string nom;
	string fabricante;
	float valor;
	int quant;
	int quantdose;
	int intervalo;
	int valdia;
	int valmes;
	int valano;
}t_vacina;

typedef struct EPI{
	string desc;
	string nom;
	string fabricante;
	float valor;
	int quant;
	int valdia;
	int valmes;
	int valano;
}t_epi;

typedef struct Medicamento{
	string nome;
	string fabricante;
	string modoDeUso;
	string formaFarmaceutica;
	float valor;
	int quantidade;
	int dosagem;
	int valdia;
	int valmes;
	int valano;
}t_medicamento;

typedef struct TransferenciaEstado{
	string nomeVacina;
	int quantVacina;
	string nomeEpi;
	int quantEpi;
	string nomeMedicamento;
	int quantMedicamento;

}t_transferenciaEstado;

static int linha1=0, linha2=0, linha3=0, linha4=0, linha5=0, linha6=0, qvac=0, qepi=0, qmed=0, qtot=0;
static int estoquevacina=0, estoqueepi=0, estoquemed=0, estoquetotal=0, valorvacina=0, valorepi=0, valormed=0, valortotal=0;
t_vacina vacina[SIZE];
t_epi epi[SIZE];
t_medicamento medicamento[SIZE];
t_transferenciaEstado AC[SIZE], AL[SIZE], AP[SIZE], AM[SIZE], BA[SIZE], CE[SIZE], DF[SIZE], ES[SIZE], GO[SIZE],
                        MA[SIZE], MT[SIZE], MS[SIZE], MG[SIZE], PA[SIZE], PB[SIZE], PR[SIZE], PE[SIZE], PI[SIZE],
                        RR[SIZE], RO[SIZE], RJ[SIZE], RN[SIZE], RS[SIZE], SC[SIZE], SP[SIZE], SE[SIZE], TO[SIZE];


void tipoCadastro(){
	int alter, n;
	system("cls");

	do{
		n=0;
		cout << "\t\t\t\tO que voce deseja cadastrar?" << endl;
		cout << endl;
		cout << "\t\t\t\t<1> Para cadastrar Vacina" << endl;
		cout << "\t\t\t\t<2> Para cadastrar EPI" << endl;
		cout << "\t\t\t\t<3> Para cadastrar Medicamento" << endl;
		cout << "\t\t\t\t<0> Para voltar ao menu principal" << endl;

		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				n++;
				break;
			case 1:
				cadastroVacina();
				break;
			case 2:
				cadastroEPI();
				break;
			case 3:
			    cadastroMedicamento();
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n=0);

}

void cadastroVacina(){
	int cad, n;

	system("cls");

	do{

		cout << "\t\t\t\tDigite o nome da Vacina: ";
		getchar();
		getline(cin, vacina[linha1].nom);
		cout << "\t\t\t\tDigite o valor unitario dessa Vacina: R$";
		cin >> vacina[linha1].valor;
		cout << "\t\t\t\tDigite a quantidade dessa Vacina: ";
		cin >> vacina[linha1].quant;
		do{
			cout << "\t\t\t\tDigite a data de validade (dia/mes/ano): ";
			n = 0;
			scanf("%d/%d/%d", &vacina[linha1].valdia, &vacina[linha1].valmes, &vacina[linha1].valano);
			if(vacina[linha1].valdia >= 32 || vacina[linha1].valdia <= 0){
				cout << "\t\t\t\t*Dia invalido*\n";
				n++;
			}
			if(vacina[linha1].valmes >= 13 || vacina[linha1].valmes <= 0){
				cout << "\t\t\t\t*Mes invalido*\n";
				n++;
			}
		}while(n > 0);
		getchar();
		cout << "\t\t\t\tDigite o nome do fabricante: ";
		getline(cin, vacina[linha1].fabricante);
		cout << "\t\t\t\tDigite a tecnologia da vacina: ";
		getline(cin, vacina[linha1].tecnologia);
		cout << "\t\t\t\tDigite quantas doses sao necessarias: ";
		cin >> vacina[linha1].quantdose;
		if (vacina[linha1].quantdose > 1){
			cout << "\t\t\t\tDigite o intervalo de dias entre as vacinas: ";
			cin >> vacina[linha1].intervalo;
		}

		cadastroEstoque();
		cout << "\t\t\t\tDigite 1 para cadastrar novamente e 0 para sair: ";
		cin >> cad;
		linha1++;
		qvac++;
		qtot++;
		system("cls");
	}while(cad == 1);
}

void cadastroEPI(){
	int cad, n;

	system("cls");

	do{

		cout << "\t\t\t\tDigite o nome da EPI: ";
		getchar();
		getline(cin, epi[linha2].nom);
		cout << "\t\t\t\tDigite o valor unitario dessa EPI: R$";
		cin >> epi[linha2].valor;
		cout << "\t\t\t\tDigite a quantidade dessa EPI: ";
		cin >> epi[linha2].quant;
		do{
			cout << "\t\t\t\tDigite a data de validade (dia/mes/ano): ";
			n = 0;
			scanf("%d/%d/%d", &epi[linha2].valdia, &epi[linha2].valmes, &epi[linha2].valano);
			if(epi[linha2].valdia >= 32 || epi[linha2].valdia <= 0){
				cout << "\t\t\t\t*Dia invalido*\n";
				n++;
			}
			if(epi[linha2].valmes >= 13 || epi[linha2].valmes <= 0){
				cout << "\t\t\t\t*Mes invalido*\n";
				n++;
			}
		}while(n > 0);
		getchar();
		cout << "\t\t\t\tDigite o nome do fabricante: ";
		getline(cin, epi[linha2].fabricante);
		cout << "\t\t\t\tDigite a descricao do item: ";
		getline(cin, epi[linha2].desc);

		cadastroEstoque();
		cout << "\t\t\t\tDigite 1 para cadastrar novamente e 0 para sair: ";
		cin >> cad;
		linha2++;
		qepi++;
		qtot++;
		system("cls");
	}while(cad == 1);
}

void cadastroMedicamento(){
	int cad, n;

	system("cls");

    do{

		cout << "\t\t\t\tDigite o nome do medicamento: ";
		getchar();
		getline(cin, medicamento[linha3].nome);
		cout << "\t\t\t\tDigite seu valor unitario: R$";
		cin >> medicamento[linha3].valor;
		cout << "\t\t\t\tDigite a quantidade adquirida: ";
		cin >> medicamento[linha3].quantidade;
		do{
			cout << "\t\t\t\tDigite a data de validade (dia/mes/ano): ";
			n = 0;
			scanf("%d/%d/%d", &medicamento[linha3].valdia, &medicamento[linha3].valmes, &medicamento[linha3].valano);
			if(medicamento[linha3].valdia >= 32 || medicamento[linha3].valdia <= 0){
				cout << "\t\t\t\t*Dia invalido*\n";
				n++;
			}
			if(medicamento[linha3].valmes >= 13 || medicamento[linha3].valmes <= 0){
				cout << "\t\t\t\t*Mes invalido*\n";
				n++;
			}
		}while(n > 0);
		getchar();
		cout << "\t\t\t\tDigite o nome do fabricante: ";
		getline(cin, medicamento[linha3].fabricante);
		cout << "\t\t\t\tDigite o modo de uso (sublingual, pela pele," << endl;
		cout << "\t\t\t\tinjecao, inalacao, gotas ou via oral): ";
		getline(cin, medicamento[linha3].modoDeUso);
        /*
        if(strcmp(medicamento[linha3].modoDeUso, "Gotas") == 0){
        cout << "Digite a dosagem em mg: ";
        cin >> medicamento[linha3].dosagem;
        }
        */
		cout << "\t\t\t\tDigite a forma farmaceutica (comprimido, capsula," << endl;
		cout << "\t\t\t\txarope, injetavel, spray): ";
		getline(cin, medicamento[linha3].formaFarmaceutica);

		cadastroEstoque();
		cout << "\t\t\t\tDigite 1 para cadastrar novamente e 0 para sair: ";
		cin >> cad;
		linha3++;
		qmed++;
		qtot++;
		system("cls");
	}while(cad == 1);
}

void tipoVerif(){
	int alter, n;
	system("cls");

	do{
		n=0;
		cout << "\t\t\t\tO que voce deseja consultar?" << endl;
		cout << endl;
		cout << "\t\t\t\t<1> Para consultar Vacina" << endl;
		cout << "\t\t\t\t<2> Para consultar EPI" << endl;
		cout << "\t\t\t\t<3> Para consultar Medicamento" << endl;
		cout << "\t\t\t\t<0> Para voltar ao menu principal" << endl;
		
		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				n++;
				break;
			case 1:
				verifVacina();
				break;
			case 2:
				verifEPI();
				break;
			case 3:
			    verifiMedicamento();
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n=0);
}

void printVerifVacina(int i){
	cout << "\t\t\t\tNome da Vacina: " << vacina[i].nom << endl;
	cout << "\t\t\t\tValor unitario da Vacina: R$" << vacina[i].valor << endl;
	cout << "\t\t\t\tQuantidade de Vacinas: " << vacina[i].quant << endl;
	cout << "\t\t\t\tValor total das Vacinas: R$" << (vacina[i].valor*vacina[i].quant) << endl;
	printf("\t\t\t\tData de vencimento da Vacina: %02d/%02d/%d\n", vacina[i].valdia, vacina[i].valmes, vacina[i].valano);
	cout << "\t\t\t\tFabricante da Vacina: " << vacina[i].fabricante << endl;
	cout << "\t\t\t\tTecnologia da Vacina: " << vacina[i].tecnologia << endl;
	cout << "\t\t\t\tQuantidade de doses da Vacina: " << vacina[i].quantdose << " doses" << endl;
	if(vacina[i].quantdose > 1){
		cout << "\t\t\t\tIntervalo entre as doses: " << vacina[i].intervalo << " dias" << endl;
	}
}

void printVerifEPI(int i){
	cout << "\t\t\t\tNome da EPI: " << epi[i].nom << endl;
	cout << "\t\t\t\tValor unitario da EPI: R$" << epi[i].valor << endl;
	cout << "\t\t\t\tQuantidade de EPIs: " << epi[i].quant << endl;
	cout << "\t\t\t\tValor total das EPIs: R$" << (epi[i].valor*epi[i].quant) << endl;
	printf("\t\t\t\tData de vencimento da EPI: %02d/%02d/%d\n", epi[i].valdia, epi[i].valmes, epi[i].valano);
	cout << "\t\t\t\tFabricante da EPI: " << epi[i].fabricante << endl;
	cout << "\t\t\t\tDescricao da EPI: " << epi[i].desc << endl;
}

void printVerifMedicamento(int i){
	cout << "\t\t\t\tNome do Medicamento: " << medicamento[i].nome << endl;
	cout << "\t\t\t\tValor unitario do Medicamento: R$" << medicamento[i].valor << endl;
	cout << "\t\t\t\tQuantidade do Medicamento: " << medicamento[i].quantidade << endl;
	cout << "\t\t\t\tValor total dos Medicamentos: R$" << (medicamento[i].valor*medicamento[i].quantidade) << endl;
	printf("\t\t\t\tData de vencimento do Medicamento: %02d/%02d/%d\n", medicamento[i].valdia, medicamento[i].valmes, medicamento[i].valano);
	cout << "\t\t\t\tFabricante do Medicamento: " << medicamento[i].fabricante << endl;
	cout << "\t\t\t\tModo de uso: " << medicamento[i].modoDeUso << endl;
	cout << "\t\t\t\tForma farmaceutica: " << medicamento[i].formaFarmaceutica << endl;
}

void cadastroEstoque(){
	estoquevacina += vacina[linha1].quant;
	estoqueepi += epi[linha2].quant;
	estoquemed += medicamento[linha3].quantidade;
	estoquetotal = estoquevacina + estoqueepi + estoquemed;
	
	valorvacina += vacina[linha1].valor * vacina[linha1].quant;
	valorepi += epi[linha2].valor * epi[linha2].quant;
	valormed += medicamento[linha3].valor * medicamento[linha3].quantidade;
	valortotal = valorvacina + valorepi + valormed;
}

void estoqueVacina(){
	int i;

	system("cls");

	cout << "\t\t\t\tAtualmente existem " << qvac << " tipo(s) de vacina(s) no estoque em um total de " << endl;
	cout << "\t\t\t\t" << estoquevacina << " quantidade de unidades em um valor corresponde a R$" << valorvacina << "." << endl;
	cout << "\t\t\t\tEsses tipos sao: " << endl;
	for(i=0; i < qvac; i++){
		cout << "\t\t\t\t" << vacina[i].nom << ": Com " << vacina[i].quant << " unidades." << endl;
		puts("");
	}

	getchar();
	getchar();
}

void estoqueEPI(){
	int i;

	system("cls");

	cout << "\t\t\t\tAtualmente existem " << qepi << " tipo(s) de EPI(s) no estoque em um total de " << endl;
	cout << "\t\t\t\t" << estoqueepi << " quantidade de unidades em um valor corresponde a R$" << valorepi << "." << endl;
	cout << "\t\t\t\tEsses tipos sao: " << endl;
	for(i=0; i < qepi; i++){
		cout << "\t\t\t\t" << epi[i].nom << ": Com " << epi[i].quant << " unidades." << endl;
		puts("");
	}

	getchar();
	getchar();
}

void estoqueMedicamento(){
	int i;

	system("cls");

	cout << "\t\t\t\tAtualmente existem " << qmed << " tipo(s) de medicamento(s) no estoque em um total de " << endl;
	cout << "\t\t\t\t" << estoquemed << " quantidade de unidades em um valor corresponde a R$" << valormed << "." << endl;
	cout << "\t\t\t\tEsses tipos sao: " << endl;
	for(i=0; i < qmed; i++){
		cout << "\t\t\t\t" << medicamento[i].nome << ": Com " << medicamento[i].quantidade << " unidades." << endl;
		puts("");
	}

	getchar();
	getchar();
}

void estoqueTotal(){
	system("cls");

	cout << "\t\t\t\tAtualmente existem " << qtot << " tipo(s) de Insumo(s) no estoque em um total de " << endl;
	cout << "\t\t\t\t" << estoquetotal << " quantidade de unidades em um valor corresponde a R$" << valortotal << "." << endl;
	cout << "\t\t\t\tEsses tipos sao: " << endl;
	puts("");
	cout << "\t\t\t\t" << qvac << " Vacina(s) com " << estoquevacina << " unidades em um valor corresponde a R$" << valorvacina << "." << endl;
	puts("");
	cout << "\t\t\t\t" << qepi << " EPI(s) com " << estoqueepi << " unidades em um valor corresponde a R$" << valorepi << "." << endl;
	puts("");
	cout << "\t\t\t\t" << qmed << " Medicamento(s) com " << estoquemed << " unidades em um valor corresponde a R$" << valormed << "." << endl;
	puts("");

	getchar();
	getchar();
}

void estoqueDetalhado(){
	int i;

	system("cls");

	cout << "\t\t\t\tAtualmente existem " << qtot << " tipo(s) de Insumo(s) no estoque em um total de " << endl;
	cout << "\t\t\t\t" << estoquetotal << " quantidade de unidades em um valor corresponde a R$" << valortotal << "." << endl;
	cout << "\t\t\t\tEsses tipos sao: " << endl;
	puts("");
	cout << "\t\t\t\t" << qvac << " Vacina(s) com " << estoquevacina << " unidades em um valor corresponde a R$" << valorvacina << "." << endl;
	cout << "\t\t\t\tSendo ela(s): " << endl;
	puts("");
	for(i=0; i < qvac; i++){
		printVerifVacina(i);
		puts("");
	}
	cout << "\t\t\t\t" << qepi << " EPI(s) com " << estoqueepi << " unidades em um valor corresponde a R$" << valorepi << "." << endl;
	cout << "\t\t\t\tSendo ele(s): " << endl;
	puts("");
	for(i=0; i < qepi; i++){
		printVerifEPI(i);
		puts("");
	}
	cout << "\t\t\t\t" << qmed << " Medicamentos(s) com " << estoquemed << " unidades em um valor corresponde a R$" << valormed << "." << endl;
	cout << "\t\t\t\tSendo ele(s): " << endl;
	puts("");
	for(i=0; i < qmed; i++){
		printVerifMedicamento(i);
		puts("");
	}

	getchar();
	getchar();
}

void consultaEstoque(){
	int alter, n;

	system("cls");

	do{
		n=0;
		cout << "\t\t\t\tQual estoque deseja consultar?" << endl;
		cout << endl;
		cout << "\t\t\t\t<1> Para consultar estoque de Vacina" << endl;
		cout << "\t\t\t\t<2> Para consultar estoque de EPI" << endl;
		cout << "\t\t\t\t<3> Para consultar estoque de Medicamento" << endl;
		cout << "\t\t\t\t<4> Para consultar estoque Total" << endl;
		cout << "\t\t\t\t<5> Para consultar estoque Detalhado" << endl;
		cout << "\t\t\t\t<0> Para sair" << endl;

		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				n++;
				break;
			case 1:
				estoqueVacina();
				break;
			case 2:
				estoqueEPI();
				break;
			case 3:
				estoqueMedicamento();
				break;
			case 4:
				estoqueTotal();
				break;
			case 5:
				estoqueDetalhado();
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n=0);
}

void verifVacina(){
	string vacinaPesquisa;
	int i, n, cad;

	system("cls");

	do{
		n = 0;
		cout << "\t\t\t\tDigite o nome do Vacina que voce quer verificar: ";
		cout << endl;
		getchar();
		getline(cin, vacinaPesquisa);

		for(i=0; i < SIZE; i++){
			if(vacina[i].nom == vacinaPesquisa){
				printVerifVacina(i);
				n++;
			}
		}

		if(n < 1){
			cout << "\t\t\t\t*A Vacina nao esta cadastrada.*\n";
		}

		cout << "\t\t\t\tDigite 1 para consultar novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void verifEPI(){
	string epiPesquisa;
	int i, n, cad;

	system("cls");

	do{
		n = 0;
		cout << "\t\t\t\tDigite o nome do EPI que voce quer verificar: ";
		cout << endl;
		getchar();
		getline(cin, epiPesquisa);

		for(i=0; i < SIZE; i++){
			if(epi[i].nom == epiPesquisa){
				printVerifEPI(i);
				n++;
			}
		}

		if(n < 1){
			cout << "\t\t\t\t*O EPI nao esta cadastrado.*\n";
		}

		cout << "\t\t\t\tDigite 1 para consultar novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void verifiMedicamento(){
    string medicamentoPesquisa;
	int i, n, cad;

	system("cls");

	do{
		n = 0;
		cout << "\t\t\t\tDigite o nome do medicamento: ";
		cout << endl;
		getchar();
		getline(cin, medicamentoPesquisa);

		for(i=0; i < SIZE; i++){
			if(medicamento[i].nome == medicamentoPesquisa){
				printVerifMedicamento(i);
				n++;
			}
		}

		if(n < 1){
			cout << "\t\t\t\t*O medicamento nao esta cadastrado.*\n";
		}

		cout << "\t\t\t\tDigite 1 para consultar novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void tipoAdiciona(){

    int alter, n;
	system("cls");

	do{
		n=0;
		cout << "\t\t\t\tQual insumo voce deseja adicionar ao estoque?" << endl;
		cout << endl;
		cout << "\t\t\t\t<1> Para Vacina" << endl;
		cout << "\t\t\t\t<2> Para EPI" << endl;
		cout << "\t\t\t\t<3> Para Medicamento" << endl;
		cout << "\t\t\t\t<0> Para voltar ao menu principal" << endl;

		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				n++;
				break;
			case 1:
                adicionaVacina();
				break;
			case 2:
                adicionaEpi();
				break;
			case 3:
                adicionaMedicamento();
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n=0);
}

void adicionaVacina(){

    system("cls");

    string vacinaEscolhida;
    int i, n, cad, quantidade, m;

    do{
		n = 0;
		m = 0;
		cout << "\t\t\t\tInsira a vacina: ";
        getchar();
        getline(cin, vacinaEscolhida);
        cout << endl;
        
        for(i=0; i<SIZE; i++){
        	if(vacina[i].nom == vacinaEscolhida){
        		m++;
			}
		}
		if(m < 1){
			cout << "\t\t\t\t*A Vacina nao esta cadastrada.*\n" << endl;
		}else{
        	cout << "\t\t\t\tInsira a quantidade a ser adicionada: ";
        	cin >> quantidade;

        	for(i=0; i<SIZE; i++){
    			if(vacina[i].nom == vacinaEscolhida){
    				estoquevacina+=quantidade;
    				estoquetotal+=quantidade;
           	        vacina[i].quant+=quantidade;
    				n++;
    			}
      	    }
		}
		
		cout << "\t\t\t\tDigite 1 para adicionar novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void adicionaEpi(){

    system("cls");

    string epiEscolhida;
    int i, n, cad, quantidade, m;

    do{
		n = 0;
		m = 0;
		cout << "\t\t\t\tInsira a EPI: ";
        getchar();
        getline(cin, epiEscolhida);
        cout << endl;
        
        for(i=0; i<SIZE; i++){
    		if(epi[i].nom == epiEscolhida){
    			m++;
    		}
        }
        if(m < 1){
			cout << "\t\t\t\t*A EPI nao esta cadastrada.*\n" << endl;
		}else{
       		cout << "\t\t\t\tInsira a quantidade a ser adicionada: ";
        	cin >> quantidade;

        	for(i=0; i<SIZE; i++){
    			if(epi[i].nom == epiEscolhida){
    				estoqueepi+=quantidade;
    				estoquetotal+=quantidade;
       	            epi[i].quant+=quantidade;
   					n++;
    			}
       	    }
       	}

		cout << "\t\t\t\tDigite 1 para adicionar novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void adicionaMedicamento(){

    system("cls");

    string medicamentoEscolhido;
    int i, n, cad, quantidade, m;

    do{
		n = 0;
		m = 0;
		cout << "\t\t\t\tInsira o medicamento: ";
        getchar();
        getline(cin, medicamentoEscolhido);
        cout << endl;
        
        for(i=0; i<SIZE; i++){
    		if(medicamento[i].nome == medicamentoEscolhido){
    			m++;
			}
		}
        if(m < 1){
			cout << "\t\t\t\t*O medicamento nao esta cadastrado.*\n" << endl;
		}else{
       		cout << "\t\t\t\tInsira a quantidade a ser adicionada: ";
        	cin >> quantidade;

        	for(i=0; i<SIZE; i++){
    			if(medicamento[i].nome == medicamentoEscolhido){
    				estoquemed+=quantidade;
    				estoquetotal+=quantidade;
                    medicamento[i].quantidade+=quantidade;
    				n++;
				}
    		}
        }

		cout << "\t\t\t\tDigite 1 para adicionar novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);

}

void tipoTransferir(){

    int alter, n;
	system("cls");

	do{
		n=0;
		cout << "\t\t\t\tQual insumo voce deseja transferir?" << endl;
		cout << endl;
		cout << "\t\t\t\t<1> Para Vacina" << endl;
		cout << "\t\t\t\t<2> Para EPI" << endl;
		cout << "\t\t\t\t<3> Para Medicamento" << endl;
		cout << "\t\t\t\t<0> Para voltar ao menu principal" << endl;

		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				n++;
				break;
			case 1:
                dadosTransferenciaVacina();
				break;
			case 2:
                dadosTransferenciaEpi();
				break;
			case 3:
                dadosTransferenciaMedicamento();
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n=0);
}

void dadosTransferenciaVacina(){

    system("cls");

    string vacinaEscolhida, estadoEscolhido;
    int i, n, cad, quantidade, m;

    do{
		n = 0;
		m = 0;
		cout << "\t\t\t\tInsira a vacina: ";
        getchar();
        getline(cin, vacinaEscolhida);
        cout<< endl;
        
        for(i=0; i<SIZE; i++){
    		if(vacina[i].nom == vacinaEscolhida){
    			m++;
			}
		}
		if(m < 1){
			cout << "\t\t\t\t*A Vacina nao esta cadastrada.*\n" << endl;
		}else{
        	cout << "\t\t\t\tInsira a quantidade transferida: ";
        	cin >> quantidade;
       		cout << "\t\t\t\tInsira o estado destino (sigla): ";
        	getchar();
        	getline(cin, estadoEscolhido);
        	
        	for(i=0; i<SIZE; i++){
    			if(vacina[i].nom == vacinaEscolhida){
    				if(quantidade <= vacina[i].quant){
              	    	transferirVacina(vacinaEscolhida, quantidade, estadoEscolhido); //função que faz a transferencia de vacinas e tem como parametros a vacina escolhida, a quantidade e o destino
                    	estoquevacina-=quantidade;
                    	estoquetotal-=quantidade;
                    	for(i=0; i<SIZE; i++){
                    		if(vacina[i].nom == vacinaEscolhida)
                  	  			vacina[i].quant-=quantidade;
                   			}
               		}else{
            			system("cls");
            			cout << "\t\t\t\t*Valor acima do estoque*" << endl;
                	}
    				n++;
    			}
        	}
		}

		cout << "\t\t\t\tDigite 1 para transferir novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void transferirVacina(string vacina, int quantidade, string estado){

    if (estado == "AC")
    {
        AC[linha4].nomeVacina=vacina;
        AC[linha4].quantVacina+=quantidade;
    }
    else if (estado == "AL")
    {
        AL[linha4].nomeVacina=vacina;
        AL[linha4].quantVacina+=quantidade;
    }
    else if (estado == "AP")
    {
        AP[linha4].nomeVacina=vacina;
        AP[linha4].quantVacina+=quantidade;
    }
    else if (estado == "AM")
    {
        AM[linha4].nomeVacina=vacina;
        AM[linha4].quantVacina+=quantidade;
    }
    else if (estado == "BA")
    {
        BA[linha4].nomeVacina=vacina;
        BA[linha4].quantVacina+=quantidade;
    }
    else if (estado == "CE")
    {
        CE[linha4].nomeVacina=vacina;
        CE[linha4].quantVacina+=quantidade;
    }
    else if (estado == "DF")
    {
        DF[linha4].nomeVacina=vacina;
        DF[linha4].quantVacina+=quantidade;
    }
    else if (estado == "ES")
    {
        ES[linha4].nomeVacina=vacina;
        ES[linha4].quantVacina+=quantidade;
    }
    else if (estado == "GO")
    {
        GO[linha4].nomeVacina=vacina;
        GO[linha4].quantVacina+=quantidade;
    }
    else if (estado == "MA")
    {
        MA[linha4].nomeVacina=vacina;
        MA[linha4].quantVacina+=quantidade;
    }
    else if (estado == "MT")
    {
        MT[linha4].nomeVacina=vacina;
        MT[linha4].quantVacina+=quantidade;
    }
    else if (estado == "MS")
    {
        MS[linha4].nomeVacina=vacina;
        MS[linha4].quantVacina+=quantidade;
    }
    else if (estado == "MG")
    {
        MG[linha4].nomeVacina=vacina;
        MG[linha4].quantVacina+=quantidade;
    }
    else if (estado == "PA")
    {
        PA[linha4].nomeVacina=vacina;
        PA[linha4].quantVacina+=quantidade;
    }
    else if (estado == "PB")
    {
        PB[linha4].nomeVacina=vacina;
        PB[linha4].quantVacina+=quantidade;
    }
    else if (estado == "PR")
    {
        PR[linha4].nomeVacina=vacina;
        PR[linha4].quantVacina+=quantidade;
    }
    else if (estado == "PE")
    {
        PE[linha4].nomeVacina=vacina;
        PE[linha4].quantVacina+=quantidade;
    }
    else if (estado == "PI")
    {
        PI[linha4].nomeVacina=vacina;
        PI[linha4].quantVacina+=quantidade;
    }
    else if (estado == "RR")
    {
        RR[linha4].nomeVacina=vacina;
        RR[linha4].quantVacina+=quantidade;
    }
    else if (estado == "RO")
    {
        RO[linha4].nomeVacina=vacina;
        RO[linha4].quantVacina+=quantidade;
    }
    else if (estado == "RJ")
    {
        RJ[linha4].nomeVacina=vacina;
        RJ[linha4].quantVacina+=quantidade;
    }
    else if (estado == "RN")
    {
        RN[linha4].nomeVacina=vacina;
        RN[linha4].quantVacina+=quantidade;
    }
    else if (estado == "RS")
    {
        RS[linha4].nomeVacina=vacina;
        RS[linha4].quantVacina+=quantidade;
    }
    else if (estado == "SC")
    {
        SC[linha4].nomeVacina=vacina;
        SC[linha4].quantVacina+=quantidade;
    }
    else if (estado == "SP")
    {
        SP[linha4].nomeVacina=vacina;
        SP[linha4].quantVacina+=quantidade;
    }
    else if (estado == "SE")
    {
        SE[linha4].nomeVacina=vacina;
        SE[linha4].quantVacina+=quantidade;
    }
    else if (estado == "TO")
    {
        TO[linha4].nomeVacina=vacina;
        TO[linha4].quantVacina+=quantidade;
    }

    linha4++;
}

void dadosTransferenciaEpi(){

    system("cls");

    string epiEscolhida, estadoEscolhido;
    int i, n, cad, quantidade, m;

    do{
		n = 0;
		m = 0;
		cout << "\t\t\t\tInsira a EPI: ";
        getchar();
        getline(cin, epiEscolhida);
        cout << endl;
        
        for(i=0; i<SIZE; i++){
	    	if(epi[i].nom == epiEscolhida){
	    		m++;
			}
		}	
		if(m < 1){
			cout << "\t\t\t\t*A EPI nao esta cadastrada.*\n" << endl;
		}else{
	        cout << "\t\t\t\tInsira a quantidade transferida: ";
	        cin >> quantidade;
	        cout << "\t\t\t\tInsira o estado destino (sigla): ";
	        getchar();
	        getline(cin, estadoEscolhido);

	        for(i=0; i<SIZE; i++){
	    		if(epi[i].nom == epiEscolhida){
	    			if(quantidade <= epi[i].quant){
	                    transferirEpi(epiEscolhida, quantidade, estadoEscolhido);
	                    estoqueepi-=quantidade;
	                    estoquetotal-=quantidade;
	                    for(i=0; i<SIZE; i++){
	                        if(epi[i].nom == epiEscolhida)
	                        epi[i].quant-=quantidade;
	                    }
	                }else{
	                    system("cls");
	                    cout << "\t\t\t\t*Valor acima do estoque*" << endl;
	                }
	    			n++;
	    		}
	        }
		}

		cout << "\t\t\t\tDigite 1 para transferir novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void transferirEpi(string epi, int quantidade, string estado){

    if (estado == "AC")
    {
        AC[linha5].nomeEpi=epi;
        AC[linha5].quantEpi+=quantidade;
    }
    else if (estado == "AL")
    {
        AL[linha5].nomeEpi=epi;
        AL[linha5].quantEpi+=quantidade;
    }
    else if (estado == "AP")
    {
        AP[linha5].nomeEpi=epi;
        AP[linha5].quantEpi+=quantidade;
    }
    else if (estado == "AM")
    {
        AM[linha5].nomeEpi=epi;
        AM[linha5].quantEpi+=quantidade;
    }
    else if (estado == "BA")
    {
        BA[linha5].nomeEpi=epi;
        BA[linha5].quantEpi+=quantidade;
    }
    else if (estado == "CE")
    {
        CE[linha5].nomeEpi=epi;
        CE[linha5].quantEpi+=quantidade;
    }
    else if (estado == "DF")
    {
        DF[linha5].nomeEpi=epi;
        DF[linha5].quantEpi+=quantidade;
    }
    else if (estado == "ES")
    {
        ES[linha5].nomeEpi=epi;
        ES[linha5].quantEpi+=quantidade;
    }
    else if (estado == "GO")
    {
        GO[linha5].nomeEpi=epi;
        GO[linha5].quantEpi+=quantidade;
    }
    else if (estado == "MA")
    {
        MA[linha5].nomeEpi=epi;
        MA[linha5].quantEpi+=quantidade;
    }
    else if (estado == "MT")
    {
        MT[linha5].nomeEpi=epi;
        MT[linha5].quantEpi+=quantidade;
    }
    else if (estado == "MS")
    {
        MS[linha5].nomeEpi=epi;
        MS[linha5].quantEpi+=quantidade;
    }
    else if (estado == "MG")
    {
        MG[linha5].nomeEpi=epi;
        MG[linha5].quantEpi+=quantidade;
    }
    else if (estado == "PA")
    {
        PA[linha5].nomeEpi=epi;
        PA[linha5].quantEpi+=quantidade;
    }
    else if (estado == "PB")
    {
        PB[linha5].nomeEpi=epi;
        PB[linha5].quantEpi+=quantidade;
    }
    else if (estado == "PR")
    {
        PR[linha5].nomeEpi=epi;
        PR[linha5].quantEpi+=quantidade;
    }
    else if (estado == "PE")
    {
        PE[linha5].nomeEpi=epi;
        PE[linha5].quantEpi+=quantidade;
    }
    else if (estado == "PI")
    {
        PI[linha5].nomeEpi=epi;
        PI[linha5].quantEpi+=quantidade;
    }
    else if (estado == "RR")
    {
        RR[linha5].nomeEpi=epi;
        RR[linha5].quantEpi+=quantidade;
    }
    else if (estado == "RO")
    {
        RO[linha5].nomeEpi=epi;
        RO[linha5].quantEpi+=quantidade;
    }
    else if (estado == "RJ")
    {
        RJ[linha5].nomeEpi=epi;
        RJ[linha5].quantEpi+=quantidade;
    }
    else if (estado == "RN")
    {
        RN[linha5].nomeEpi=epi;
        RN[linha5].quantEpi+=quantidade;
    }
    else if (estado == "RS")
    {
        RS[linha5].nomeEpi=epi;
        RS[linha5].quantEpi+=quantidade;
    }
    else if (estado == "SC")
    {
        SC[linha5].nomeEpi=epi;
        SC[linha5].quantEpi+=quantidade;
    }
    else if (estado == "SP")
    {
        SP[linha5].nomeEpi=epi;
        SP[linha5].quantEpi+=quantidade;
    }
    else if (estado == "SE")
    {
        SE[linha5].nomeEpi=epi;
        SE[linha5].quantEpi+=quantidade;
    }
    else if (estado == "TO")
    {
        TO[linha5].nomeEpi=epi;
        TO[linha5].quantEpi+=quantidade;
    }

    linha5++;
}

void dadosTransferenciaMedicamento(){

    system("cls");

    string medicamentoEscolhido, estadoEscolhido;
    int i, n, cad, quantidade, m;

    do{
		n = 0;
		m = 0;
		cout << "\t\t\t\tInsira o medicamento: ";
        getchar();
        getline(cin, medicamentoEscolhido);
        cout << endl;
        
        for(i=0; i<SIZE; i++){
	    	if(medicamento[i].nome == medicamentoEscolhido){
	    		m++;
	    	}
	    }
	   	if(m < 1){
			cout << "\t\t\t\t*O medicamento nao esta cadastrada.*\n" << endl;
		}else{
	        cout << "\t\t\t\tInsira a quantidade transferida: ";
	        cin >> quantidade;
	        cout << "\t\t\t\tInsira o estado destino (sigla): ";
	        getchar();
	        getline(cin, estadoEscolhido);
	
	
	        for(i=0; i<SIZE; i++){
	    		if(medicamento[i].nome == medicamentoEscolhido){
	    			if(quantidade <= medicamento[i].quantidade){
	                    transferirMedicamento(medicamentoEscolhido, quantidade, estadoEscolhido);
	                    estoquemed-=quantidade;
	                    estoquetotal-=quantidade;
	                    for(i=0; i<SIZE; i++){
	                        if(medicamento[i].nome == medicamentoEscolhido)
	                        medicamento[i].quantidade-=quantidade;
	                    }
	                }else{
	                	system("cls");
	                    cout << "\t\t\t\t*Valor acima do estoque*" << endl;
	                }
	    			n++;
	    		}
	        }
		}
		
		cout << "\t\t\t\tDigite 1 para transferir novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void transferirMedicamento(string medicamento, int quantidade, string estado){

    if (estado == "AC")
    {
        AC[linha6].nomeMedicamento=medicamento;
        AC[linha6].quantMedicamento+=quantidade;

    }
    else if (estado == "AL")
    {
        AL[linha6].nomeMedicamento=medicamento;
        AL[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "AP")
    {
        AP[linha6].nomeMedicamento=medicamento;
        AP[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "AM")
    {
        AM[linha6].nomeMedicamento=medicamento;
        AM[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "BA")
    {
        BA[linha6].nomeMedicamento=medicamento;
        BA[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "CE")
    {
        CE[linha6].nomeMedicamento=medicamento;
        CE[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "DF")
    {
        DF[linha6].nomeMedicamento=medicamento;
        DF[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "ES")
    {
        ES[linha6].nomeMedicamento=medicamento;
        ES[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "GO")
    {
        GO[linha6].nomeMedicamento=medicamento;
        GO[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "MA")
    {
        MA[linha6].nomeMedicamento=medicamento;
        MA[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "MT")
    {
        MT[linha6].nomeMedicamento=medicamento;
        MT[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "MS")
    {
        MS[linha6].nomeMedicamento=medicamento;
        MS[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "MG")
    {
        MG[linha6].nomeMedicamento=medicamento;
        MG[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "PA")
    {
        PA[linha6].nomeMedicamento=medicamento;
        PA[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "PB")
    {
        PB[linha6].nomeMedicamento=medicamento;
        AC[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "PR")
    {
        PR[linha6].nomeMedicamento=medicamento;
        PR[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "PE")
    {
        PE[linha6].nomeMedicamento=medicamento;
        PE[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "PI")
    {
        PI[linha6].nomeMedicamento=medicamento;
        PI[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "RR")
    {
        RR[linha6].nomeMedicamento=medicamento;
        RR[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "RO")
    {
        RO[linha6].nomeMedicamento=medicamento;
        RO[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "RJ")
    {
        RJ[linha6].nomeMedicamento=medicamento;
        RJ[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "RN")
    {
        RN[linha6].nomeMedicamento=medicamento;
        RN[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "RS")
    {
        RS[linha6].nomeMedicamento=medicamento;
        RS[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "SC")
    {
        SC[linha6].nomeMedicamento=medicamento;
        SC[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "SP")
    {
        SP[linha6].nomeMedicamento=medicamento;
        SP[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "SE")
    {
        SE[linha6].nomeMedicamento=medicamento;
        SE[linha6].quantMedicamento+=quantidade;
    }
    else if (estado == "TO")
    {
        TO[linha6].nomeMedicamento=medicamento;
        TO[linha6].quantMedicamento+=quantidade;
    }

    linha6++;
}

void consultaEstoqueEstado(){
    string estado;
	int cad;

	system("cls");

	do{
		cout << "\t\t\t\tDigite o estado (sigla) para exibir o historico de transferencias: ";
		getchar();
		getline(cin, estado);
		cout << endl;

		if(estado=="AC" || estado=="AL" || estado=="AP" || estado=="AM" || estado=="BA" || estado=="CE" || estado=="ES" || estado=="GO" || estado=="MA"){
            printVerifEstoqueEstado(estado);
		}
		else if(estado=="MT" || estado=="MS" || estado=="MG" || estado=="PA" || estado=="PB" || estado=="PR" || estado=="PE" || estado=="PI" || estado=="RJ")
        {
            printVerifEstoqueEstado(estado);
        }
        else if(estado=="RN" || estado=="RS" || estado=="RO" || estado=="RR" || estado=="SC" || estado=="SP" || estado=="SE" || estado=="TO" || estado=="DF")
        {
            printVerifEstoqueEstado(estado);
        }else{
            system("cls");
            cout << "\t\t\t\t*Estado invalido*" << endl;
		}

		cout << "\t\t\t\tDigite 1 para consultar novamente e 0 para sair: ";
		cin >> cad;
		system("cls");
	}while(cad == 1);
}

void printVerifEstoqueEstado(string estado){

    int i, n=0;

    if (estado == "AC"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (ACRE):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(AC[i].quantVacina){
            	cout << "\t\t\t\tVacina: " << AC[i].nomeVacina << endl;
            	cout << "\t\t\t\tQuantidade: " << AC[i].quantVacina << endl << endl;
        		n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AC[i].quantEpi){
            	cout << "\t\t\t\tEPI: " << AC[i].nomeEpi << endl;
            	cout << "\t\t\t\tQuantidade: " << AC[i].quantEpi << endl << endl;
            	n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AC[i].quantMedicamento){
            	cout << "\t\t\t\tMedicamento: " << AC[i].nomeMedicamento << endl;
            	cout << "\t\t\t\tQuantidade: " << AC[i].quantMedicamento << endl << endl;
            	n++;
            }
        }
        if(n==0){
        	cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "AL"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (ALAGOAS):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(AL[i].quantVacina){
            	cout << "\t\t\t\tVacina: " << AL[i].nomeVacina << endl;
            	cout << "\t\t\t\tQuantidade: " << AL[i].quantVacina << endl << endl;
            	n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AL[i].quantEpi){
            	cout << "\t\t\t\tEPI: " << AL[i].nomeEpi << endl;
            	cout << "\t\t\t\tQuantidade: " << AL[i].quantEpi << endl << endl;
            	n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AL[i].quantMedicamento){
            	cout << "\t\t\t\tMedicamento: " << AL[i].nomeMedicamento << endl;
            	cout << "\t\t\t\tQuantidade: " << AL[i].quantMedicamento << endl << endl;
            	n++;
            }
        }
        if(n==0){
        	cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "AP"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (AMAPA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(AP[i].quantVacina){
            	cout << "\t\t\t\tVacina: " << AP[i].nomeVacina << endl;
            	cout << "\t\t\t\tQuantidade: " << AP[i].quantVacina << endl << endl;
            	n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AP[i].quantEpi){
            	cout << "\t\t\t\tEPI: " << AP[i].nomeEpi << endl;
           		cout << "\t\t\t\tQuantidade: " << AP[i].quantEpi << endl << endl;
            	n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AC[i].quantMedicamento){
            	cout << "\t\t\t\tMedicamento: " << AC[i].nomeMedicamento << endl;
           		cout << "\t\t\t\tQuantidade: " << AC[i].quantMedicamento << endl << endl;
            	n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "AM"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (AMAZONAS):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(AM[i].quantVacina){
            	cout << "\t\t\t\tVacina: " << AM[i].nomeVacina << endl;
           		cout << "\t\t\t\tQuantidade: " << AM[i].quantVacina << endl << endl;
            	n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AM[i].quantEpi){
            	cout << "\t\t\t\tEPI: " << AM[i].nomeEpi << endl;
            	cout << "\t\t\t\tQuantidade: " << AM[i].quantEpi << endl << endl;
            	n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AM[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << AM[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << AM[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "BA"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (BAHIA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(BA[i].quantVacina){
                cout << "\t\t\t\tVacina: " << BA[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << BA[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(BA[i].quantEpi){
            	cout << "\t\t\t\tEPI: " << BA[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << BA[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(BA[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << BA[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << BA[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "CE"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (CEARA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(CE[i].quantVacina){
                cout << "\t\t\t\tVacina: " << CE[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << CE[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(CE[i].quantEpi){
                cout << "\t\t\t\tEPI: " << CE[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << CE[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(CE[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << CE[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << CE[i].quantMedicamento << endl << endl;
                n++;
                }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "DF"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (DISTRITO FEDERAL):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(AC[i].quantVacina){
                cout << "\t\t\t\tVacina: " << AC[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << AC[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AC[i].quantEpi){
                cout << "\t\t\t\tEPI: " << AC[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << AC[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(AC[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << AC[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << AC[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "ES"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (ESPIRITO SANTO):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(ES[i].quantVacina){
                cout << "\t\t\t\tVacina: " << ES[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << ES[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(ES[i].quantEpi){
                cout << "\t\t\t\tEPI: " << ES[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << ES[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(ES[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << ES[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << ES[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "GO"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (GOIAS):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(GO[i].quantVacina){
                cout << "\t\t\t\tVacina: " << GO[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << GO[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(GO[i].quantEpi){
                cout << "\t\t\t\tEPI: " << GO[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << GO[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(GO[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << GO[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << GO[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "MA"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (MARANHAO):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(MA[i].quantVacina){
                cout << "\t\t\t\tVacina: " << MA[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << MA[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MA[i].quantEpi){
                cout << "\t\t\t\tEPI: " << MA[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << MA[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MA[i].quantMedicamento){
            	cout << "\t\t\t\tMedicamento: " << MA[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << MA[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "MT"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (MATO GROSSO):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(MT[i].quantVacina){
                cout << "\t\t\t\tVacina: " << MT[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << MT[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MT[i].quantEpi){
                cout << "\t\t\t\tEPI: " << MT[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << MT[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MT[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << MT[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << MT[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "MS"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (MATO GROSSO DO SUL):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(MS[i].quantVacina){
                cout << "\t\t\t\tVacina: " << MS[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << MS[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MS[i].quantEpi){
                cout << "\t\t\t\tEPI: " << MS[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << MS[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MS[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << MS[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << MS[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "MG"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (MINAS GERAIS):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(MG[i].quantVacina){
                cout << "\t\t\t\tVacina: " << MG[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << MG[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MG[i].quantEpi){
                cout << "\t\t\t\tEPI: " << MG[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << MG[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(MG[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << MG[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << MG[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "PA"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (PARA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(PA[i].quantVacina){
                cout << "\t\t\t\tVacina: " << PA[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << PA[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PA[i].quantEpi){
                cout << "\t\t\t\tEPI: " << PA[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << PA[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PA[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << PA[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << PA[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "PB"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (PARAIBA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(PB[i].quantVacina){
                cout << "\t\t\t\tVacina: " << PB[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << PB[i].quantVacina << endl << endl;
                n++;
        	}
        }
        for(i=0;i<SIZE;i++){
            if(PB[i].quantEpi){
                cout << "\t\t\t\tEPI: " << PB[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << PB[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PB[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << PB[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << PB[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "PR"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (PARANA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(PR[i].quantVacina){
                cout << "\t\t\t\tVacina: " << PR[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << PR[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PR[i].quantEpi){
                cout << "\t\t\t\tEPI: " << PR[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << PR[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PR[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << PR[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << PR[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "PE"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (PERNAMBUCO):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(PE[i].quantVacina){
                cout << "\t\t\t\tVacina: " << PE[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << PE[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PE[i].quantEpi){
                cout << "\t\t\t\tEPI: " << PE[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << PE[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PE[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << PE[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << PE[i].quantMedicamento << endl << endl;
                n++;
            }   
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "PI"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (PIAUI):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(PI[i].quantVacina){
                cout << "\t\t\t\tVacina: " << PI[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << PI[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PI[i].quantEpi){
            	cout << "\t\t\t\tEPI: " << PI[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << PI[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(PI[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << PI[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << PI[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "RR"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (RORAIMA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(RR[i].quantVacina){
                cout << "\t\t\t\tVacina: " << RR[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << RR[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RR[i].quantEpi){
                cout << "\t\t\t\tEPI: " << RR[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << RR[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RR[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << RR[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << RR[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "RO"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (RONDONIA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(RO[i].quantVacina){
                cout << "\t\t\t\tVacina: " << RO[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << RO[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RO[i].quantEpi){
                cout << "\t\t\t\tEPI: " << RO[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << RO[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RO[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << RO[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << RO[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "RJ"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (RIO DE JANEIRO):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(RJ[i].quantVacina){
                cout << "\t\t\t\tVacina: " << RJ[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << RJ[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RJ[i].quantEpi){
                cout << "\t\t\t\tEPI: " << RJ[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << RJ[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RJ[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << RJ[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << RJ[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
	}else if (estado == "RN"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (RIO GRANDE DO NORTE):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(RN[i].quantVacina){
                cout << "\t\t\t\tVacina: " << RN[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << RN[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RN[i].quantEpi){
                cout << "\t\t\t\tEPI: " << RN[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << RN[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RN[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << RN[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << RN[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "RS"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (RIO GRANDE DO SUL):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(RS[i].quantVacina){
                cout << "\t\t\t\tVacina: " << RS[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << RS[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RS[i].quantEpi){
                cout << "\t\t\t\tEPI: " << RS[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << RS[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(RS[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << RS[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << RS[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "SC"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (SANTA CATARINA):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(SC[i].quantVacina){
                cout << "\t\t\t\tVacina: " << SC[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << SC[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(SC[i].quantEpi){
                cout << "\t\t\t\tEPI: " << SC[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << SC[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(SC[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << SC[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << SC[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "SP"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (SAO PAULO):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(SP[i].quantVacina){
                cout << "\t\t\t\tVacina: " << SP[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << SP[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(SP[i].quantEpi){
                cout << "\t\t\t\tEPI: " << SP[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << SP[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(SP[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << SP[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << SP[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "SE"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (SERGIPE):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(SE[i].quantVacina){
                cout << "\t\t\t\tVacina: " << SE[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << SE[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(SE[i].quantEpi){
                cout << "\t\t\t\tEPI: " << SE[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << SE[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(SE[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << SE[i].nomeMedicamento << endl;
                cout << "\t\t\t\tQuantidade: " << SE[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }else if (estado == "TO"){
        system("cls");
        cout << "\t\t\t\tHistorico de transferencias (TOCANTINS):" << endl << endl;
        for(i=0;i<SIZE;i++){
            if(TO[i].quantVacina){
                cout << "\t\t\t\tVacina: " << TO[i].nomeVacina << endl;
                cout << "\t\t\t\tQuantidade: " << TO[i].quantVacina << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(TO[i].quantEpi){
                cout << "\t\t\t\tEPI: " << TO[i].nomeEpi << endl;
                cout << "\t\t\t\tQuantidade: " << TO[i].quantEpi << endl << endl;
                n++;
            }
        }
        for(i=0;i<SIZE;i++){
            if(TO[i].quantMedicamento){
                cout << "\t\t\t\tMedicamento: " << TO[i].nomeMedicamento << endl;
            	cout << "\t\t\t\tQuantidade: " << TO[i].quantMedicamento << endl << endl;
                n++;
            }
        }
        if(n==0){
            cout << "\t\t\t\t*Sem historico de transferencias*" << endl << endl;
        }
    }
    linha6++;
}
