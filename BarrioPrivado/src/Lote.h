#ifndef LOTE_H
#define LOTE_H

#include <iostream>
#include "ConsumoElectrico.h"
#include "Expensa.h"
#include "Contratacion.h"
#include "Persona.h"
#include <vector>

using namespace std;

class Lote
{
	protected:
		const float indefinido = -999;
		static int lotesCreados;
		static float sumaArea;

		int nLote;
		float area;
	public:
		Lote();
		Lote(float area);
		Lote(Lote &l);

		int getNLote();
		float getPorcentajeArea();
		float getArea();

		virtual void listarInfo();

		virtual ~Lote();
};

class Comunitario : public Lote
{
	public:
		Comunitario();
		Comunitario(float area);
		Comunitario(Comunitario &c);

		virtual ~Comunitario();

};


#endif /*LOTE*/
