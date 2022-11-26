/*
 * Privado.h
 *
 *  Created on: 19 nov 2022
 *      Author: Agu
 */

#ifndef PRIVADO_H_
#define PRIVADO_H_
#include "Lote.h"
#include "Reserva.h"


class Privado: public Lote{
private:
	vector<ConsumoElectrico *> consumos;
	vector<Expensa *> expensas;
	vector<Persona *> habitantes;
	vector<Persona *> propietarios;
	vector<Reserva *> reservas;

	bool existeExpensa(int mes) ;
	bool comprobarHabitante(Persona p);
	float calcularBonificacion(short mes);
	float consumoMes(int mes);
	void agregarExpensa(Expensa *e);
	void listarExpensa(Expensa e, float servicios) ;


public:
	Privado();
	Privado(float area);

	void crearExpensa(short mes,float servicios);
	void expensaMes(int mes, float servicios) ;
	void pagarExpensa(int mes);

	void agregarConsumoElectrico(short dia,short mes,short anio,float medicion, float monto);
	void agregarReserva(Fecha fecha, int horaInicio, int horaFin, float precio, Persona *reservante, Lote *loteReservado);
	void agregarHabitante(Persona *p);
	void agregarPropietario(Persona *p);

	void infoConsumo(int mes);
	void infoReservas(int mes);
	void infoHabitantes();
	void infoPropietarios();

	virtual ~Privado();
};

#endif /* PRIVADO_H_ */
