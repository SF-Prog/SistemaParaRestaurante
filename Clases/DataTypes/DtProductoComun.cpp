#include "DtProductoComun.h"

//Constructores
DtProductoComun::DtProductoComun(){}
DtProductoComun::DtProductoComun(string codigo, string descripcion, float precio, int cantidadFactura, float cantidadEM) : DtProducto(codigo, descripcion, precio, cantidadFactura)
{
    this->cantEnMenu = cantidadEM;
}

//Getters & Setters
float DtProductoComun::getCantEnMenu()
{
    return this->cantEnMenu;
}
void DtProductoComun::setCantEnMenu(float cantEM)
{
    this->cantEnMenu = cantEM;
}

//Destructores
DtProductoComun::~DtProductoComun() {}

//Metodos
ostream &operator<<(ostream &salida, const DtProductoComun &dtPC)
{
    salida << (DtProductoBase)dtPC << "  \n\tPrecio:  " << dtPC.precio << "\n\t Cantidad en el Menu:" << dtPC.cantEnMenu << endl;
    return salida;
}
