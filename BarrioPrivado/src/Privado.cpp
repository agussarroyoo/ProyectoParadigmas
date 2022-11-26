/*
 * Privado.cpp
 *
 *  Created on: 19 nov 2022
 *      Author: Agu
 */

#include "Privado.h"

Privado::Privado() {}

Privado::Privado(float area):Lote(area){}

void Privado::agregarConsumoElectrico(short dia,short mes,short anio,float medicion,float monto) {
	this->consumos.insert(this->consumos.end(), new ConsumoElectrico(dia,mes, anio, medicion,monto) );
}


void Privado::agregarReserva(Fecha fecha, int horaInicio, int horaFin, float precio, Persona *reservante, Lote *loteReservado){
	this->reservas.insert(this->reservas.end(), new Reserva(fecha,  horaInicio,  horaFin,  precio,  reservante,  loteReservado));
}
void Privado::agregarHabitante(Persona *p){
	this->habitantes.insert(this->habitantes.end(), p);
}
void Privado::agregarPropietario(Persona *p){
	this->propietarios.insert(this->propietarios.end(), p);

}

//Comprueba si la Persona p pertenece a los Habitantes del Lote
bool Privado::comprobarHabitante(Persona p){
	bool aux = false;
	for (unsigned int i = 0; i < this->habitantes.size(); i++) {
		if ( this->habitantes[i]->getDni() == p.getDni()) {
			return true;
		}
	}
	return aux;
}

//Crea la expensa recibiendo desde Sistema el monto de los servicios contratados en ese mes
void Privado::crearExpensa(short mes,float servicios){

	float monto = servicios * (this->area / this->sumaArea ) + this->consumoMes(mes) + this->calcularBonificacion(mes);

	Expensa nueva(mes, monto);
	this->agregarExpensa(&nueva);
	this->listarExpensa(nueva, servicios);
}

void Privado::agregarExpensa(Expensa *e) {
	this->expensas.insert(this->expensas.end(), e);
}

//Lista la Expensa de determinado mes
void Privado::expensaMes(int mes, float servicios) {
	for (unsigned int i = 0; i<this->expensas.size(); i++) {
		if (this->expensas[i]->getMes() == mes) {
			this->listarExpensa(*this->expensas[i], servicios);
		}
	}
}

//Recibe una Expensa y la lista
void Privado::listarExpensa(Expensa e, float servicios) {
		cout<<"                              EXPENSA: "<<e.getNroExpensa()<<endl;
		cout << "  -------------------------------------------" << endl;
	 	cout <<"LOTE: " <<this->getNLote()<<"                 Mes de facturacion: "<< e.getMes()<<endl;
		cout << "  -------------------------------------------" << endl<< endl;
		cout << "  En concepto de:" << endl;
		cout << "  -------------------------------------------" << endl;
		cout << "     Servicios ------------------------------ $" << servicios << endl;
		cout << "                   " ;
		cout << "     Reservas" << endl;
		cout << "                   -" ;
		this->infoReservas(e.getMes());
		cout << "  -------------------------------------------" << endl;
		cout << "     Consumo Electrico" << endl;
		cout << "                   -" ;
		this->infoConsumo(e.getMes());
		cout << "  -------------------------------------------" << endl;
		cout << "  Total a pagar ....... $ " << e.getMonto()<< endl;
}

//Devuelve el monto del Consumo Electrico correspondiente al mes
float Privado::consumoMes(int mes) {
	for (unsigned int i= 0; i < this->consumos.size(); i++) {
			if (this->consumos[i]->getFecha().getMes() == mes) {
				return this->consumos[i]->getMonto();
			}
		}
	return 0;
}


//Calcula la bonificacion correspondiente al monto de las Reservas realizadas por los Habitantes del Lote
float Privado::calcularBonificacion(short mes) {
	float aux = 0;
	for (unsigned int i = 0; i < this->reservas.size(); i++) {
		if (this->reservas[i]->getFecha().getMes() == mes) {
			aux = aux + this->reservas[i]->getPrecio() * 0.05;
		}
	}
	return aux;
}

void Privado::infoConsumo(int mes) {
	for (unsigned int i= 0; i < this->consumos.size(); i++) {
			if (this->consumos[i]->getFecha().getMes() == mes) {
				this->consumos[i]->listarInfo();
			}
		}
}

void Privado::infoReservas(int mes) {
	for (unsigned int i = 0; i < this->reservas.size(); i++) {
		if (this->reservas[i]->getFecha().getMes() == mes) {
			this->reservas[i]->listarInfo();
		}
	}
}

void Privado::infoHabitantes() {
	for (unsigned int i = 0; i<this->habitantes.size(); i++) {
		this->habitantes[i]->toString();
	}
}
void Privado::infoPropietarios() {
	for (unsigned int i = 0; i<this->propietarios.size(); i++) {
		this->propietarios[i]->toString();
	}
}
Privado::~Privado() {
	// TODO Auto-generated destructor stub
}

