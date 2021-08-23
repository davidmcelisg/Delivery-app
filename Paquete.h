#ifndef Paquete_h
#define Paquete_h
#pragma once
#include"Envio.h"

class Paquete : public Envio {
  protected:
    double peso;
    double costoKg;
  public:
    Paquete();
    Paquete(Persona, Persona, double, double, double);
    void setPeso(double);
    void setCostoKg(double);
    double getPeso();
    double getCostoKg();
    double calculaCostoEnvio();
};

Paquete::Paquete() : Envio() {
  peso = 0;
  costoKg = 0;
}

Paquete::Paquete(Persona r, Persona d, double c, double p, double cKg) : Envio(r,d,c) {
  peso = p;
  costoKg = cKg;
}

void Paquete::setPeso(double p) {
  peso = p;
}

void Paquete::setCostoKg(double cKg) {
  costoKg = cKg;
}

double Paquete::getPeso() {
  return peso;
}

double Paquete::getCostoKg() {
  return costoKg;
}

double Paquete::calculaCostoEnvio() {
  double total;
  if (remitente.estado == destinatario.estado) {
    total = costoEstandar;
  }
  else {
    total = costoEstandar + ((peso/5)*costoKg);
  }
}

#endif /* Paquete_h */