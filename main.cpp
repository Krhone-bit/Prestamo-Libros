#include "include/prestamo.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <stdio.h>
int main()
{
    Libro l("Geometria Vectorial","Venero",421,2,"Espanol");
	Persona luis("Luis","Cordoba","Quispe",15,'M');
	Fecha f(3,8,2011);
	Hora h(15,23,18);

	Prestamo p;
	p.PrestarLibro(luis,l,h,f);
	p.Mostrar();

    return 1;
}
