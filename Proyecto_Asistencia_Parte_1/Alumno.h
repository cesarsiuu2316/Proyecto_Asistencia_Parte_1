#pragma once
#include <iostream>
using namespace std;

class Alumno
{
public:
	Alumno();
	Alumno(string nombre);
	Alumno(string nombre, int usarMicro, int nousaMicro, int asistencia);
	string getnombre();
	void aumentarConteos(int usaMicro);
	int getusaMicro();
	int getnousaMicro();
	int getasistencia();
	double getPorcentaje();
	void setnombre(string nombre);
	void setusaMicro(int usaMicro);
	void setnousaMicro(int noUsaMicro);
	void setasistencia(int asistencia);
	void calcularPorcentaje();
private:
	double porcentaje;
	string nombre;
	int usaMicro;
	int nousaMicro;
	int asistencia;
};