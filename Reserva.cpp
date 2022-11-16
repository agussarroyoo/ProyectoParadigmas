#include "Reserva.h"

Reserva::Reserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario){
	this->fecha = fReserva;
	this->horaFin = hFin;
	this->horaInicio = hInicio;
	this->precio = precio;
	this->lote_reservado = lComunitario;
	this->reservante = pReserva;
}

float Reserva::getPrecio() {
	return this->precio;
}
Fecha Reserva::getFecha() {
	return this->fecha;
}

