/*
 * Expensa.h
 *
 *  Created on: 12 nov 2022
 *      Author: Agu
 */

#ifndef EXPENSA_H_
#define EXPENSA_H_

class Expensa {
private:
	static int expensasCreadas;
	int nroExpensa;
	int mes;
	float monto;
	bool pagado;
public:
	Expensa();
	Expensa(int mes, float monto, bool pagado);
	virtual ~Expensa();

	int getMes() const {
		return mes;
	}

	float getMonto() const {
		return monto;
	}

	int getNroExpensa() const {
		return nroExpensa;
	}

	bool isPagado() const {
		return pagado;
	}
};

#endif /* EXPENSA_H_ */
