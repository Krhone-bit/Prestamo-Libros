#include "../include/Persona.h"
#include <string.h>
#include <iostream>
using namespace std;
Persona::Persona(){
	cod_persona=-1;
	SetPersona("","","",0,'x');
	SetClave("");
}
Persona::Persona(long cod,char Nombres[20],char Appat[20],char Apmat[20],int Edad,char Sexo){
	cod_persona=cod;
	SetPersona(Nombres,Appat,Apmat,Edad,Sexo);
	SetClave("");
}

void Persona::SetCodigo(long cod){
    if(cod_persona==-1)
        cod_persona=cod;
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

void Persona::SetPersona(char Nombres[20],char Appat[20],char Apmat[20],int Edad,char Sexo){
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
void Persona::SetPersona(Persona p){
	SetPersona(p.nombres,p.appat,p.apmat,p.edad,p.sexo);
}
void Persona::SetNombres(char Nombres[20]){
	if(Validar(Nombres))
		strcpy(nombres,Nombres);
}
void Persona::SetAppat(char Appat[20]){
	if(Validar(Appat))
		strcpy(appat,Appat);
}
void Persona::SetApmat(char Apmat[20]){
	if(Validar(Apmat))
		strcpy(apmat,Apmat);
}
void Persona::SetEdad(int Edad){
	if(Edad>edad)//La Edad debe de ser mayor por que no se le puede quitar a�os a una persona
		edad=Edad;
}
void Persona::CumplirAnio(){
	edad++;
}
void Persona::SetClave(char clv[6]){
    strcpy(clave,clv);
}
long Persona::GetCodigo(){
    return cod_persona;
}
char*Persona::GetNombres(){
	return nombres;
}
char*Persona::GetAppat(){
	return appat;
}
char*Persona::GetApmat(){
	return apmat;
}
int Persona::GetEdad(){
	return edad;
}
Persona Persona::GetPersona(){
	return Persona(cod_persona,nombres,appat,apmat,edad,sexo);
}
char Persona::GetSexo(){
	return sexo;
}
void Persona::Mostrar(){
	cout<<"Datos: "<<nombres<<" "<<appat<<" "<<apmat<<"\n";
	cout<<"Edad : "<<edad<<"\n";
	if(sexo=='M'||sexo=='m')
		cout<<"Sexo : Masculino"<<endl;
	else if(sexo=='F'||sexo=='f')
		cout<<"Sexo : Femenino"<<endl;
}
void Persona::MostrarConsulta(){
	cout<<cod_persona<<"\t"<<nombres<<"\t"<<appat<<"\t";
	cout<<clave<<"\t"<<sexo<<"\t"<<endl;
}
char*Persona::GetClave(){
    return clave;
}
Persona::~Persona(){
	strcpy(nombres,"");
	strcpy(appat,"");
	strcpy(apmat,"");
	edad=0;
	sexo='x';
}
