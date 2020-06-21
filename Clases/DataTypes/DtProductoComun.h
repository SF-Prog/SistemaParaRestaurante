#ifndef DTPRODUCTOCOMUN
#define DTPRODUCTOCOMUN

#include <string>
#include <iostream>
#include "DtProducto.h"

using namespace std;

class DtProductoComun : public DtProducto
{
protected:
    float cantEnMenu;

public:
    //Constructores
    DtProductoComun();
    DtProductoComun(string, string, float, float);

    //Getters & Setters
    float getCantEnMenu();
    void setCantEnMenu(float);

    //Destructores
    virtual ~DtProductoComun();

    //Metodos
    friend ostream &operator<<(ostream &, const DtProductoComun &);
};

#endif //DTPRODUCTOCOMUN