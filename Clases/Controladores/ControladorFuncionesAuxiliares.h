#ifndef CONTROLADORFUNCIONESAUXILIARES
#define CONTROLADORFUNCIONESAUXILIARES

#include "../Interfaces/IControladorFuncionesAuxiliares.h"
#include "../Objetos/VentaLocal.h"

class ControladorFuncionesAuxiliares : public IControladorFuncionesAuxiliares {
public:
    bool estaMesaTieneVenta(int);
    bool existeMesa(int);
    bool existeMozo(string);
    bool existeProducto(string);
    bool MostrarInformacion(string);
    VentaLocal* obtenerCodigoDeVenta(int);
    Mesa* obtenerMesa(int);
    TipoProducto tipoProducto(string);
    bool ventaFacturada(int);
};

#endif //CONTROLADORFUNCIONESAUXILIARES