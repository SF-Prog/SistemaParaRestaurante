#ifndef FABRICA
#define FABRICA

#include "Interfaces/IControladorAgregarDatos.h"
#include "Interfaces/IControladorAgregarProducto.h"
#include "Interfaces/IControladorAltaProducto.h"
#include "Interfaces/IControladorBajaProducto.h"
#include "Interfaces/IControladorFacturacion.h"
#include "Interfaces/IControladorFuncionesAuxiliares.h"
#include "Interfaces/IControladorIniciarVenta.h"
#include "Interfaces/IControladorQuitarProducto.h"
#include "Interfaces/IControladorAsignarMesasAMozos.h"

class Fabrica {
private:
    static Fabrica* instancia;
    Fabrica();
public:
    //Instancia
    static Fabrica* getInstancia();

    //Destructor
    ~Fabrica();

    //Metodos
    IControladorAgregarDatos* getIControladorAgregarDatos();
    IControladorAgregarProducto* getIControladorAgregarProducto();
    IControladorAltaProducto* getIControladorAltaProducto();
    IControladorBajaProducto* getIControladorBajaProducto();
    IControladorFacturacion* getIControladorFacturacion();
    IControladorFuncionesAuxiliares* getIControladorFuncionesAuxiliares();
    IControladorIniciarVenta* getIControladorIniciarVenta();
    IControladorQuitarProducto* getIControladorQuitarProducto();
		IControladorAsignarMesasAMozos* getIControladorAsignarMesasAMozos();
};

#endif //FABRICA
