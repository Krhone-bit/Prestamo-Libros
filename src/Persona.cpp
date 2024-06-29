#include "../include/Persona.h"
#include <string.h>
#include <iostream>
#include <Consultar.h>
using namespace std;

Persona::Persona() {
    cod_persona = -1;
    SetPersona("", "", "", 0, 'X');
    SetClave("");
}

Persona::Persona(char Nombres[20], char Appat[20], char Apmat[20], int edad, char Sexo) {
    // cod_persona = cod;
    SetPersona(Nombres, Appat, Apmat, edad, Sexo);
    SetClave("");
}

void Persona::SetCodigo(long cod) {
    cod_persona = cod;
}

void Persona::SetTipo(char tipo) {
	this->tipo= tipo;
}

void Persona::SetPersona(char Nombres[20], char Appat[20], char Apmat[20], int edad, char Sexo) {
    strcpy(nombres, Nombres);
    strcpy(appat, Appat);
    strcpy(apmat, Apmat);
    this->edad = edad;
    this->sexo = Sexo;
}

void Persona::SetPersona(const Persona& p) {
    cod_persona = p.cod_persona;
    strcpy(nombres, p.nombres);
    strcpy(appat, p.appat);
    strcpy(apmat, p.apmat);
    edad = p.edad;
    sexo = p.sexo;
}

void Persona::SetClave(char clave[6]) {
    strcpy(this->clave, clave);
}

long Persona::GetCodigo() {
    return cod_persona;
}

Persona Persona::GetPersonaByCode(int cod) {
	Consultar busqueda;

	return busqueda.BuscarUsuario(cod);
}

char* Persona::GetNombres() {
    return nombres;
}

char*Persona::GetClave(){
    return clave;
}

void Persona::Mostrar() {
    cout << "Codigo: " << cod_persona << endl;
    cout << "Nombres: " << nombres << endl;
    cout << "Apellido Paterno: " << appat << endl;
    cout << "Apellido Materno: " << apmat << endl;
    cout << "Edad: " << edad << endl;
    cout << "Sexo: " << sexo << endl;
}

void Persona::MostrarUsuario(){
	cout<<cod_persona<<"\t"<<nombres<<"\t"<<appat<<" "<<apmat<<endl;
}

bool Persona::operator==(Persona persona){
	if (cod_persona == persona.cod_persona) {
		return true;
	}
	return false;
}

// bool Fecha::operator==(Fecha fecha){
//     if(dia==fecha.dia && mes==fecha.mes && anio==fecha.anio)
//         return true;
//     return false;
// }
