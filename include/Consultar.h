#ifndef CONSULTAR_H
#define CONSULTAR_H
#include "Persona.h"
#include "Libro.h"
#include "Prestamo.h"
class Consultar{
   private:
        Persona BuscarPersona(int codigo,char dir[15]);
    public:
        Libro BuscarLibro(int codigo);
        Persona BuscarUsuario(int codigo);
        // Celular BuscarCelular(int codigo);
        // bool SeEncuentra(char buscada[20],char cadena[20]);
        // Celular*BuscarCelular(char marca[20],int&n);
        void MostrarLibros();
        void MostrarPrestamos();
        Persona*BuscarPersonas(int&n);
        // void MostrarCompradores();
        // int GetNumCelulares();
        Persona GetAdmin();
        Prestamo*MostrarLibrosPrestados(Persona usuario, int&n);
        Persona BuscarPersonaCodigoMasAlto(int&b);
        void MostrarUsuarios();
        void MostrarPrestatarios();
        void MostrarBibliotecarios();
        Prestamo* GetPrestamosFecha(Fecha fe, int&n);
        Persona BuscarBibliotecario(int codigo);
        int GetNumLibros();
        int GetNumPersonas(char dir[15]);
        // VentaCelular*GetVentasFecha(Fecha f,int&n);
};
#endif // CONSULTAR_H
