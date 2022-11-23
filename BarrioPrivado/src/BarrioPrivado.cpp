//============================================================================
// Name        : BarrioPrivado.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Sistema.h"

int main() {
	Sistema S;
	S.crearLote(privado, 19.3);

	vector<Contratacion *> contrataciones;
	Contratacion *C = new Contratacion("Empresa 1",salud,10, 11,2022, 132.5);
	Contratacion *R = new Contratacion("Empresa 2",entretenimiento,1, 11,2022, 157.5);
	contrataciones.insert(contrataciones.end(), C);
	contrataciones.insert(contrataciones.end(), R);

	S.agregarServicios(contrataciones);

	Persona P("Agustina Arroyo", 44979839);
	Persona P1("Nicolas Leal",44747829);
	S.agregarHabitante(P, 1);
	S.agregarPropietario(P1, 1);
	S.agregarConsumoElectrico(1, 2, 11, 2022, 12220, 500);




	return 0;
}
