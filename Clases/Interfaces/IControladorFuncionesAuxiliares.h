#ifndef ICONTROLADORFUNCIONESAUXILIARES
#define ICONTROLADORFUNCIONESAUXILIARES

#include <string>

using namespace std;

class IControladorFuncionesAuxiliares {
public:
	virtual void altaProducto(string, string, float) = 0;
	virtual bool estaMesaTieneVenta(int) = 0;
	virtual bool existeProducto(string) = 0;
};

#endif //ICONTROLADORFUNCIONESAUXILIARES
