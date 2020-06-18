#include "DtFacturaLocal.h"

//Constructores
DtFacturaLocal::DtFacturaLocal() {}
DtFacturaLocal::DtFacturaLocal(string codVenta, DtFechaHora fechaEmision, list<DtProductoFactura*> productos, float subTotalVenta, float descuento, float montoTotalVenta, float montoTotalVentaConIva, string nombreMozo):DtFactura(codVenta, fechaEmision, productos, subTotalVenta, descuento, montoTotalVenta, montoTotalVentaConIva) {
    this->nombreMozo = nombreMozo;
}

//Getters & Setters
string DtFacturaLocal::getNombreMozo() {
    return this->nombreMozo;
}
void DtFacturaLocal::setNombreMozo(string nombreMozo) {
    this->nombreMozo = nombreMozo;
}

//Destructores
DtFacturaLocal::~DtFacturaLocal() {}

//Metodos
//Aca crear ostream
ostream& operator <<(ostream& salida, const DtFacturaLocal& dtfL) {
  cout << "Mozo: " << dtfL.nombreMozo << endl;
  cout <<"Codigo de venta:" << dtfL.codVenta << endl;
  cout <<"Fecha:" << dtfL.fechaEmision << endl;
  for (DtProductoFactura* dtP : dtfL.productos){
    cout <<"Descripción: " << dtP->getDescripcion() << "  Precio: " << dtP->getPrecio() << "  Cantidad: " << dtP->getCantidad() << endl;
  }
  cout <<"Subtotal Venta:" << dtfL.subtotalVenta << endl;
  cout <<"Descuento:" << dtfL.descuento << endl;
  cout <<"Total Venta:" << dtfL.montoTotalVenta << endl;
  cout <<"Total Venta con IVA" << dtfL.montoTotalVentaConIva << endl;
	return salida;
}
