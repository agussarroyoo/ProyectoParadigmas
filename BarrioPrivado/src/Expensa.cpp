/*
 * Expensa.cpp
 *
 *  Created on: 12 nov 2022
 *      Author: Agu
 */

#include "Expensa.h"

int Expensa::expensasCreadas = 0;

Expensa::Expensa() {
	this->mes = indefinido;
	this->nroExpensa = indefinido;
	this->pagado = false;
}
Expensa::Expensa(int mes, float monto) {
	this->mes = mes;
	this->monto = monto;
	this->pagado = false;
	expensasCreadas = expensasCreadas + 1;
	this->nroExpensa = this->expensasCreadas ;
}

void Expensa::fuePagada() {
	this->pagado = true;
}
Expensa::~Expensa() {
	// TODO Auto-generated destructor stub
}

