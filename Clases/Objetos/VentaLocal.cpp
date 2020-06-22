#include "../Manejadores/ManejadorProducto.h"
#include "VentaLocal.h"

//Constructores
VentaLocal::VentaLocal() {}
VentaLocal::VentaLocal(string codigo):Venta(codigo) {}
VentaLocal::VentaLocal(Mozo* mozo) {
    this->mozo = mozo;
}

//Getters & Setters
Mozo* VentaLocal::getMozo() {
    return this->mozo;
}
void VentaLocal::setMozo(Mozo* mozo) {
    this->mozo = mozo;
}

//Destructores
VentaLocal::~VentaLocal() {}

//Metodos
bool VentaLocal::tieneElProducto(string codigoProducto) {
    bool tiene = false;
    for (VentaProducto* vp : this->getVentaProductos()) {
        if (vp->getCodigoProducto() == codigoProducto) {
            tiene = true;
            break;
        }
    }
    return tiene;
}
void VentaLocal::agregarProducto(DtProductoCantidad pc) {
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    Producto* pro = mP->getProducto(pc.getCodigo());
    VentaProducto* vp = new VentaProducto(pc.getCantidad(), pro);
    list<VentaProducto*> lVP = this->getVentaProductos();
    lVP.push_back(vp);
    this->setVentaProductos(lVP);
}
void VentaLocal::incrementar(DtProductoCantidad pc) {
    for (VentaProducto* vp : this->getVentaProductos()) {
        if (vp->getCodigoProducto() == pc.getCodigo())
            vp->incrementarCantidad(pc.getCantidad());
    }
}
list<DtProducto*> VentaLocal::listarProductos() {
    list<DtProducto*> dtproductos;
    for (VentaProducto* vp : this->getVentaProductos()) {
        DtProducto* dtp = vp->getDtProducto();
        dtproductos.push_back(dtp);
    }
    return dtproductos;
}
string VentaLocal::getNombreMozo() {
    Mozo* m = this->getMozo();
    return m->getNombre();
}
float VentaLocal::getSubTotalVenta() {
    float suma = 0;
    for (VentaProducto* vp : this->getVentaProductos())
        suma += vp->getPrecioProductoEnVenta();
    return suma;
}
list<DtProductoFactura*> VentaLocal::getDtProductoFactura() {
    list<DtProductoFactura*> dtproductosFact;
    for (VentaProducto* vp : this->getVentaProductos()) {
        DtProductoFactura* dtpf = vp->getDtProductoFactura();
        dtproductosFact.push_back(dtpf);
    }
    return dtproductosFact;
}