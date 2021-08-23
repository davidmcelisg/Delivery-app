#ifndef Envio_h
#define Envio_h
#pragma once
#include"Persona.h"

class Envio {
  protected:
    Persona remitente;
    Persona destinatario;
    double costoEstandar;
  public:
    Envio();
    Envio(Persona, Persona, double);
    void setRemitente(Persona);
    Persona getRemitente();
    void setDestinatario(Persona);
    Persona getDestinatario();
    void setCostoEstandar(double);
    double getCostoEstandar();
    virtual double calculaCostoEnvio()=0; //no se desarrolla, es virtual puro
};

Envio::Envio() {
  remitente = Persona();
  destinatario = Persona();
  costoEstandar = 0;
}

Envio::Envio(Persona r, Persona d, double c) {
  remitente = r;
  destinatario = d;
  costoEstandar = c;
}

void Envio::setRemitente(Persona r) {
  remitente = r;
}

Persona Envio::getRemitente() {
  return remitente;
}

void Envio::setDestinatario(Persona d) {
  destinatario = d;
}

Persona Envio::getDestinatario(){
  return destinatario;
}

void Envio::setCostoEstandar(double c) {
  costoEstandar = c;
}

double Envio::getCostoEstandar() {
  return costoEstandar;
}

#endif /* Envio_h */