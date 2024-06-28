#include "../include/Guardar.h"
#include <stdio.h>

void Guardar::GuardarAdmin(){
    FILE*archivo;
    archivo = fopen("admin.bin","w");
    Persona per(0,"admin","","",0,0);
    per.SetClave("clave");
    fseek(archivo, SEEK_SET,0);
    fwrite(&per,sizeof(per),1,archivo);
    fclose(archivo);
}

void Guardar::GuardarPersona(Persona per,char dir[15]){
    FILE*archivo;
    archivo = fopen(dir,"a");
    fseek(archivo, SEEK_SET,0);
    fwrite(&per,sizeof(per),1,archivo);
    fclose(archivo);
}
void Guardar::GuardarLibro(Libro li,char dir[15]){
    FILE*archivo;
    archivo = fopen(dir,"a");
    fseek(archivo, SEEK_SET,0);
    fwrite(&li,sizeof(li),1,archivo);
    fclose(archivo);
}
void Guardar::GuardarLibro(Libro lib){
    GuardarLibro(lib, "lib.bin");
}

void Guardar::GuardarPersona(Persona per){
    GuardarPersona(per, "per.bin");
}

void Guardar::GuardarPrestamo(Prestamo pre){
    FILE*archivo;
    archivo = fopen("pre.bin","w");
    // Prestamo(pre);
    fseek(archivo, SEEK_SET,0);
    fwrite(&pre,sizeof(pre),1,archivo);
    fclose(archivo);
}
