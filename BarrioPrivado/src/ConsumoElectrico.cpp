/*
 * ConsumoElectrico.cpp
 *
 *  Created on: 14 nov. 2022
 *      Author: Alumno
 */

#include "ConsumoElectrico.h"

ConsumoElectrico::ConsumoElectrico() {
	this->fecha.setFechaActual();
	this->medicion=0;
}

ConsumoElectrico::ConsumoElectrico(short dia,short mes,short anio,float medicion,float monto) {
	this->fecha=Fecha(dia,mes,anio);
	this->medicion=medicion;
	this->monto = monto;
}
ConsumoElectrico::~ConsumoElectrico() {
}

Fecha ConsumoElectrico:: getFecha(){
	return this->fecha;
}
float ConsumoElectrico::getMedicion() {
	return this->medicion;
}
float ConsumoElectrico::getMonto() {
	return this->monto;
}

void ConsumoElectrico::listarInfo() {
	cout<< "Fecha: " << this->fecha.toString()<<endl;
	cout<< "Medicion: " << this->medicion<<endl;
	cout<< "Monto: $" << this->monto<<endl;
}
ConsumoElectrico::ConsumoElectrico(const ConsumoElectrico &other) {
	// TODO Auto-generated constructor stub
	this->medicion=other.medicion;
	this->fecha=other.fecha;
	this->monto = other.monto;
}
