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
    cout<<"+--------------------+"<<endl;
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
    cout<<I()<<" [2] USUARIOS           "<<I()<<endl;
    cout<<I()<<" [3] SALIR              "<<I()<<endl;
    Linea();

    cout<<"Opcion >> ";
    cin>>opcion;

    if(opcion==1)
        LoginAdministrador();
    else if(opcion==2){
        LoginUsuarios();
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
    cout<<I()<<"         LOGIN      "<<I()<<endl;
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
    cout<<I()<<"[1] NUEVO LIBRO                     "<<I()<<endl;
    cout<<I()<<"[2] NUEVO USUARIO                   "<<I()<<endl;
    cout<<I()<<"[3] PRESTAMOS DE LIBROS x FECHA     "<<I()<<endl;
    cout<<I()<<"[4] MOSTRAR LIBROS                  "<<I()<<endl;
    cout<<I()<<"[5] SALIR                           "<<I()<<endl;
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
            Inicio();
        break;

        default:
            cout<<"Elija Una Opcion Valida"<<endl;
            system("PAUSE");
            Administrador();
        break;
    }
}

void Menu::LoginUsuarios(){
    int codigo;
    char clave[20];
    Limpiar();
    Linea();
    cout<<I()<<"        LOGIN       "<<I()<<endl;
    cout<<I()<<"      VENDEDORES    "<<I()<<endl;
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
        Usuarios(codigo);
    }
    else{
        cout<<"USUARIO O CONTRASEÑA INCORRECTA ..."<<endl;
        system("PAUSE");
        LoginUsuarios();
    }
}


void Menu::Usuarios(long cod_user){
    Limpiar();
    Linea();
    cout<<I()<<"[1] REGISTRAR PRESTAMO      "<<I()<<endl;
    cout<<I()<<"[2] VER LIBROS PRESTADOS    "<<I()<<endl;
    cout<<I()<<"[3] SALIR                   "<<I()<<endl;
    Linea();
    cout<<"Opcion >> ";
    cin>>opcion;
    Consultar con;
    Guardar objGuardar;
    Fecha f;
    // VentaCelular venta;
    Libro libro;
    Persona ven;
    // Celular cel;
    Persona per;
    int n;
    switch(opcion){
        case 1:
            Limpiar();
            int cod_libro;
            int cod_cel;
            cout<<"CODIGO DE LIBRO: ";
            cin>>cod_libro;
            libro=con.BuscarLibro(cod_libro);
            if(cod_libro==libro.GetCodLibro()){
                libro.MostrarConsulta();
            }
            
//             else{
//                 per=IngresarDatos();
//                 per.SetCodigo(cod_com);
//                 objGuardar.GuardarComprador(per);
//                 per.Mostrar();
//             }
//             Linea();
//             char modelo[20];
//             Celular*objs;
//             cout<<"INGRESE SU MODELO: ";
//             cin>>modelo;
//             con.BuscarCelular(modelo,n);
//             objs=new Celular[n];
//             objs=con.BuscarCelular(modelo,n);
//             for(int i=0;i<n;i++){
//                 cout<<"["<<i<<"] ";
//                 objs[i].MostrarConsulta();
//                 cout<<endl;
//             }
//             cout<<"INGRESE SU OPCION [0,"<<n<<"]: ";
//             cin>>cod_cel;
//             cod_cel=objs[cod_cel].GetCodigo();
//             Linea();
//             f=IngresarFecha();
//             venta.SetDatos(cod_com,cod_ven,cod_cel,f);
//             objGuardar.GuardarVentaCelular(venta);
//             system("PAUSE");
//             Vendedores(cod_ven);
        break;

        case 2:
            Limpiar();
//             con.MostrarCompradores();
//             system("PAUSE");
//             Vendedores(cod_ven);
        break;

        case 3:
            Inicio();
        break;

        default:
            cout<<"Elija Una Opcion Valida"<<endl;
            system("PAUSE");
            Usuarios(cod_user);
        break;
    }
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
    return Libro(cod_libro,nombre,autor,paginas,edicion,idioma);
}

Persona Menu::IngresarDatosPersona(){
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
    return Persona(-1,nombre,appat,apmat,edad,sexo);
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
    Persona p;
    cout<<"INGRESE CODIGO: ";
    cin>>cod;
    cout<<"CLAVE: ";
    cin>>clave;
    p=IngresarDatosPersona();
    p.SetCodigo(cod);
    p.SetClave(clave);
    Guardar objGuardar;
    objGuardar.GuardarPersona(p);
    Linea();
    cout<<"Usuario Registrado Satisfactoriamente"<<endl;
    system("PAUSE");
}


void Menu::PrestamosLibrosFecha(){
    
}
