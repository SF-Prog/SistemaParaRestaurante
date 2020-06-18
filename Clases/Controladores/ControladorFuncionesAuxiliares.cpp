#include "../Controladores/ControladorFuncionesAuxiliares.h"
#include "../Manejadores/ManejadorEmpleado.h"
#include "../Manejadores/ManejadorMesa.h"
#include "../Manejadores/ManejadorProducto.h"
#include "../Manejadores/ManejadorVenta.h"
#include <string.h>
void ControladorFuncionesAuxiliares::altaProducto(string codigo, string descripcion, float precio) {
}
bool ControladorFuncionesAuxiliares::estaMesaTieneVenta(int mesa) {
    ManejadorMesa* mM = ManejadorMesa::getInstancia();
    Mesa* M = mM->getMesa(mesa);
    bool tiene = M->tieneVenta();
    return tiene;
}
bool ControladorFuncionesAuxiliares::existeProducto(string codigo) {
    ManejadorProducto* mP = ManejadorProducto::getInstancia();
    return mP->existeProducto(codigo);
}

VentaLocal* ControladorFuncionesAuxiliares::obtenerCodigoDeVenta(int idMesa) {
    ManejadorMesa* mM=ManejadorMesa::getInstancia();
    Mesa *me = mM->getMesa(idMesa);
    VentaLocal* v = me->getVentaLocal();
    return  v;
}