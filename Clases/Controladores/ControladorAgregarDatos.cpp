#include "../Controladores/ControladorAgregarProducto.h"
#include "../Controladores/ControladorIniciarVenta.h"
#include "../Controladores/ControladorFacturacion.h"
#include "../Manejadores/ManejadorEmpleado.h"
#include "../Manejadores/ManejadorMesa.h"
#include "../Manejadores/ManejadorProducto.h"
#include "../Manejadores/ManejadorVenta.h"
#include "../DataTypes/DtFecha.h"
#include "../DataTypes/DtProductoFactura.h"
#include "ControladorAgregarDatos.h"

void ControladorAgregarDatos::cargarDatos(){
	//Empleados
	ManejadorEmpleado* mE=ManejadorEmpleado::getInstancia();
	Empleado* m= new Mozo("A01", "Juan");
	Empleado* m2= new Mozo("A02", "Ines");
	Empleado* m3= new Mozo("A03", "Maria");
	mE->agregarEmpleado(m);
	mE->agregarEmpleado(m2);
	mE->agregarEmpleado(m3);

	//Ventas
	ManejadorVenta* mV=ManejadorVenta::getInstancia();
	VentaLocal* vL=new VentaLocal("V01");
	Venta* vL2= new VentaLocal("V02");
	Venta* vL3= new VentaLocal("V03");
	VentaLocal* vL4 = new VentaLocal(dynamic_cast<Mozo*>(m));
	vL4->setCodigoVenta("vL4");
	mV->agregarVenta(vL);
	mV->agregarVenta(vL2);
	mV->agregarVenta(vL3);
	mV->agregarVenta(vL4);

	//Producto
	ManejadorProducto* mP=ManejadorProducto::getInstancia();
	Producto* p= new Comun("P01", "Pollo", 25);
	Producto* p2= new Comun("P02", "Lechuga", 13);
	Producto* p3= new Comun("P03", "Pan ", 19);
	Producto* p4= new Menu("M01", "Chiivito", 105, 1);
	Producto* p5= new Menu("M02", "Sandwich Palta, Lechuga y tomates", 133, 1);
	mP->agregarProducto(p);
	mP->agregarProducto(p2);
	mP->agregarProducto(p3);
	mP->agregarProducto(p4);
	mP->agregarProducto(p5);

	//Mesas
	ManejadorMesa* mM =ManejadorMesa::getInstancia();
	Mesa* mesa1 = new Mesa(1);
	Mesa* mesa2 = new Mesa(2);
	Mesa* mesa3 = new Mesa(3);
	Mesa* mesa4 = new Mesa(4);
	Mesa* mesa5 = new Mesa(5);
	Mesa* mesa6 = new Mesa(6);
	Mesa* mesa7 = new Mesa(7);
	Mesa* mesa8 = new Mesa(8);
	mM->agregarMesa(mesa1);
	mM->agregarMesa(mesa2);
	mM->agregarMesa(mesa3);
	mM->agregarMesa(mesa4);
	mM->agregarMesa(mesa5);
	mM->agregarMesa(mesa6);
	mM->agregarMesa(mesa7);
	mM->agregarMesa(mesa8);
	/*
	//Facturacion
	DtFactura* dtFact;
	DtFechaHora fecha;
	DtProductoFactura* dtPF;
	list<DtProductoFactura*> col_dtPF;
	dtPF = new DtProductoFactura("Sandwich Palta - Lechuga y tomates", 133, 1);
	col_dtPF.push_back(dtPF);
	dtPF = new DtProductoFactura("Pan", 19, 1);
	col_dtPF.push_back(dtPF);
	dtFact = new DtFactura("V01", fecha.actual(), col_dtPF, 200, 0, 200, 250);

	vL4->setFactura(dtFact);
	*/

	//Asignar mesas a mozos
	mesa1->setVentaLocal(vL4);
	list<int> mesasLibres = m2->mesasAsignadasSinVenta();
	m2->asignarMesas(mesasLibres, vL4);
}
