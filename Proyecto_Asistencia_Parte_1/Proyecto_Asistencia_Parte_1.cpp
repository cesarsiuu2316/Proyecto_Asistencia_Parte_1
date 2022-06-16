#include <iostream>
#include <fstream>
#include <vector>
#include "Alumno.h"
#include <string>
#include <iomanip>
using namespace std;

void listar();
void leerAlumnos(ifstream& file);
void ordenarVector();

static vector<Alumno*> alumnos;

int main()
{
    string nombre = "Cesar";
    alumnos.push_back(new Alumno(nombre, 13, 0, 13));
    alumnos.push_back(new Alumno("Juan", 11, 5, 16));
    alumnos.push_back(new Alumno("Pablo", 7, 10, 17));
    listar();
    ifstream file("./Contenido del Curso/hola.txt"); // "./Contenido del Curso/Semana 01/2021-07-20.txt"
    string x;
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, x);
            cout << x << endl;
        }
        file.close();
    }
    for (int i = 0; i < alumnos.size(); i++)
        delete alumnos[i];
}

void listar() { 
    cout << "LISTADO:\n========\n"; 
    cout << "\tALUMN0  AUDIO  NO_AUDIO  ASISTENCIA  PORCENTAJE\n";
    cout << "\t------  -----  --------  ----------  ----------\n";
    for (Alumno* a : alumnos) {
        cout << right << setw(14) << a->getnombre() << setw(6) << a->getusaMicro() << setw(7) << a->getnousaMicro() << setw(12)
            << a->getasistencia() << setw(13) << fixed << setprecision(2) << a->getPorcentaje() << "%\n";
    }
}

void leerAlumnos(ifstream& file) {
    string Nombre, usaMicro;
    string linea;
    double porcentaje = 0;
    bool yaExiste = false;
    cout << left << setw(10) << "Cuenta" << setw(13)
        << "Nombre" << "Saldo" << '\n' << fixed << showpoint;
    while (getline(file, linea)) {
        if (yaExiste) {

        }
        else {
            
            Alumno* alumno = new Alumno();
            alumno->setnombre(Nombre);
            usaMicro = "NO_AUDIO";
            alumnos.push_back(alumno);
        }
    }
}

void ordenarVector() {

}

