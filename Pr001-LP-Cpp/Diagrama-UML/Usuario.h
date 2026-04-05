#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

using namespace std;

class Usuario
{
protected:
    string nome;
    string id;

public:
    Usuario(string nome, string id);

    virtual ~Usuario() {}

    string getNome() const;
    string getId() const;

    void setNome(string nome);
    void setId(string id);

    virtual void mostrarDados();
};

#endif