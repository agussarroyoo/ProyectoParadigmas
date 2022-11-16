#ifndef RESERVA_H
#define RESERVA_H

#include "Persona.h"
#include "Comunitario.h"
#include "Fecha.h"

using namespace std;

class Reserva
{
	private:
		Fecha fecha;
		int horaInicio;
		int horaFin;
		float precio;
		Persona reservante;
		Comunitario lote_reservado;
		
	public:
		Reserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario);
		float getPrecio();
		Fecha getFecha();
};

#endif
