#ifndef CONTROLADORASIGNARMESASAMOZOS
#define CONTROLADORASIGNARMESASAMOZOS

#include "../Manejadores/ManejadorMesa.h"
#include "../Manejadores/ManejadorEmpleado.h"
#include "../Interfaces/IControladorAsignarMesasAMozos.h"
#include "../Objetos/VentaLocal.h"

class ControladorAsignarMesasAMozos : public IControladorAsignarMesasAMozos {
public:

		//Destructores
		~ControladorAsignarMesasAMozos();

		//Metodos
		list<DtAsignacion*> asignarMozosMesas();
};

#endif //CONTROLADORASIGNARMESASAMOZOS
