#include "Clases/Fabrica.h"

Fabrica* fabrica;
IControladorAgregarDatos* iConAgD;
IControladorAgregarProducto* iConAgP;
IControladorAltaProducto* iConAlP;
IControladorBajaProducto* iConBjP;
IControladorFacturacion* iConFac;
IControladorFuncionesAuxiliares* iConFuA;
IControladorIniciarVenta* iConInV;
IControladorQuitarProducto* iConQtP;

//OPERACION1 ALTA PRODUCTO
void altaProducto();
//OPERACION2 INICIAR VENTA
void iniciarVenta();
//OPERACION3 AGREGAR PRODUCTO A UNA VENTA
void agregarProductoAVenta();
//OPERACION4 QUITAR PRODUCTO A UNA VENTA
void quitarProductoAVenta();
//OPERACION5 FACTURACION DE UNA VENTA
void facturacionDeUnaVenta();
//OPERACION6 ASIGNAR MOZOS A MESAS AUTOMATICAMENTE
void asignarMozosAMesas();
//OPERACION7 BAJA PRODUCTO
void bajaProducto();
//OPERACION8 INFORMACION PRODUCTO
void informacionProducto();
//OPERACION9 CARGAR DATOS DE PRUEBA
void cargarDatosPrueba();

//FUNCIONES AUXILIARES

void desplegarMenu();

void altaProducto() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "==============A L T A   P R O D U C T O==============" << endl;
	cout << "_____________________________________________________" << endl;
}

void iniciarVenta() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "===============I N I C I A R   V E N T A=============" << endl;
	cout << "_____________________________________________________" << endl;
}

void agregarProductoAVenta() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "===A G R E G A R   P R O D U C T O   A   V E N T A===" << endl;
	cout << "_____________________________________________________" << endl;
}

void quitarProductoAVenta() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "====Q U I T A R   P R O D U C T O   A   V E N T A====" << endl;
	cout << "_____________________________________________________" << endl;

}

void facturacionDeUnaVenta() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "===F A C T U R A C I O N   D E   U N A   V E N T A===" << endl;
	cout << "_____________________________________________________" << endl;
}

void asignarMozosAMesas() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "======A S I G N A R   M O Z O S   A   M E S A S======" << endl;
	cout << "_____________________________________________________" << endl;
}

void bajaProducto() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "==============B A J A   P R O D U C T O==============" << endl;
	cout << "_____________________________________________________" << endl;
}

void informacionProducto() {
	system("clear");

	cout << "_____________________________________________________" << endl;
	cout << "=======I N F O R M A C I O N   P R O D U C T O=======" << endl;
	cout << "_____________________________________________________" << endl;
}

void cargarDatosPrueba() {
	system("clear");
	iConAgD->cargarDatos();
}

//MENU
void desplegarMenu() {
	cout << "_____________________________________________________" << endl;
	cout << "==                    M  E  N  U                   ==" << endl;
	cout << "=====================================================" << endl;
	cout << "1. ALTA PRODUCTO" << endl;
	cout << "2. INICIAR VENTA" << endl;
	cout << "3. AGREGAR PRODUCTO A UNA VENTA" << endl;
	cout << "4. QUITAR PRODUCTO A UNA VENTA" << endl;
	cout << "5. FACTURACION DE UNA VENTA" << endl;
	cout << "6. ASIGNAR MOZOS A MESAS AUTOMATICAMENTE" << endl;
	cout << "7. BAJA PRODUCTO" << endl;
	cout << "8. INFORMACION PRODUCTO" << endl;
	cout << "9. CARGAR DATOS DE PRUEBA" << endl;
	cout << "0. SALIR" << endl;
	cout << "_____________________________________________________" << endl;
	cout << "OPCION>> ";
}

//MAIN
int main(){
	fabrica = Fabrica::getInstancia();

	iConAgD = fabrica->getIControladorAgregarDatos();
	iConAgP = fabrica->getIControladorAgregarProducto();
	iConAlP = fabrica->getIControladorAltaProducto();
	iConBjP = fabrica->getIControladorBajaProducto();
	iConFuA = fabrica->getIControladorFuncionesAuxiliares();
	iConFac = fabrica->getIControladorFacturacion();
	iConInV = fabrica->getIControladorIniciarVenta();
	iConQtP = fabrica->getIControladorQuitarProducto();

	desplegarMenu();

	int opcion;
	cin >> opcion;
	while (opcion != 0) {
		switch (opcion) {
		case 1: altaProducto();
			break;
		case 2: iniciarVenta();
			break;
		case 3: agregarProductoAVenta();
			break;
		case 4: quitarProductoAVenta();
			break;
		case 5: facturacionDeUnaVenta();
			break;
		case 6: asignarMozosAMesas();
			break;
		case 7: bajaProducto();
			break;
		case 8: informacionProducto();
			break;
		case 9: cargarDatosPrueba();
			break;
		case 0: {
			system("exit");

			cout << "SALIENDO..." << endl;
		}
		default:
			cout << endl << "OPCION INCORRECTA" << endl;
		}
		desplegarMenu();

		cin >> opcion;
	}
	return 0;
}