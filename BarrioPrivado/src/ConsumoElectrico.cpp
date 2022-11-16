/*
 * ConsumoElectrico.cpp
 *
 *  Created on: 14 nov. 2022
 *      Author: Alumno
 */

#include "ConsumoElectrico.h"

//inicio de constructor por defecto
ConsumoElectrico::ConsumoElectrico() {
	// TODO Auto-generated constructor stub
	this->fecha.setFechaActual();
	this->medicion=0;
}
//inicio de constructor sobrecargado
ConsumoElectrico::ConsumoElectrico(short dia,short mes,short anio,float medicion) {
	// TODO Auto-generated constructor stub
	this->fecha=Fecha(dia,mes,anio);
	this->medicion=medicion;
}
ConsumoElectrico::~ConsumoElectrico() {
	// TODO Auto-generated destructor stub
}

Fecha ConsumoElectrico:: getFecha(){
	return this->fecha;
}
float ConsumoElectrico::getMedicion() {
	return this->medicion;
}

ConsumoElectrico::ConsumoElectrico(const ConsumoElectrico &other) {
	// TODO Auto-generated constructor stub
	this->medicion=other.medicion;
	this->fecha=other.fecha;
}
