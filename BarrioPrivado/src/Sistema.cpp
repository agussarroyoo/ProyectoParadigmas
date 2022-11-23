/*
 * Sistema.cpp
 *
 *  Created on: 16 nov 2022
 *      Author: Agu
 */

#include "Sistema.h"


Sistema::Sistema() {

}

void Sistema::listarLotes(){
	for(unsigned int i = 0; i<this->lotesP.size();i++) {
		this->lotesP[i]->listarInfo();
	}
	for(unsigned int i = 0; i<this->lotesC.size();i++) {
			this->lotesC[i]->listarInfo();
		}
}
void Sistema::agregarServicios(vector<Contratacion *> contrataciones) {
	for(unsigned int i = 0; i<contrataciones.size(); i++) {
		this->contrataciones.insert(this->contrataciones.end(), contrataciones[i]);
	}
}

void Sistema::agregarHabitante(Persona p, int nroLote) {
	for (unsigned int i = 0; i < this->lotesP.size(); i++) {
		this->lotesP[i]->agregarHabitante(p);
	}
}
void Sistema::agregarPropietario(Persona p, int nroLote){
	for (unsigned int i = 0; i < this->lotesP.size(); i++) {
			this->lotesP[i]->agregarPropietario(p);
		}

}
float Sistema::gastoDeServicios(int mes) {
	float aux = 0;
	for (unsigned int i = 0; i < this->contrataciones.size(); i++) {
		if (this->contrataciones[i]->getFecha().getMes() == mes) {
			aux = aux + this->contrataciones[i]->getCosto();
		}
	}
	return aux;
}

void Sistema::crearLote(TipoDeLote tipo, float area) {
	switch (tipo) {
	case privado : this->lotesP.insert(this->lotesP.end(), new Privado(area)); break;
	case comunitario : this->lotesC.insert(this->lotesC.end(), new Comunitario(area)); break;
	}
}

void Sistema::emitirExpensa(int mes, int nroLote) {
	for(unsigned int i = 0; i < this->lotesP.size(); i++) {
		if (this->lotesP[i]->getNLote() == nroLote) {
			 this->lotesP[i]->crearExpensa(mes, this->gastoDeServicios(mes));
		}
	}
}

void Sistema::listarServicios(int mes) {
	for (unsigned int i = 0; i < this->contrataciones.size(); i++) {
			if (this->contrataciones[i]->getFecha().getMes() == mes) {
				this->contrataciones[i]->listarInfo();
			}
		}
}

void Sistema::agregarConsumoElectrico(int nLote, short dia,short mes,short anio,float medicion, float monto){
	for (unsigned int i = 0; i < this->lotesP.size(); i++){
		if (this->lotesP[i]->getNLote() == nLote){
			this->lotesP[i]->agregarConsumoElectrico(dia, mes, anio, medicion, monto);
		}
	}
}

void Sistema::agregarReserva(int nLote, Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario){
	for (unsigned int i = 0; i < this->lotesP.size(); i++){
			if (this->lotesP[i]->getNLote() == nLote){
				this->lotesP[i]->agregarReserva(fReserva, hInicio, hFin, precio, pReserva, lComunitario);
			}
	}
}
Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

