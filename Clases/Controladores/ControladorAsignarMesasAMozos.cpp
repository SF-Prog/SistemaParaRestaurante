#include "ControladorAsignarMesasAMozos.h"


//Destructores
ControladorAsignarMesasAMozos::~ControladorAsignarMesasAMozos(){}

list<DtAsignacion*> ControladorAsignarMesasAMozos::getListaAsignacion(){
			return this->listaAsignacion;
}
void ControladorAsignarMesasAMozos::setListaAsignacion(list<DtAsignacion*> la){
			this->listaAsignacion = la;
}
//Metodos
list<DtAsignacion*> ControladorAsignarMesasAMozos::asignarMozosMesas(){

			ManejadorMesa* mm = ManejadorMesa::getInstancia();

			list<Mesa*> mesasActuales = mm->getMesas();

			ManejadorEmpleado* me = ManejadorEmpleado::getInstancia();

			list<Empleado*> empleadosActuales = me->getEmpleados();

			list<DtAsignacion*> listaDtA;
		  //Explotando ACA

			float MeMo = (mesasActuales.size()/empleadosActuales.size());
			float resto = (mesasActuales.size()%empleadosActuales.size());
			int ultimaMesaAsignada = 1;// Numero de Mesas desde el 1 al 8

			for (Empleado* e : empleadosActuales){
						Mozo* m = dynamic_cast<Mozo*>(e);
						DtAsignacion* dtA = new DtAsignacion();
						list<int> mesasAsignar;
						list<Mesa*> mesasParaMozo;
						dtA->setIdMozoAsignacion(m->getIdEmpleado()); 
						int pos = ultimaMesaAsignada;
						for(int i=0 ; i<MeMo ; i++){
							/*if(mesa no esta asignada me->tieneVenta){}*/
									Mesa* ma = mm->getMesa(pos+i);
									mesasParaMozo.push_back(ma);
									mesasAsignar.push_back(ma->getNumero());
									ultimaMesaAsignada++;
						}
						if(resto > 0){
									Mesa* mr = mm->getMesa(ultimaMesaAsignada);
									mesasParaMozo.push_back(mr);
									mesasAsignar.push_back(mr->getNumero());
									ultimaMesaAsignada++;
									resto--;
						}
						m->setMesas(mesasParaMozo);
						dtA->setMesasAsignacion(mesasAsignar);
						listaDtA.push_back(dtA);
			}
		//	this->setListaAsignacion(listaDtA);

			return listaDtA;

}
