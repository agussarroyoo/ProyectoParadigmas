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
	if (comprobarHabitante(*reservante)) {
		this->reservas.insert(this->reservas.end(), new Reserva(fecha,  horaInicio,  horaFin,  precio,  reservante,  loteReservado));
	} else {
		cout << "El reservante no es habitante de este lote."<<endl;
	}
}
void Privado::agregarHabitante(Persona *p){
	this->habitantes.insert(this->habitantes.end(), p);
}
void Privado::agregarPropietario(Persona *p){
	this->propietarios.insert(this->propietarios.end(), p);

}

void Privado::agregarExpensa(Expensa *e) {
	this->expensas.insert(this->expensas.end(), e);
}

//Comprueba si la Persona p pertenece a los Habitantes del Lote
bool Privado::comprobarHabitante(Persona p){
	for (unsigned int i = 0; i < this->habitantes.size(); i++) {
		if ( this->habitantes[i]->getDni() == p.getDni()) {
			return true;
		}
	}
	return false;
}

//Crea la expensa recibiendo desde Sistema el monto de los servicios contratados en ese mes
void Privado::crearExpensa(short mes,float servicios){
	if (existeExpensa(mes)) {
		cout << "La expensa correspondiente al mes " << mes << " ya fue emitida" << endl;
	} else {
		float monto = servicios * this->getPorcentajeArea() + this->consumoMes(mes) + this->calcularBonificacion(mes);
		Expensa *nueva = new Expensa(mes, monto);
		this->agregarExpensa(nueva);
		this->listarExpensa(*nueva, servicios);
	}

}

//Controla si ya existe una expensa creada en dicho mes
bool Privado::existeExpensa(int mes) {
	for (unsigned int i = 0; i < this->expensas.size(); i++) {
			if (this->expensas[i]->getMes() == mes) {
				return true;
			}
		}
	return false;
}


//Lista la Expensa de determinado mes
void Privado::expensaMes(int mes, float servicios) {
	for (unsigned int i = 0; i<this->expensas.size(); i++) {
		if (this->expensas[i]->getMes() == mes) {
			this->listarExpensa(*this->expensas[i], servicios);
		}
	}
}

void Privado::pagarExpensa(int mes) {
	if (existeExpensa(mes)) {
		for (unsigned int i = 0; i < this->expensas.size(); i++) {
			if (this->expensas[i]->getMes() == mes) {
				if (this->expensas[i]->isPagado()) {
					cout << "La expensa del mes " << mes << " ya había sido pagada"<<endl;
				} else {
					this->expensas[i]->fuePagada();
					cout << "Expensa pagada" << endl;
				}

			}
		}
	} else {
		cout << "No se emitio una expensa correspondiente al mes " << mes <<endl;
	}
}

//Recibe una Expensa y la lista
void Privado::listarExpensa(Expensa e, float servicios) {
		cout << "  -------------------------------------------" << endl;
		cout<<"                              EXPENSA: "<<e.getNroExpensa()<<endl;
	 	cout <<"LOTE: " <<this->getNLote()<<"                 Mes de facturacion: "<< e.getMes()<<endl;
		cout << "" << endl<< endl;
		cout << "En concepto de:" << endl;
		cout << " " << endl;
		cout << "SERVICIOS .............................. $" << servicios * this->getPorcentajeArea() << endl;
		cout << "                   "<<endl ;
		cout << "RESERVAS" << endl;
		cout << "-------------------------------"<<endl;
		cout << " " <<endl ;
		this->infoReservas(e.getMes());
		cout << "...................................A pagar: $" << this->calcularBonificacion(e.getMes())<<endl<<endl;
		cout << "-------------------------------"<<endl;

		cout << " " <<endl;
		cout << "CONSUMO ELECTRICO" << endl;
		cout << "-------------------------------"<<endl;
		cout << " " <<endl ;
		this->infoConsumo(e.getMes());
		cout << " " <<endl ;
		cout << "-------------------------------"<<endl<<endl;
		cout << "                                Total ....... $ " << e.getMonto()<< endl<<endl;

		if (e.isPagado()) {
			cout << "-------------------ESTADO: PAGADA-------------------" << endl;
		} else {
			cout << "-------------------ESTADO: IMPAGADA-------------------" << endl;
		}
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
			cout << " " <<endl;

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

