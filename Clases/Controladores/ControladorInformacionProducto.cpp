#include "../Manejadores/ManejadorProducto.h"
#include "ControladorInformacionProducto.h"

DtProducto ControladorInformacionProducto::seleccionarProducto(string cod)
{
	ManejadorProducto *mP = ManejadorProducto::getInstancia();
	Producto *p = mP->getProducto(cod);
	DtProductoBase dtPB = p->getDtProductoBase();
	DtProducto dtP;
	dtP->setPrecio(p->getPrecio());
	//CANTIDAD
	if (Menu * m dynamic_cast<Menu *>(p))
	{
		cout << "\n\t Productos Comunes del Menu:" << endl;
		list<ProductoMenu *> productosMenu;
		for (ProductoMenu *pm : productosMenu)
		{
			cout << "\n\t\t" << *pm << endl;
		}
		}
}

list<DtProductoBase *> ControladorInformacionProducto::listarProductos()
{
	ManejadorProducto *mP = ManejadorProducto::getInstancia();
	list<DtProductoBase *> dtproductos;
	for (Producto *p : mP->getProductos())
		dtproductos.push_back(p->getDtProductoBase());
	return dtproductos;
}
ControladorInformacionProducto::~ControladorInformacionProducto() {}
