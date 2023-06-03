# Actividad Practica Numero 4

![banner](https://i.imgur.com/An11jdH.png)

Esta actividad se  basara principalmente en Programacion Orientada a Objetos (POO), originalmente en ingles, Object-oriented programming (OOP).

-----

## Crea una clase **Persona**

1. **📄 Atributos:**
   - Nombre: `String`
   - Edad: `Int`
   - DNI: `Int`
2. **🛠️ Metodos:**
   - **🔐 Obtener**:
      - Nombre `getNombre`
      - Edad `getEdad`
      - DNI `getDNI`
   - **✏️ Establecer:**
      - Nombre `setNombre`
      - Edad `setEdad`
      - DNI `setDNI`
   - **📜 Imprimir**:
      - Todos los datos `imprimirDatos`

-----

## Crea una clase **Estudiante**

1. **🧬 Hereda de Persona**
2. **📄 Atributos:**
   - Carrera: `String`
   - Notas: `vector<float>`
3. **🛠️ Metodos:**
   - **🔐 Obtener**:
      - Carrera `getCarrera`
      - Promedio `calcularPromedio`
   - **✏️ Establecer:**
      - Carrera `setCarrera`
   - **📜 Imprimir**:
      - Todos los datos `imprimirDatos`

-----

## Crea una clase **Profesor**

1. **🧬 Hereda de Persona**
2. **📄 Atributos:**
   - Area: `String`
   - Estudiantes: `vector<Estudiante>`
3. **🛠️ Metodos:**
   - **🔐 Obtener**:
     - Area `getArea`
   - **✏️ Establecer**:
     - Area `setArea`
   - **📜 Imprimir**:
     - Todos los datos `imprimirDatos`
     - Todos los promedios `imprimirPromedios`

-----

## Crea una clase **Curso**

> 💡 **¡Felicitaciones! 🎉** Haz finalizado con las herencias. ahora crearemos una clase que es El curso, que contendra todas las clases anteriores

1. **📄 Atributos:**
   - Nombre: `String`
   - Profesor: `Profesor`
   - Estudiantes: `vector<Estudiante>`
2. **🛠️ Metodos:**
   - **🔐 Obtener**:
      - Nombre `getNombre`
      - Profesor `getProfesor`
   - **✏️ Establecer**:
      - Agregar Estudiante: `agregarEstudiante`
      - Eliminar Estudiante: `eliminarEstudiante`
   - **📜 Imprimir**:
      - Todos los datos `imprimirDatos` (Esto incluye los estudiantes, haz volar tu imaginacion)

-----

## 💡 Aclaraciones

> La funcion principal (`main`) ira cambiando a medida de la clase para ir mostrando las funciones de cada clase por lo tanto en el archivo de solucion, la funcion main, esta vacia, para que ustedes usen como quieran la misma.

Sin nada mas que decir, Agradecemos tu presencia y aguante durante todas estas clases.

### 💡 ¿Queres Practicar?

Si es asi, te hemos dejado un archivo ([`tarea.md`](tarea.md)) para que ustedes practiquen por su cuenta. Agradezcan a Nico por dejarles este Archivo.

_Archivo creado por Lucho en colaboracion con Nico._

-----
![gracias](https://i.imgur.com/fdQzEGg.gif)
