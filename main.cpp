#include <algorithm>
#include <unistd.h>
#include "Clases/Fabrica.h"

//FABRICA
Fabrica* fabrica;

//INTERFACES
IControladorAgregarDatos* iConAgD;
IControladorAgregarProducto* iConAgP;
IControladorAltaProducto* iConAlP;
IControladorAsignarMesasAMozos* iConAsMM;
IControladorBajaProducto* iConBjP;
IControladorFacturacion* iConFac;
IControladorFuncionesAuxiliares* iConFuA;
IControladorIniciarVenta* iConInV;
IControladorQuitarProducto* iConQtP;
IControladorInformacionProducto* iConInfP;

//PROPIEDADES
bool primeraVezAsignacion = true;
bool primeraVezCargaDeDatos = true;

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

//OPERACIONES AUXILIARES
void desplegarMenu();
void procesarProductoComun(string, string);
void procesarProductoMenu(string, string);

//OPERACIONES PRINCIPALES
void altaProducto() {
    string codigo, descripcion, confirma;
    bool finalizar, finalizar2;

    try {
        finalizar = false;
        do {
            system("clear");

            cout << "_____________________________________________________" << endl;
            cout << "==============A L T A   P R O D U C T O==============" << endl;
            cout << "_____________________________________________________" << endl;

            cout << endl << "CODIGO: ";
            cin >> codigo;

            if (iConFuA->existeProducto(codigo))
                throw invalid_argument("ERROR! El producto ya existe en el sistema.");

            cout << "DESCRIPCION: ";
            cin >> descripcion;

            list<DtProductoBase*> lComunes = iConAlP->listarProductosComunes();
            if (lComunes.size() > 0) {
                cout << endl << "TIPO DE PRODUCTO" << endl;
                cout << "\t1.COMUN" << endl;
                cout << "\t2.MENU" << endl;
                cout << "OPCION: ";

                int tipoProducto;
                cin >> tipoProducto;
                if (tipoProducto < 1 || tipoProducto > 2)
                    throw invalid_argument("\nERROR! opcion invalida.");
                else {
                    switch (tipoProducto) {
                        case 1: {
                            procesarProductoComun(codigo, descripcion);
                            break;
                        }
                        case 2: {
                            procesarProductoMenu(codigo, descripcion);
                            break;
                        }
                    }
                }
            } else
                procesarProductoComun(codigo, descripcion);

            cout << endl << "¿Desea continuar agregando productos? (y/n): ";
            cin >> confirma;
            if (confirma == "y" || confirma == "Y")
                finalizar = false;
            else {
                finalizar = true;
                if (confirma != "n" && confirma != "N")
                    throw invalid_argument("ERROR! opcion invalida.");
            }
        } while (!finalizar);
    } catch (exception& e) {
        cout << endl << e.what() << endl;
    }
}

void iniciarVenta() {
    system("clear");

    cout << "_____________________________________________________" << endl;
    cout << "===============I N I C I A R   V E N T A=============" << endl;
    cout << "_____________________________________________________" << endl;

    string confirma, idMozo;
    bool finalizar = false;
    int mesa;

    try {
        cout << endl << "ID MOZO: ";
        cin >> idMozo;

        if (!iConFuA->existeMozo(idMozo))
            throw invalid_argument("ERROR! El mozo no existe en el sistema.");

        list<int> lMesasElegidas;
        list<int> lMesasSinVentas = iConInV->ingresarIDMozo(idMozo);
        if (lMesasSinVentas.size() > 0) {
            cout << endl << "SELECCIONE LAS MESAS SIN VENTAS (de a una):" << endl << endl;
            for (list<int>::iterator it = lMesasSinVentas.begin(); it != lMesasSinVentas.end(); it++)
                cout << (*it) << endl;
            do {
                cout << endl << "NUMERO: ";
                cin >> mesa;

                list<int>::iterator it1 = find(lMesasSinVentas.begin(), lMesasSinVentas.end(), mesa);
                if (it1 == lMesasSinVentas.end())
                    cout << "La mesa seleccionada no es valida." << endl;
                else {
                    list<int>::iterator it2 = find(lMesasElegidas.begin(), lMesasElegidas.end(), mesa);
                    if (it2 != lMesasElegidas.end())
                        cout << "La mesa ya se encuentra seleccionada." << endl;
                    else
                        lMesasElegidas.push_back(mesa);
                }
                if (lMesasElegidas.size() < lMesasSinVentas.size()) {
                    cout << endl << "¿Desea continuar seleccionando mesas? (y/n): ";
                    cin >> confirma;
                    if (confirma != "y" && confirma != "Y") {
                        finalizar = true;
                        if (confirma != "n" && confirma != "N")
                            cout << "Opcion invalida. Seleccion de mesas cancelada" << endl;
                    }
                } else
                    finalizar = true;
            } while (!finalizar);

            if (lMesasElegidas.size() > 0) {
                if (lMesasElegidas.size() == 1)
                    cout << endl << "¿Desea iniciar la venta? (y/n): ";
                else
                    cout << endl << "¿Desea iniciar las ventas? (y/n): ";
                cin >> confirma;
                if (confirma == "y" || confirma == "Y") {
                    iConInV->seleccionarMesas(lMesasElegidas);
                    iConInV->confirmarIniciarVenta();
                    if (lMesasElegidas.size() == 1)
                        cout << "Venta iniciada." << endl;
                    else
                        cout << "Ventas iniciadas." << endl;
                } else {
                    iConInV->cancelarIniciarVenta();
                    if (confirma != "n" && confirma != "N")
                        cout << "Opcion invalida. ";
                    if (lMesasElegidas.size() == 1)
                        cout << "Venta no iniciada." << endl;
                    else
                        cout << "Ventas no iniciadas." << endl;
                }
            } else
                cout << endl << "No ha seleccionado mesas. No se han iniciado ventas." << endl;
        } else
            cout << endl << "El mozo no tiene mesas asignadas sin venta." << endl;
    } catch (exception& e) {
        cout << endl << e.what() << endl;
    }
}

void agregarProductoAVenta() {
    system("clear");

    cout << "_____________________________________________________" << endl;
    cout << "===A G R E G A R   P R O D U C T O   A   V E N T A===" << endl;
    cout << "_____________________________________________________" << endl;

    list<int> mesas = iConInV->listarMesas();
    if (mesas.size() > 0) {
        cout << endl << "Seleccione la mesa para agregar productos: " << endl << endl;

        for (list<int>::iterator it = mesas.begin(); it != mesas.end(); ++it)
            cout << "Mesa Nro.: " << *it << endl;

        int mesaSeleccionada;
        cout << endl << "Ingrese su numero: ";
        cin >> mesaSeleccionada;

        bool exitAgregar = true;
        while (exitAgregar) {
            int continuar;

            if (iConFuA->existeMesa(mesaSeleccionada)) {
                if (!iConFuA->estaMesaTieneVenta(mesaSeleccionada)) {
                    exitAgregar = false;
                    cout << "La Mesa seleccionada no posee ventas iniciadas." << endl;
                }
                else {
                    list<DtProductoBase*> productos;
                    int prod, cantSeleccion = 0;
                    string seleccion;

                    cout << "Seleccione el producto que desea agregar " << endl;
                    cout << " \t 1.Producto Comun \n" << "\t 2.Producto Menu\n" << "\t 0.Salir" << endl;

                    cin >> prod;
                    switch (prod) {
                    case 1: {
                        productos = iConAlP->listarProductosComunes();
                        break;
                    }
                    case 2: {
                        productos = iConAlP->listarProductosMenu();
                        break;
                    }
                    default: {
                        exitAgregar = false;
                        break;
                    }
                    }

                    if (exitAgregar) {
                        cout << "Producto\t\tCodigo\t" << endl;
                        for (list<DtProductoBase*>::iterator it = productos.begin(); it != productos.end(); it++) {
                            cout << "" << (*it)->getDescripcion();
                            cout << "\t\t\t" << (*it)->getCodigo();
                            cout << "\t" << endl;
                        }
                        cout << endl << "Ingrese el codigo: ";
                        cin >> seleccion;

                        if (iConFuA->existeProducto(seleccion)) {
                            iConAgP->seleccionarMesa(mesaSeleccionada);

                            cout << endl << "Ingrese la cantidad: ";
                            cin >> cantSeleccion;

                            VentaLocal* v = iConFuA->obtenerCodigoDeVenta(mesaSeleccionada);
                            DtProductoCantidad dtPC = DtProductoCantidad(seleccion, cantSeleccion);

                            iConAgP->seleccionarProducto(dtPC);

                            if (iConAgP->hayEsteProductoEnEnEstaVenta(v, seleccion)) {
                                iConAgP->incrementarProductoEnVenta(v, dtPC);
                                cout << "Se incremento la cantidad del Producto en la venta." << endl;
                            }
                            else {
                                cout << endl << "¿Desea confirmar el producto en la venta? (y/n): ";
                                cin >> seleccion;
                                if (seleccion == "y" || seleccion == "Y") {
                                    iConAgP->confirmarAgregarProductoVenta();
                                    cout << "Se agrego un nuevo producto a la venta." << endl;
                                }
                                else {
                                    iConAgP->cancelarAgregarProductoVenta();
                                    if (seleccion != "n" && seleccion != "N")
                                        cout << "Opcion invalida. ";
                                    cout << "No se pudo agregar el producto a la venta." << endl;
                                }
                            }
                        }
                        else
                            cout << "No existe el producto indicado." << endl;

                        cout << endl << "¿Desea agregar otro producto?? (y/n): ";
                        cin >> seleccion;

                        if (seleccion == "y" || seleccion == "Y")
                            prod = 1;
                        else {
                            prod = 0;
                            exitAgregar = false;
                            if (seleccion != "n" && seleccion != "N")
                                cout << "Opcion invalida.";
                        }
                    }
                }
            }
            else {
                exitAgregar = false;
                cout << "La mesa seleccionada no existe." << endl;
            }
        }
    }
    else
        cout << endl << "El sistema no posee mesas." << endl;
}

void quitarProductoAVenta() {
    system("clear");
    cout << "_____________________________________________________" << endl;
    cout << "====Q U I T A R   P R O D U C T O   A   V E N T A====" << endl;
    cout << "_____________________________________________________" << endl;

    int mesaElegida;
    string codigoProductoEliminar;
    int cantidadProductoEliminar;
    string confirmacion;
    string quitar="s";


    cout << "Ingrese la mesa a la cual quitar productos: " << endl;
    cin >> mesaElegida;

				if(iConFuA->existeMesa(mesaElegida)){
						Mesa* mesa = iConFuA->obtenerMesa(mesaElegida);
						list<DtProducto*> productosVenta;
						VentaLocal* vloc = mesa->getVentaLocal();

        if(vloc == NULL){
            std::cout << "\t\t\tLa mesa "<< mesa->getNumero() << " NO tiene VentaLocal asignada." << '\n';
            sleep(2);
            system("clear");
        }else{
            productosVenta = iConQtP->listarProductos(mesaElegida);
            while(quitar=="S" || quitar=="s"){

                for (list<DtProducto*>::iterator it = productosVenta.begin(); it != productosVenta.end(); it++)	{

                    DtProductoBase* productoBase = dynamic_cast<DtProductoBase*>(*it);
										cout << productoBase << endl;
								}

								cout << "Ingrese el codigo de producto que desea eliminar: " << endl;
								cin >> codigoProductoEliminar;
								cout << "Ingrese la cantidad de producto que desea eliminar: " << endl;
								cin >> cantidadProductoEliminar;

								DtProductoCantidad productoEliminar = DtProductoCantidad (codigoProductoEliminar, cantidadProductoEliminar);
								iConQtP->seleccionarProductoEliminar(productoEliminar);

								cout << "Desea confirmar la quita del producto de la venta?: S/N para continuar " << endl;
								cin >> confirmacion;

								if(confirmacion=="S" || confirmacion=="s"){
								iConQtP->confirmarQuitarProducto();
								cout << "Se quito un producto de la mesa a la venta"<< endl;
								}else{
								iConQtP->cancelarQuitarProducto();
								cout << "Ha cancelado la quita "<< endl;
								}

                cout << "Desea quitar otro producto?: S/N para continuar " << endl;
                cin >> quitar;
            }
            system("clear");
        }
    }else{
        std::cout << "\t\t\tMesa Incorrecta" << '\n';
        sleep(2);
        system("clear");
    }
}

void facturacionDeUnaVenta() {

  int idMesa;
  float descuento;
  DtFacturaLocal dtFL;
  bool encontro, finalizar;
	string confirma;


	try {
			finalizar = false;
			do {

				system("clear");

		    cout << "_____________________________________________________" << endl;
		    cout << "===F A C T U R A C I O N   D E   U N A   V E N T A===" << endl;
		    cout << "_____________________________________________________" << endl;

		    cout << endl << "Ingrese Nº de mesa: ";
		    cin >> idMesa;

				if (!iConFuA->existeMesa(idMesa))
						throw invalid_argument("ERROR! No existe la mesa ingresada");

						if (!iConFuA->estaMesaTieneVenta(idMesa)){
						        cout << endl << "esta Mesa NOOOO TieneVenta";
						}else{
							cout << endl << "esta Mesa SIII TieneVenta";}


		    cout << "\nDescuento: ";
		    cin >> descuento;

				dtFL = iConFac->facturar(idMesa,descuento);

        cout << endl << "Se ha generado la siguiente factura:";
        cout << endl << dtFL;

				cout << endl << "¿Desea facturar otra mesa? (y/n): ";
				cin >> confirma;
				if (confirma == "y" || confirma == "Y")
						finalizar = false;
				else {
						finalizar = true;
						if (confirma != "n" && confirma != "N")
								throw invalid_argument("ERROR! opcion invalida.");
				}

		} while (!finalizar);
	} catch (exception& e) {
		cout << endl << e.what() << endl;
	}

}

void asignarMozosAMesas() {
    system("clear");

    cout << "_____________________________________________________" << endl;
    cout << "======A S I G N A R   M O Z O S   A   M E S A S======" << endl;
    cout << "_____________________________________________________" << endl;

    try {
        if (primeraVezCargaDeDatos)
            cout << endl << "No es posible. Mozos y/o mesas insuficientes." << endl;
        else if (primeraVezAsignacion) {
            list<DtAsignacion*> listaAsignaciones = iConAsMM->asignarMozosMesas();
            cout << endl << "Mozos asignados de la siguienta manera:" << endl << endl;
            for (DtAsignacion* dta : listaAsignaciones)
                cout << *dta << endl;
            primeraVezAsignacion = false;
        } else
            cout << endl << "Las mesas actuales ya habian sido asignadas." << endl;
    } catch (exception& e) {
        cout << endl << e.what() << endl;
    }
}

void bajaProducto() {
    system("clear");

    cout << "_____________________________________________________" << endl;
    cout << "==============B A J A   P R O D U C T O==============" << endl;
    cout << "_____________________________________________________" << endl;


    bool encontro = false;
		bool primerVez = true;
    string codProd;
    string cero = "0";
		string confirmacion;

    list<DtProductoBase*> productosActuales = iConBjP->listarProductos() ;
    if (productosActuales.empty()) {
        system("clear");
        cout<< "          -No hay Productos en el Sistema-" << endl;
        system("clear");
    } else {
				if(primerVez){
        cout<< "Lista de productos actualizada: " << endl;
        for (DtProductoBase* dtPB : productosActuales)
            cout << *dtPB << endl;
				primerVez = false;
				}
        cout << "\nINGRESE EL CODIGO DEL PRODUCTO A DAR DE BAJA (0 para volver al menu) :";
        cin >> codProd;

        for (DtProductoBase* dtPB : productosActuales) {
            if (codProd.compare(dtPB->getCodigo()) == 0) {
                encontro = true;
                iConBjP->seleccionarProducto(codProd);
                cout << "----------DETALLES DEL PRODUCTO----------\n" << "          Descripcion:  "<< dtPB->getDescripcion()<< ".\n"<< "          Codigo:  "<< dtPB->getCodigo() << ".\n          FUE ENCONTRADO EN EL SISTEMA." << endl;
								sleep(2);
            }
        }
        if ((encontro == false)&&(codProd.compare(cero) != 0)) {
            system("clear");
            cout<<"\n\nEl codigo ingresado no es correcto, Volver al Menu..." << endl;
						sleep(2);
        } else if (codProd.compare(cero) == 0){
            system("clear");
				}else{
							cout << "Confirmar Baja de Producto "<< codProd <<"(y/n): "<< endl;
							cin >> confirmacion;
							if((confirmacion == "y")||(confirmacion == "Y")){
								cout << "\n\t BAJA PRODUCTO CONFIRMADA " << '\n';
								iConBjP->eliminarProducto();
								sleep(1);
								system("clear");
							}else if((confirmacion == "n")||(confirmacion == "N")){
								cout << "\n\t BAJA PRODUCTO CANCELADA " << '\n';
								iConBjP->cancelarBajaProducto();
								sleep(1);
								system("clear");
							}else{
								cout << "\n\tOpcion incorrecta. Volver al MENU..." << endl;
								sleep(2);
								system("clear");
							}
				}

    }
}

void informacionProducto() {
    system("clear");

    cout << "_____________________________________________________" << endl;
    cout << "=======I N F O R M A C I O N   P R O D U C T O=======" << endl;
    cout << "_____________________________________________________" << endl;
// 			bool primeraVez = true;
// 			bool esmenu;
//     bool seguirMostrando = true;
//     string codigoProducto;
//     char opcion;
//
// 		list<DtProductoBase*> productosActuales = iConInfP->listarProductos();
// 		if (productosActuales.empty()) {
// 				system("clear");
// 				cout<< "          -No hay Productos en el Sistema-" << endl;
// 				system("clear");
// 		} else {
// 				if(primeraVez){
// 						cout<< "Lista de productos actualizada: " << endl;
// 						for (DtProductoBase* dtPB : productosActuales)
// 								cout << *dtPB << endl;
// 				}else{
// 						while(seguirMostrando){
//
//               cout << "Ingrese el codigo de producto que desea eliminar: " << endl;
//               cin >> codigoProducto;
//
//               if (iConFuA->existeProducto(codigoProducto)){
//                 DtProducto* productoInfo = iConInfP->seleccionarProducto(codigoProducto);
// 				esmenu = iConFuA-> MostrarInformacion(codigoProducto);
//
//                 cout << "\n\t\t" << productoInfo << endl;
//
//                 if (esmenu){
//                 cout << "\n\t Productos Comunes del Menu:" << endl;
//
// 		DtProductoMenu* productoArmadoMenu = dynamic_cast<DtProductoMenu*>(productoInfo);
//
// 		list<DtProductoComun*> productosMenu = productoArmadoMenu->getListaComunes();
//
// 		for (DtProductoComun *pm : productosMenu){
// 			cout << "\n\t\t" << *pm << endl;
// 		}
// 	}
//
//                 cout << "Desea Seguir viendo la informacion de mas productos? S/N" << endl;
//                 cin >> opcion;
//
//                 if (opcion =='n' || opcion =='N') {
//                   seguirMostrando = false;
//                 }
//
//               }else{seguirMostrando = false;}
//
// 						}
// 				}
// }
}
void cargarDatosPrueba() {
    system("clear");

    cout << "_____________________________________________________" << endl;
    cout << "=====C A R G A R   D A T O S   D E   P R U E B A=====" << endl;
    cout << "_____________________________________________________" << endl;

    try {
        if (primeraVezCargaDeDatos) {
            iConAgD->cargarDatos();
            primeraVezCargaDeDatos = false;
            cout << endl << "Datos de prueba cargados." << endl;
        } else
            cout << endl << "No es posible volver a generar datos de prueba." << endl;
    } catch (exception& e) {
        cout << endl << e.what() << endl;
    }
}

//OPERACIONES AUXILIARES
void procesarProductoComun(string codigo, string descripcion) {
    string confirma;
    float precio;

    cout << "PRECIO: ";
    cin >> precio;

    iConAlP->datosProductoComun(codigo, descripcion, precio);

    cout << endl << "¿Desea confirmar el producto? (y/n): ";
    cin >> confirma;
    if (confirma == "y" || confirma == "Y") {
        iConAlP->confirmarProductoComun();
        cout << "Producto dado de alta" << endl;
    } else {
        iConAlP->cancelarProductoComun();
        if (confirma != "n" && confirma != "N")
            cout << "Opcion invalida. ";
        cout << "Alta de producto cancelada" << endl;
    }
}
void procesarProductoMenu(string codigo, string descripcion) {
    iConAlP->datosProductoMenu(codigo, descripcion);

    string codComun, confirma;
    bool finalizar = false;
    int cantidad;

    list<DtProductoBase*> lPC = iConAlP->listarProductosComunes();
    cout << endl << "SELECCIONE LOS PRODUCTOS DEL MENU:" << endl << endl;
    cout << "CODIGO\t\tPRODUCTO" << endl;
    for (list<DtProductoBase*>::iterator it = lPC.begin(); it != lPC.end(); it++) {
        cout << "" << (*it)->getCodigo();
        cout << "\t\t" << (*it)->getDescripcion() << endl;
    }
    do {
        cout << endl << "CODIGO: ";
        cin >> codComun;

        if (iConFuA->existeProducto(codComun) && iConFuA->tipoProducto(codComun) == comun) {
            bool fueAgregado = false;
            list<DtProductoCantidad*> lPC = iConAlP->getProductosComun();
            list<DtProductoCantidad*>::iterator it = lPC.begin();
            while (!fueAgregado && it != lPC.end()) {
                if ((*it)->getCodigo() == codComun)
                    fueAgregado = true;
                ++it;
            }
            if (fueAgregado)
                cout << "El producto ya se encuentra en el menu." << endl;
            else {
                cout << "CANTIDAD: ";
                cin >> cantidad;

                DtProductoCantidad* dtPC = new DtProductoCantidad(codComun, cantidad);
                iConAlP->agregarAlProductoMenu(dtPC);

                if (iConAlP->getProductosComun().size() < iConAlP->listarProductosComunes().size()) {
                    cout << endl << "¿Desea continuar agregando productos al menu? (y/n): ";
                    cin >> confirma;
                    if (confirma != "y" && confirma != "Y") {
                        finalizar = true;
                        if (confirma != "n" && confirma != "N")
                            cout << "Opcion invalida. Seleccion de productos cancelada" << endl;
                    }
                } else
                    finalizar = true;
            }
        } else
            cout << "El producto seleccionado no es valido." << endl;
    } while (!finalizar);

    cout << endl << "¿Desea confirmar el menu? (y/n): ";
    cin >> confirma;
    if (confirma == "y" || confirma == "Y") {
        iConAlP->confirmarProductoMenu();
        cout << "Menu dado de alta" << endl;
    } else {
        iConAlP->cancelarProductoMenu();
        if (confirma != "n" && confirma != "N")
            cout << "Opcion invalida. ";
        cout << "Alta de menu cancelada" << endl;
    }
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
    iConAsMM = fabrica->getIControladorAsignarMesasAMozos();
//		iConInfP = fabrica->getIControladorInformacionProducto();

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
//            case 8: informacionProducto();
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