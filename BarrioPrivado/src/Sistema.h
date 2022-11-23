/*
 * Sistema.h
 *
 *  Created on: 16 nov 2022
 *      Author: Agu
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include "Contratacion.h"
#include <vector>
#include "Privado.h"
#include "Privado.h"


enum TipoDeLote {
	privado,
	comunitario
};

class Sistema {
private:
	vector <Contratacion *> contrataciones;
	vector <Privado *> lotesP;
	vector <Comunitario *> lotesC;

	float gastoDeServicios(int mes);

public:
	Sistema();
	void crearLote(TipoDeLote tipo, float area);
	void agregarReserva(int nLote, Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario);
	void agregarConsumoElectrico(int nLote, short dia,short mes,short anio,float medicion, float monto);

	void listarLotes();
	void agregarServicios(vector<Contratacion *> contrataciones);

	void agregarHabitante(Persona p, int nroLote);
	void agregarPropietario(Persona p, int nroLote);

	void emitirExpensa(int mes, int nroLote);


	void listarServicios(int mes);
	void infoConsumo(int mes, Privado *lote);
	void infoReservas(int mes, Privado *lote);

	virtual ~Sistema();
};

#endif /* SISTEMA_H_ */
