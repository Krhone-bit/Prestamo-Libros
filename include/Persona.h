#ifndef PERSONA_H
#define PERSONA_H
class Persona {
    private:
        long cod_persona;
        char nombre_usuario[20];
        char nombres[20];
        char appat[20];
        char apmat[20];
        int edad;
		char tipo;
        char sexo;
        char clave[6];
    public:
        Persona();
        Persona(char Nombres[20], char Appat[20], char Apmat[20], int edad, char Sexo);
        bool Validar(char cad[20]);
        bool ValidarSexo(char Sexo);
        void SetCodigo(long cod);
		void SetTipo(char tipo);
        void SetPersona(char Nombres[20], char Appat[20], char Apmat[20], int edad, char Sexo);
        void SetPersona(const Persona& p); // Asegúrate de que este método esté bien definido
        void SetClave(char clave[6]);
        void SetNombreUsuario(char nombreU[20]);
        long GetCodigo();
		Persona GetPersonaByCode(int cod);
        char* GetNombres();
        void Mostrar();
		char*GetClave();
        char*GetNombreUsuario();
		void MostrarUsuario();
		bool ValidarCodigo(long codigo);
		bool operator==(Persona persona);
};
#endif // PERSONA_H
