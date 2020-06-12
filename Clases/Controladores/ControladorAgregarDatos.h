#ifndef CONTROLADORAGREGARDATOS
#define CONTROLADORAGREGARDATOS

#include "../Interfaces/IControladorAgregarDatos.h"

class ControladorAgregarDatos: public IControladorAgregarDatos {
public:
    void cargarDatos();
};

#endif //CONTROLADORAGREGARDATOS