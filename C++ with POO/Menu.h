#ifndef MENU_H
#define MENU_H
#include <string>
#include <iostream>
#include "Controler.h"
#include "Persistencia.h"

class Menu 
{
	public:
		Menu();
		
		void exibeMenu1();
		void exibeMenu2(Controler *contr);
		void exibeMenu3(Controler *contr);
		void exibeMenu4(Controler *contr);
		void exibeMenu5(Controler *contr);
		void exibeMenu6(Controler *contr, int alter);
		void exibeMenu7(Controler *contr, int tip);
		
	protected:
};

#endif
