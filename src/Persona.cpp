#include "../include/Persona.h"
#include<iostream>
#include<string.h>
using namespace std;
Persona::Persona(){
	SetNombres("");
	SetApPaterno("");
	SetApMaterno("");
	SetSexo('x');
	SetEdad(0);
}
Persona::Persona(char n[30],char ap[20],char am[20],int e,char s){
	SetNombres(n);
	SetApPaterno(ap);
	SetApMaterno(am);
	SetSexo(s);
	SetEdad(e);
}
void Persona::SetPersona(const Persona&p){
	*this=p;
}
void Persona::SetNombres(char n[30]){
	strcpy(nombres,Validar(n));
}
void Persona::SetApPaterno(char ap[20]){
	strcpy(ap_pat,Validar(ap));
}
void Persona::SetApMaterno(char am[20]){
	strcpy(ap_mat,Validar(am));
}
void Persona::SetEdad(int e){
	edad=Validar(e);
}
void Persona::SetSexo(char s){
	sexo=Validar(s);
}
char*Persona::Validar(char cad[30]){
	int i;
	char*tmp;
	tmp=new char[30];
	for(i=0;cad[i]!='\0';i++){
		if(isalpha(cad[i])){
			tmp[i]=cad[i];
		}
		else{
			tmp[i]='\0';
			return tmp;
		}
	}
	tmp[i]='\0';
	return tmp;
}
int Persona::Validar(int num){
	if(num>0)
		return num;
	return -num;
}
char Persona::Validar(char s){
	if(s=='M' || s=='m')
		return 'm';
	else if(s=='F' || s=='f')
		return 'f';
	return 'x';
}
char*Persona::GetNombres(){
	return nombres;
}
char*Persona::GetApPaterno(){
	return ap_pat;
}
char*Persona::GetApMaterno(){
	return ap_mat;
}
int Persona::GetEdad(){
	return edad;
}
char Persona::GetSexo(){
	return sexo;
}
void Persona::CumplirAnios(){
	edad++;
}
void Persona::MostrarSexo(){
	cout<<"Sexo: ";
	if(sexo=='m')
		cout<<"Masculino"<<endl;
	else if(sexo=='f')
		cout<<"Femenino"<<endl;
	else if(sexo=='x')
		cout<<"No Definido"<<endl;
}
void Persona::Mostrar(){
	cout<<"Nombres: "<<nombres<<endl;
	cout<<"Apellidos: "<<ap_pat<<" "<<ap_mat<<endl;
	cout<<"Edad: "<<edad<<endl;
	MostrarSexo();
}
