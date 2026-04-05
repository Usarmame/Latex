#ifndef ALUNOCONTACARTAO_H
#define ALUNOCONTACARTAO_H

#include "Aluno.h"
#include "ContaCartao.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AlunoContaCartao : public Aluno, public ContaCartao {
public:
    
    AlunoContaCartao(string nome, string id,string contacto, string instituicao, string endereco, double saldo, double beneficio);

    
    void salvar();
    void mostrarDados() override;
    void executarMenu();
};

#endif