/*
 * Contratacion.cpp
 *
 *  Created on: 12 nov. 2022
 *      Author: user
 */

#include "Contratacion.h"
//constructor por defecto
Contratacion::Contratacion() {
	// TODO Auto-generated constructor stub
	this->costo=0;
	this->empresa="";
	this->fecha.setFechaActual();
	this->tipo_servicio=salud;
}
//constructor sobrecargado
Contratacion::Contratacion(string empresa, TipoServicio tipo_servicio,short dia,short mes,short anio, float costo):fecha(dia,mes,anio){
	this->empresa=empresa;
	this->tipo_servicio=tipo_servicio;
	this->costo=costo;
}
//constructor copia
Contratacion::Contratacion(Contratacion &copia){
	this->costo=copia.costo;
	this->empresa=copia.empresa;
	this->tipo_servicio=copia.tipo_servicio;
	this->fecha=copia.fecha;
}

//destructor
Contratacion::~Contratacion() {
	// TODO Auto-generated destructor stub
	this->fecha.~Fecha();
}

