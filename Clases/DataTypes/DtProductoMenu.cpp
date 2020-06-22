
#include "DtProductoComun.h"
#include "DtProductoMenu.h"
#include "DtProducto.h"


DtProductoMenu::DtProductoMenu() {}
DtProductoMenu::DtProductoMenu(string codigo, string descripcion, float precio, int cantidadEF, list<DtProductoComun*> listaCom) : DtProducto(codigo, descripcion, precio, cantidadEF)
{
    this->listaComunes = listaCom;
}

//Getters & Setters
list<DtProductoComun*> DtProductoMenu::getListaComunes()
{
    return this->listaComunes;
}

void DtProductoMenu::setListaComunes(list<DtProductoComun*> listaCom)
{
    this->listaComunes = listaCom;
}

//Destructores
DtProductoMenu::~DtProductoMenu() {}
// DtProductoMenu::~DtProductoComun() {}
