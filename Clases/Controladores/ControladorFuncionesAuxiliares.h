#ifndef CONTROLADORFUNCIONESAUXILIARES
#define CONTROLADORFUNCIONESAUXILIARES

#include "../Interfaces/IControladorFuncionesAuxiliares.h"
#include "../Objetos/VentaLocal.h"

class ControladorFuncionesAuxiliares : public IControladorFuncionesAuxiliares {
public:
    bool estaMesaTieneVenta(int);
    bool existeMozo(string);
    bool existeProducto(string);
    VentaLocal* obtenerCodigoDeVenta(int);
    TipoProducto tipoProducto(string);
};

#endif //CONTROLADORFUNCIONESAUXILIARES