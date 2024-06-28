#include "../include/Prestamo.h"
#include <iostream>
using namespace std;
Prestamo::Prestamo(){

}
void Prestamo::PrestarLibro(Persona P,Libro L,Hora H,Fecha F){
	p.SetPersona(P);
	l.SetLibro(L);
	h.SetHora(H);
	f.SetFecha(F);
}
void Prestamo::Mostrar(){
	cout<<"El senior: "<<endl;
	p.Mostrar();
	cout<<endl;
	cout<<"Se presto el Libro: "<<endl;
	l.Mostrar();
	cout<<endl;
	cout<<"En la Fecha: ";
	f.Mostrar();
	cout<<endl;
	cout<<"A horas: ";
	h.Mostrar();
}
