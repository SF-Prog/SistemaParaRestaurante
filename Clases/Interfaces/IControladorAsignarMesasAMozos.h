#ifndef ICONTROLADORASIGNARMESASAMOZOS
#define ICONTROLADORASIGNARMESASAMOZOS

#include "../DataTypes/DtAsignacion.h"

class IControladorAsignarMesasAMozos {
public:
		virtual list<DtAsignacion*> asignarMozosMesas() = 0;
};

#endif //ICONTROLADORASIGNARMESASAMOZOS
