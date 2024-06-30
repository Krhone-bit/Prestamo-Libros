#include "../include/Guardar.h"
#include <stdio.h>

void Guardar::GuardarAdmin(){
    FILE*archivo;
    archivo = fopen("admin.bin","w");
    Persona per("admin","","",0,0);
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

void Guardar::ActualizarLibro(Libro lib) {
    FILE* archivo = fopen("lib.bin", "r+b"); // Abrir archivo en modo de lectura/escritura binaria
    if (archivo == nullptr) {
        perror("Error al abrir el archivo");
        return;
    }

    Libro temp;
    bool encontrado = false;
    while (fread(&temp, sizeof(Libro), 1, archivo)) {
        if (temp.GetCodLibro() == lib.GetCodLibro()) {
            fseek(archivo, -sizeof(Libro), SEEK_CUR); // Mover el cursor hacia atrás para sobrescribir
            fwrite(&lib, sizeof(Libro), 1, archivo);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Libro no encontrado." << endl;
    }

    fclose(archivo);
}

void Guardar::GuardarPersona(Persona per, char tipo){
    if(tipo == 'E'){
        GuardarPersona(per, "enc.bin");
    }else{
        GuardarPersona(per, "per.bin");
    }
}

void Guardar::GuardarPrestamo(const Prestamo&pre){
    FILE*archivo;
    archivo = fopen("pre.bin","a");
    fseek(archivo, SEEK_SET,0);
    fwrite(&pre,sizeof(pre),1,archivo);
    fclose(archivo);
}
