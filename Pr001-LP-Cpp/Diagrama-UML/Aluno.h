#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <string>
#include <iostream>

using namespace std;

class Aluno : virtual public Usuario
{
private:
    string endereco;
    string contacto;
    string instituicao;

public:

    Aluno(string nome, string id, string contacto, string instituicao, string endereco);

    string getEndereco() const;
    string getContacto() const;
    string getInstituicao() const;

    void setInstituicao(string instituicao);
    void setEndereco(string endereco);
    void setContacto(string contacto);

    void mostrarDados() override; 
};

#endif