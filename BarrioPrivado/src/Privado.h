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
public:
	Privado();
	Privado(float area);
//	Privado(vector<Persona *> habitantes,vector<Persona *> propietarios,float area);

	void crearExpensa(short mes,float servicios);

	float calcularBonificacion(short mes);
	float consumoMes(int mes);

	void agregarConsumoElectrico(short dia,short mes,short anio,float medicion, float monto);
	void agregarReserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario);
	void agregarHabitante(Persona p);
	void agregarPropietario(Persona p);
	void agregarExpensa(Expensa e);
	bool comprobarHabitante(Persona p);

	void infoConsumo(int mes);
	void infoReservas(int mes);
	void listarExpensa(Expensa *e, float servicios) ;

	virtual ~Privado();
};

#endif /* PRIVADO_H_ */
