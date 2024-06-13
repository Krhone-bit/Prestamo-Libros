#ifndef CONSULTAR_H
#define CONSULTAR_H
#include "Persona.h"
#include "Libro.h"
// #include "VentaCelular.h"
class Consultar{
   private:
        Persona BuscarPersona(int codigo,char dir[15]);
    public:
        // Persona BuscarComprador(int codigo);
        // Persona BuscarVendedor(int codigo);
        // Celular BuscarCelular(int codigo);
        // bool SeEncuentra(char buscada[20],char cadena[20]);
        // Celular*BuscarCelular(char marca[20],int&n);
        void MostrarLibros();
        // void MostrarCompradores();
        // int GetNumCelulares();
        Persona GetAdmin();
        // VentaCelular*GetVentasFecha(Fecha f,int&n);
};
#endif // CONSULTAR_H
