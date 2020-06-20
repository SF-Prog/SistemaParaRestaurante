#include "../Manejadores/ManejadorEmpleado.h"
#include "../Manejadores/ManejadorVenta.h"
#include "../Manejadores/ManejadorMesa.h"
#include "../Objetos/Mozo.h"
#include "ControladorIniciarVenta.h"

//Getters & Setters
string ControladorIniciarVenta::getMozo() {
	return this->mozo;
}
void ControladorIniciarVenta::setMozo(string mozo) {
	this->mozo = mozo;
}
list<int> ControladorIniciarVenta::getMesas() {
	return this->mesas;
}
void ControladorIniciarVenta::setMesas(list<int> mesas) {
	this->mesas = mesas;
}

//Destructor
ControladorIniciarVenta::~ControladorIniciarVenta() {}

//Metodos
list<int> ControladorIniciarVenta::ingresarIDMozo(string idMozo) {
	this->setMozo(idMozo);
	ManejadorEmpleado* mE = ManejadorEmpleado::getInstancia();
	Mozo* mo = dynamic_cast<Mozo*>(mE->getEmpleado(this->getMozo()));
	return mo->mesasAsignadasSinVenta();
}
list<int> ControladorIniciarVenta::seleccionarMesas(list<int> mesas) {
	this->setMesas(mesas);
	return mesas;
}
void ControladorIniciarVenta::cancelarIniciarVenta() {
}
void ControladorIniciarVenta::confirmarIniciarVenta() {
	ManejadorEmpleado* mE = ManejadorEmpleado::getInstancia();
	Mozo* mo = dynamic_cast<Mozo*>(mE->getEmpleado(this->getMozo()));
	VentaLocal* vl = new VentaLocal(mo);
	mo->asignarMesas(this->getMesas(), vl);
	ManejadorVenta* mV = ManejadorVenta::getInstancia();
	mV->agregarVenta(vl);
}

list <int> ControladorIniciarVenta::listarMesas() {
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    list<Mesa*> mesas = mM->getMesas();
    list<int> numeroMesa;
    for (list<Mesa*>::iterator it=mesas.begin(); it!=mesas.end(); it++)
        numeroMesa.push_back((*it)->getNumero());
    return numeroMesa;
}