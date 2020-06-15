#include "../Controladores/ControladorFuncionesAuxiliares.h"
#include "../Manejadores/ManejadorEmpleado.h"
#include "../Manejadores/ManejadorMesa.h"
#include "../Manejadores/ManejadorProducto.h"
#include "../Manejadores/ManejadorVenta.h"

bool validarProducto(string codigo, float precio) {

}
void altaProducto(string codigo, string descripcion, float precio) {
	cout << endl << "TIPO DE PRODUCTO" << endl;
	cout << "\t1.COMUN" << endl;
	cout << "\t2.MENU" << endl;
	cout << "OPCION: ";

	int tipoProducto;
	cin >> tipoProducto;
	if (tipoProducto < 1 || tipoProducto > 2)
		throw invalid_argument("\nERROR! opcion invalida.");
	switch (tipoProducto) {
		case 1: {
			/*
			cout << endl << "¿TIENE LUCES?" << endl;
			cout << "\t1.SI " << endl;
			cout << "\t2.NO" << endl;
			cout << "OPCION: ";

			int opTieneLuces;
			cin >> opTieneLuces;
			if (opTieneLuces < 1 || opTieneLuces > 2)
				throw invalid_argument("\nERROR! opción inválida.");
			bool tieneLuces = (opTieneLuces == 1) ? true : false;

			Monopatin* mono = new Monopatin(vehiculo.getNroSerie(), vehiculo.getPorcentaje(), vehiculo.getPrecioBase(), tieneLuces);
			coleccionVehiculos.vehiculos[coleccionVehiculos.tope] = mono;
			*/
			break;
		}
		case 2: { /*
			cout << endl << "TIPO DE BICICLETA: " << endl;
			cout << "\t1.PASEO" << endl;
			cout << "\t2.MONTANIA" << endl;
			cout << "OPCION: ";

			tipoBici tipo;
			int opTipoBici;
			cin >> opTipoBici;
			if (opTipoBici < 1 || opTipoBici > 2)
				throw invalid_argument("\nERROR! opción inválida.");
			switch (opTipoBici) {
			case 1: tipo = Paseo;
				break;
			case 2: tipo = Montania;
				break;
			}

			int cantCambios;
			cout << endl << "CANTIDAD DE CAMBIOS: ";
			cin >> cantCambios;
			if (cantCambios < 0)
				throw invalid_argument("\nERROR! no puede ingresar cantidad negativa.");

			Bicicleta* bici = new Bicicleta(vehiculo.getNroSerie(), vehiculo.getPorcentaje(), vehiculo.getPrecioBase(), tipo, cantCambios);
			coleccionVehiculos.vehiculos[coleccionVehiculos.tope] = bici;
			*/
			break;
		}
	}

	cout << endl << "Producto dado de alta." << endl;
}