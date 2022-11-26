#include "Lote.h"

int Lote::lotesCreados = 0;
float Lote::sumaArea = 0;


Lote::Lote(){
	this->nLote = indefinido;
	this->area = indefinido;
}

Lote::Lote(float area){
	lotesCreados = lotesCreados + 1;
	sumaArea = sumaArea + area;

	this->nLote=lotesCreados;
	this->area=area;
}

Lote::Lote(Lote &l){
	this->area=l.area;
	this->nLote=l.nLote;
}

int Lote::getNLote(){
	return this->nLote;
}

float Lote::getPorcentajeArea() {
	return (this->area / sumaArea);
}
float Lote::getArea(){
	return this->area;
}

 void Lote::listarInfo() {
	 cout <<"Nro de Lote: "<<this->nLote<<endl;
	 cout <<"Area: " << this->area<<endl;
	 cout <<"Porcentaje de area: "<<this->getPorcentajeArea()<<endl;

 }

Lote::~Lote(){}

/* COMUNITARIO */


Comunitario::Comunitario():Lote(){}

Comunitario::Comunitario(float area):Lote(area){}

Comunitario::Comunitario(Comunitario &c):Lote(c){}

Comunitario::~Comunitario(){}



