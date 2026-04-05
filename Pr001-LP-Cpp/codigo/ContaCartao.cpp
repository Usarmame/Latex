#include "ContaCartao.h"

ContaCartao::ContaCartao(double saldo, double beneficio):Usuario("",""), saldo(saldo), beneficio(beneficio) 
{}

double ContaCartao::getSaldo() const { return saldo; }
double ContaCartao::getBeneficio() const { return beneficio; }

void ContaCartao::setSaldo(double saldo) { this->saldo = saldo; }
void ContaCartao::setBeneficio(double beneficio) { this->beneficio = beneficio; }

void ContaCartao::depositar(double valor) {
    if (valor > 0) {
        saldo += valor;
        cout << "Deposito de " << valor << " realizado com sucesso!" << endl;
    }
}

bool ContaCartao::sacar(double valor) {
    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        return true;
    }
    return false;
}

void ContaCartao::mostrarDados() {
    cout << "Saldo Atual: " << saldo << " MT" << endl;
    cout << "Beneficio: " << beneficio << "%" << endl;
}