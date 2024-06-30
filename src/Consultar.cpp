#include "../include/Consultar.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
Persona Consultar::BuscarPersona(int codigo, char dir[15]) {
    Persona per;
    FILE *archivo;
    archivo = fopen(dir, "rb");
    if (archivo == NULL)
        return per;
    fseek(archivo, SEEK_SET, 0);
    while (fread(&per, sizeof(per), 1, archivo)) {
        if (per.GetCodigo() == codigo) {
            fclose(archivo);
            return per;
        }
    }
    fclose(archivo);
    return per;
}

Persona*Consultar::BuscarPersonas(int&n) {
    Persona per;
    Persona personas[1000];
    FILE *archivo;
    archivo = fopen("per.bin", "rb");
    if (archivo == NULL)
        return personas;
    fseek(archivo, SEEK_SET, 0);
    while (fread(&per, sizeof(per), 1, archivo)) {
        personas[n++] = per;
            fclose(archivo);
            return personas;
    }
    fclose(archivo);
    return personas;
}

Persona Consultar::BuscarPersonaCodigoMasAlto(int&b) {
    int n = 0;
    Persona* personas = BuscarPersonas(b);
    if (n == 0) {
        // No hay personas en el archivo
        return Persona();
    }

    Persona personaCodigoMasAlto = personas[0];
    for (int i = 1; i < n; i++) {
        if (personas[i].GetCodigo() > personaCodigoMasAlto.GetCodigo()) {
            personaCodigoMasAlto = personas[i];
        }
    }
    return personaCodigoMasAlto;
}

Persona Consultar::GetAdmin(){
    Persona per;
    FILE*archivo;
    archivo = fopen("admin.bin", "rb");
    if(archivo==NULL)
        return per;
    fseek(archivo, SEEK_SET,0);
    fread(&per,sizeof(per),1,archivo);
    fclose(archivo);
    return per;
}

void Consultar::MostrarLibros() {
    Libro lib;
    FILE* archivo = fopen("lib.bin", "rb"); // Abrir archivo en modo de lectura binaria
    if (archivo == nullptr) {
        perror("Error al abrir el archivo");
        return;
    }

    cout << "CODIGO\tNOMBRE\tAUTOR\tPAGINAS\tEDICION\tIDIOMA\tESTADO" << endl;

    while (fread(&lib, sizeof(Libro), 1, archivo)) {
        lib.MostrarConsulta();
    }

    fclose(archivo);
}

int Consultar::GetNumLibros() {
    Libro lib;
    FILE* archivo = fopen("lib.bin", "rb"); // Abrir archivo en modo de lectura binaria
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    int num = ftell(archivo) / sizeof(Libro);
    fclose(archivo);
    return num;
}

int Consultar::GetNumPersonas(char dir[15]) {
    Persona per;
    FILE* archivo = fopen(dir, "rb"); // Abrir archivo en modo de lectura binaria
    if (archivo == nullptr) {
        return 0;
    }
    fseek(archivo, 0, SEEK_END);
    int num = ftell(archivo) / sizeof(Persona);
    fclose(archivo);
    return num;
}

void Consultar::MostrarBibliotecarios(){
    Persona per;
    FILE* archivo = fopen("enc.bin", "rb");
    if(archivo==NULL)
        return;
    fseek(archivo, SEEK_SET,0);
    fread(&per,sizeof(per),1,archivo);
    cout<<"CODIGO\tNOMBRE\tAPERLLIDOS"<<endl;
    while(!feof(archivo)){
        per.MostrarUsuario();
        fread(&per,sizeof(per),1,archivo);
    }
    fclose(archivo);
}


Prestamo *Consultar::MostrarLibrosPrestados(Persona usuario, int &n) {
    n = 0;
    Prestamo pre;
    Prestamo prestamos[1000];
    FILE *archivo;
    archivo = fopen("pre.bin", "rb");
    if (archivo == NULL)
        return prestamos;

    fseek(archivo, SEEK_SET, 0);
    fread(&pre,sizeof(pre),1,archivo);
    while (!feof(archivo)) {
        if(usuario==pre.GetPersona()){
            prestamos[n++] = pre;
        }
        fread(&pre,sizeof(pre),1,archivo);
    }
    fclose(archivo);
    return prestamos;
}

Persona Consultar::BuscarUsuario(int codigo){
    return BuscarPersona(codigo,"per.bin");
}

Persona Consultar::BuscarBibliotecario(int codigo){
    return BuscarPersona(codigo,"enc.bin");
}


Libro Consultar::BuscarLibro(int codigo){
    Libro lib;
    FILE*archivo;
    archivo = fopen("lib.bin", "rb");
    if(archivo==NULL)
        return lib;
    fseek(archivo, SEEK_SET,0);
    fread(&lib,sizeof(lib),1,archivo);
    while(!feof(archivo)){
        if(lib.GetCodLibro()==codigo){
            fclose(archivo);
            return lib;
        }
        fread(&lib,sizeof(lib),1,archivo);
    }
    fclose(archivo);
    return lib;
}


void Consultar::MostrarPrestatarios(){
    Persona per;
    FILE*archivo;
    archivo = fopen("per.bin", "rb");
    if(archivo==NULL)
        return;
    fseek(archivo, SEEK_SET,0);
    fread(&per,sizeof(per),1,archivo);
    cout<<"CODIGO\tNOMBRE\tAPELLIDOS"<<endl;
    while(!feof(archivo)){
        per.MostrarUsuario();
        fread(&per,sizeof(per),1,archivo);
    }
    fclose(archivo);
}

void Consultar::MostrarPrestamos(){
    Prestamo pre;
    FILE*archivo;
    archivo = fopen("pre.bin", "rb");
    if(archivo==NULL)
        return;
    fseek(archivo, SEEK_SET,0);
    fread(&pre,sizeof(pre),1,archivo);
    cout<<"ENCARGADO\tLIBRO\tUSUARIO\tFECHA\tHORA"<<endl;
    while(!feof(archivo)){
        pre.MostrarConsulta();
        fread(&pre,sizeof(pre),1,archivo);
    }
    fclose(archivo);
}

Prestamo* Consultar::GetPrestamosFecha(Fecha fe, int&n){
    n=0;
    Prestamo pre;
    Prestamo prestamos[1000];
    FILE *archivo;
    archivo = fopen("pre.bin", "r+");
    if (archivo == NULL)
        return prestamos;
    fseek(archivo, SEEK_SET, 0);
    fread(&pre,sizeof(pre),1,archivo);
    while (!feof(archivo)) {
        if(fe==pre.GetFecha()){
            prestamos[n++].SetDatos(pre);
        }
        fread(&pre,sizeof(pre),1,archivo);
    }
    fclose(archivo);
    return prestamos;
}
