#ifndef ICONTROLADORFUNCIONESAUXILIARES
#define ICONTROLADORFUNCIONESAUXILIARES

class IControladorFuncionesAuxiliares {
public:
	void validarProducto(string, float) = 0;
	void altaProducto(string, string, float) = 0;
};

#endif //ICONTROLADORFUNCIONESAUXILIARES