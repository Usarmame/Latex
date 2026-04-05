#include "Usuario.h"

Usuario::Usuario(string nome, string id)
    : nome(nome), id(id)
{
}

string Usuario::getNome() const
{
    return nome;
}

string Usuario::getId() const
{
    return id;
}

void Usuario::setNome(string nome)
{
    this->nome = nome;
}

void Usuario::setId(string id)
{
    this->id = id;
}

void Usuario::mostrarDados() {
    cout << "Nome: " << nome << endl;
    cout << "ID: " << id << endl;
}