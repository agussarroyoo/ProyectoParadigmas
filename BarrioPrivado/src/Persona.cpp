#include "Persona.h"

Persona::Persona(){
	this->dni = indefinido;
}

Persona::Persona(string nombre, int dni){
	this->nombre=nombre;
	this->dni=dni;
}


Persona::Persona(Persona &per){
	this->dni=per.dni;
	this->nombre=per.nombre;
}

int Persona::getDni() const {
	return dni;
}

const string& Persona::getNombre() const {
	return nombre;
}

void Persona::toString() {
	cout << "Nombre: " << this->nombre <<endl;
	cout << "DNI: " << this->dni <<endl;
}
