/*persona ingresa datos del auto para consultar multa la cual va a variar segun la velocidad a la que iba.*/
#include <iostream>
#include <string>
// THIS puntero implisito apunta a un solo objeto para referirse a los miembros de la clase dentro de sus propios metodos..
using namespace std;


class Vehiculo{
private:
    int velocidadMaxima;
    int velocidadActual;
    string marca;
    string modelo;
    string patente;

public:
    // Constructor: es un conjunto de instrucciones diseñado especialmente
    // para inicializar una instancia de un objeto. Pueden pasarse parametros a un constructor,
    // de la misma forma que una funcion. El nombre del constructor tiene que ser SIEMPRE el mismo que el de la clase
    Vehiculo (string marca, string modelo, string patente, int velocidadMaxima, int velocidadActual){
        this->marca = marca;
        this->modelo = modelo;
        this->patente = patente;
        this->velocidadMaxima = velocidadMaxima;
        this->velocidadActual = velocidadActual;
    }
   

    bool verificarVelocidadMaxima(){
        return velocidadActual == velocidadMaxima;
    }

    int calcularMulta(){
        if (velocidadActual <= velocidadMaxima){
            return 0;
    } else {
        int excesoVelocidad = velocidadActual - velocidadMaxima;
        int multa = excesoVelocidad * 500;
        return multa;
    }
    }
    void mostrarInformacion()
    {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Velocidad maxima permitida: " << velocidadMaxima << "km/h" << endl;
        cout << "Velocidad actual: " << velocidadActual << "km/h" << endl;
        cout << "Patente: " << patente << endl;
    }
};

int main()
{

    string marca, modelo, patente;
    int velocidadActual, velocidadMaxima;

    cout << "Ingrese marca del vehiculo: \n";
    getline(cin, marca);
    cout << "Ingrese modelo del vehiculo: \n";
    getline(cin, modelo);
    cout << "Ingrese velocidad maxima permitida: \n";
    cin >> velocidadMaxima;
    cout << "Ingrese velocidad en la que transita: \n";
    cin >> velocidadActual;

    cin.ignore(); // Ignoramos el salto de lineas pendiente

    cout << "Ingrese la patente del vehiculo: \n";
    getline(cin, patente);

    Vehiculo vehiculo (marca, modelo, patente, velocidadMaxima, velocidadActual);

    vehiculo.mostrarInformacion();
    
    //ANTES ESTABA ASI.
    /* if (vehiculo.verificarVelocidadMaxima())
    {
        cout << "Estas dentro del rango de velocidad permitido" << endl;
    }
    else if (vehiculo.calcularMulta())
    {
        cout << "Valor a pagar: $" << multa << endl;
    }*/

    if (vehiculo.verificarVelocidadMaxima()){
        cout << "El vehiculo esta en la velocidad maxima permitida." << endl;
    } else {
        int multa = vehiculo.calcularMulta();
        if (multa > 0){
            cout << "El vehiculo tiene una multa." << endl;
            cout << "Velocidad: " << velocidadActual << "km/h" << endl;
            cout << "Multa a pagar: $" << multa << endl;
        } else {
            cout << "El vehiculo no tiene multa." << endl;
        }
    }

    return 0;
}
