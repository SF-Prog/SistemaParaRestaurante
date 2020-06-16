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
			std::cout << "A" << '\n';
			ManejadorMesa* mm;
			std::cout << "AA" << '\n';
			ManejadorEmpleado* me;
			std::cout << "AAA" << '\n';
			list<DtAsignacion*> listaDtA;
			std::cout << "AAAA" << '\n';
			list<Mesa*> mesasActuales = mm->getMesas();//Explotando ACA
std::cout << "AAAAA" << '\n';
			list<Empleado*> empleadosActuales = me->getEmpleados();
			list<Mozo*> mozosActuales;
std::cout << "AAAAAA" << '\n';
			float MeMo = (mesasActuales.size()/empleadosActuales.size());
std::cout << "AAAAAAA" << '\n';
			float resto = (mesasActuales.size()%empleadosActuales.size());
			int ultimaMesaAsignada = 0;
			cout<< resto << "--------------" <<MeMo << endl;
			for (Empleado* e : empleadosActuales){
						DtAsignacion* dtA;
						list<int> mesasParaMozo;
						if(Mozo* m = dynamic_cast<Mozo*>(e)){
									dtA->setIdMozo(m->getIdEmpleado());
						}

						for(int i=0 ; i<MeMo ; i++){
									Mesa* ma = mm->getMesa(i);
									mesasParaMozo.push_back(ma->getNumero());
									ultimaMesaAsignada++;
						}
						dtA->setMesasAsignadas(mesasParaMozo);
						listaDtA.push_back(dtA);
			}
			this->setListaAsignacion(listaDtA);
			for(int j=0;j<resto;j++){
						int pos = ultimaMesaAsignada + j;
						Mesa* mr = mm->getMesa(pos);

			}
			return listaDtA;

}
