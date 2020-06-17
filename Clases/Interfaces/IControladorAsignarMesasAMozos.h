#ifndef ICONTROLADORASIGNARMESASAMOZOS
#define ICONTROLADORASIGNARMESASAMOZOS

#include "../DataTypes/DtAsignacion.h"
#include "../Manejadores/ManejadorMesa.h"

class IControladorAsignarMesasAMozos {
public:
	virtual list<DtAsignacion*> asignarMozosMesas() = 0;
};

#endif //ICONTROLADORASIGNARMESASAMOZOS