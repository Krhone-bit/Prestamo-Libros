#include "../include/Hora.h"
#include <iostream>
using namespace std;
Hora::Hora(){
	hora=0;
	min=0;
	seg=0;
}
void Hora::SetHora(const Hora&h){
	*this=h;
}
Hora::Hora(int h,int m,int s){
	hora=h;
	min=m;
	seg=s;
}
void Hora::SetHora(int h,int m,int s){
	hora=h;
	min=m;
	seg=s;
}

bool Hora::validarHora(int h,int m,int s){
	if(h<0 || h>23) return false;
	if(m<0 || m>59) return false;
	if(s<0 || s>59) return false;
	return true;
}

int Hora::GetHora(){
	return hora;
}
int Hora::GetMin(){
	return min;
}
int Hora::GetSeg(){
	return seg;
}
void Hora::Mostrar(){
	cout<<hora<<":"<<min<<":"<<seg<<endl;
}
