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
	DtFactura* f;

	float total = subtotal;
	if (descuento > 0)
		total -= subtotal * (descuento / 100);
	float totalCIVA = total * 1.22;

	f = new DtFactura(cod, fh.actual(), dtproductos, subtotal, descuento, total, totalCIVA);
	v->setFactura(f);
	cod = f->getCodVenta();
	fh = f->getFechaEmision();
	string nomMozo = v->getNombreMozo();
	
	DtFacturaLocal dtf;
	dtf = DtFacturaLocal(cod, fh, dtproductos, subtotal, descuento, total, totalCIVA, nomMozo);

	return dtf;
}