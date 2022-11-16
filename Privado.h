/*
 * Privado.h
 *
 *  Created on: 14 nov. 2022
 *      Author: Alumno
 */

#ifndef PRIVADO_H_
#define PRIVADO_H_
#include "ConsumoElectrico.h"
#include "Expensa.h"
#include "Contratacion.h"
#include "Persona.h"
#include "Reserva.h"
#include "Comunitario.h"
#include <vector>
class Privado: public Lote{
private:
	vector<ConsumoElectrico *> consumos;
	vector<Expensa *> expensas;
	vector<Contratacion *> contrataciones;
	vector<Persona *> habitantes;
	vector<Persona *> propietarios;
	vector<Reserva *> reservas;
public:
	Privado();
	Privado(vector<Persona *> habitantes,vector<Persona *> propietarios,int n,float a);
	float calcularExpensa(short mes);
	float calcularBonificacion(short mes);
	void agregarConsumoElectrico(short dia,short mes,short anio,float medicion);
	void agregarContratacion(string empresa,TipoServicio tipo_servicio,short dia,short mes,short anio, float costo);
	void agregarReserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario);
	void agregarHabitante(Persona p);
	void agregarPropietario(Persona p);
	bool comprobarHabitante(Persona p);
	virtual ~Privado();
};

#endif /* PRIVADO_H_ */
