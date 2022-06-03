class Tienda{
private:
    Producto vec[200] ;//vector de objetos tipo producto
    int cantidad; //espacios llenos
    int tamano;
public:
    Tienda(){
   	 cantidad=0;
   	 tamano=200;
    }
    //gets
    int getCantidad(){
   	 return cantidad;
    }
    int getTamano(){
   	 return tamano;
    }
    //set
    void setCantidad(int cant){
   	 cantidad=cant;
    }
    //metodos
    void ingresaProducto(Producto producto){
   	 if(cantidad<tamano){
   		 vec[cantidad]=producto;
   		 cantidad++;
   	 }
    }
    void eliminarProductoPorSu(int cod) {  //elimina producto por código
   	 for(int i=0; i<cantidad; i++){
   		 if(vec[i].getCodigo()==cod){
   			 for(int i=0; i<cantidad; i++){
   			 vec[i]=vec[i+1];
   			 }
   			 cantidad--;
   		 }
   	 }
   	 
    }
    Producto obtenerProductoDeMayorValor(){//mayor precio de venta
   	 Producto pmayor=vec[0]; // defino un producto para comparlo con los del vector
   	 for(int i=0; i<cantidad; i++){
   		 if(vec[i].precioVenta()>pmayor.precioVenta()){
   			 pmayor=vec[i];
   		 }
   	 }
   	 return pmayor;
    }
    Producto obtenerProductoConMayorExistencia(){//mayor cantidad de unidades existentes
   	 Producto cmayor=vec[0]; // defino un producto para comparlo con los del vector
   	 for(int i=0; i<cantidad; i++){
   		 if(vec[i].getExistencia()> cmayor.getExistencia()){
   			 cmayor=vec[i];
   		 }
   	 }
   	 return cmayor;
    }
    void ordenarPorductoPorCodigo(){        	 
   	 Producto aux;
   	 for(int i=0; i<cantidad; i++){
   		 for(int j=i+1; j<cantidad; j++){
   			 if(vec[i].getCodigo()> vec[j].getCodigo()){
   				 aux = vec[i];
   				 vec[i] =vec[j];
   				 vec[j]=aux;
   			 }
   		 }
   	 }
    }
    void imprimirTodosLosProductos(){
   	 
   	 for(int i=0; i<cantidad; i++){
   		 cout<<"\n--------Datos del producto #"<<i<<"--------"<<endl;
   		 cout<<"Código: "<<vec[i].getCodigo()<<endl;
   		 cout<<"Nombre: "<<vec[i].getNombre()<<endl;
   		 cout<<"Porcentaje de ganancia: "<<vec[i].getPorcentajeGanancia()<<endl;
   		 cout<<"Precio venta: "<<vec[i].precioVenta()<<endl;
   		 
   	 }
   	 cout<<"-------------------------------------"<<endl;
    }
    int cantDeProductosBajosDeExistencia(){
   	 int cant=0;
   	 for(int i=0; i<cantidad; i++){
   		 if(vec[i].getExistencia() < vec[i].getExistenciaMin()){
   			 cant++;
   		 }
   	 }
   	 return cant;
    }
    void imprimirProductosBajosDeExistencia(){
   	 
   	 for(int i=0; i< cantDeProductosBajosDeExistencia(); i++){
   		 cout<<"\nInformación de productos de baja existencia"<<endl;
   		 if(vec[i].getExistencia() < vec[i].getExistenciaMin()){
   			 cout<<"------------------------------------"<<endl;
   			 cout<<"Código: "<<vec[i].getCodigo()<<endl;
   			 cout<<"Nombre: "<<vec[i].getNombre()<<endl;
   			 cout<<"Existencia: "<<vec[i].getExistencia()<<endl;
   			 cout<<"Existencia mínima: "<<vec[i].getExistenciaMin()<<endl;
   		 }
   	 }
   	 cout<<"------------------------------------"<<endl;
   	 
    }
    float cuantosKgsSeHanVendidoEnGeneral(){
   	 float kgs=0;
   	 int cantv;
   	 
   	 for(int i=0; i<cantidad; i++){
   		 cantv=vec[i].getCantidadVendida();
   		 kgs+=cantv*vec[i].getPesoUnitario();
   	 }
   	 
   	 return kgs;
    }
    
};
