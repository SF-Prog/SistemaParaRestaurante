#ifndef CONTROLADORFUNCIONESAUXILIARES
#define CONTROLADORFUNCIONESAUXILIARES

#include "../Interfaces/IControladorFuncionesAuxiliares.h"

class ControladorFuncionesAuxiliares : public IControladorFuncionesAuxiliares {
public:
    bool validarProducto(string, float);
    void altaProducto(string, string, float);
};

#endif //CONTROLADORFUNCIONESAUXILIARES
