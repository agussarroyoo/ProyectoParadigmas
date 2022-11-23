#ifndef LOTE_H
#define LOTE_H

#include <iostream>
#include "ConsumoElectrico.h"
#include "Expensa.h"
#include "Contratacion.h"
#include "Persona.h"
#include <vector>

using namespace std;

const float indefinido = -9999;

class Lote
{
	protected:
		int nLote;
		static int nro;
		static float sumaArea;
		float area;
	public:
		Lote();
		Lote(float area);
		Lote(Lote &l);
		int getNLote();
		int getPorcentajeArea();
		float getArea();
		virtual void crearExpensa(short mes,float servicios) = 0;
		virtual void agregarHabitante(Persona p) = 0;
		virtual void agregarPropietario(Persona p) = 0;
		virtual void agregarConsumoElectrico(short dia,short mes,short anio,float medicion,float monto) = 0;
		virtual void listarInfo();
};

class Comunitario : public Lote
{
	public:
		Comunitario();
		Comunitario(float area);
		Comunitario(Comunitario &c);
		void crearExpensa(short mes,float servicios) {};
		void agregarHabitante(Persona p) {};
		void agregarPropietario(Persona p) {};
		void agregarConsumoElectrico(short dia,short mes,short anio,float medicion,float monto){};
};


//class Privado: public Lote{
//private:
//	vector<ConsumoElectrico *> consumos;
//	vector<Expensa *> expensas;
//	vector<Contratacion *> contrataciones;
//	vector<Persona *> habitantes;
//	vector<Persona *> propietarios;
//	vector<Reserva *> reservas;
//public:
//	Privado();
//	Privado(vector<Persona *> habitantes,vector<Persona *> propietarios,float area);
//	float crearExpensa(short mes,float servicios);
//	float calcularBonificacion(short mes);
//	void agregarConsumoElectrico(short dia,short mes,short anio,float medicion);
//	void agregarContratacion(string empresa,TipoServicio tipo_servicio,short dia,short mes,short anio, float costo);
//	void agregarReserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario);
//	void agregarHabitante(Persona p);
//	void agregarPropietario(Persona p);
//	bool comprobarHabitante(Persona p);
//	virtual ~Privado();
//};



#endif /*LOTE*/
