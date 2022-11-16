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
	//inicio de consumo electrico
private:
	float medicion;
	Fecha fecha;
public:
	ConsumoElectrico();
	ConsumoElectrico(short dia,short mes,short anio,float medicion);
	virtual ~ConsumoElectrico();
	ConsumoElectrico(const ConsumoElectrico &other);
};

#endif /* CONSUMOELECTRICO_H_ */
