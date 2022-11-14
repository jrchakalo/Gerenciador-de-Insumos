#ifndef PROJETO_H_INCLUDED
#define PROJETO_H_INCLUDED

void cadastroVacina();
void cadastroEPI();
void cadastroMedicamento();

void verifVacina();
void verifEPI();
void verifiMedicamento();

void adicionaVacina();
void adicionaEpi();
void adicionaMedicamento();

void tipoCadastro();
void tipoVerif();
void tipoAdiciona();
void tipoTransferir();

void printVerifVacina(int i);
void printVerifEPI(int i);

void cadastroEstoque();
void consultaEstoque();

void estoqueVacina();
void estoqueEPI();
void estoqueMedicamento();
void estoqueTotal();
void estoqueDetalhado();

void dadosTransferenciaVacina();
void dadosTransferenciaEpi();
void dadosTransferenciaMedicamento();

void transferirVacina(std::string vacina, int quantidade, std::string estado);
void transferirEpi(std::string epi, int quantidade, std::string estado);
void transferirMedicamento(std::string medicamento, int quantidade, std::string estado);

void consultaEstoqueEstado();
void printVerifEstoqueEstado(std::string estado);

#endif
