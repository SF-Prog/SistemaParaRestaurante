#include "../Manejadores/ManejadorMesa.h"
#include "../Manejadores/ManejadorProducto.h"
#include "../Manejadores/ManejadorVenta.h"
#include "ControladorAgregarProducto.h"

//Getters & Setters
int ControladorAgregarProducto::getMesa() {
	return this->mesa;
}
void ControladorAgregarProducto::setMesa(int mesa) {
	this->mesa = mesa;
}
DtProductoCantidad ControladorAgregarProducto::getProductoVenta() {
	return this->productoVenta;
}
void ControladorAgregarProducto::setProductoVenta(DtProductoCantidad productoVenta) {
	this->productoVenta = productoVenta;
}

//Destructor
ControladorAgregarProducto::~ControladorAgregarProducto() {}

//Metodos
void ControladorAgregarProducto::seleccionarMesa(int idMesa) {
	this->setMesa(idMesa);
}
void ControladorAgregarProducto::seleccionarProducto(DtProductoCantidad pc) {
	this->setProductoVenta(pc);
}
list<DtProductoBase*> ControladorAgregarProducto::listarProductos() {
	ManejadorProducto* mP = ManejadorProducto::getInstancia();
	list<DtProductoBase*> dtproductos;
	for (Producto* p : mP->getProductos())
		dtproductos.push_back(p->getDtProductoBase());
	return dtproductos;
}
void ControladorAgregarProducto::cancelarAgregarProductoVenta() {
}
void ControladorAgregarProducto::confirmarAgregarProductoVenta() {
	ManejadorMesa* mM = ManejadorMesa::getInstancia();
	Mesa* me = mM->getMesa(this->getMesa());
	me->agregarProducto(this->getProductoVenta());
}
bool ControladorAgregarProducto::hayEsteProductoEnEnEstaVenta(VentaLocal* VL, string codigo) {
	ManejadorVenta* mV= ManejadorVenta::getInstancia();
	return VL->tieneElProducto(codigo);
}