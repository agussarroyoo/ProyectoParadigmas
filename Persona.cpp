#include "Persona.h"

Persona::Persona(){
	this->nombre="nombre default";
	this->dni=9999;
}

Persona::Persona(string nom, int _dni){
	this->nombre=nom;
	this->dni=_dni;
}

int Persona::getDni() const {
	return dni;
}

void Persona::setDni(int dni) {
	this->dni = dni;
}

const string& Persona::getNombre() const {
	return nombre;
}

void Persona::setNombre(const string &nombre) {
	this->nombre = nombre;
}

Persona::Persona(Persona *per){
	this->dni=per->dni;
	this->nombre=per->nombre;
}