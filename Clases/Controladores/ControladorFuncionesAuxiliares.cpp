#include "../Controladores/ControladorFuncionesAuxiliares.h"
#include "../Manejadores/ManejadorEmpleado.h"
#include "../Manejadores/ManejadorMesa.h"
#include "../Manejadores/ManejadorProducto.h"
#include "../Manejadores/ManejadorVenta.h"

bool ControladorFuncionesAuxiliares::estaMesaTieneVenta(int mesa) {
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* M = mM->getMesa(mesa);
    bool tiene = M->tieneVenta();
    //RS: Viendo si consigo el codigo de la venta.
    VentaLocal* venLoc = M->getVentaLocal();
    string venCod = venLoc->getCodigo();
    cout << endl << "obj: [ControladorFuncionesAuxiliares.h]  -  [RS]   -    estaMesaTieneVenta (codigo de venta)  "<< venCod;
    //Fin debug
    return tiene;
}
bool ControladorFuncionesAuxiliares::existeMozo(string codigo) {
    ManejadorEmpleado* mE = ManejadorEmpleado::getInstancia();
    return mE->existeEmpleado(codigo);
}
bool ControladorFuncionesAuxiliares::existeProducto(string codigo) {
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    return mP->existeProducto(codigo);
}
VentaLocal* ControladorFuncionesAuxiliares::obtenerCodigoDeVenta(int idMesa) {
    ManejadorMesa* mM=ManejadorMesa::getInstancia();
    Mesa *me = mM->getMesa(idMesa);
    VentaLocal* v = me->getVentaLocal();
    return v;
}
TipoProducto ControladorFuncionesAuxiliares::tipoProducto(string codigo) {
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    return mP->getProducto(codigo)->getTipoProducto();
}
Mesa* ControladorFuncionesAuxiliares::obtenerMesa(int codigo) {
  ManejadorMesa* mM=ManejadorMesa::getInstancia();
  Mesa *me = mM->getMesa(codigo);
    return me;
}
bool ControladorFuncionesAuxiliares::existeMesa(int codigo) {
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    return mM->existeMesa(codigo);
}
