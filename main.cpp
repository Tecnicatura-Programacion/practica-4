#include <iostream>
#include <vector>

// Clase numero 4 de practica
// Clase sobre  POO (Programacion orientada a objetos)

// Declaro clase padre llamada Persona.
class Persona {
    private:
        // Atributos en estado privado de un objeto.
        std::string nombre;  
        int edad;
        int dni;
    public:
        // Constructor para acceder a los atributos privados.
        Persona(std::string nombre, int edad, int dni)
            : nombre(nombre), edad(edad), dni(dni) {} 

        // Metodos Get (conseguir)
        std::string getNombre(){
            return nombre;
        }

        int getEdad() {
            return edad;
        }

        int getDNI() {
            return dni;
        }

        // Metodo set (Asignar)
        void setNombre(std::string nuevo_nombre) {
            this->nombre = nuevo_nombre;
        }

        void setEdad(int nueva_edad) {
            this->edad = nueva_edad;
        }

        void setDNI(int nuevo_dni) {
            this->dni = nuevo_dni;
        }
        
        // metodo que imprime todos los datos.
        void imprimirDatos() {
            std::cout << "----[Información]----"<< std::endl;
            std::cout << "Nombre: " << nombre << std::endl;
            std::cout << "Edad: " << edad << std::endl;
            std::cout << "DNI: " << dni << std::endl;
        }
};

// Creamos una clase HIJA de clase padre (clase Persona), llamada Estudiante.
class Estudiante : public Persona {
    private:
        std::string carrera;
        std::vector<float> notas;
    public:
        Estudiante(std::string nombre, int edad, int dni,
                    std::string carrera, std::vector<float> notas) 
                        : Persona(nombre, edad, dni) {
                            this->carrera = carrera;
                            this->notas = notas;
                        }
        
        std::string getCarrera() {
            return carrera;
        }

        void setCarrera(std::string nueva_carrera) {
            this->carrera = nueva_carrera;
        }

        float calcularPromedio() {
            
            float temp = 0.0;
            for (float nota: notas) {
                // es lo mismo que temp = temp + nota.
                temp += nota;
            };
            return temp / notas.size();
        }

        void imprimirDatos() {
            Persona::imprimirDatos();
            std::cout << "Carrera: "<< carrera << std::endl;
            std::cout << "Notas: " << std::endl;
            for (float nota: notas) {
                std::cout << nota << " | ";
            }
            std::cout << std::endl;
            std::cout << "Promedio: " << calcularPromedio() << std::endl;
        }
        

        
};


class Profesor : public Persona {
    private:
        std::string area;
        std::vector<Estudiante> estudiantes;
    public:
        Profesor(std::string nombre, int edad, int dni, std::string area, 
            std::vector<Estudiante> estudiantes) :
                Persona(nombre, edad, dni) {
                this->area = area;
                this->estudiantes = estudiantes;
            }

        std::string getArea(){
            return area;
        }

        void setArea(std::string nueva_area) {
            this->area = area;
        }

        void imprimirDatos() {
            Persona::imprimirDatos();
            std::cout << "Area: " << area << std::endl;
            std::cout << "Estudiantes: " << std::endl;
            for (Estudiante estudiante: estudiantes) {
                std::cout << "- " << estudiante.getNombre() << std::endl;;
            }

        }

        void imprimirPromedios() {
            std::cout << "---- [ Promedios ] ----" << std::endl;
            for (Estudiante estudiante : estudiantes) {
                std::cout << estudiante.getNombre() << ": " << estudiante.calcularPromedio() << std::endl;
            }
        }
};

class Curso {
    private:
        std::string nombre;
        Profesor profesor;
        std::vector<Estudiante> estudiantes;
    public:

        Curso(std::string nombre, Profesor profesor, std::vector<Estudiante> estudiantes)
        : nombre(nombre), profesor(profesor), estudiantes(estudiantes) {
            this->nombre = nombre;
            this->profesor = profesor;
            this->estudiantes = estudiantes;
        }

        std::string getNombre() {
            return nombre;
        }
        
        Profesor getProfesor() {
            return profesor;
        }

        void agregarEstudiante(Estudiante estudiante) {
            estudiantes.push_back(estudiante);
        }

        void eliminarEstudiante(Estudiante estudiante) {
            for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
                if (it->getDNI() == estudiante.getDNI()) {
                    estudiantes.erase(it);
                    break;
                }
            }
        }

        void imprimirDatos(){
            std::cout << "Curso: " << nombre << std::endl;
            std::cout << "Profesor: " << profesor.getNombre() << std::endl;
            std::cout << "Estudiantes: " << std::endl;
            for (Estudiante estudiante: estudiantes) {
                std::cout << "・ " << estudiante.getNombre() << std::endl;
            }
        }

};

int main(){

    

    Estudiante nico("Nicolas Pacheco", 18, 45723477, "Gramatica", {1.0, 7.9, 3.0});

    Estudiante rodri("Rodrigo Caullan", 33,34766721, "Programacion", {9.8, 8.9, 10.0});

    std::vector<Estudiante> todos_estudiantes = {nico, rodri};

    Profesor meli("Melina Burtre", 25, 40300441, "Programación", todos_estudiantes);

    Curso desprogramadores("Programación", meli, todos_estudiantes);

    desprogramadores.imprimirDatos();

    Estudiante lucho("Lucho", 18, 46152500, "Programacion", {8.0, 8.0, 7.9});
    
    desprogramadores.agregarEstudiante(lucho);

    std::cout << "----------------------------"<< std::endl;
    desprogramadores.imprimirDatos();
    
    std::cout << "----------------------------"<<std::endl;
    desprogramadores.eliminarEstudiante(nico);
    desprogramadores.imprimirDatos();


    return 0;
}

