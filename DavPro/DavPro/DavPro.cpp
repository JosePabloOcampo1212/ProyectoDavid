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
                cout << "Existencia mínima: " << vec[i].getExistenciaMin() << endl;
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

int main() {

    Producto p1; //crea producto sin parámetros
    Producto p2(10003, "Uvas", 200, 0.05, 1, 30, 3, 10); //con parámetros
    Producto p3(10001, "Jabón", 400, 0.15, 1, 30, 200, 10);
    Producto p4(10002, "Paño", 1500, 0.05, 1, 30, 420, 15);

    Tienda coleccionproducto; //crea una coleccion
    coleccionproducto.ingresaProducto(p1); //agrega el productos
    coleccionproducto.ingresaProducto(p2);
    coleccionproducto.ingresaProducto(p3);
    coleccionproducto.ingresaProducto(p4);
    coleccionproducto.imprimirTodosLosProductos(); //muestra posicion de producto  en el vector + atributos del mismo

    coleccionproducto.eliminarProductoPorSu(00000);
    coleccionproducto.imprimirTodosLosProductos();

    cout << "Producto de mayor valor: " << coleccionproducto.obtenerProductoDeMayorValor().getNombre() << endl;
    cout << "Producto con mayor existencia: " << coleccionproducto.obtenerProductoConMayorExistencia().getNombre() << endl;
    cout << "Kilogramos vendidos en general de todos los productos: " << coleccionproducto.cuantosKgsSeHanVendidoEnGeneral() << "kg" << endl;
    cout << "Cantidad de productos bajos de existencia: " << coleccionproducto.cantDeProductosBajosDeExistencia() << endl;

    coleccionproducto.imprimirProductosBajosDeExistencia();

    coleccionproducto.ordenarPorductoPorCodigo();
    coleccionproducto.imprimirTodosLosProductos();

    return 0;
}