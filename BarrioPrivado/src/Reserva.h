#ifndef RESERVA_H
#define RESERVA_H

#include "Persona.h"
#include "Fecha.h"
#include "Lote.h"
using namespace std;


class Reserva
{
	private:
		Fecha fecha;
		int horaInicio;
		int horaFin;
		float precio;
		Persona *reservante;
		Lote *lote_reservado;
		
	public:
		Reserva(){};
		Reserva(Fecha fecha, int horaInicio, int horaFin, float precio, Persona *reservante, Lote *loteReservado);

		float getPrecio();
		Fecha getFecha();

		void listarInfo();

};

#endif
