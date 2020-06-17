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
		string getIdMozoAsignacion();
		void setIdMozoAsignacion(string);
		list<int> getMesasAsignacion();
		void setMesasAsignacion(list<int>);

		//Destructores
		~DtAsignacion();
		//Metodos
		friend ostream& operator<<(ostream&, const DtAsignacion&);
};

#endif  //DTASIGNACION
