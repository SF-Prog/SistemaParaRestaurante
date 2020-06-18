#ifndef MANEJADORVENTA
#define MANEJADORVENTA

#include <map>
#include "../Objetos/VentaLocal.h"

class ManejadorVenta {
private:
    static ManejadorVenta* instancia;
    map<string, Venta*> ventas;
    ManejadorVenta();
public:
    //Instancia
    static ManejadorVenta* getInstancia();

    //Destructor
    virtual ~ManejadorVenta();

    //Metodos
    list<Venta*> getVentas();
    Venta* getVenta(string);
    void removerVenta(Venta*);
    bool agregarVenta(Venta*);

    };

#endif //MANEJADORVENTA