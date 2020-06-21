#ifndef CONTROLADORINFORMACIONPRODUCTO
#define CONTROLADORINFORMACIONPRODUCTO

#include "../Interfaces/IControladorInformacionProducto.h"

class ControladorInformacionProducto : public IControladorInformacionProducto {
public:

    //Destructor
    ~ControladorInformacionProducto();

    //Metodos
    list<DtProductoBase*> listarProductos();
    DtProducto* seleccionarProducto(string);

};
#endif //CONTROLADORINFORMACIONPRODUCTO
