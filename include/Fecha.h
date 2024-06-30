#ifndef FECHA_H
#define FECHA_H
class Fecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
		Fecha();
		Fecha(int dd,int mm,int aa);
		void SetFecha(const Fecha&F);
		void SetDia(int dd);
		void SetMes(int mm);
		bool validarFecha(int dd,int mm,int aa);
		void SetAnio(int aa);
		int GetDia();
		int GetMes();
		int GetAnio();
		void Mostrar();
		bool operator==(Fecha fecha);
};
#endif // FECHA_H
