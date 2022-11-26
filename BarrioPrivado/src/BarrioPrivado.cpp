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

	cout << "Se crea un Sistema"<<endl;
	Sistema S;

	cout << " " <<endl;

	cout << "Se crean 4 servicios contratados en el mes 11"<<endl;
	Contratacion *enfermeria = new Contratacion("Empresa 1",salud,10, 11,2022, 132.5);
	Contratacion *autocine = new Contratacion("Empresa 2",entretenimiento,1, 11,2022, 157.5);
	Contratacion *custodia = new Contratacion("Empresa 3",seguridad,10, 11,2022, 132.5);
	Contratacion *plomero = new Contratacion("Empresa 4",plomeria,1, 11,2022, 157.5);

	cout << " " <<endl;

	cout << "Se agregan las contrataciones al Sistema"<<endl;
	vector<Contratacion *> contrataciones;
	contrataciones.insert(contrataciones.end(), enfermeria);
	contrataciones.insert(contrataciones.end(), autocine);
	contrataciones.insert(contrataciones.end(), custodia);
	contrataciones.insert(contrataciones.end(), plomero);
	S.agregarServicios(contrataciones);

	cout << " " <<endl;

	//hacer funcion del toString del Enum
	cout << "Se listan dichas contrataciones"<<endl;

	cout << " " <<endl;

	S.listarServicios(11);

	cout << " " <<endl;

	cout << "Se crean 3 lotes privados"<<endl;
	S.crearLote(privado, 19.3);
	S.crearLote(privado, 24.3);
	S.crearLote(privado, 10.3);

	cout << " " <<endl;

	cout << "Se crean 3 lotes comunitarios"<<endl;
	S.crearLote(comunitario, 41.3);
	S.crearLote(comunitario, 16.3);
	S.crearLote(comunitario, 14.3);

	cout << " " <<endl;

	cout << "Se lista la informacion de los lotes"<<endl;

	cout << " " <<endl;

	S.listarLotes();

	cout << " " <<endl;

	cout << "Se crean las personas involucradas en los lotes privados (habitantes y propietarios de los mismos)"<<endl;
	Persona *Prop1_1 = new Persona("Cristina Werenitzky", 32441223);
	Persona *Hab1_1 = new Persona("Agustina Arroyo", 44979839);
	Persona *Hab2_1 = new Persona("Nicolas Leal", 44979839);
	Persona *Hab3_1 = new Persona("Facundo Carabajal", 44979839);

	Persona *Prop1_2 = new Persona("Alejandra Villanueva", 21744012);
	Persona *Prop2_2 = new Persona("Abel Villanueva", 10982654);
	Persona *Hab1_2 = new Persona("Belen Arroyo", 45725774);

	Persona *Prop1_3 = new Persona("Celina Gomez", 24765189);
	Persona *Hab1_3 = new Persona("Antonio Leal", 20987654);
	Persona *Hab2_3= new Persona("Ignacio Leal", 49917190);

	cout << " " <<endl;

	cout << "Agregamos los habitantes a los lotes correspondientes y listamos su informacion"<<endl;

	S.agregarPropietario(1, Prop1_1);
	S.agregarHabitante(1, Hab1_1);
	S.agregarHabitante(1, Hab2_1);
	S.agregarHabitante(1, Hab3_1);

	S.agregarPropietario(2, Prop1_2);
	S.agregarPropietario(2, Prop2_2);
	S.agregarHabitante(2, Hab1_2);

	S.agregarPropietario(3, Prop1_3);
	S.agregarHabitante(3, Hab1_3);
	S.agregarHabitante(3, Hab2_3);

	cout << " " <<endl;

	cout << "--HABITANTES--" <<endl;
	S.infoHabitantes();

	cout << "--PROPIETARIOS--" <<endl;
	S.infoPropietarios();

	cout << " " <<endl;

	cout << "Creamos un consumo electrico del mes 11 en cada lote" <<endl;
	S.agregarConsumoElectrico(1, 21, 11, 2022, 10.2, 1200);
	S.agregarConsumoElectrico(2, 13, 11, 2022, 29.2, 2780);
	S.agregarConsumoElectrico(3, 11, 11, 2022, 13.2, 1324);

	cout << " " <<endl;

	cout << "Listamos la informacion de los consumos recien creados" << endl;
	cout << "Lote 1" <<endl;
	S.infoConsumo(1, 11);
	cout << "Lote 2" <<endl;
	S.infoConsumo(2, 11);
	cout << "Lote 3" <<endl;
	S.infoConsumo(3, 11);

	cout << " " <<endl;


	cout << "Agregamos reservas en 2 lotes" << endl;

	Fecha Fecha1 = Fecha();



	Fecha Fecha2(10,11,2022);



	return 0;
}
