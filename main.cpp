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

	string codigo, descripcion;
	float precio;
	bool okRegistro = false;

	try {
		cout << endl << "CODIGO: ";
		cin >> codigo;
		cout << endl << "DESCRIPCION: ";
		cin >> descripcion;
		cout << endl << "PRECIO: ";
		cin >> precio;
	}
	catch (exception& e) {
		cout << endl << "ERROR! Tipo de dato invalido." << endl;
	}
	try {
		if (iConFuA->validarProducto(codigo, precio))
			iConFuA->altaProducto(codigo, descripcion, precio);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
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

	int idMesa;
	float descuento;
	DtFacturaLocal DTFL;

	cout << "\nIngrese Nº de mesa: ";
	cin >> idMesa;
	cout << "\nDescuento: ";
	cin >> descuento;

	DTFL = iConFac->facturar(idMesa, descuento);

	cout << "\nSe ha generadola siguiente factura:\n ";
	cout << "\n┌──────────────────────────────────────────┐";//─(alt+196)┘(alt+217)┌(alt+218)┐(alt+191)└(alt+192)
	cout << "\n|   Código de venta: "<< DTFL.getCodVenta()<< "|";


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
	bool encontro = false;
string codProd;
string cero = "0";

list<DtProductoBase*> productosActuales = iConBjP->listarProductos() ;






if(productosActuales.empty()){
			system("clear");
			cout<< "          -No hay Productos en el Sistema-" << endl;
			// sleep(2);
			system("clear");
}else{
			cout<< "Lista de productos actualizada: " << endl;
			for (DtProductoBase* dtPB : productosActuales){
									cout << *dtPB << endl;
			}



			cout << "\nINGRESE EL CODIGO DEL PRODUCTO A DAR DE BAJA (0 para volver al menu) :" << endl;
			cin >> codProd;
			/*Producto* p = productosActuales->getProducto(codProd);*/

			for (DtProductoBase* dtPB : productosActuales){
						if(codProd.compare(dtPB->getCodigo()) == 0){


									encontro = true;
									system("clear");
									iConBjP->seleccionarProducto(codProd);
									iConBjP->eliminarProducto();

									cout << "----------DETALLES DEL PRODUCTO----------\n" << "          Descripcion:  "<< dtPB->getDescripcion()<< ".\n"<< "          Codigo:  "<< dtPB->getCodigo() << ".\n          FUE DADO DE BAJA SATISFACTORIAMENTE." << endl;
									// sleep(4);
									system("clear");
						}
			}

			if((encontro == false)&&(codProd.compare(cero) != 0)){
						system("clear");
						cout<<"\n\nEl codigo ingresado no es correcto, intentelo nuevamente..." << endl;
						// sleep(2);
						iConBjP->cancelarBajaProducto();
						bajaProducto();
			}
			else if(codProd.compare(cero) == 0){
						system("clear");
			}


}
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
