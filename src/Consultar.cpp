#include "../include/Consultar.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
Persona Consultar::BuscarPersona(int codigo,char dir[15]){
    Persona per;
    FILE*archivo;
    archivo = fopen(dir, "r+");
    if(archivo==NULL)
        return per;
    fseek(archivo, SEEK_SET,0);
    while(!feof(archivo)){
        fread(&per,sizeof(per),1,archivo);
        if(per.GetCodigo()==codigo){
            fclose(archivo);
            return per;
        }
    }
    fclose(archivo);
    return per;
}

Persona Consultar::GetAdmin(){
    Persona per;
    FILE*archivo;
    archivo = fopen("admin.bin", "r");
    if(archivo==NULL)
        return per;
    fseek(archivo, SEEK_SET,0);
    fread(&per,sizeof(per),1,archivo);
    fclose(archivo);
    return per;
}

void Consultar::MostrarLibros(){
    Libro lib;
    FILE*archivo;
    archivo = fopen("lib.bin", "r+");
    if(archivo==NULL)
        return;
    fseek(archivo, SEEK_SET,0);
    fread(&lib,sizeof(lib),1,archivo);
    cout<<"CODIGO\t\tNOMBRE\tAUTOR\tPAGINAS\tEDICION\tIDIOMA"<<endl;
    while(!feof(archivo)){
        lib.MostrarConsulta();
        fread(&lib,sizeof(lib),1,archivo);
    }
    fclose(archivo);
}

Persona Consultar::BuscarUsuario(int codigo){
    return BuscarPersona(codigo,"per.bin");
}


Libro Consultar::BuscarLibro(int codigo){
    Libro lib;
    FILE*archivo;
    archivo = fopen("lib.bin", "r+");
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
