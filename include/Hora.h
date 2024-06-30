#ifndef HORA_H
#define HORA_H
class Hora{
	private:
		int hora;
		int min;
		int seg;
	public:
		Hora();
		Hora(int h,int m,int s);
		void SetHora(int h,int m,int s);
		void SetHora(const Hora&h);
		bool validarHora(int h,int m,int s);
		int GetHora();
		int GetMin();
		int GetSeg();
		void Mostrar();
};
#endif // HORA_H
