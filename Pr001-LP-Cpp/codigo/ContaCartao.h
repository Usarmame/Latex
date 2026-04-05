#ifndef CONTACARTAO_H
#define CONTACARTAO_H

#include "Usuario.h"
#include <iostream>

using namespace std;

class ContaCartao : virtual public Usuario
{
private:
    double saldo;
    double beneficio;

public:
    ContaCartao(double saldo, double beneficio);

    double getSaldo() const;
    double getBeneficio() const;
    
    void setSaldo(double saldo);
    void setBeneficio(double beneficio);

    void depositar(double valor);
    bool sacar(double valor); 

    virtual void mostrarDados() override;
};

#endif