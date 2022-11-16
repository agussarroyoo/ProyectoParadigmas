/*
 * Contratacion.h
 *
 *  Created on: 12 nov. 2022
 *      Author: user
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_
#include "Fecha.h"
#include <iostream>
using namespace std;
enum TipoServicio{
	seguridad,
	recoleccionBasura,
	transporte,
	limpiezaDomestica,
	plomeria,
	electricidad,
	mecanica,
	salud,
	entretenimiento
};
class Contratacion {
//inicio de la clase contratacion
private:
	string empresa;
	TipoServicio tipo_servicio;
	Fecha fecha;
	float costo;
public:
	Contratacion(string empresa,TipoServicio tipo_servicio,short dia,short mes,short anio, float costo);
	Contratacion();
	Fecha getFecha();
	float getCosto();
	Contratacion(Contratacion &copia);
	virtual ~Contratacion();
};
#endif /* CONTRATACION_H_ */
