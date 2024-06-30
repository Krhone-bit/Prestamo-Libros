#include "../include/Prestamo.h"
#include <iostream>
using namespace std;

Prestamo::Prestamo() {
	Persona per;
	Libro lib;
    // SetDatos(Persona(-1,"","",0,0,0),Libro(-1,"","",0,0,""),Hora(0,0,0),Fecha(0,0,0));
	SetDatos(-1,-1,-1,Hora(0,0,0),Fecha(0,0,0));
}

Prestamo::Prestamo(int cod_en, int cod_lib, int cod_us, Hora H, Fecha F) {
    SetDatos(cod_en, cod_lib, cod_us, H, F);
}

void Prestamo::SetDatos(int cod_en, int cod_lib, int cod_us, Hora H, Fecha F){
    cod_encargado=cod_en;
	cod_usuario=cod_us;
    cod_libro=cod_lib;
    hora.SetHora(H);
    fecha.SetFecha(F);
}


Persona Prestamo::GetPersona() {
	Persona person;
	return person.GetPersonaByCode(cod_encargado);
}

void Prestamo::Mostrar(Persona persona, Libro libro) {
    cout << "El usuario: " << endl;
    persona.Mostrar();
    cout << endl;
    cout << "Se prestó el Libro: " << endl;
    libro.Mostrar();
    cout << endl;
    cout << "En la Fecha: ";
    fecha.Mostrar();
    cout << endl;
    cout << "A horas: ";
    hora.Mostrar();
}

void Prestamo::MostrarConsulta() {
    int dia = fecha.GetDia();
    int mes = fecha.GetMes();
    int anio = fecha.GetAnio();
    int h = hora.GetHora();
    int m = hora.GetMin();
    int s = hora.GetSeg();
    cout << cod_encargado << "\t\t" << cod_libro << "\t" << cod_usuario << "\t";
    cout << dia << "/" << mes << "/" << anio << "\t" << h << ":" << m << ":" << s << endl;
}


Fecha Prestamo::GetFecha() {
    return fecha;
}

void Prestamo::SetDatos(const Prestamo&prestamo){
    *this=prestamo;
}

int Prestamo::GetCodUsuario() {
    return cod_usuario; 
}

int Prestamo::GetCodEncargado() {
    return cod_usuario;
}

int Prestamo::GetCodLibro() {
    return cod_libro;
}
