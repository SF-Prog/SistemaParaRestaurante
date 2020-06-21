#ifndef ICONTROLADORINFORMACIONPRODUCTO
#define ICONTROLADORINFORMACIONPRODUCTO

#include "../DataTypes/DtProducto.h"
#include "../DataTypes/DtProductoBase.h"

class IControladorInformacionProducto {
public:
	virtual list<DtProductoBase*> listarProductos() = 0;
	virtual DtProducto seleccionarProducto(string) = 0;
};

#endif //IControladorInformacionProducto
