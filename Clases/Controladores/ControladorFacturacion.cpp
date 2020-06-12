#include "../Manejadores/ManejadorMesa.h"
#include "ControladorFacturacion.h"

//Destructor
ControladorFacturacion::~ControladorFacturacion() {}

//Metodos
DtFacturaLocal ControladorFacturacion::facturar(int idMesa, float descuento) {
	ManejadorMesa* mM = ManejadorMesa::getInstancia();
	Mesa* me = mM->getMesa(idMesa);
	VentaLocal* v = me->getVentaLocal();
	list<DtProductoFactura*> dtproductos = v->getDtProductoFactura();
	float subtotal = v->getSubTotalVenta();
	string cod = v->getCodigo();
	DtFechaHora fh;
	DtFactura* f = new DtFactura(cod, fh.actual(), dtproductos, subtotal, descuento, subtotal * (1 - descuento), subtotal * (1 - descuento) * 1.22);
	v->setFactura(f);
	cod = f->getCodVenta();
	fh = f->getFechaEmision();
	string nomMozo = v->getNombreMozo();

	DtFacturaLocal dtf = DtFacturaLocal(cod, fh, dtproductos, subtotal, descuento, subtotal * (1 - descuento), subtotal * (1 - descuento) * 1.22, nomMozo);
	return dtf;
}