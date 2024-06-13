#ifndef MENU_H
#define MENU_H
#include "fecha.h"
#include "persona.h"
#include "libro.h"
class Menu{
    private:
        int opcion;
        void Linea();
        void Limpiar();
        char I();
    public:
        Menu();
        void Inicio();
        void LoginAdministrador();
        void LoginUsuarios();
        void Administrador();
        void NuevoLibro();
        Libro IngresarDatosLibro();
        void NuevaPersona();
        Persona IngresarDatosPersona();
        void PrestamosLibrosFecha();
        // void Vendedores(long cod_ven);
        // void NuevoVendedor();
        // void NuevoProducto();
        // Fecha IngresarFecha();
        // Persona IngresarDatos();
};
#endif // MENU_H
