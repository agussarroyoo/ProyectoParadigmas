/*
 * Contratacion.cpp
 *
 *  Created on: 12 nov. 2022
 *      Author: user
 */

#include "Contratacion.h"

Contratacion::Contratacion() {
	this->costo = indefinido;
	this->fecha.setFechaActual();
}

Contratacion::Contratacion(string empresa, TipoServicio tipo_servicio,short dia,short mes,short anio, float costo):fecha(dia,mes,anio){
	this->empresa=empresa;
	this->tipo_servicio=tipo_servicio;
	this->costo=costo;
}

Contratacion::Contratacion(Contratacion &copia){
	this->costo=copia.costo;
	this->empresa=copia.empresa;
	this->tipo_servicio=copia.tipo_servicio;
	this->fecha=copia.fecha;
}

Fecha Contratacion::getFecha() {
	return this->fecha;
}

float Contratacion::getCosto() {
	return this->costo;
}

void Contratacion::listarInfo() {
	cout <<"Servicio: " << this->tipo_servicio<<endl;
	cout << "Fecha: " << this->fecha.toString()<<endl;
	cout << "Empresa: " << this->empresa<<endl;
	cout << "Costo: $" << this->costo<<endl;

}

Contratacion::~Contratacion() {
	// TODO Auto-generated destructor stub
	this->fecha.~Fecha();
}

