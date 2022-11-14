#ifndef LOTE_H
#define LOTE_H

#include <iostream>

using namespace std;

class Lote
{
	private:
		int nLote;
		float area;
		
	public:
		Lote();
		Lote(int n, float a);
		Lote(Lote *l);
		int getNLote();
		float getArea();
};

#endif
