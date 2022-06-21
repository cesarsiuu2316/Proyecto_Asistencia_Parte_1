#pragma once
#include <iostream>
#include <string>
using namespace std;

class Alumno
{
public:
	Alumno();
	Alumno(string nombre);
	Alumno(string nombre, int usarMicro, int nousaMicro, int asistencia);
	string getnombre();
	void aumentarConteos(int usaMicro);
	int getusaMicro() const;
	int getnousaMicro();
	int getasistencia();
	double getPorcentaje();
	void setnombre(string nombre);
	void setusaMicro(int usaMicro);
	void setnousaMicro(int noUsaMicro);
	void setasistencia(int asistencia);
	void calcularPorcentaje();
	string toString();
private:
	double porcentaje;
	string nombre;
	int usaMicro;
	int nousaMicro;
	int asistencia;
};