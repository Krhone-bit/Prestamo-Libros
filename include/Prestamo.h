#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Persona.h"
#include "Libro.h"
#include "Hora.h"
#include "Fecha.h"

class Prestamo{
private:
    long cod_encargado;
    long cod_libro;
	long cod_usuario;
    Hora hora;
    Fecha fecha;

public:
    Prestamo();
    void PrestarLibro(int p, int l, int prestador, Hora h, Fecha f);
    void Mostrar(Persona p, Libro l);
    void MostrarConsulta();
    long GetCodigoPersona(Persona persona);
	
    Persona GetPersona(); // Agregar un método para obtener la persona asociada con el préstamo
};

#endif // PRESTAMO_H
