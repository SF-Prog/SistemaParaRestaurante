#ifndef CONTROLADORFUNCIONESAUXILIARES
#define CONTROLADORFUNCIONESAUXILIARES

#include "../Interfaces/IControladorFuncionesAuxiliares.h"

class ControladorFuncionesAuxiliares : public IControladorFuncionesAuxiliares {
public:
    void altaProducto(string, string, float);
    bool estaMesaTieneVenta(int);
    bool existeProducto(string);
};

#endif //CONTROLADORFUNCIONESAUXILIARES