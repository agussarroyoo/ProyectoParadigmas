/*
 * Privado.cpp
 *
 *  Created on: 14 nov. 2022
 *      Author: Alumno
 */

#include "Privado.h"


//inicio de constructor por defecto
Privado::Privado() {
	// TODO Auto-generated constructor stub
	this->consumos;
	this->contrataciones;
	this->expensas;
	this->habitantes;
	this->propietarios;
	this->reservas;
}
//inicio de constructor sobrecargado
Privado::Privado(vector<Persona *> habitantes,vector<Persona *> propietarios,int n, float a):Lote(n,a) {
	for(unsigned int i=0;i<habitantes.size();i=i+1 ){
		this->habitantes[i]= habitantes[i];
	}

	for(unsigned int i=0;i<propietarios.size();i=i+1 ){
		this->propietarios[i]= propietarios[i];
	}
	this->consumos;
	this->contrataciones;
	this->expensas;
	this->reservas;
}

void Privado::agregarConsumoElectrico(short dia,short mes,short anio,float medicion) {
	this->consumos.insert(this->consumos.end(), new ConsumoElectrico(dia,mes, anio, medicion) );
}
void Privado::agregarContratacion(string empresa,TipoServicio tipo_servicio,short dia,short mes,short anio, float costo){
	this->contrataciones.insert(this->contrataciones.end(), new Contratacion( empresa, tipo_servicio, dia, mes, anio,  costo));
}

void Privado::agregarReserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario) {
	this->reservas.insert(this->reservas.end(),new Reserva( fReserva,  hInicio,  hFin,  precio,  pReserva,  lComunitario) );
}
void Privado::agregarHabitante(Persona p){
	this->habitantes.insert(this->habitantes.end(), &p);
}
void Privado::agregarPropietario(Persona p){
	this->propietarios.insert(this->propietarios.end(), &p);

}
bool Privado::comprobarHabitante(Persona p){
	bool aux = false;
	for (unsigned int i = 0; i < this->habitantes.size(); i++) {
		if ( this->habitantes[i]->getDni() == p.getDni()) {
			return true;
		}
	}
	return aux;
}

float Privado::calcularExpensa(short mes) {
	float aux = 0;
	for (unsigned int i= 0; i < this->consumos.size(); i++) {
		if (this->consumos[i]->getFecha().getMes() == mes) {
			aux = aux + this->consumos[i]->getMedicion();
		}
	}
	for (unsigned int i = 0; i<this->contrataciones.size(); i++) {
		if (this->contrataciones[i]->getFecha().getMes() == mes) {
					aux = aux + this->contrataciones[i]->getCosto();
		}
	}
	return aux + this->calcularBonificacion(mes);

}

float Privado::calcularBonificacion(short mes) {
	float aux = 0;
	for (unsigned int i = 0; i < this->reservas.size(); i++) {
		if (this->reservas[i]->getFecha().getMes() == mes) {
			aux = aux + this->reservas[i]->getPrecio() * 0.05;
		}
	}
	return aux;
}
Privado::~Privado() {
	// TODO Auto-generated destructor stub
}



