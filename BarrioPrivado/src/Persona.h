#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona
{
	private:
		string nombre;
		int dni;
		
	public:
		Persona();
		Persona(string nom, int _dni);
		Persona(Persona *per);
};

#endif
