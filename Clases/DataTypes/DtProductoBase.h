#ifndef DTPRODUCTOBASE
#define DTPRODUCTOBASE

#include <string>
#include <iostream>

using namespace std;

class DtProductoBase {
protected:
    string codigo;
    string descripcion;
public:
    //Constructores
    DtProductoBase();
    DtProductoBase(string, string);

    //Getters & Setters
    string getCodigo();
    void setCodigo(string);
    string getDescripcion();
    void setDescripcion(string);

    //Destructores
    virtual ~DtProductoBase();

    //Metodos
		friend ostream& operator<<(ostream&, const DtProductoBase&);
};

#endif //DTPRODUCTOBASE
