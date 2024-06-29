#include "../include/Menu.h"
#include <iostream>
#include <stdlib.h>
#include "../include/Guardar.h"
#include "../include/Consultar.h"
#include "../include/Libro.h"
#include <conio.h>
#include <string.h>
using namespace std;
Menu::Menu(){
    opcion=0;
}

void Menu::Linea(){
    cout<<"+------------------------+"<<endl;
}

char Menu::I(){
    return '|';
}

void Menu::Limpiar(){
    system("CLS");
}

void Menu::Inicio(){
    Limpiar();
    Guardar g;
    g.GuardarAdmin();
    Linea();
    cout<<I()<<"  SISTEMA DE PRESTAMO   "<<I()<<endl;
    cout<<I()<<"    DE LIBROS           "<<I()<<endl;
    Linea();
    cout<<I()<<" [1] ADMINISTRADOR      "<<I()<<endl;
    cout<<I()<<" [2] BIBLIOTECARIO      "<<I()<<endl;
    cout<<I()<<" [3] SALIR              "<<I()<<endl;
    Linea();

    cout<<"Opcion >> ";
    cin>>opcion;

    if(opcion==1)
        LoginAdministrador();
    else if(opcion==2){
        LoginBibliotecario();
    }
    else if(opcion==3){
        exit(0);
    }
    else{
        cout<<"Elija Una Opcion Valida"<<endl;
        system("PAUSE");
        Inicio();
    }
}


void Menu::LoginAdministrador(){
    char user[20];
    char clave[20];
    Limpiar();
    Linea();
    cout<<I()<<"        LOGIN       "<<I()<<endl;
    cout<<I()<<"    ADMINISTRADOR   "<<I()<<endl;
    cout<<I()<<"                    "<<I()<<endl;
    Linea();
    cout<<"  USER >> ";
    cin>>user;
    cout<<" CLAVE >> ";
    cin>>clave;
    cout<<endl;

    Consultar con;
    Persona x=con.GetAdmin();
    cout<<x.GetNombres()<<endl;
    cout<<x.GetClave()<<endl;
    if(strcmp(x.GetClave(),clave)==0 &&
       strcmp(x.GetNombres(),user)==0){
        Administrador();
    }
    else{
        cout<<"USUARIO O CONTRASEÑA INCORRECTA ..."<<endl;
        system("PAUSE");
        LoginAdministrador();
    }
}

void Menu::Administrador(){
    Limpiar();
    Linea();
    cout<<I()<<"[1] NUEVO LIBRO             "<<I()<<endl;
    cout<<I()<<"[2] NUEVO USUARIO           "<<I()<<endl;
    cout<<I()<<"[3] PRESTAMOS x FECHA       "<<I()<<endl;
    cout<<I()<<"[4] MOSTRAR LIBROS          "<<I()<<endl;
    cout<<I()<<"[5] MOSTRAR BIBLIOTECARIOS  "<<I()<<endl;
    cout<<I()<<"[6] MOSTRAR PRESTATARIOS    "<<I()<<endl;
    cout<<I()<<"[7] SALIR                   "<<I()<<endl;
    Linea();
    cout<<"Opcion >> ";
    cin>>opcion;
    Consultar con;
    Persona us;
    Libro li;
    Fecha f;
    int n;
    switch(opcion){
        case 1:
            cout<<"Libro Creado"<<endl;
            NuevoLibro();
            Administrador();
        break;

        case 2:
            cout<<"Nueva Usuario Creado"<<endl;
            NuevoUsuario();
            Administrador();

        break;

        case 3:
            cout<<"Prestamos Creados"<<endl;
            PrestamosLibrosFecha();
        break;

        case 4:
            cout<<"Libros Cargados"<<endl;
            con.MostrarLibros();
            system("PAUSE");
            Administrador();
        break;

        case 5:
            cout<<"Usuarios Encargados"<<endl;
            con.MostrarBibliotecarios();
            system("PAUSE");
            Administrador();
        break;


        case 6:
            cout<<"Usuarios Cargados"<<endl;
            con.MostrarPrestatarios();
            system("PAUSE");
            Administrador();
        break;

        case 7:
            Inicio();
        break;

        default:
            cout<<"Elija Una Opcion Valida"<<endl;
            system("PAUSE");
            Administrador();
        break;
    }
}

void Menu::LoginBibliotecario(){
    int codigo;
    char clave[20];
    Limpiar();
    Linea();
    cout<<I()<<"        LOGIN       "<<I()<<endl;
    cout<<I()<<"    BIBLIOTECARIO   "<<I()<<endl;
    cout<<I()<<"                    "<<I()<<endl;
    Linea();
    cout<<"  CODIGO >> ";
    cin>>codigo;
    cout<<"   CLAVE >> ";
    cin>>clave;
    cout<<endl;
    Consultar con;
    Persona x=con.BuscarUsuario(codigo);
    if(strcmp(x.GetClave(),clave)==0){
        Bibliotecario(codigo);
    }
    else{
        cout<<"USUARIO O CONTRASEÑA INCORRECTA ..."<<endl;
        system("PAUSE");
        LoginBibliotecario();
    }
}


void Menu::Bibliotecario(long cod_user){
    Limpiar();
    Linea();
    cout<<I()<<"[1] REGISTRAR PRESTAMO  "<<I()<<endl;
    cout<<I()<<"[2] VER PRESTATARIOS    "<<I()<<endl;
    cout<<I()<<"[3] SALIR               "<<I()<<endl;
    Linea();
    cout<<"Opcion >> ";
    cin>>opcion;
    Consultar con;
    Guardar objGuardar;
    Fecha f;
    Prestamo prestamo_libro;
    Libro libro;
    Hora hora;
    Fecha fecha;
    Persona encargado;
    Persona usuario;
    int n;
    switch(opcion){
        case 1:
            Limpiar();
            int cod_libro;
            int cod_usuario;
            char opc;
            cout<<"CODIGO DE LIBRO: ";
            cin>>cod_libro;
            libro=con.BuscarLibro(cod_libro);
            if(cod_libro==libro.GetCodLibro()){
                libro.MostrarConsulta();
            }else{
                cout<<"LIBRO NO ENCONTRADO"<<endl;
                system("PAUSE");
                Bibliotecario(cod_user);
            }
            cout<<"CODIGO DE USUARIO: ";
            cin>>cod_usuario;
            usuario = con.BuscarUsuario(cod_usuario);
            if(cod_usuario==usuario.GetCodigo()){
                hora=IngresarHora();
                fecha=IngresarFecha();
                cout<<"USUARIO ENCONTRADO"<<endl;
                // per.Mostrar();
                prestamo_libro.PrestarLibro(cod_usuario, cod_libro, cod_user,hora,fecha);
            }else{
                char tipo = 'U';
                cout<<"USUARIO NO ENCONTRADO"<<endl;
                usuario=IngresarDatosPersona();
                usuario.SetCodigo(cod_usuario);
                objGuardar.GuardarPersona(usuario, tipo);
                usuario.Mostrar();
                hora=IngresarHora();
                fecha=IngresarFecha();
                prestamo_libro.PrestarLibro(usuario.GetCodigo(), cod_libro, cod_user,hora,fecha);
            }
            prestamo_libro.Mostrar(usuario, libro);
            objGuardar.GuardarPrestamo(prestamo_libro);
            system("PAUSE");
            Bibliotecario(cod_user);
            return;
        break;

        case 2:
            Limpiar();
            con.MostrarPrestatarios();
            system("PAUSE");
            Bibliotecario(cod_user);
            return;
        break;

        case 3:
            Inicio();
        break;

        default:
            cout<<"Elija Una Opcion Valida"<<endl;
            system("PAUSE");
            Bibliotecario(cod_user);
        break;
    }
}

Fecha Menu::IngresarFecha(){
    int dd;
    int mm;
    int aa;
    cout<<"FECHA: "<<endl;
    cout<<"\tDIA: ";
    cin>>dd;
    cout<<"\tMES: ";
    cin>>mm;
    cout<<"\tAÑO: ";
    cin>>aa;
    return Fecha(dd,mm,aa);
}

Hora Menu::IngresarHora(){
    int hora;
    int min;
    int seg;
    cout<<"HORA: "<<endl;
    cout<<"\tHORA: ";
    cin>>hora;
    cout<<"\tMINUTO: ";
    cin>>min;
    cout<<"\tSEGUNDO: ";
    cin>>seg;
    return Hora(hora,min,seg);
}

Libro Menu::IngresarDatosLibro(){
    int cod_libro;
	char nombre[50];
	char autor[50];
	int paginas;
	int edicion;
	char idioma[50];
    cout<<"INGRESE CODGIGO DEL LIBRO: ";
    cin>>cod_libro;
    cout<<"INGRESE NOMBRE: ";
    cin>>nombre;
    cout<<"INGRESE AUTOR: ";
    cin>>autor;
    cout<<"INGRESE PAGINAS: ";
    cin>>paginas;
    cout<<"INGRESE EDICION: ";
    cin>>edicion;
    cout<<"INGRESE IDIOMA: ";
    cin>>idioma;
    return Libro(cod_libro,nombre,autor,paginas,edicion,idioma,true);
}

Persona Menu::IngresarDatosPersona(){
    int n=0;
    char nombre[20];
    char appat[20];
    char apmat[20];
    int edad;
    char sexo;
    cout<<"INGRESE NOMBRE: ";
    cin>>nombre;
    cout<<"INGRESE APELLIDO PATERNO: ";
    cin>>appat;
    cout<<"INGRESE APELLIDO MATERNO: ";
    cin>>apmat;
    cout<<"INGRESE SEXO [M o F]: ";
    cin>>sexo;
    cout<<"INGRESE EDAD: ";
    cin>>edad;
    return Persona(nombre,appat,apmat,edad,sexo);
}

void Menu::NuevoLibro(){
    Limpiar();
    Linea();
    int cod_libro;
	char nombre[50];
	char autor[50];
	int paginas;
	int edicion;
	char idioma[50];
    Libro l;
    l=IngresarDatosLibro();
    Guardar objGuardar;
    objGuardar.GuardarLibro(l);
    Linea();
    cout<<"Libro Registrado Satisfactoriamente"<<endl;
    system("PAUSE");
}


void Menu::NuevoUsuario(){
    Limpiar();
    Linea();
    long cod;
    char clave[6];
    char tipo; //encargado o prestador
    Persona p;
    cout<<"INGRESE CODIGO: ";
    cin>>cod;
    cout<<"CLAVE: ";
    cin>>clave;
    cout<<"TIPO DE USUARIO [(E)ncargado , (U)suario]: "; // E=encargado U=Usuario prestador
    cin>>tipo;
    p=IngresarDatosPersona();
    p.SetCodigo(cod);
    p.SetClave(clave);
    p.SetTipo(tipo);
    Guardar objGuardar;
    objGuardar.GuardarPersona(p,tipo);
    Linea();
    cout<<"Usuario Registrado Satisfactoriamente"<<endl;
    system("PAUSE");
}


void Menu::PrestamosLibrosFecha(){
    
}
