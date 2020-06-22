#include "../Manejadores/ManejadorMesa.h"
#include "ControladorFacturacion.h"

//Destructor
ControladorFacturacion::~ControladorFacturacion() {}

//Metodos
DtFacturaLocal ControladorFacturacion::facturar(int idMesa, float descuento) {
		ManejadorMesa* mM = ManejadorMesa::getInstancia();
		Mesa* me = mM->getMesa(idMesa);
		cout << "\nA" << endl;
		VentaLocal* v = me->getVentaLocal();
		cout << "\nB" << endl;
		list<DtProductoFactura*> dtproductos = v->getDtProductoFactura();
		cout << "\nC" << endl;
		float subtotal = v->getSubTotalVenta();
		cout << "\nD" << endl;
		string cod = v->getCodigo();
		cout << "\nE" << endl;
		DtFechaHora fh;
		cout << "\nF" << endl;
		DtFactura* f = new DtFactura(cod, fh.actual(), dtproductos, subtotal, descuento, subtotal * (1 - descuento), subtotal * (1 - descuento) * 1.22);
		cout << "\nG" << endl;
		v->setFactura(f);
		cout << "\nH" << endl;
		cod = f->getCodVenta();
		cout << "\nI" << endl;
		fh = f->getFechaEmision();
		cout << "\nJ" << endl;
		string nomMozo = "Robert"; // v->getNombreMozo();
		cout << "\nK" << endl;

		DtFacturaLocal dtf = DtFacturaLocal(cod, fh, dtproductos, subtotal, descuento, subtotal * (1 - descuento), subtotal * (1 - descuento) * 1.22, nomMozo);

		return dtf;
}
