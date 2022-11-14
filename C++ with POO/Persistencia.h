#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include "Controler.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

class Persistencia
{
	public:
		Persistencia();
		
		int lerInsumos(Controler *contr);
		void salvarInsumos(Controler contr);
		
	protected:
};

#endif
