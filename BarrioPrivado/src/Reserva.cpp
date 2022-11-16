#include "Reserva.h"

Reserva::Reserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario){
	this->fecahReserva = fReserva;
	this->horaFin = hFin;
	this->horaInicio = hInicio;
	this->precio = precio;
	this->loteComunitario = lComunitario;
	this->personaReserva = pReserva;
}