#include "Lote.h"

Lote::Lote(){
	this->nLote=9999;
	this->area=9999;
}

Lote::Lote(int n, float a){
	this->nLote=n;
	this->area=a;
}

Lote::Lote(Lote *l){
	this->area=l->area;
	this->nLote=l->nLote;
}

int Lote::getNLote(){
	return this->nLote;
}

float Lote::getArea(){
	return this->area;
}
