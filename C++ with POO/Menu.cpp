#include "Menu.h"

using namespace std;

Menu::Menu(){
}

void Menu::exibeMenu1(){
	int alter;
	Menu menu;
	Controler contr;
	Persistencia per;

	per.lerInsumos(&contr);

	do{
		system("cls");
		puts("\t\t\t\t                        BEM VINDO!                         ");
		cout << endl;
        puts("\t\t\t\tPROGRAMA DE GERENCIAMENTO DE INSUMOS DO MINISTERIO DA SAUDE");	

		cout << endl;
		cout << "\t\t\t\tO que deseja fazer?\n" << endl;
		cout << "\t\t\t\t<1> Cadastrar insumos" << endl;
		cout << "\t\t\t\t<2> Consultar insumos" << endl;
		cout << "\t\t\t\t<3> Transferir insumos" << endl;
		cout << "\t\t\t\t<4> Historico de transferencia" << endl;
		cout << "\t\t\t\t<0> Sair" << endl;

		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				break;
			case 1:
				menu.exibeMenu2(&contr);
				break;
			case 2:
                menu.exibeMenu3(&contr);
				break;
            case 3:
                menu.exibeMenu4(&contr);
				break;
            case 4:
            	menu.exibeMenu5(&contr);
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
		
		if(alter ==  0){
			break;
		}
		
	}while(1);
}

void Menu::exibeMenu2(Controler *contr){
	int alter, n, cad;
	Insumo *insu;
	Persistencia per;
	system("cls");
	
	do{
		per.salvarInsumos(*contr);
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
		getchar();

		switch (alter){
			case 0:
				n++;
				break;
			case 1:
				do{
					insu = contr->lerInsumosMS(alter);
					contr->cadastraInsumosMS(insu);
					cout << "\t\t\t\tDigite 1 para cadastrar novamente e 0 para sair: ";
					cin >> cad;
					getchar();
					system("cls");	
				}while(cad == 1);
				break;
			case 2:
				do{
					insu = contr->lerInsumosMS(alter);
					contr->cadastraInsumosMS(insu);
					cout << "\t\t\t\tDigite 1 para cadastrar novamente e 0 para sair: ";
					cin >> cad;
					getchar();
					system("cls");	
				}while(cad == 1);
				break;
			case 3:
			    do{
					insu = contr->lerInsumosMS(alter);
					contr->cadastraInsumosMS(insu);
					cout << "\t\t\t\tDigite 1 para cadastrar novamente e 0 para sair: ";
					cin >> cad;
					getchar();
					system("cls");	
				}while(cad == 1);
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n == 0);
}

void Menu::exibeMenu3(Controler *contr){
	int alter, n;
	Menu menu;
	system("cls");

	do{
		n=0;
		cout << "\t\t\t\tO que voce deseja consultar?" << endl;
		cout << endl;
		cout << "\t\t\t\t<1> Para consultar insumos disponiveis" << endl;
		cout << "\t\t\t\t<2> Para consultar a descricao de insumos disponiveis" << endl;
		cout << "\t\t\t\t<3> Para consultar insumos por tipo" << endl;
		cout << "\t\t\t\t<0> Para voltar ao menu principal" << endl;
		
		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				n++;
				break;
			case 1:
				menu.exibeMenu6(contr, alter);
				break;
			case 2:
				menu.exibeMenu6(contr, alter);
				break;
			case 3:
			    menu.exibeMenu6(contr, alter);
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n==0);
}

void Menu::exibeMenu4(Controler *contr){
	int alter, n, tip;
	Menu menu;
	Persistencia per;

	do{
		per.salvarInsumos(*contr);
		system("cls");
		n=0;
		cout << "\t\t\t\tQual insumo voce deseja transferir?" << endl;
		cout << endl;
		cout << "\t\t\t\t<1> Para Vacina" << endl;
		cout << "\t\t\t\t<2> Para EPI" << endl;
		cout << "\t\t\t\t<3> Para Medicamento" << endl;
		cout << "\t\t\t\t<0> Para voltar ao menu principal" << endl;

		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> tip;	
		
		switch (tip){
			case 0:
				n++;
				break;
			case 1:
				menu.exibeMenu7(contr, tip);
				break;
			case 2:
				menu.exibeMenu7(contr, tip);
				break;
			case 3:
			    menu.exibeMenu7(contr, tip);
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(n==0);
}

void Menu::exibeMenu5(Controler *contr){
	system("cls");
	
	system("cls");
	int numest;
	
	cout << "\t\t\t\tSelecione o local que voce deseja ver o historico:" << endl;
	cout << "\t\t\t\t[0]Ministerio da Saude 		[14]Para" << endl;
	cout << "\t\t\t\t[1]Acre 			[15]Paraiba" << endl;
	cout << "\t\t\t\t[2]Alagoas 			[16]Parana" << endl;
	cout << "\t\t\t\t[3]Amapa 			[17]Pernambuco" << endl;
	cout << "\t\t\t\t[4]Amazonas 			[18]Piaui" << endl;
	cout << "\t\t\t\t[5]Bahia 			[19]Rio de Janeiro" << endl;
	cout << "\t\t\t\t[6]Ceara 			[20]Rio Grande do Norte" << endl;
	cout << "\t\t\t\t[7]Distrito Federal 		[21]Rio Grande do Sul" << endl;
	cout << "\t\t\t\t[8]Espirito Santo 		[22]Rondonia" << endl;
	cout << "\t\t\t\t[9]Goias 			[23]Roraima" << endl;
	cout << "\t\t\t\t[10]Maranhao 			[24]Santa Catarina" << endl;
	cout << "\t\t\t\t[11]Mato Grosso 		[25]Sao Paulo" << endl;
	cout << "\t\t\t\t[12]Mato Grosso do Sul 		[26]Sergipe" << endl;
	cout << "\t\t\t\t[13]Minas Gerais 		[27]Tocantins" << endl;
		
	cout << endl;
	cout << "\t\t\t\tOpcao selecionada: ";
	cin >> numest;
	getchar();
	
	contr->exibeHistorico(numest);	
}

void Menu::exibeMenu6(Controler *contr, int alter){
	system ("cls");
	int numest, tip;
	
	if(alter == 3){
		cout << "\t\t\t\tQual insumo deseja consultar: " << endl;
		cout << "\t\t\t\t<1> Para Vacina" << endl;
		cout << "\t\t\t\t<2> Para EPI" << endl;
		cout << "\t\t\t\t<3> Para Medicamento" << endl;
		
		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> tip;
		system("cls");
	}
	
	cout << "\t\t\t\tSelecione o local que voce deseja consultar:" << endl;
	cout << "\t\t\t\t[0]Ministerio da Saude 		[14]Para" << endl;
	cout << "\t\t\t\t[1]Acre 			[15]Paraiba" << endl;
	cout << "\t\t\t\t[2]Alagoas 			[16]Parana" << endl;
	cout << "\t\t\t\t[3]Amapa 			[17]Pernambuco" << endl;
	cout << "\t\t\t\t[4]Amazonas 			[18]Piaui" << endl;
	cout << "\t\t\t\t[5]Bahia 			[19]Rio de Janeiro" << endl;
	cout << "\t\t\t\t[6]Ceara 			[20]Rio Grande do Norte" << endl;
	cout << "\t\t\t\t[7]Distrito Federal 		[21]Rio Grande do Sul" << endl;
	cout << "\t\t\t\t[8]Espirito Santo 		[22]Rondonia" << endl;
	cout << "\t\t\t\t[9]Goias 			[23]Roraima" << endl;
	cout << "\t\t\t\t[10]Maranhao 			[24]Santa Catarina" << endl;
	cout << "\t\t\t\t[11]Mato Grosso 		[25]Sao Paulo" << endl;
	cout << "\t\t\t\t[12]Mato Grosso do Sul 		[26]Sergipe" << endl;
	cout << "\t\t\t\t[13]Minas Gerais 		[27]Tocantins" << endl;
		
	cout << endl;
	cout << "\t\t\t\tOpcao selecionada: ";
	cin >> numest;	
	
	switch(alter){
		case 1:
			contr->consultaInsumos(numest);
			break;
		case 2:
			contr->consultaInsumosDescricao(numest);
			break;
		case 3:
			contr->consultaInsumos(numest, tip);
			break;	
	}
}

void Menu::exibeMenu7(Controler *contr, int tip){
	system("cls");
	int numest;
	
	cout << "\t\t\t\tSelecione o local para que voce deseja transferir:" << endl;
	cout << "\t\t\t\t[0]Ministerio da Saude 		[14]Para" << endl;
	cout << "\t\t\t\t[1]Acre 			[15]Paraiba" << endl;
	cout << "\t\t\t\t[2]Alagoas 			[16]Parana" << endl;
	cout << "\t\t\t\t[3]Amapa 			[17]Pernambuco" << endl;
	cout << "\t\t\t\t[4]Amazonas 			[18]Piaui" << endl;
	cout << "\t\t\t\t[5]Bahia 			[19]Rio de Janeiro" << endl;
	cout << "\t\t\t\t[6]Ceara 			[20]Rio Grande do Norte" << endl;
	cout << "\t\t\t\t[7]Distrito Federal 		[21]Rio Grande do Sul" << endl;
	cout << "\t\t\t\t[8]Espirito Santo 		[22]Rondonia" << endl;
	cout << "\t\t\t\t[9]Goias 			[23]Roraima" << endl;
	cout << "\t\t\t\t[10]Maranhao 			[24]Santa Catarina" << endl;
	cout << "\t\t\t\t[11]Mato Grosso 		[25]Sao Paulo" << endl;
	cout << "\t\t\t\t[12]Mato Grosso do Sul 		[26]Sergipe" << endl;
	cout << "\t\t\t\t[13]Minas Gerais 		[27]Tocantins" << endl;
		
	cout << endl;
	cout << "\t\t\t\tOpcao selecionada: ";
	cin >> numest;
	getchar();
	
	contr->distribuiInsumo(numest, tip);	
}
