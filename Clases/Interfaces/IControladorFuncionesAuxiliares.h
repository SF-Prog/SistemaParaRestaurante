#ifndef ICONTROLADORFUNCIONESAUXILIARES
#define ICONTROLADORFUNCIONESAUXILIARES

#include "../Objetos/VentaLocal.h"

class IControladorFuncionesAuxiliares {
public:
	virtual bool estaMesaTieneVenta(int) = 0;
	virtual bool existeProducto(string) = 0;
	virtual VentaLocal* obtenerCodigoDeVenta(int) = 0;
	virtual TipoProducto tipoProducto(string) = 0;
};

#endif //ICONTROLADORFUNCIONESAUXILIARES