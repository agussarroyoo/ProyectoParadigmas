#include "Lote.h"

int Lote::nro = 0;
float Lote::sumaArea = 0;


Lote::Lote(){
	nro = nro + 1;
	this->nLote=nro;
}

Lote::Lote(float area){
	nro = nro + 1;
	this->nLote=nro;
	this->area=area;
	sumaArea = sumaArea + area;
}

Lote::Lote(Lote &l){
	this->area=l.area;
	this->nLote=l.nLote;
}

int Lote::getNLote(){
	return this->nLote;
}

int Lote::getPorcentajeArea() {
	return this->area / sumaArea;
}
float Lote::getArea(){
	return this->area;
}

 void Lote::listarInfo() {
	 cout <<"Nro lote: "<<this->nLote<<endl;
	 cout <<"Area: " << this->area<<endl;

 }


/* COMUNITARIO */


Comunitario::Comunitario():Lote(){}

Comunitario::Comunitario(float area):Lote(area){}

Comunitario::Comunitario(Comunitario &c):Lote(c){}



/* PRIVADO */

//Privado::Privado() {
//	// TODO Auto-generated constructor stub
////	this->consumos;
////	this->contrataciones;
////	this->expensas;
////	this->habitantes;
////	this->propietarios;
////	this->reservas;
//}
////inicio de constructor sobrecargado
//Privado::Privado(vector<Persona *> habitantes,vector<Persona *> propietarios, float area):Lote(area) {
//	for(unsigned int i=0;i<habitantes.size();i=i+1 ){
//		this->habitantes[i]= habitantes[i];
//	}
//
//	for(unsigned int i=0;i<propietarios.size();i=i+1 ){
//		this->propietarios[i]= propietarios[i];
//	}
////	this->consumos;
////	this->contrataciones;
////	this->expensas;
////	this->reservas;
//}
//
//void Privado::agregarConsumoElectrico(short dia,short mes,short anio,float medicion) {
//	this->consumos.insert(this->consumos.end(), new ConsumoElectrico(dia,mes, anio, medicion) );
//}
//void Privado::agregarContratacion(string empresa,TipoServicio tipo_servicio,short dia,short mes,short anio, float costo){
//	this->contrataciones.insert(this->contrataciones.end(), new Contratacion( empresa, tipo_servicio, dia, mes, anio,  costo));
//}
//
//void Privado::agregarReserva(Fecha fReserva, int hInicio, int hFin, float precio, Persona *pReserva, Comunitario *lComunitario) {
//	this->reservas.insert(this->reservas.end(), new Reserva(fReserva,  hInicio,  hFin,  precio,  pReserva,  lComunitario));
//}
//void Privado::agregarHabitante(Persona p){
//	this->habitantes.insert(this->habitantes.end(), &p);
//}
//void Privado::agregarPropietario(Persona p){
//	this->propietarios.insert(this->propietarios.end(), &p);
//
//}
//bool Privado::comprobarHabitante(Persona p){
//	bool aux = false;
//	for (unsigned int i = 0; i < this->habitantes.size(); i++) {
//		if ( this->habitantes[i]->getDni() == p.getDni()) {
//			return true;
//		}
//	}
//	return aux;
//}
//
//float Privado::crearExpensa(short mes,float servicios){
//	float consumo = 0;
//	for (unsigned int i= 0; i < this->consumos.size(); i++) {
//		if (this->consumos[i]->getFecha().getMes() == mes) {
//			consumo = consumo + this->consumos[i]->getMedicion();
//		}
//	}
//
//	return servicios * (this->area / this->sumaArea ) + consumo + this->calcularBonificacion(mes);
//
//}
//
//float Privado::calcularBonificacion(short mes) {
//	float aux = 0;
//	for (unsigned int i = 0; i < this->reservas.size(); i++) {
//		if (this->reservas[i]->getFecha().getMes() == mes) {
//			aux = aux + this->reservas[i]->getPrecio() * 0.05;
//		}
//	}
//	return aux;
//}
//Privado::~Privado() {
//	// TODO Auto-generated destructor stub
//}



