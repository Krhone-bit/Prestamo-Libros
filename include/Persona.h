#ifndef PERSONA_H
#define PERSONA_H
class Persona{
	private:
		int cod_persona;
		char nombres[30];
		char ap_pat[20];
		char ap_mat[20];
		int edad;
		char sexo;
	public:
		Persona();
		Persona(char n[30],char ap[20],char am[20],int e,char s);
		void SetPersona(const Persona&p);
		void SetNombres(char n[30]);
		void SetApPaterno(char ap[20]);
		void SetApMaterno(char am[20]);
		void SetSexo(char s);
		void SetEdad(int e);
		char*Validar(char cad[30]);
		int Validar(int num);
		char Validar(char s);
		char*GetNombres();
		char*GetApPaterno();
		char*GetApMaterno();
		int GetEdad();
		char GetSexo();
		void CumplirAnios();
		void MostrarSexo();
		void Mostrar();
};
#endif // PERSONA_H
