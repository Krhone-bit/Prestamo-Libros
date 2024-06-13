#include "../include/Libro.h"
#include <string.h>
#include <iostream>
using namespace std;
Libro::Libro(){
	cod_libro=-1;
	SetNombre("");
	SetAutor("");
	SetPaginas(0);
	SetEdicion(0);
	SetIdioma("");
}
Libro::Libro(char n[50],char a[50],int p,int e,char i[50]){
	SetNombre(n);
	SetAutor(a);
	SetPaginas(p);
	SetEdicion(e);
	SetIdioma(i);
}

Libro::Libro(int cod,char n[50],char a[50],int p,int e,char i[50]){
	cod_libro=cod;
	SetNombre(n);
	SetAutor(a);
	SetPaginas(p);
	SetEdicion(e);
	SetIdioma(i);
}
// Persona::Persona(long cod,char Nombres[20],char Appat[20],char Apmat[20],int Edad,char Sexo){
// 	cod_persona=cod;
// 	SetPersona(Nombres,Appat,Apmat,Edad,Sexo);
// 	SetClave("");
// }
void Libro::SetLibro(const Libro&l){
	*this=l;
}
void Libro::SetNombre(char n[50]){
	strcpy(nombre,Validar(n));
}
void Libro::SetAutor(char a[50]){
	strcpy(autor,Validar(a));
}
void Libro::SetPaginas(int p){
	paginas=Validar(p);
}
void Libro::SetEdicion(int e){
	edicion=Validar(e);
}
void Libro::SetIdioma(char i[50]){
	strcpy(idioma,Validar(i));
}
char*Libro::GetNombre(){
	return nombre;
}
char*Libro::GetAutor(){
	return autor;
}
int Libro::GetPaginas(){
	return paginas;
}
int Libro::GetEdicion(){
	return edicion;
}
char*Libro::GetIdioma(){
	return idioma;
}
char*Libro::Validar(char cad[50]){
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
int Libro::Validar(int num){
	if(num>0)
		return num;
	return -num;
}
void Libro::Mostrar(){
	cout<<"Titulo del Libro: "<<nombre<<endl;
	cout<<"Autor: "<<autor<<endl;
	cout<<"Paginas: "<<paginas<<endl;
	cout<<"Edicion: "<<edicion<<endl;
	cout<<"Idioma: "<<idioma<<endl<<endl;
}

void Libro::MostrarConsulta(){
	cout<<cod_libro<<"\t"<<nombre<<"\t"<<autor<<"\t"<<paginas<<"\t";
	cout<<edicion<<"\t"<<idioma<<endl;
}
