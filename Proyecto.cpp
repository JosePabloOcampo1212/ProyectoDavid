class Producto{
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
    Producto(){ //constructor sin parámetros
   	 codigo=00000;
   	 nombre="Sin definir";
   	 precioBase=0.0;
   	 porcentajeGanancia=0.0;
   	 pesoUnitario=0.0;
   	 cantVendida=0;
   	 existencia=0;
   	 existenciaMin=0;
    }
    Producto (int codigo, string nombre, float precioBase, float porcentajeGanancia, float pesoUnitario, int cantVendida, int existencia, int existenciaMin){
   	 this->codigo=codigo; 	//constructor con parámetros
   	 this->nombre=nombre;
   	 this->precioBase=precioBase;
   	 this->porcentajeGanancia=porcentajeGanancia;
   	 this->pesoUnitario=pesoUnitario;
   	 this->cantVendida=cantVendida;
   	 this->existencia=existencia;
   	 this->existenciaMin=existenciaMin;
    }
    //gets
    int getCodigo(){
   	 return codigo;
    }
    string getNombre(){
   	 return nombre;
    }
    float getPrecioBase(){
   	 return precioBase;
    }
    float getPorcentajeGanancia(){
   	 return porcentajeGanancia;
    }
    float getPesoUnitario(){
   	 return pesoUnitario;
    }
    int getCantidadVendida(){
   	 return cantVendida;
    }
    int getExistencia(){
   	 return existencia;
    }
    int getExistenciaMin(){
   	 return existenciaMin;
    }
    //sets
    void setCodigo(int cod){
   	 codigo=cod;
    }
    void setNombre(string nom){
   	 nombre=nom;
    }
    void setPrecioBase(float pb){
   	 precioBase=pb;
    }
    void setPorcentajeGanancia(float pg){
   	 porcentajeGanancia=pg;
    }
    void setPesoUnitario(float pu){
   	 pesoUnitario=pu;
    }
    void setCantidadVendida(int cv){
   	 cantVendida=cv;
    }
    void setExistencia(int ex){
   	 existencia=ex;
    }
    void setExistebciaMin(float exm){
   	 existenciaMin=exm;
    }
    //métodos-cálculos
    float precioVenta (){
   	 float pv, porcentaje;
   	 porcentaje=precioBase*porcentajeGanancia;
   	 pv=precioBase+porcentaje;
   	 return pv;
    }
    //toString
    string toString(){
   	 stringstream s;
   	 s<<"\n--------Datos del producto--------"<<endl;
   	 s<<"Código: "<<codigo<<endl;
   	 s<<"Nombre: "<<nombre<<endl;
   	 s<<"Precio base: "<<precioBase<<" colones"<<endl;
   	 s<<"Porcentaje de ganancia: "<<porcentajeGanancia<<"%"<<endl;
   	 s<<"Peso unitario: "<<pesoUnitario<<"kg"<<endl;
   	 s<<"----------------------------------"<<endl;
   	 return s.str();
    }
};
