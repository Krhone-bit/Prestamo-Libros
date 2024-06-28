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
        void NuevoUsuario();
        Persona IngresarDatosPersona();
        void PrestamosLibrosFecha();
        void Usuarios(long cod_user);
        // void NuevoVendedor();
        // void NuevoProducto();
        // Fecha IngresarFecha();
        // Persona IngresarDatos();
};
#endif // MENU_H
