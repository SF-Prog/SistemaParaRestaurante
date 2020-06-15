#ifndef CONTROLADORFUNCIONESAUXILIARES
#define CONTROLADORFUNCIONESAUXILIARES

#include "../Interfaces/IControladorFuncionesAuxiliares.h"

class ControladorFuncionesAuxiliares : public IControladorFuncionesAuxiliares {
public:
    void validarProducto(string, float);
    void altaProducto(string, string, float);
};

#endif //CONTROLADORFUNCIONESAUXILIARES