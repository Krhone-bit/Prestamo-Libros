#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "Persona.h"
#include "Libro.h"
#include "Hora.h"
#include "Fecha.h"
class Prestamo{
	private:
		Persona p;
		Libro l;
		Hora h;
		Fecha f;
	public:
		Prestamo();
		void PrestarLibro(Persona P,Libro L,Hora H,Fecha F);
		void Mostrar();
};
#endif // PRESTAMO_H
