#ifndef MESA
#define MESA

#include <list>
#include "../DataTypes/DtProducto.h"
#include "VentaLocal.h"

using namespace std;

class VentaLocal;
class Mesa {
private:
    int numero;
    VentaLocal* ventaLocal;
public:
    //Constructores
    Mesa();
    Mesa(int);

    //Getters & Setters
    int getNumero();
    void setNumero(int);
    VentaLocal* getVentaLocal();
    void setVentaLocal(VentaLocal*);

    //Destructores
    ~Mesa();

    //Metodos
    bool tieneVenta();
    void agregarProducto(DtProductoCantidad);
    list<DtProducto*> listarProductos();
    void quitarProducto(DtProductoCantidad);
};

#endif //MESA
