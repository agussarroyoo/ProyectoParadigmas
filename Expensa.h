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
	int mes;
	float monto;
	bool pagado;
public:
	Expensa();
	Expensa(int mes, float monto, bool pagado);
	virtual ~Expensa();
};

#endif /* EXPENSA_H_ */
