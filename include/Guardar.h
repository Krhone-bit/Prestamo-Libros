#ifndef GUARDAR_H
#define GUARDAR_H
#include "Persona.h"
#include "Libro.h"
#include "Prestamo.h"
#include <iostream>
using namespace std;
class Guardar
{
    private:
        void GuardarPersona(Persona per,char dir[15]);
    public:
        void GuardarPersona(Persona per, char tipo);
        // void GuardarVendedor(Persona ven);
        void GuardarLibro(Libro li);
        void GuardarLibro(Libro li,char dir[15]);
        // void GuardarCelular(Celular&cel);
        // void GuardarVentaCelular(VentaCelular ven);
        void ActualizarLibro(Libro li);
        void GuardarAdmin();
        void GuardarPrestamo(const Prestamo&pre);
};
        
#endif // GUARDAR_H
