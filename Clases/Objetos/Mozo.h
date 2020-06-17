#ifndef MOZO
#define MOZO

#include "Empleado.h"

class Mesa;
class Mozo: public Empleado {
private:
    list<Mesa*> mesas;
public:
    //Constructores
    Mozo();
    Mozo(string, string);

    //Getters & Setters
    list<Mesa*> getMesas();
    void setMesas(list<Mesa*>);

    //Destructores
    ~Mozo();

    //Metodos
    list<int> mesasAsignadasSinVenta();
    void asignarMesas(list<int>, VentaLocal*);
};

#endif //MOZO
