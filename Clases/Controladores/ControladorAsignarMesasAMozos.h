#ifndef CONTROLADORASIGNARMESASAMOZOS
#define CONTROLADORASIGNARMESASAMOZOS

#include "../Interfaces/IControladorAsignarMesasAMozos.h"
#include "../Manejadores/ManejadorMesa.h"
#include "../Manejadores/ManejadorEmpleado.h"
#include "../Objetos/VentaLocal.h"

class ControladorAsignarMesasAMozos : public IControladorAsignarMesasAMozos {
	list<DtAsignacion*> listaAsignacion;
public:
	//Getters y Setters
	list<DtAsignacion*> getListaAsignacion();
	void setListaAsignacion(list<DtAsignacion*>);

	//Destructores
	~ControladorAsignarMesasAMozos();

	//Metodos
	list<DtAsignacion*> asignarMozosMesas();
};

#endif //CONTROLADORASIGNARMESASAMOZOS