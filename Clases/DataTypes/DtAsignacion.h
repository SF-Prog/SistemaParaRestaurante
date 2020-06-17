#ifndef DTASIGNACION
#define DTASIGNACION

#include <iostream>
#include "../Objetos/Mozo.h"

class DtAsignacion {
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