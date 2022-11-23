/*
 * Expensa.cpp
 *
 *  Created on: 12 nov 2022
 *      Author: Agu
 */

#include "Expensa.h"

int Expensa::expensasCreadas = 0;

Expensa::Expensa() {
	// TODO Auto-generated constructor stub

}
Expensa::Expensa(int mes, float monto, bool pagado) {
	this->mes = mes;
	this->monto = monto;
	this->pagado = pagado;
	expensasCreadas + 1;
	this->nroExpensa = this->expensasCreadas + 1;
}

Expensa::~Expensa() {
	// TODO Auto-generated destructor stub
}

