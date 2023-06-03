#include <iostream>
#include <vector>

class Persona {
    private:
        std::string nombre;
        int edad;
        int dni;
    public:
        Persona(std::string nombre, int edad, int dni)
            : nombre(nombre), edad(edad), dni(dni) {}

        // Metodos Get (Conseguir)
        std::string getNombre() {
            return nombre;
        }
        int getEdad() {
            return edad;
        }
        int getDNI() {
            return dni;
        }
        
        // Metodos Set (Asignar)
        void setNombre(std::string nombre) {
            this->nombre = nombre;
        }
        void setEdad(int edad) {
            this->edad = edad;
        }
        void setDNI(int dni) {
            this->dni = dni;
        }

        void imprimirDatos() {
            std::cout << "------------------" << std::endl;
            std::cout << "Nombre: " << nombre << std::endl;
            std::cout << "Edad: " << edad << std::endl;
            std::cout << "DNI: " << dni << std::endl;
        }
};

class Estudiante : public Persona {
    private:
        std::string carrera;
        std::vector<float> notas;
    public:
        Estudiante(std::string nombre, 
                    int edad, int dni, 
                    std::string carrera,
                    std::vector<float> notas)
            : Persona(nombre, edad, dni) {
                this->carrera = carrera;
                this->notas = notas;
            }

        std::string getCarrera() {
            return carrera;
        }
        void setCarrera(std::string carrera) {
            this->carrera = carrera;
        }

        float calcularPromedio() {
            float temp = 0.0;
            for (float nota: notas) {
                temp += nota;
            };
            return temp / notas.size(); 
        }
        void imprimirDatos() {
            Persona::imprimirDatos();
            std::cout << "Carrera: " << carrera << std::endl;
            std::cout << "Notas: " << std::endl;
            for (float nota: notas) {
                std::cout << nota << "|";
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
        Profesor(std::string nombre, int edad, int dni, std::string area,  std::vector<Estudiante> estudiantes)            : Persona(nombre, edad, dni) {
                this->area = area;
                this->estudiantes = estudiantes;
            }
        std::string getArea() {
            return area;
        }
        void setArea(std::string area) {
            this->area = area;
        }
        void imprimirDatos() {
            Persona::imprimirDatos();
            std::cout << "Area: " << area << std::endl;
            std::cout << "Estudiantes: " << std::endl;
            for (Estudiante estudiante : estudiantes) {
                std::cout << estudiante.getNombre();
            }
        }
        void imprimirPromedios() {
            std::cout << "Promedios: " << std::endl;
            for (Estudiante estudiante: estudiantes ){
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
        Curso(std::string nombre, Profesor profesor, std::vector<Estudiante> estudiantes): 
        nombre(nombre), profesor(profesor), estudiantes(estudiantes) {
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

        void imprimirDatos() {
            std::cout << "Profesor: " << profesor.getNombre() << std::endl;
            std::cout << "Estudiantes: " << std::endl;
            for (Estudiante estudiante: estudiantes) {
                
                std::cout <<"- " << estudiante.getNombre() << std::endl;

            }
        }

};

int main() {
    /*
        Aca podes definir objetos en base a lo dado
        y utilizar sus metodos. Suerte
    */

    return 0; 
}
