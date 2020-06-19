#ifndef ICONTROLADORALTAPRODUCTO
#define ICONTROLADORALTAPRODUCTO

#include <list>
#include "../DataTypes/DtProductoBase.h"
#include "../DataTypes/DtProductoCantidad.h"

class IControladorAltaProducto {
public:
    //Getters & Setters
    virtual string getCodMenu() = 0;
    virtual void setCodMenu(string) = 0;
    virtual string getDescMenu() = 0;
    virtual void setDescMenu(string) = 0;
    virtual string getCodComun() = 0;
    virtual void setCodComun(string) = 0;
    virtual string getDescComun() = 0;
    virtual void setDescComun(string) = 0;
    virtual list<DtProductoCantidad*> getProductosComun() = 0;
    virtual void setProductosComun(list<DtProductoCantidad*>) = 0;
    virtual float getPrecioComun() = 0;
    virtual void setPrecioComun(float) = 0;

    //Metodos
    virtual list<DtProductoBase*> listarProductosComunes() = 0;
    virtual list<DtProductoBase*> listarProductosMenu()= 0;
    virtual void datosProductoComun(string, string, float) = 0;
    virtual void cancelarProductoComun() = 0;
    virtual void confirmarProductoComun() = 0;
    virtual void datosProductoMenu(string, string) = 0;
    virtual void agregarAlProductoMenu(DtProductoCantidad*) = 0;
    virtual void cancelarProductoMenu() = 0;
    virtual void confirmarProductoMenu() = 0;
};

#endif //ICONTROLADORALTAPRODUCTO