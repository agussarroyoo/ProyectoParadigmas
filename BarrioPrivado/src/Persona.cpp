#include "Persona.h"

Persona::Persona(){
	this->nombre="nombre default";
	this->dni=9999;
}

Persona::Persona(string nom, int _dni){
	this->nombre=nom;
	this->dni=_dni;
}

Persona::Persona(Persona *per){
	this->dni=per->dni;
	this->nombre=per->nombre;
}