#ifndef DTPRODUCTOMENU
#define DTPRODUCTOMENU

#include <string>
#include <iostream>
#include "DtProducto.h"
#include "DtProductoComun.h"

using namespace std;

class DtProductoMenu : public DtProducto
{
protected:
    list<DtProductoComun*> listaComunes;

public:
    //Constructores
    DtProductoMenu();
    DtProductoMenu(string, string, list<DtProductoComun*>);

    //Getters & Setters
    list<DtProductoComun*> getListaComunes();
    void setListaComunes(list<DtProductoComun*>);

    //Destructores
    virtual ~DtProductoMenu();

    //Metodos
};

#endif //DTPRODUCTOCOMUN
