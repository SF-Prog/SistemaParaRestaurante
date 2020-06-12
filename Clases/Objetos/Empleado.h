#ifndef EMPLEADO
#define EMPLEADO

#include <list>
#include <string>

using namespace std;

class VentaLocal;
class Empleado {
private:
    string idEmpleado;
    string nombre;
public:
    //Constructores
    Empleado();
    Empleado(string, string);

    //Getters & Setters
    string getIdEmpleado();
    void setIdEmpleado(string);
    string getNombre();
    void setNombre(string);

    //Destructores
    ~Empleado();

    //Metodos
    virtual list<int> mesasAsignadasSinVenta() = 0;
    virtual void asignarMesas(list<int>, VentaLocal*) = 0;
};

#endif //EMPLEADO