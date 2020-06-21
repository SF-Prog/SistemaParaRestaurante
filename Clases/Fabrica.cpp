#include "Fabrica.h"
#include "Controladores/ControladorAgregarDatos.h"
#include "Controladores/ControladorAgregarProducto.h"
#include "Controladores/ControladorAltaProducto.h"
#include "Controladores/ControladorAsignarMesasAMozos.h"
#include "Controladores/ControladorBajaProducto.h"
#include "Controladores/ControladorFacturacion.h"
#include "Controladores/ControladorFuncionesAuxiliares.h"
#include "Controladores/ControladorIniciarVenta.h"
#include "Controladores/ControladorQuitarProducto.h"
#include "Controladores/ControladorInformacionProducto.h"

//Constructor
Fabrica::Fabrica() {}

//Instancia
Fabrica* Fabrica::instancia = NULL;
Fabrica* Fabrica::getInstancia() {
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

//Destructor
Fabrica::~Fabrica() {}

//Metodos
IControladorAgregarDatos* Fabrica::getIControladorAgregarDatos() {
    return new ControladorAgregarDatos();
}
IControladorAgregarProducto* Fabrica::getIControladorAgregarProducto() {
    return new ControladorAgregarProducto();
}
IControladorAltaProducto* Fabrica::getIControladorAltaProducto() {
    return new ControladorAltaProducto();
}
IControladorAsignarMesasAMozos* Fabrica::getIControladorAsignarMesasAMozos() {
    return new ControladorAsignarMesasAMozos();
}
IControladorBajaProducto* Fabrica::getIControladorBajaProducto() {
    return new ControladorBajaProducto();
}
IControladorFacturacion* Fabrica::getIControladorFacturacion() {
    return new ControladorFacturacion();
}
IControladorQuitarProducto* Fabrica::getIControladorQuitarProducto() {
    return new ControladorQuitarProducto();
}
IControladorIniciarVenta* Fabrica::getIControladorIniciarVenta() {
    return new ControladorIniciarVenta();
}
IControladorFuncionesAuxiliares* Fabrica::getIControladorFuncionesAuxiliares() {
    return new ControladorFuncionesAuxiliares();
}
IControladorInformacionProducto* Fabrica::getIControladorInformacionProducto() {
    return new ControladorInformacionProducto();
}
