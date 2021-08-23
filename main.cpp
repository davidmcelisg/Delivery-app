#include <iostream>
#include <typeinfo>
using namespace std;
#include"Persona.h"
#include"Envio.h"
#include"Sobre.h"
#include"Paquete.h"

int main() {
  Persona arrClientes[19]; //como es un arreglo de obj automaticamente crea los 20 objetos de tipo Persona
  string nombre, estado, ciudad, cp;
  int opcion, posR, posD;
  int contClientes = 0;
  string nomR, nomD;
  Envio *arrEnvios[19]; //como es arreglo de apuntdores, no se crean los objetos
  int contEnvios = 0;
  double costoEst, largo, ancho, cargoAd, peso, costoKg;
  int tipo;
  string nombreRemitente, nombreDestinatario;
  int totalenvios = 0;

  do{
    cout << endl << "1. Dar de alta cliente" << endl;
    cout << "2. Dar de alta nuevo envío" << endl;
    cout << "3. Desplegar info de un envío" << endl;
    cout << "4. Mostrar envios" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese operación deseada (1-5)" << endl;
    cin >> opcion;

    switch(opcion) {
      case 1: 
        if (contClientes < 20) {
          cout << "Ingresa nombre: ";
          cin >> nombre;
          arrClientes[contClientes].setNombre(nombre);
          cout << "Ingresa estado: ";
          cin >> estado;
          arrClientes[contClientes].setEstado(estado);
          cout << "Ingresa ciudad: ";
          cin >> ciudad;
          arrClientes[contClientes].setCiudad(ciudad);
          cout << "Ingresa CP: ";
          cin >> cp;
          arrClientes[contClientes].setCP(cp);
          contClientes++;
          } 
        else {
          cout << "Arreglo de clientes lleno";
        }
      break;
      case 2:
        //validación de remitente esté dado de alta
        do {
          cout << "Ingrese el nombre del remitente: ";
          cin >> nomR;
          for (int i = 0; i < contClientes;i++) {
            if (nomR == arrClientes[i].getNombre()) {
              posR = i;
            }
          }
          if (posR == -1) {
            cout << "Error, Remitente " << nomR << "no está dado de alta en clientes de sistema" << endl;
          }
        } while (posR == -1);
        //validación de destinatario esté dado de alta
        do {
          cout << "Ingrese el nombre del destinatario: ";
          cin >> nomD;
          for (int i = 0; i < contClientes;i++) {
            if (nomD == arrClientes[i].getNombre()) {
              posD = i;
            }
          }
          if (posD == -1) {
            cout << "Error, Destinatario " << nomD << "no está dado de alta en clientes de sistema" << endl;
          }
        } while (posD == -1);
        cout << "Ingresa el costo estándar: ";
        cin >> costoEst;
        cout << "Ingrese si quiere 1) Sobre o 2) Paquete: ";
        cin >> tipo;
        if (tipo == 1) {
          cout << "Dame el largo: ";
          cin >> largo;
          cout << "Dame el ancho: ";
          cin >> ancho;
          cout << "Dame el cargo adicional: ";
          cin >> cargoAd;
          arrEnvios[contEnvios]=new Sobre(arrClientes[posR],arrClientes[posD],costoEst,largo, ancho, cargoAd);
          contEnvios++;
        }
        else {
          cout << "Dame el peso: ";
          cin >> peso;
          cout << "Dame el costo por kg: ";
          cin >> costoKg;
          arrEnvios[contEnvios]=new Paquete(arrClientes[posR],arrClientes[posD],costoEst,peso, costoKg);
          contEnvios++;
        }
      break;
      case 3:
        int posE;
        posE = -1;
        cout << "Ingresa el Remitente: ";
        cin >> nombreRemitente;
        cout << "Ingresa el Destinatario: ";
        cin >> nombreDestinatario;

        for (int i = 0; i < contEnvios; i++ ) {
          if (arrEnvios[i]->getRemitente().getNombre() == nombreRemitente && arrEnvios[i]-> getDestinatario().getNombre() == nombreDestinatario) {
            posE = i;
          }
        }
        if (posE == -1) {
          cout << "No se encuentra el envío " << endl;
        }
        else {
          cout << " Remitente: ";
          arrEnvios[posE]->getRemitente().imprimir();
          cout << " Destinatario: ";
          arrEnvios[posE]->getDestinatario().imprimir();
          if (typeid(*arrEnvios[posE]) == typeid(Sobre)) { //identificar qué tipo de objeto es
            Sobre* miSobre;
            miSobre = (Sobre *)arrEnvios[posE];
            cout << "Sobre con el cargo adicional de: " << miSobre->getCargoAd() << endl;
          }
          else {
            Paquete* miPaquete;
            miPaquete = (Paquete *)arrEnvios[posE];
            cout << "Paquete con un costo por cada 5 kg: " << miPaquete->getCostoKg() << endl;
          }
        }
      break;
      case 4: 
        cout << "Información de cada uno de los Envíos" << endl;
        for (int z = 0; z<contEnvios ;z++) {
          cout << "Envio " << z+1;
          cout << endl << "Nombre Remitente: ";
          arrEnvios[z]->getRemitente().imprimir();
          cout << endl << "Nombre Destinatario: ";
          arrEnvios[z]->getDestinatario().imprimir();
          if (typeid(*arrEnvios[posE]) == typeid(Sobre)) {
            cout << endl << "SOBRE con el cargo adicional de: "; 
            cout << arrEnvios[z]->getCostoEstandar() << endl;
            cout << "Costo envío " << z+1 << " $" << arrEnvios[z]->calculaCostoEnvio() << endl;
          }
          else {
            cout << "PAQUETE con un costo por cada 5 kg de: ";
            cout << arrEnvios[z]->getCostoEstandar() << endl;
            cout << "Costo envío " << z+1 << " $" << arrEnvios[z]->calculaCostoEnvio() << endl;
          }
          cout << "*******************************************" << endl;
        }
        cout << "*******************************************" << endl;
        cout << "*******************************************" << endl;
        cout << "*******************************************" << endl;
        for (int z = 0; z<contEnvios ;z++) {
          totalenvios = totalenvios + arrEnvios[z]->calculaCostoEnvio();
        }
        cout << "Total de Envíos: " << totalenvios;
    } 
  }while (opcion != 5);
} 