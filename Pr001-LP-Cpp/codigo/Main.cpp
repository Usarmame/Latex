#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "AlunoContaCartao.h"

using namespace std;

string validarString(const string &mensagem)
{
    string valor;
    do
    {
        cout << mensagem;
        getline(cin, valor);
        if (valor.empty())
            cout << "Entrada invalida! O campo nao pode ser vazio. Tente novamente." << endl;
    } while (valor.empty());
    return valor;
}

double validarDouble(const string &mensagem)
{
    double valor;
    do
    {
        cout << mensagem;
        while (!(cin >> valor))
        {
            cout << "Entrada invalida! Digite um numero valido. Tente novamente." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << mensagem;
        }
        if (valor < 0)
            cout << "Valor invalido! O valor nao pode ser negativo. Tente novamente." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (valor < 0);
    return valor;
}

void demonstrarClasses()
{
    cout << "\n========================================" << endl;
    cout << "  DEMONSTRACAO DAS CLASSES DA HIERARQUIA" << endl;
    cout << "========================================" << endl;

    // --- Classe Aluno ---
    cout << "\n[1] Objeto da classe ALUNO:" << endl;
    Aluno aluno("Maria Joao", "A001", "845123456", "UEM", "Av. Eduardo Mondlane");
    aluno.mostrarDados();

    // --- Classe ContaCartao ---
    cout << "\n[2] Objeto da classe CONTACARTAO:" << endl;
    ContaCartao conta(500.0, 10.0);
    conta.mostrarDados();
    conta.depositar(200.0);
    cout << "Saldo apos deposito: " << conta.getSaldo() << " MT" << endl;

    // --- Classe AlunoContaCartao (sub-classe comum) ---
    cout << "\n[3] Objeto da classe ALUNOCONTACARTAO (herda Aluno + ContaCartao):" << endl;
    AlunoContaCartao acc("Pedro Silva", "B002", "841987654", "UCM", "Rua da Paz, 12", 1000.0, 5.0);
    acc.mostrarDados();
acc.salvar();
acc.executarMenu();
}

void cadastrarAluno(vector<AlunoContaCartao> &alunos)
{
    cout << "\n=== CADASTRO DE NOVO ALUNO ===" << endl;
    string nome = validarString("Nome: ");
    string id = validarString("ID: ");
    string inst = validarString("Instituicao: ");
    string contacto = validarString("Contacto: ");
    string endereco = validarString("Endereco: ");
    double sld = validarDouble("Saldo Inicial: ");
    double ben = validarDouble("Beneficio (Estudante): ");

    alunos.push_back(AlunoContaCartao(nome, id, contacto, inst, endereco, sld, ben));
    cout << "\nAluno '" << nome << "' cadastrado com sucesso!" << endl;
}

void listarAlunos(vector<AlunoContaCartao> &alunos)
{
    if (alunos.empty())
    {
        cout << "\nNenhum aluno cadastrado." << endl;
        return;
    }
    cout << "\n=== LISTA DE ALUNOS ===" << endl;
    for (int i = 0; i < (int)alunos.size(); i++)
        cout << i + 1 << ". " << alunos[i].getNome()
             << " (ID: " << alunos[i].getId() << ")" << endl;
}

void selecionarAluno(vector<AlunoContaCartao> &alunos)
{
    if (alunos.empty())
    {
        cout << "\nNenhum aluno cadastrado." << endl;
        return;
    }
    listarAlunos(alunos);
    int indice;
    cout << "\nEscolha o numero do aluno: ";
    while (!(cin >> indice) || indice < 1 || indice > (int)alunos.size())
    {
        cout << "Opcao invalida! Tente novamente: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    alunos[indice - 1].executarMenu();
}

int main()
{
    vector<AlunoContaCartao> alunos;
    int opcao;

    demonstrarClasses();

    do
    {
        cout << "\n=============================" << endl;
        cout << "   MENU PRINCIPAL DO SISTEMA  " << endl;
        cout << "=============================" << endl;
        cout << "1. Cadastrar Novo Aluno" << endl;
        cout << "2. Selecionar Aluno" << endl;
        cout << "3. Listar Todos os Alunos" << endl;
        cout << "4. Ver Demonstracao das Classes" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao)
        {
        case 1:
            cadastrarAluno(alunos);
            break;
        case 2:
            selecionarAluno(alunos);
            break;
        case 3:
            listarAlunos(alunos);
            break;
        case 4:
            demonstrarClasses();
            break;
        case 0:
            cout << "\nSessao encerrada." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
