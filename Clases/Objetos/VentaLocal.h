#ifndef VENTALOCAL
#define VENTALOCAL

#include "../DataTypes/DtProductoCantidad.h"
#include "Mozo.h"
#include "Venta.h"

class Mozo;
class VentaLocal : public Venta {
private:
    Mozo* mozo;
public:
    //Constructores
    VentaLocal();
    VentaLocal(string);
    VentaLocal(Mozo*);

    //Getters & Setters
    Mozo* getMozo();
    void setMozo(Mozo*);

    //Destructores
    ~VentaLocal();

    //Metodos
    bool tieneElProducto(string);
    void agregarProducto(DtProductoCantidad);
    void incrementar(DtProductoCantidad);
    list<DtProducto*> listarProductos();
    string getNombreMozo();
    float getSubTotalVenta();
    list<DtProductoFactura*> getDtProductoFactura();
};

#endif //VENTALOCAL
