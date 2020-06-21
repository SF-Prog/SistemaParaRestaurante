DtProductoMenu::DtProductoMenu() {}
DtProductoMenu::DtProductoMenu(string codigo, string descripcion, float precio, float cantidadEF, list<DtProductoComun *> listaCom) : DtProducto(codigo, descripcion, precio, cantidadEF)
{
    this->listaComunes = listaCom;
}

//Getters & Setters
list<DtProductoComun *> DtProductoMenu::getCantEnMenu()
{
    return this->listaComunes;
}

void DtProductoMenu::setCantEnMenu(list<DtProductoComun *> listaCom)
{
    this->listaComunes = listaCom;
}

//Destructores
virtual DtProductoMenu::~DtProductoComun() {}