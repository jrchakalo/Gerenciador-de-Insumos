#include <iostream>
#include <stdlib.h>
#include <string>
#include "projeto.h"
#include "projeto.cpp"

using namespace std;

int main(void){
	int alter;

	do{
		system("cls");
		puts("\t\t\t\t                        BEM VINDO!                         ");
		cout << endl;
        puts("\t\t\t\tPROGRAMA DE GERENCIAMENTO DE INSUMOS DO MINISTERIO DA SAUDE");	

		cout << endl;
		cout << "\t\t\t\tO que deseja fazer?\n" << endl;
		cout << "\t\t\t\t<1> Cadastrar insumos" << endl;
		cout << "\t\t\t\t<2> Consultar insumos" << endl;
		cout << "\t\t\t\t<3> Estoque" << endl;
		cout << "\t\t\t\t<4> Transferir insumos" << endl;
		cout << "\t\t\t\t<5> Historico de transferencia" << endl;
		cout << "\t\t\t\t<0> Sair" << endl;

		cout << endl;
		cout << "\t\t\t\tOpcao selecionada: ";
		cin >> alter;

		switch (alter){
			case 0:
				return 0;
			case 1:
				tipoCadastro();
				break;
			case 2:
                tipoVerif();
				break;
            case 3:
                consultaEstoque();
				break;
            case 4:
                tipoTransferir();
				break;
			case 5:
				consultaEstoqueEstado();
				break;
			default:
				cout << "\t\t\t\t*Opcao Invalida*\n";
				system("pause");
				system("cls");
				break;
		}
	}while(1);

    return 0;
}
