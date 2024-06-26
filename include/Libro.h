#ifndef LIBRO_H
#define LIBRO_H
#include <string.h>
#include <iostream>
using namespace std;

class Libro{
	private:
		int cod_libro;
		char nombre[50];
		char autor[50];
		int paginas;
		int edicion;
		char idioma[50];
		bool disponible;
	public:
		Libro();
		Libro(char n[50],char a[50],int p,int e,char i[50],bool d);
		Libro(int cod,char n[50],char a[50],int p,int e,char i[50], bool d);
		void SetLibro(const Libro&l);
		void SetNombre(char n[50]);
		void SetAutor(char a[50]);
		void SetPaginas(int p);
		void SetEdicion(int e);
		void SetIdioma(char i[50]);
		void SetDisponible(bool d);
		bool GetDisponible();

		long GetCodLibro();
		char*GetNombre();
		char*GetAutor();
		int GetPaginas();
		int GetEdicion();
		char*GetIdioma();
		void MostrarConsulta();
		char*Validar(char cad[50]);
		int Validar(int num);

		void Mostrar();
};
#endif // LIBRO_H
