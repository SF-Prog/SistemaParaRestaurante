#ifndef CONTROLADORFACTURACION
#define CONTROLADORFACTURACION

#include "../Interfaces/IControladorFacturacion.h"

class ControladorFacturacion : public IControladorFacturacion {
public:
    //Destructor
    ~ControladorFacturacion();

    //Metodos
    DtFacturaLocal facturar(int, float);
};

#endif //CONTROLADORFACTURACION