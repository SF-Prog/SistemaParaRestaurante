#include "DtAsignacion.h"



//Constructores
DtAsignacion::DtAsignacion(){}
DtAsignacion::DtAsignacion(string id, list<int> lm){
				this->idMozo = id;
				this->mesasAsignadas = lm;
}
//Getters y Setters
string DtAsignacion::getIdMozoAsignacion(){
			return this->idMozo;
}
void DtAsignacion::setIdMozoAsignacion(string id){
			this->idMozo = id;
}
list<int> DtAsignacion::getMesasAsignacion(){
			return this->mesasAsignadas;
}
void DtAsignacion::setMesasAsignacion(list<int> lm){
			this->mesasAsignadas = lm;
}

//Destructores
DtAsignacion::~DtAsignacion(){}
//Metodos
ostream& operator<<(ostream& salida, const DtAsignacion& dt){
    salida << "El mozo con ID : " << dt.idMozo << " tiene asignadas las mesas: ";
		for(int numMesa : dt.mesasAsignadas){
					salida << "  " << numMesa;
		}
	  return salida;
}
