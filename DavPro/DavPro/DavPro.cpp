// DavPro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Producto {
private:
    int codigo;
    string nombre;
    float precioBase;
    float porcentajeGanancia;
    float pesoUnitario;
    int cantVendida; //
    int existencia; //
    int existenciaMin; //

public:
    Producto() { //constructor sin parámetros
        codigo = 00000;
        nombre = "Sin definir";
        precioBase = 0.0;
        porcentajeGanancia = 0.0;
        pesoUnitario = 0.0;
        cantVendida = 0;
        existencia = 0;
        existenciaMin = 0;
    }
    Producto(int codigo, string nombre, float precioBase, float porcentajeGanancia, float pesoUnitario, int cantVendida, int existencia, int existenciaMin) {
        this->codigo = codigo; 	//constructor con parámetros
        this->nombre = nombre;
        this->precioBase = precioBase;
        this->porcentajeGanancia = porcentajeGanancia;
        this->pesoUnitario = pesoUnitario;
        this->cantVendida = cantVendida;
        this->existencia = existencia;
        this->existenciaMin = existenciaMin;
    }
    //gets
    int getCodigo() {
        return codigo;
    }
    string getNombre() {
        return nombre;
    }
    float getPrecioBase() {
        return precioBase;
    }
    float getPorcentajeGanancia() {
        return porcentajeGanancia;
    }
    float getPesoUnitario() {
        return pesoUnitario;
    }
    int getCantidadVendida() {
        return cantVendida;
    }
    int getExistencia() {
        return existencia;
    }
    int getExistenciaMin() {
        return existenciaMin;
    }
    //sets
    void setCodigo(int cod) {
        codigo = cod;
    }
    void setNombre(string nom) {
        nombre = nom;
    }
    void setPrecioBase(float pb) {
        precioBase = pb;
    }
    void setPorcentajeGanancia(float pg) {
        porcentajeGanancia = pg;
    }
    void setPesoUnitario(float pu) {
        pesoUnitario = pu;
    }
    void setCantidadVendida(int cv) {
        cantVendida = cv;
    }
    void setExistencia(int ex) {
        existencia = ex;
    }
    void setExistebciaMin(float exm) {
        existenciaMin = exm;
    }
    //métodos-cálculos
    float precioVenta() {
        float pv, porcentaje;
        porcentaje = precioBase * porcentajeGanancia;
        pv = precioBase + porcentaje;
        return pv;
    }
    //toString
    string toString() {
        stringstream s;
        s << "\n--------Datos del producto--------" << endl;
        s << "Código: " << codigo << endl;
        s << "Nombre: " << nombre << endl;
        s << "Precio base: " << precioBase << " colones" << endl;
        s << "Porcentaje de ganancia: " << porcentajeGanancia << "%" << endl;
        s << "Peso unitario: " << pesoUnitario << "kg" << endl;
        s << "----------------------------------" << endl;
        return s.str();
    }
};

//------------------------------------------------------------------------------

class Tienda {
private:
    Producto vec[200];//vector de objetos tipo producto
    int cantidad; //espacios llenos
    int tamano;
public:
    Tienda() {
        cantidad = 0;
        tamano = 200;
    }
    //gets
    int getCantidad() {
        return cantidad;
    }
    int getTamano() {
        return tamano;
    }
    //set
    void setCantidad(int cant) {
        cantidad = cant;
    }
    //metodos
    void ingresaProducto(Producto producto) {
        if (cantidad < tamano) {
            vec[cantidad] = producto;
            cantidad++;
        }
    }
    void eliminarProductoPorSu(int cod) {  //elimina producto por código
        for (int i = 0; i < cantidad; i++) {
            if (vec[i].getCodigo() == cod) {
                for (int i = 0; i < cantidad; i++) {
                    vec[i] = vec[i + 1];
                }
                cantidad--;
            }
        }

    }
    Producto obtenerProductoDeMayorValor() {//mayor precio de venta
        Producto pmayor = vec[0]; // defino un producto para comparlo con los del vector
        for (int i = 0; i < cantidad; i++) {
            if (vec[i].precioVenta() > pmayor.precioVenta()) {
                pmayor = vec[i];
            }
        }
        return pmayor;
    }
    Producto obtenerProductoConMayorExistencia() {//mayor cantidad de unidades existentes
        Producto cmayor = vec[0]; // defino un producto para comparlo con los del vector
        for (int i = 0; i < cantidad; i++) {
            if (vec[i].getExistencia() > cmayor.getExistencia()) {
                cmayor = vec[i];
            }
        }
        return cmayor;
    }
    void ordenarPorductoPorCodigo() {
        Producto aux;
        for (int i = 0; i < cantidad; i++) {
            for (int j = i + 1; j < cantidad; j++) {
                if (vec[i].getCodigo() > vec[j].getCodigo()) {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
    void imprimirTodosLosProductos() {

        for (int i = 0; i < cantidad; i++) {
            cout << "\n--------Datos del producto #" << i << "--------" << endl;
            cout << "Código: " << vec[i].getCodigo() << endl;
            cout << "Nombre: " << vec[i].getNombre() << endl;
            cout << "Porcentaje de ganancia: " << vec[i].getPorcentajeGanancia() << endl;
            cout << "Precio venta: " << vec[i].precioVenta() << endl;

        }
        cout << "-------------------------------------" << endl;
    }
    int cantDeProductosBajosDeExistencia() {
        int cant = 0;
        for (int i = 0; i < cantidad; i++) {
            if (vec[i].getExistencia() < vec[i].getExistenciaMin()) {
                cant++;
            }
        }
        return cant;
    }
    void imprimirProductosBajosDeExistencia() {

        for (int i = 0; i < cantDeProductosBajosDeExistencia(); i++) {
            cout << "\nInformación de productos de baja existencia" << endl;
            if (vec[i].getExistencia() < vec[i].getExistenciaMin()) {
                cout << "------------------------------------" << endl;
                cout << "Código: " << vec[i].getCodigo() << endl;
                cout << "Nombre: " << vec[i].getNombre() << endl;
                cout << "Existencia: " << vec[i].getExistencia() << endl;
                cout << "Existencia minima: " << vec[i].getExistenciaMin() << endl;
            }
        }
        cout << "------------------------------------" << endl;

    }
    float cuantosKgsSeHanVendidoEnGeneral() {
        float kgs = 0;
        int cantv;

        for (int i = 0; i < cantidad; i++) {
            cantv = vec[i].getCantidadVendida();
            kgs += cantv * vec[i].getPesoUnitario();
        }

        return kgs;
    }

};

void interfazDeUsuario() {

    int opcion;
    bool repetir = true;
    string nombre;
    int codigo;
    float precioBase;
    float porcentajeGanancia;
    float pesoUnitario;
    int cantVendida;
    int existencia;
    int existenciaMin;
    int eliminarCod;
    Tienda t1 = Tienda();

    do {
        system("cls");

        cout << "--------------------------------------------MENU-------------------------------------" << endl;
        cout << "1. Ingresar un producto." << endl;
        cout << "2. Eliminar un producto." << endl;
        cout << "3. Desplegar el producto de mayor precio." << endl;
        cout << "4. Desplegar el producto con mayor existencia." << endl;
        cout << "5. Ordenar los productos por código." << endl;
        cout << "6. Desplegar todos los productos." << endl;
        cout << "7. Desplegar la cantidad de productos bajos de existencia." << endl;
        cout << "8. Desplegar los productos bajos de existencia." << endl;
        cout << "9. Desplegar el total de kilogramos de todos los productos vendidos." << endl;
        cout << "10. Desplegar el total de Kilogramos vendidos de un producto." << endl;
        cout << "20. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Digite código del producto: ";
            cin >> codigo;
            cout << "Nombre del producto: ";
            cin >> nombre;
            cout << "Precio base en colones: ";
            cin >> precioBase;
            cout << "Porcentaje de ganancia: ";
            cin >> porcentajeGanancia;
            cout << "Peso unitario en kilogramos: ";
            cin >> pesoUnitario;
            cout << "Cantidad vendida: ";
            cin >> cantVendida;
            cout << "Existecnia: ";
            cin >> existencia;
            cout << "Existecnia mínima: ";
            cin >> existenciaMin;
            t1.ingresaProducto(Producto(codigo, nombre, precioBase, porcentajeGanancia, pesoUnitario, cantVendida, existencia, existenciaMin));
            system("pause>nul"); // Pausa
            break;

        case 2:
            cout << "Ingrese el código del producto que desea eliminar: ";
            cin >> eliminarCod;
            t1.eliminarProductoPorSu(eliminarCod);
            system("pause>nul"); // Pausa
            break;

        case 3:
            cout << "Producto de mayor valor: " << t1.obtenerProductoDeMayorValor().getNombre();
            system("pause>nul"); // Pausa            
            break;

        case 4:
            cout << "Producto con mayor existencia: " << t1.obtenerProductoConMayorExistencia().getNombre();
            system("pause>nul"); // Pausa                
            break;

        case 5:
            t1.ordenarPorductoPorCodigo();
            cout << "Se han ordenado los productos por código de forma ascendente, exitosamente.";
            system("pause>nul"); // Pausa                
            break;

        case 6:
            t1.imprimirTodosLosProductos();
            system("pause>nul"); // Pausa                
            break;

        case 7:
            cout << "Cantidad de productos bajos de existencia: " << t1.cantDeProductosBajosDeExistencia();
            system("pause>nul"); // Pausa                
            break;

        case 8:
            t1.imprimirProductosBajosDeExistencia();
            system("pause>nul"); // Pausa                
            break;

        case 9:
            cout << "Total de kilogramos de todos los productos vendidos: " << t1.cuantosKgsSeHanVendidoEnGeneral();
            system("pause>nul"); // Pausa                
            break;

        case 20:
            repetir = false;
            break;
        }
    } while (repetir);

}



int main() {

    interfazDeUsuario();

    return 0;
}

