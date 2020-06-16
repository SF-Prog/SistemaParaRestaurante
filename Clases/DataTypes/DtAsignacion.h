#ifndef DTASIGNACION
#define DTASIGNACION

#include <string>
#include <list>
#include <iostream>
#include "../Objetos/Mozo.h"

using namespace std;

class	DtAsignacion {
private:
		string idMozo;
		list<int> mesasAsignadas;
public:
		//Constructores
		DtAsignacion();
		DtAsignacion(string, list<int>);
		//Getters y Setters
		string getIdMozo();
		void setIdMozo(string);
		list<int> getMesasAsignadas();
		void setMesasAsignadas(list<int>);

		//Destructores
		~DtAsignacion();
};

#endif  //DTASIGNACION
