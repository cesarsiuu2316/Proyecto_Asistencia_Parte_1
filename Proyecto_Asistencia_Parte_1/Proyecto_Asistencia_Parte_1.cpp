#include <iostream>
#include <fstream>
#include <vector>
#include "Alumno.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <algorithm>

using namespace std;
using fs = filesystem::recursive_directory_iterator;

void listar();
void leerAlumnos(vector<string>& absolutePaths);
void ordenarVector();
void listarDirectorios(vector<string>& absolutePaths);
void printDirectorios();
void agregarAlumno(string Nombre, int usaMicro, string& print);
int posicionAlumno(string nombre);
static vector<Alumno*> alumnos;
static vector<string> paths;

int main()
{    
    vector<string> absolutePaths;
    listarDirectorios(absolutePaths);
    leerAlumnos(absolutePaths);
    ordenarVector();
    listar();
    for (int i = 0; i < alumnos.size(); i++)
        delete alumnos[i];
    system("pause");
}

void listar() { 
    cout << "\n*LISTADO:\n=========\n"; 
    cout << "\tALUMN0  AUDIO  NO_AUDIO  ASISTENCIA  PORCENTAJE\n";
    cout << "\t------  -----  --------  ----------  ----------\n";
    for (Alumno* a : alumnos) {
        cout << right << setw(14) << a->getnombre() << setw(6) << a->getusaMicro() << setw(7) << a->getnousaMicro() << setw(12)
            << a->getasistencia() << setw(13) << fixed << setprecision(2) << a->getPorcentaje() << "%\n";
    }
}

void leerAlumnos(vector<string>& absolutePaths) {
    string print = "";
    string Nombre = "";
    int usaMicro = -1;
    for (int i = 0; i < paths.size(); i++) {
        string linea;
        ifstream file(paths[i]); // "./Contenido del Curso/Semana 01/2021-07-20.txt"
        if (file.is_open()) {
            print = "\n*REVISANDO EL ARCHIVO:\n{" + absolutePaths[i] + "}:\n";
            getline(file, linea);
            print += "\tI";
            getline(file, linea);
            while (!file.eof()) {
                Nombre = "";
                usaMicro = -1;
                if (linea == "") {                    
                    print += "I";
                }
                else if (linea.find(" - ") != string::npos) {
                    usaMicro = 0;
                    for (int i = 0; i < linea.size(); i++) {      
                        try {
                            Nombre += linea[i];
                            if (linea[i + 1] == ' ') {
                                break;
                            }
                        }
                        catch (...) {}
                    }
                    agregarAlumno(Nombre, usaMicro, print);
                }
                else if (linea.find(" ") != string::npos) {
                    print += "I";
                }
                else {
                    usaMicro = 1;
                    Nombre = linea;
                    agregarAlumno(Nombre, usaMicro, print);
                }   
                getline(file, linea);
            }
            cout << print << '\n';
            file.close();
        }
    }
}

void listarDirectorios(vector<string>& absolutePaths) {
    string path = ".\\Contenido del Curso";
    for (const auto& file : fs::recursive_directory_iterator(path)){
        string path = file.path().string();
        string absPath = filesystem::absolute(file).string();
        int size = (int)path.size() - 3;
        string txt = path.substr(size, 3);
        if (txt == "txt") {
            paths.push_back(path);
            absolutePaths.push_back(absPath);
        }
    }       
}

void ordenarVector() {
    vector<Alumno*> Alumn = alumnos;
    sort(Alumn.begin(), Alumn.end(), [](const Alumno* lhs, const Alumno* rhs) {
        return lhs->getusaMicro() > rhs->getusaMicro();
    }); 
    alumnos = Alumn;
}

void printDirectorios() {
    for (string p : paths) 
        cout << p << '\n';    
}

int posicionAlumno(string nombre) {
    for (int i = 0; i < alumnos.size(); i++) {
        if (alumnos[i]->getnombre() == nombre) {
            return i;
        }
    }
    return -1;
}

void agregarAlumno(string Nombre, int usaMicro, string& print) {
    int pos = posicionAlumno(Nombre);
    if (pos != -1) { // existe
        if (usaMicro == 1) {
            alumnos[pos]->aumentarConteos(1);
        }
        else if (usaMicro == 0) {
            alumnos[pos]->aumentarConteos(0);
        }
        print += "[" + Nombre + "][A]FU,";
    }
    else {
        Alumno* alumno = new Alumno(Nombre);
        alumno->setnombre(Nombre);
        if (usaMicro == 1) {
            alumno->aumentarConteos(1);
        }
        else if (usaMicro == 0) {
            alumno->aumentarConteos(0);
        }
        print += "[" + Nombre + "][A]NC,";
        alumnos.push_back(alumno);
    }
}