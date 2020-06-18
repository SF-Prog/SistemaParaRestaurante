#ifndef CONTROLADORFUNCIONESAUXILIARES
#define CONTROLADORFUNCIONESAUXILIARES

#include "../Interfaces/IControladorFuncionesAuxiliares.h"
#include "../Objetos/VentaLocal.h"

class ControladorFuncionesAuxiliares : public IControladorFuncionesAuxiliares {
public:
    void altaProducto(string, string, float);
    bool estaMesaTieneVenta(int);
    bool existeProducto(string);
    VentaLocal* obtenerCodigoDeVenta(int);

};

#endif //CONTROLADORFUNCIONESAUXILIARES