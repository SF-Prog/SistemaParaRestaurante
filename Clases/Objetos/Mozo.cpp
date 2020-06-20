#include <algorithm>
#include "../Manejadores/ManejadorMesa.h"
#include "Mesa.h"
#include "Mozo.h"

//Constructores
Mozo::Mozo() {}
Mozo::Mozo(string idEmpleado, string nombre):Empleado(idEmpleado, nombre) {}

//Getters & Setters
list<Mesa*> Mozo::getMesas() {
	return this->mesas;
}
void Mozo::setMesas(list<Mesa*> mesas) {
	this->mesas = mesas;
}

//Destructores
Mozo::~Mozo() {};

//Metodos
list<int> Mozo::mesasAsignadasSinVenta() {
	list<int> mesasSinVenta;
	for (Mesa* me : this->getMesas()) {
		if (!me->tieneVenta())
			mesasSinVenta.push_back(me->getNumero());
	}
	return mesasSinVenta;
}
void Mozo::asignarMesas(list<int> mesas, VentaLocal* vl) {
	ManejadorMesa* mM = ManejadorMesa::getInstancia();
	list<Mesa*> lMesas = this->getMesas();
	for (int mesa : mesas) {
		Mesa* me = mM->getMesa(mesa);
		list<Mesa*>::iterator m = find(lMesas.begin(), lMesas.end(), me);
		if (m != lMesas.end())
			(*m)->setVentaLocal(vl);
	}
}