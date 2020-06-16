#include "DtAsignacion.h"



//Constructores
DtAsignacion::DtAsignacion(){}
DtAsignacion::DtAsignacion(string id, list<int> lm){
				this->idMozo = id;
				this->mesasAsignadas = lm;
}
//Getters y Setters
string DtAsignacion::getIdMozo(){
			return this->idMozo;
}
void DtAsignacion::setIdMozo(string id){
			this->idMozo = id;
}
list<int> DtAsignacion::getMesasAsignadas(){
			return this->mesasAsignadas;
}
void DtAsignacion::setMesasAsignadas(list<int> lm){
			this->mesasAsignadas = lm;
}

//Destructores
DtAsignacion::~DtAsignacion(){}
