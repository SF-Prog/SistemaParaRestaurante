#ifndef DTPRODUCTO
#define DTPRODUCTO

#include "DtProductoBase.h"

class DtProducto : public DtProductoBase
{
private:
    float precio;
    int cantEnFactura;

public:
    //Constructores
    DtProducto();
    DtProducto(string, string, float, int);

    //Getters & Setters
    float getPrecio();
    void setPrecio(float);
    int getCantEnFactura();
    void setCantEnFactura(int);

    //Destructores
    virtual ~DtProducto();

    //Metodos
    friend ostream &operator<<(ostream &, const DtProducto &);
};

#endif //DTPRODUCTO