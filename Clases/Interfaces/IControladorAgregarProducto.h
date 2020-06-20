#ifndef ICONTROLADORAGREGARPRODUCTO
#define ICONTROLADORAGREGARPRODUCTO

#include <list>
#include "../DataTypes/DtProductoBase.h"
#include "../DataTypes/DtProductoCantidad.h"
#include "../Objetos/VentaLocal.h"

class IControladorAgregarProducto {
public:
    virtual void seleccionarMesa(int) = 0;
    virtual void seleccionarProducto(DtProductoCantidad) = 0;
    virtual list<DtProductoBase*> listarProductos() = 0;
    virtual void cancelarAgregarProductoVenta() = 0;
    virtual void confirmarAgregarProductoVenta() = 0;
    virtual void incrementarProductoEnVenta(VentaLocal*, DtProductoCantidad) = 0;
    virtual bool hayEsteProductoEnEnEstaVenta(VentaLocal*, string) = 0;
};

#endif //ICONTROLADORAGREGARPRODUCTO