#include "../Manejadores/ManejadorProducto.h"
#include "ControladorInformacionProducto.h"

DtProducto ControladorInformacionProducto::seleccionarProducto(string cod) {
			ManejadorProducto* mP = ManejadorProducto::getInstancia();
			Producto* p = mP->getProducto(cod);
			DtProducto dtP;
			
}

list<DtProductoBase*> ControladorInformacionProducto::listarProductos(){


}
ControladorInformacionProducto::~ControladorInformacionProducto(){ }
