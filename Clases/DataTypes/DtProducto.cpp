#include "DtProducto.h"

//Constructores
DtProducto::DtProducto(){};
DtProducto::DtProducto(string codigo, string descripcion, float precio, int cantidad) : DtProductoBase(codigo, descripcion)
{
    this->precio = precio;
    this->cantEnFactura = cantidad;
}

//Getters & Setters
float DtProducto::getPrecio()
{
    return this->precio;
}
void DtProducto::setPrecio(float precio)
{
    this->precio = precio;
}
int DtProducto::getCantEnFactura()
{
    return this->cantEnFactura;
}
void DtProducto::setCantEnFactura(int cantEF)
{
    this->cantEnFactura = cantEF;
}

//Destructores
DtProducto::~DtProducto() {}

//Metodos
ostream &operator<<(ostream &salida, const DtProducto &dt)
{
    salida << (DtProductoBase)dt << "PrecioProd:  " << dt.precio << "-----------  Cantidad: " << dt.cantEnFactura;
    return salida;
}
