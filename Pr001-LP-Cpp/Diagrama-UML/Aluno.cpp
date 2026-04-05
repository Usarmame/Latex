#include "Aluno.h"

// Implementação do Construtor
// Nota: O parâmetro 'numero' é passado para o ID do Usuario
Aluno::Aluno(string nome, string id,string contacto, string instituicao, string endereco)
    : Usuario(nome, id), 
      contacto(contacto), 
      instituicao(instituicao), 
      endereco(endereco) 
{
}


string Aluno::getEndereco() const { return endereco; }
string Aluno::getContacto() const { return contacto; }
string Aluno::getInstituicao() const { return instituicao; }

void Aluno::setInstituicao(string instituicao) { this->instituicao = instituicao; }
void Aluno::setEndereco(string endereco) { this->endereco = endereco; }
void Aluno::setContacto(string contacto) { this->contacto = contacto; }


void Aluno::mostrarDados() {
    Usuario::mostrarDados(); 
    cout << "Instituicao: " << instituicao << endl;
    cout << "Contacto: " << contacto << endl;
    cout << "Endereco: " << endereco << endl;
}