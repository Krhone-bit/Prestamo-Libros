#ifndef PERSONA_H
#define PERSONA_H
class Persona{
	private:
		long cod_persona;
		char nombres[20];
		char appat[20];
		char apmat[20];
		int edad;
		char sexo;
        char clave[6];
	public:
		Persona();
		Persona(long cod,char Nombres[20],char Appat[20],char Apmat[20],int edad,char Sexo);
		bool Validar(char cad[20]);
		bool ValidarSexo(char Sexo);
        void SetCodigo(long cod);
        void SetPersona(char Nombres[20],char Appat[20],char Apmat[20],int edad,char Sexo);
		void SetPersona(Persona persona);
		void SetNombres(char Nombres[20]);
		void SetAppat(char Appat[20]);
		void SetApmat(char Apmat[20]);
		void SetEdad(int Edad);
		void SetClave(char clv[6]);
		void CumplirAnio();
		long GetCodigo();
		char*GetNombres();
		char*GetAppat();
		char*GetApmat();
		char GetSexo();
		int GetEdad();
		char*GetClave();
		Persona GetPersona();
		void Mostrar();
		void MostrarConsulta();
		Persona IngresarDatosPersona(char Nombres[20],char Appat[20],char Apmat[20],int Edad,char Sexo);
		~Persona();
};
#endif // PERSONA_H
