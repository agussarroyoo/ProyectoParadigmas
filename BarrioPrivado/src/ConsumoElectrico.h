/*
 * ConsumoElectrico.h
 *
 *  Created on: 14 nov. 2022
 *      Author: Alumno
 */

#ifndef CONSUMOELECTRICO_H_
#define CONSUMOELECTRICO_H_
#include "Fecha.h"

class ConsumoElectrico {
private:
	float medicion;
	Fecha fecha;
	float monto;
public:
	ConsumoElectrico();
	ConsumoElectrico(short dia,short mes,short anio,float medicion, float monto);
	ConsumoElectrico(const ConsumoElectrico &other);

	Fecha getFecha();
	float getMedicion();
	float getMonto();

	void listarInfo();

	virtual ~ConsumoElectrico();
};

#endif /* CONSUMOELECTRICO_H_ */
