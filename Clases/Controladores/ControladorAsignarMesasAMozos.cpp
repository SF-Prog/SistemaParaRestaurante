#include "ControladorAsignarMesasAMozos.h"


//Destructores
ControladorAsignarMesasAMozos::~ControladorAsignarMesasAMozos(){}

//Metodos
list<DtAsignacion*> ControladorAsignarMesasAMozos::asignarMozosMesas(){
			ManejadorMesa* mm;
			ManejadorEmpleado* me;
			list<DtAsignacion*> listaDtA;
			list<Mesa*> mesasActuales = mm->getMesas();
			list<Empleado*> empleadosActuales = me->getEmpleados();
			list<Mozo*> mozosActuales;
			cout << "/* 1 */" << '\n';
			float MeMo = (mesasActuales.size()/empleadosActuales.size());
			cout << "/* 1.2 */" << '\n';
			float resto = (mesasActuales.size()%empleadosActuales.size());
			cout << "/* 1.3 */" << '\n';
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
						}
						listaDtA.push_back(dtA);
			}
			
			return listaDtA;

/*
			for (Empleado* e : empleadosActuales){







							if(Mozo* m = dynamic_cast<Mozo*>(e)){
										list<Mesa*> mesasParaE;
										for(int i=0 ; i<MeMo ; i++){
													Mesa* ma = mm->getMesa(i);
													mesasParaE.push_back(ma);
										}
										Mozo* mozo = *e;
										mozo->setMesas(mesasParaE);
							}
			}*/
}
