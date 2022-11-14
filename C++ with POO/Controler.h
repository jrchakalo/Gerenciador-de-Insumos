#ifndef CONTROLER_H
#define CONTROLER_H
#include <iostream>
#include "Local.h"
#include "Insumo.h"
#include "Vacina.h"
#include "EPI.h"
#include "Medicamento.h"

class Controler
{
	public:
		Controler();
		
		Insumo* lerInsumosMS(int tipInsu);
		int cadastraInsumosMS(Insumo *tipInsu);
		void cadastraInsumos(Insumo *tipInsu, int indice);
		void consultaInsumos(int indice);
		void consultaInsumosDescricao(int indice);
		void consultaInsumos(int indice, int tipoInsumo);
		void distribuiInsumo(int dest, int tipoInsumo);
		void exibeHistorico(int indice);
		Local getLocal(int pos);
		
	private:
		Local locais[27];
		std::string estados[28] = {"Ministerio da Saude", "Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara", "Distrito Federal", "Espirito Santo",
		"Goias", "Maranhao", "Mato Grosso", "Mato Grosso do Sul", "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui", "Rio de Janeiro",
		"Rio Grande do Norte", "Rio Grande do Sul", "Rondonia", "Roraima", "Santa Catarina", "Sao Paulo", "Sergipe", "Tocantins"};
};

#endif
