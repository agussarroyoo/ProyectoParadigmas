/*
 * Privado.cpp
 *
 *  Created on: 19 nov 2022
 *      Author: Agu
 */

#include "Privado.h"

Privado::Privado() {
	// TODO Auto-generated constructor stub
//	this->consumos;
//	this->contrataciones;
//	this->expensas;
//	this->habitantes;
//	this->propietarios;
//	this->reservas;
}

Privado::Privado(float area) {
	this->area = area;
}

//Privado::Privado(vector<Persona *> habitantes,vector<Persona *> propietarios, float area):Lote(area) {
//	for(unsigned int i=0;i<habitantes.size();i=i+1 ){
//		this->habitantes[i]= habitantes[i];
//	}
//
//	for(unsigned int i=0;i<propietarios.size();i=i+1 ){
//		this->propietarios[i]= propietarios[i];
//	}
////	this->consumos;
////	this->contrataciones;
////	this->expensas;
////	this->reservas;
//}

void Privado::agregarConsumoElectrico(short dia,short mes,short anio,float medicion,float monto) {
	this->consumos.insert(this->consumos.end(), new ConsumoElectrico(dia,mes, anio, medicion,monto) );
}


void Privado::agregarReserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario) {
	this->reservas.insert(this->reservas.end(), new Reserva(fReserva,  hInicio,  hFin,  precio,  pReserva,  lComunitario));
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
void Privado::crearExpensa(short mes,float servicios){

	float monto = servicios * (this->area / this->sumaArea ) + this->consumoMes(mes) + this->calcularBonificacion(mes);

	Expensa *nueva = new Expensa(mes, monto, false);
	this->agregarExpensa(*nueva);
	this->listarExpensa(nueva, servicios);

}

void Privado::listarExpensa(Expensa *e, float servicios) {
	cout<<"                              EXPENSA: "<<e->getNroExpensa()<<endl;
		cout << "  -------------------------------------------" << endl;
	 	cout <<"LOTE: " <<this->getNLote()<<"                 Mes de facturacion: "<< e->getMes()<<endl;
		cout << "  -------------------------------------------" << endl<< endl;
		cout << "  En concepto de:" << endl;
		cout << "  -------------------------------------------" << endl;
		cout << "     Servicios ------------------------------ $" << servicios << endl;
		cout << "                   " ;
		cout << "     Reservas" << endl;
		cout << "                   -" ;
		this->infoReservas(e->getMes());
		cout << "  -------------------------------------------" << endl;
		cout << "     Consumo Electrico" << endl;
		cout << "                   -" ;
		this->infoConsumo(e->getMes());
		cout << "  -------------------------------------------" << endl;		cout << "  -------------------------------------------" << endl;
		cout << "  Total a pagar ....... $ " << e->getMonto()<< endl;
}

void Privado::agregarExpensa(Expensa e) {
	this->expensas.insert(this->expensas.end(), &e);
}


float Privado::consumoMes(int mes) {
	for (unsigned int i= 0; i < this->consumos.size(); i++) {
			if (this->consumos[i]->getFecha().getMes() == mes) {
				return this->consumos[i]->getMonto();
			}
		}
	return 0;
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

