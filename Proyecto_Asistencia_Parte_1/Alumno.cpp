#include "Alumno.h"

Alumno::Alumno() : nombre(""), usaMicro(0), nousaMicro(0), asistencia(0), porcentaje(0) {}

Alumno::Alumno(string nombre) : asistencia(0), usaMicro(0), nousaMicro(0), porcentaje(0)
{
	this->nombre = nombre;
}

Alumno::Alumno(string nombre, int usaMicro, int nousaMicro, int asistencia) {
	this->nombre = nombre;
	this->usaMicro = usaMicro;
	this->nousaMicro = nousaMicro;
	this->asistencia = asistencia;
}


string Alumno::getnombre()
{
	return nombre;
}

int Alumno::getusaMicro()
{
	return usaMicro;
}

int Alumno::getnousaMicro()
{
	return nousaMicro;
}

int Alumno::getasistencia()
{
	return asistencia;
}

double Alumno::getPorcentaje() {
	calcularPorcentaje();
	return porcentaje;
}

void Alumno::setnombre(string nombre)
{
	this->nombre = nombre;
}

void Alumno::setusaMicro(int usaMicro)
{
	this->usaMicro = usaMicro;
}

void Alumno::setnousaMicro(int nousaMicro)
{
	this->nousaMicro = nousaMicro;
}

void Alumno::setasistencia(int asistencia)
{
	this->asistencia = asistencia;
}

void Alumno::aumentarConteos(int usaMicro) {
	if (usaMicro == 1) {
		this->usaMicro++;
	}
	else {
		this->nousaMicro++;
	}
	this->asistencia++;
}

void Alumno::calcularPorcentaje() {
	this->porcentaje = ((double)usaMicro * 100.0) / (double)asistencia;
}