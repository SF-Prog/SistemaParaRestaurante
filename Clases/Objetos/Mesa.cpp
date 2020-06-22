#include "Mesa.h"
#include "../Manejadores/ManejadorProducto.h"

//Constructores
Mesa::Mesa() {}
Mesa::Mesa(int nroMesa) {
    this->numero = nroMesa;
    this->ventaLocal = NULL;
}

//Getters & Setters
int Mesa::getNumero() {
    return this->numero;
}
void Mesa::setNumero(int numero) {
    this->numero = numero;
}
VentaLocal* Mesa::getVentaLocal() {
    return this->ventaLocal;
}
void Mesa::setVentaLocal(VentaLocal* ventaLocal) {
    this->ventaLocal = ventaLocal;
}

//Destructores
Mesa::~Mesa() {};

//Metodos
bool Mesa::tieneVenta() {
    return this->getVentaLocal() != NULL;
}
void Mesa::agregarProducto(DtProductoCantidad pc) {
    VentaLocal* ventaLocal = this->getVentaLocal();
    if (ventaLocal->tieneElProducto(pc.getCodigo()))
        ventaLocal->incrementar(pc);
    else
        ventaLocal->agregarProducto(pc);
}
list<DtProducto*> Mesa::listarProductos() {
    return this->getVentaLocal()->listarProductos();
}
void Mesa::quitarProducto(DtProductoCantidad pc) {
    this->getVentaLocal()->eliminarProducto(pc.getCodigo());
}