#include "Comunitario.h"

Comunitario::Comunitario():Lote(){}

Comunitario::Comunitario(int n, float a):Lote(n,a){}

Comunitario::Comunitario(Comunitario *c):Lote(*c){}

