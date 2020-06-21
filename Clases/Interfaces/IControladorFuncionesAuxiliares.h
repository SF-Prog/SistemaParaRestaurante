#ifndef ICONTROLADORFUNCIONESAUXILIARES
#define ICONTROLADORFUNCIONESAUXILIARES

#include "../Objetos/VentaLocal.h"

class IControladorFuncionesAuxiliares {
public:
	virtual bool estaMesaTieneVenta(int) = 0;
	virtual bool existeMozo(string) = 0;
	virtual bool existeProducto(string) = 0;
	virtual VentaLocal* obtenerCodigoDeVenta(int) = 0;
	virtual TipoProducto tipoProducto(string) = 0;
	virtual Mesa* obtenerMesa(int) = 0;
    virtual bool existeMesa(int) = 0;
    virtual	bool MostrarInformacion(string) = 0;
};

#endif //ICONTROLADORFUNCIONESAUXILIARES
