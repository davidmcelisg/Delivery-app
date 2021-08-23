#ifndef Persona_h
#define Persona_h
#pragma once

class Persona {
  public:
    string nombre;
    string estado;
    string ciudad;
    string cp;
  public:
    Persona();
    Persona(string, string, string, string);
    void setNombre(string);
    string getNombre();
    void setEstado(string);
    string getEstado();
    void setCiudad(string);
    string getCiudad();
    void setCP(string);
    string getCP();
    void imprimir();
};

Persona::Persona() {
  nombre = "";
  estado = "";
  ciudad = "";
  cp = "";
}

Persona::Persona(string n, string e, string ciu, string c) {
  nombre = n;
  estado = e;
  ciudad = ciu;
  cp = c;
}

void Persona::setNombre(string n) {
  nombre = n;
}

string Persona::getNombre() {
  return nombre;
}

void Persona::setEstado(string e) {
  estado = e;
}

string Persona::getEstado() {
  return estado;
}

void Persona::setCiudad(string ciu) {
  ciudad = ciu;
}

string Persona::getCiudad() {
  return ciudad;
}

void Persona::setCP(string c) {
  cp = c;
}

string Persona::getCP() {
  return cp;
}

void Persona::imprimir() {
  cout << "Cliente: " << nombre << endl << "Estado: " << estado << endl << "Ciudad: " << ciudad << " CP: " << cp << endl;
}

#endif /* Persona_h */