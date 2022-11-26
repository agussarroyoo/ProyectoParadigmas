/*
 * Sistema.cpp
 *
 *  Created on: 16 nov 2022
 *      Author: Agu
 */

#include "Sistema.h"


Sistema::Sistema() {}

void Sistema::crearLote(TipoDeLote tipo, float area) {
	switch (tipo) {
	case privado : this->lotesP.insert(this->lotesP.end(), new Privado(area)); break;
	case comunitario : this->lotesC.insert(this->lotesC.end(), new Comunitario(area)); break;
	}
}

void Sistema::listarLotes(){

	cout << "-----LOTES PRIVADOS-----"<<endl;
	for(unsigned int i = 0; i<this->lotesP.size();i++) {
		this->lotesP[i]->listarInfo();
	}

	cout << " " <<endl;

	cout << "-----LOTES COMUNITARIOS-----"<<endl;
	for(unsigned int i = 0; i<this->lotesC.size();i++) {
			this->lotesC[i]->listarInfo();
		}
}

void Sistema::agregarServicios(vector<Contratacion *> contrataciones) {
	for(unsigned int i = 0; i<contrataciones.size(); i++) {
		this->contrataciones.insert(this->contrataciones.end(), contrataciones[i]);
	}
}

void Sistema::listarServicios(int mes) {
	for (unsigned int i = 0; i < this->contrataciones.size(); i++) {
			if (this->contrataciones[i]->getFecha().getMes() == mes) {
				this->contrataciones[i]->listarInfo();
			}
		}
}

float Sistema::gastoDeServicios(int mes) {
	float aux = 0;
	for (unsigned int i = 0; i < this->contrataciones.size(); i++) {
		if (this->contrataciones[i]->getFecha().getMes() == mes) {
			aux = aux + this->contrataciones[i]->getCosto();
		}
	}
	return aux;
}

//FUNCIONES PARA LOTES PRIVADOS

void Sistema::agregarHabitante(int nroLote, Persona *p) {
	for (unsigned int i = 0; i < this->lotesP.size(); i++) {
		if (this->lotesP[i]->getNLote() == nroLote) {
			this->lotesP[i]->agregarHabitante(p);
		}
	}
}

void Sistema::infoHabitantes() {
	for (unsigned int i = 0; i<this->lotesP.size(); i++) {
		cout << "---LOTE [" << this->lotesP[i]->getNLote() << "]---" <<endl;
		this->lotesP[i]->infoHabitantes();
	}
}

void Sistema::infoHabitantesLote(int nroLote) {
	for (unsigned int i = 0; i<this->lotesP.size(); i++) {
		if (this->lotesP[i]->getNLote() == nroLote) {
			this->lotesP[i]->infoHabitantes();
		}
	}
}

void Sistema::agregarPropietario(int nroLote, Persona *p){
	for (unsigned int i = 0; i < this->lotesP.size(); i++) {
			if(this->lotesP[i]->getNLote() == nroLote) {
				this->lotesP[i]->agregarPropietario(p);
			}
		}

}
void Sistema::infoPropietarios() {
	for (unsigned int i = 0; i<this->lotesP.size(); i++) {
		cout << "---LOTE [" << this->lotesP[i]->getNLote() << "]---" <<endl;
		this->lotesP[i]->infoPropietarios();
	}
}

void Sistema::infoPropietariosLote(int nroLote) {
	for (unsigned int i = 0; i<this->lotesP.size(); i++) {
		if (this->lotesP[i]->getNLote() == nroLote) {
			this->lotesP[i]->infoHabitantes();
		}
	}
}

void Sistema::agregarConsumoElectrico(int nLote, short dia,short mes,short anio,float medicion, float monto){
	for (unsigned int i = 0; i < this->lotesP.size(); i++){
		if (this->lotesP[i]->getNLote() == nLote){
			this->lotesP[i]->agregarConsumoElectrico(dia, mes, anio, medicion, monto);
		}
	}
}

void Sistema::agregarReserva(int nLote,Fecha fecha, int horaInicio, int horaFin, float precio, Persona *reservante, int nroLoteReserv){
	for (unsigned int i = 0; i < this->lotesP.size(); i++){
			if (this->lotesP[i]->getNLote() == nLote){
				for (unsigned int j=0 ; j < this->lotesC.size(); j++) {
					if (this->lotesC[j]->getNLote() == nroLoteReserv) {
						this->lotesP[i]->agregarReserva(fecha, horaInicio, horaFin, precio, reservante, this->lotesC[j]);
					}
				}
			}
	}
}

void Sistema::emitirExpensa(int nroLote, int mes) {
	for(unsigned int i = 0; i < this->lotesP.size(); i++) {
		if (this->lotesP[i]->getNLote() == nroLote) {
			 this->lotesP[i]->crearExpensa(mes, this->gastoDeServicios(mes));
		}
	}
}

void Sistema::pagarExpensa(int nroLote, int mes) {
	for(unsigned int i = 0; i < this->lotesP.size(); i++) {
			if (this->lotesP[i]->getNLote() == nroLote) {
				 this->lotesP[i]->pagarExpensa(mes);
			}
		}
}
void Sistema::listarExpensa(int nroLote, int mes) {
	for(unsigned int i = 0; i < this->lotesP.size(); i++) {
			if (this->lotesP[i]->getNLote() == nroLote) {
				 this->lotesP[i]->expensaMes(mes, this->gastoDeServicios(mes));
			}
		}
}

void Sistema::infoConsumo(int nLote,int mes) {
	for(unsigned int i = 0; i < this->lotesP.size(); i++) {
		if (this->lotesP[i]->getNLote() == nLote) {
			this->lotesP[i]->infoConsumo(mes);
		}
	}

}


void Sistema::infoReservas(int nLote,int mes) {
	for(unsigned int i = 0; i < this->lotesP.size(); i++) {
		if (this->lotesP[i]->getNLote() == nLote) {
			this->lotesP[i]->infoReservas(mes);
		}
	}
}


Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

