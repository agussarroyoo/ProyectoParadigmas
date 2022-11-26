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
	void listarLotes();
	void agregarServicios(vector<Contratacion *> contrataciones);
	void listarServicios(int mes);



	//FUNCIONES PARA LOTES PRIVADOS

	void agregarReserva(int nLote,Fecha fecha, int horaInicio, int horaFin, float precio, Persona *reservante, int nroLoteReserv);
	void agregarConsumoElectrico(int nLote, short dia,short mes,short anio,float medicion, float monto);
	void agregarHabitante(int nroLote, Persona *p);
	void agregarPropietario(int nroLote, Persona *p);
	void emitirExpensa(int nroLote, int mes);
	void pagarExpensa(int nroLote, int mes);
	void listarExpensa(int nroLote, int mes);
	void infoConsumo(int nLote,int mes);
	void infoReservas(int nLote,int mes);
	void infoHabitantes();
	void infoPropietarios();
	void infoHabitantesLote(int nroLote) ;
	void infoPropietariosLote(int nroLote) ;



	virtual ~Sistema();
};

#endif /* SISTEMA_H_ */
