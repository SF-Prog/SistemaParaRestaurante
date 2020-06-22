#ifndef CONTROLADORAGREGARPRODUCTO
#define CONTROLADORAGREGARPRODUCTO

#include "../Interfaces/IControladorAgregarProducto.h"

class ControladorAgregarProducto : public IControladorAgregarProducto {
private:
    int mesa;
    DtProductoCantidad productoVenta;
public:
    //Getters & Setters
    int getMesa();
    void setMesa(int);
    DtProductoCantidad getProductoVenta();
    void setProductoVenta(DtProductoCantidad);

    //Destructor
    ~ControladorAgregarProducto();

    //Metodos
    void seleccionarMesa(int); 
    void seleccionarProducto(DtProductoCantidad);
    list<DtProductoBase*> listarProductos();
    void cancelarAgregarProductoVenta();
    void confirmarAgregarProductoVenta();
    bool hayEsteProductoEnEnEstaVenta(VentaLocal*, string);
};

#endif //CONTROLADORAGREGARPRODUCTO