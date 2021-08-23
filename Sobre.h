#ifndef Sobre_h
#define Sobre_h
#pragma once
#include"Envio.h"

class Sobre : public Envio {
  protected:
    double largo;
    double ancho;
    double cargoAdicional;
  public:
    Sobre();
    Sobre(Persona, Persona, double, double, double, double);
    void setLargo(double);
    void setAncho(double);
    void setCargoAd(double);
    double getLargo();
    double getAncho();
    double getCargoAd();
    double calculaCostoEnvio();
};

Sobre::Sobre() : Envio() {
  largo = 0;
  ancho = 0;
  cargoAdicional = 0;
}

Sobre::Sobre(Persona r, Persona d, double c, double l, double a, double cA) : Envio(r, d, c) {
  largo = l;
  ancho = a;
  cargoAdicional = cA;
}

void Sobre::setLargo(double l) {
  largo = l;
}

void Sobre::setAncho(double a) {
  ancho = a;
}

void Sobre::setCargoAd(double cA) {
  cargoAdicional = cA;
}

double Sobre::getLargo() {
  return largo;
}

double Sobre::getAncho() {
  return ancho;
}

double Sobre::getCargoAd() {
  return cargoAdicional;
}

double Sobre::calculaCostoEnvio() {
  double total;
  if (remitente.estado == destinatario.estado) {
    total = costoEstandar;
  }
  else {
    total = costoEstandar + cargoAdicional;
  }
  return total;
}

#endif /* Sobre_h */