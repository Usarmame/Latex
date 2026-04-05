#include "AlunoContaCartao.h"
#include <limits>

AlunoContaCartao::AlunoContaCartao(string nome, string id, string contacto, string instituicao, string endereco, double saldo, double beneficio)
    : Usuario(nome, id), 
      Aluno(nome, id, contacto, instituicao, endereco),
      ContaCartao(saldo, beneficio) 
{}

void AlunoContaCartao::salvar() {
    ofstream ficheiro("dados.txt", ios::app);
    if (ficheiro.is_open()) {
        ficheiro << getNome() << "," << getInstituicao() << "," 
                 << getId() << "," << getSaldo() << "\n";
        ficheiro.close();
        cout << "Dados guardados com sucesso!" << endl;
    }
}

void AlunoContaCartao::mostrarDados() {
    cout << "\n--- FICHA DO ALUNO CONTA-CARTAO ---" << endl;
    Aluno::mostrarDados();      // Mostra Nome, ID, Instituição, Contacto
    ContaCartao::mostrarDados(); // Mostra Saldo e Benefício
}

void AlunoContaCartao::executarMenu() {
    int opcao;
    do {
        cout << "\n>>>> OPERACOES PARA: " << getNome() << " <<<<" << endl;
        cout << "1. Visualizar Perfil Completo" << endl;
        cout << "2. Efetuar Deposito" << endl;
        cout << "3. Exportar para Ficheiro" << endl;
        cout << "0. Sair do Menu" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                mostrarDados();
                break;
            case 2:
                double valor;
                cout << "Informe o valor do deposito: ";
                cin >> valor;
                depositar(valor);
                break;
            case 3:
                salvar();
                break;
            case 0:
                cout << "Saindo do menu do aluno..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);
}