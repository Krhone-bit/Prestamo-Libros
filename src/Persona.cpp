#include "../include/Persona.h"
#include <string.h>
#include <iostream>
#include <Consultar.h>
using namespace std;

Persona::Persona() {
    cod_persona = -1;
    SetPersona("", "", "", 0, 'X');
    SetClave("");
    SetNombreUsuario("");
}

Persona::Persona(char Nombres[20], char Appat[20], char Apmat[20], int edad, char Sexo) {
    SetPersona(Nombres, Appat, Apmat, edad, Sexo);
}

void Persona::SetCodigo(long cod) {
    cod_persona = cod;
}

void Persona::SetNombreUsuario(char nombreU[20]) {
    strcpy(nombre_usuario, nombreU);
}

void Persona::SetTipo(char tipo) {
	this->tipo= tipo;
}

void Persona::SetPersona(char Nombres[20], char Appat[20], char Apmat[20], int Edad, char Sexo) {
	if(Validar(Nombres))
		strcpy(nombres,Nombres);
	else
		strcpy(nombres,"");

	if(Validar(Appat))
		strcpy(appat,Appat);
	else
		strcpy(appat,"");

	if(Validar(Apmat))
		strcpy(apmat,Apmat);
	else
		strcpy(apmat,"");

	if(Edad>=0)
		edad=Edad;
	else
		edad=0;

	if(ValidarSexo(Sexo))
		sexo=Sexo;
	else
		sexo='x';
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

char*Persona::GetNombreUsuario() {
    return nombre_usuario;
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

bool Persona::Validar(char cad[20]){
	int i=0;
	while(cad[i]!='\0'){
		if(cad[i]==' '){}
		else if(!isalpha(cad[i]))//verifica si un caracter es una letra del alfabeto si no es una letra del alfabeto retorna falso
			return false;
		i++;
	}
	return true;
}

bool Persona::ValidarSexo(char Sexo){
	if(Sexo=='M' || Sexo=='m' || Sexo=='F'|| Sexo=='f')
		return true;
	return false;
}
