#ifndef ICONTROLADORFUNCIONESAUXILIARES
#define ICONTROLADORFUNCIONESAUXILIARES

#include <string>

using namespace std;

class IControladorFuncionesAuxiliares {
public:
	virtual bool validarProducto(string, float) = 0;
	virtual void altaProducto(string, string, float) = 0;
};

#endif //ICONTROLADORFUNCIONESAUXILIARES
