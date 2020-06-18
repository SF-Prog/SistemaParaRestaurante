#include "DtFactura.h"

//Constructores
DtFactura::DtFactura() {}
DtFactura::DtFactura(string codVenta, DtFechaHora fechaEmision, list<DtProductoFactura*> productos, float subTotalVenta, float descuento, float montoTotalVenta, float montoTotalVentaConIva) {
    this->codVenta = codVenta;
    this->fechaEmision = fechaEmision;
    this->productos = productos;
    this->subtotalVenta = subTotalVenta;
    this->descuento = descuento;
    this->montoTotalVenta = montoTotalVenta;
    this->montoTotalVentaConIva = montoTotalVentaConIva;
}

//Getters & Setters
string DtFactura::getCodVenta() {
    return this->codVenta;
}
void DtFactura::setCodVenta(string codVenta) {
    this->codVenta = codVenta;
}
DtFechaHora DtFactura::getFechaEmision() {
    return this->fechaEmision;
}
void DtFactura::setFechaEmision(DtFechaHora fechaEmision) {
    this->fechaEmision = fechaEmision;
}
list<DtProductoFactura*> DtFactura::getProductos() {
    return this->productos;
}
void DtFactura::setProductos(list<DtProductoFactura*> productos) {
    this->productos = productos;
}
float DtFactura::getSubtotalVenta() {
    return this->subtotalVenta;
}
void DtFactura::setSubtotalVenta(float subtotalVenta) {
    this->subtotalVenta = subtotalVenta;
}
float DtFactura::getDescuento() {
    return this->descuento;
}
void DtFactura::setDescuento(float descuento) {
    this->descuento = descuento;
}
float DtFactura::getMontoTotalVenta() {
    return this->montoTotalVenta;
}
void DtFactura::setMontoTotalVenta(float montoTotalVenta) {
    this->montoTotalVenta = montoTotalVenta;
}
float DtFactura::getTotalMontoVentaConIva() {
    return this->montoTotalVentaConIva;
}
void DtFactura::setTotalMontoVentaConIva(float montoTotalVentaConIva) {
    this->montoTotalVentaConIva = montoTotalVentaConIva;
}

//Destructores
DtFactura::~DtFactura() {}

//Metodos
ostream& operator <<(ostream& salida, const DtFactura& dtf) {
	cout <<"Codigo de venta:" << dtf.codVenta << endl;
  cout <<"Fecha:" << dtf.fechaEmision << endl;
  for (DtProductoFactura* dtP : dtf.productos){
    cout <<"Descripción: " << dtP->getDescripcion() << "  Precio: " << dtP->getPrecio() << "  Cantidad: " << dtP->getCantidad() << endl;
  }
  cout <<"Subtotal Venta:" << dtf.subtotalVenta << endl;
  cout <<"Descuento:" << dtf.descuento << endl;
  cout <<"Total Venta:" << dtf.montoTotalVenta << endl;
  cout <<"Total Venta con IVA" << dtf.montoTotalVentaConIva << endl;

  return salida;
}
