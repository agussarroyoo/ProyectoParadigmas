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
	int getDni() const;
	void setDni(int dni);
	const string& getNombre() const;
	void setNombre(const string &nombre);
};

#endif
