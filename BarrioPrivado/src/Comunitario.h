#ifndef COMUNITARIO_H
#define COMUNITARIO_H

#include "Lote.h"
#include <iostream>

using namespace std;

class Comunitario : public Lote
{
	public:
		Comunitario();
		Comunitario(int n, float a);
		Comunitario(Comunitario *c);
;};

#endif
