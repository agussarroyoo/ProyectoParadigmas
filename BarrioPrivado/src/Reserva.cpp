#include "Reserva.h"

Reserva::Reserva(Fecha fecha, int horaInicio, int horaFin, float precio, Persona *reservante, Lote *loteReservado){
	this->fecha = fecha;
	this->horaFin = horaFin;
	this->horaInicio = horaInicio;
	this->precio = precio;
	this->lote_reservado = loteReservado;
	this->reservante = reservante;
}

float Reserva::getPrecio() {
	return this->precio;
}
Fecha Reserva::getFecha() {
	return this->fecha;
}

void Reserva::listarInfo() {
	cout<<"Fecha: " << this->fecha.toString()<<endl;
	cout <<"Lote Reservado: " << this->lote_reservado->getNLote()<<endl;
	cout<<"Reservante: " << this->reservante->getNombre()<<endl;
	cout<<"....................... Precio: $" << this->precio<<endl;
}
