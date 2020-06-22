#include "../Manejadores/ManejadorProducto.h"
#include "ControladorInformacionProducto.h"

DtProducto* ControladorInformacionProducto::seleccionarProducto(string cod)
{
	ManejadorProducto *mP = ManejadorProducto::getInstancia();
	Producto *p = mP->getProducto(cod);
	DtProductoBase *dtPB = p->getDtProductoBase();
	
	//DtProducto productoArmado(dtPB->getCodigo(), dtPB->getDescripcion(), p->getPrecio(), 12/* aca va lo de la cantidad */);
	
	DtProducto* productoArmado = dynamic_cast<DtProducto*>(dtPB);
	
	return productoArmado;

}

list<DtProductoBase*>  ControladorInformacionProducto::listarProductos()
{
	ManejadorProducto *mP = ManejadorProducto::getInstancia();
	list<DtProductoBase *> dtproductos;
	for (Producto *p : mP->getProductos())
		dtproductos.push_back(p->getDtProductoBase());
	return dtproductos;
}


//Destructor
ControladorInformacionProducto::~ControladorInformacionProducto() {}
