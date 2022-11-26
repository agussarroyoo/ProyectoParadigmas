#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona
{
	private:
		const int indefinido = -999;
		string nombre;
		int dni;
		
	public:
		Persona();
		Persona(string nombre, int dni);
		Persona(Persona &per);

		void toString();

		int getDni() const;
		const string& getNombre() const;
};

#endif
