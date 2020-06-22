#include "Mesa.h"

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
    if (this->getVentaLocal()->tieneElProducto(pc.getCodigo())) {
        //cout << "Entro1" << endl;
        this->getVentaLocal()->incrementar(pc);
    } else {
        //cout << "Entro2" << endl;
        this->getVentaLocal()->agregarProducto(pc);
    }
}
list<DtProducto*> Mesa::listarProductos() {
    return this->getVentaLocal()->listarProductos();
}
void Mesa::quitarProducto(DtProductoCantidad pc) {
    this->getVentaLocal()->eliminarProducto(pc.getCodigo());
}