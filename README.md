Simulador de Gestión Hospitalaria
Este proyecto es un simulador de gestión hospitalaria desarrollado en C++ siguiendo los principios de programación orientada a objetos y técnicas de código limpio. El sistema permite administrar pacientes, médicos y citas médicas, generando reportes y almacenando la información en archivos.

Estructura del Proyecto
La estructura del proyecto es la siguiente:

Recuperacion_AB_progra/
├── CMakeLists.txt
├── include/
│   ├── GestionHospitalaria.hpp
│   ├── Paciente.hpp
│   ├── Medico.hpp
│   └── CitaMedica.hpp
└── src/
    ├── main.cpp
    ├── Paciente.cpp
    ├── Medico.cpp
    ├── CitaMedica.cpp
    └── GestionHospitalaria.cpp
include/: Contiene los archivos de cabecera (.hpp) con la definición de las clases.
src/: Contiene los archivos de implementación (.cpp) y el archivo principal main.cpp.
CMakeLists.txt: Archivo de configuración para compilar el proyecto con CMake.
Funcionalidades

El simulador permite:

Gestión de Pacientes: Agregar, buscar, actualizar y eliminar pacientes.
Gestión de Médicos: Agregar, buscar, actualizar y eliminar médicos.
Gestión de Citas: Agregar citas médicas.
Ordenar citas por fecha o por nivel de urgencia.
Cancelar citas.
Manejo de Archivos:

Guardar y cargar los datos en un archivo (datos_hospital.txt).
El programa presenta un menú interactivo en la terminal que permite al usuario seleccionar distintas operaciones.

Requisitos C++11 o superior.
CMake (versión 3.10 o superior).
Un compilador compatible (g++, clang++ o Visual Studio).
Instrucciones de Compilación y Ejecución
Clonar o descargar el proyecto en tu máquina.

Abrir una terminal en la raíz del proyecto.

Crear un directorio de compilación y navegar a él:
mkdir build
cd build

Generar los archivos de compilación con CMake:
cmake ..

Compilar el proyecto:
cmake --build .

Ejecutar el programa desde la terminal:
hospital.exe

En Linux/macOS:
./hospital

Uso del Programa
Al ejecutar el programa se mostrará un menú interactivo con las siguientes opciones:

Agregar Paciente: Permite registrar un nuevo paciente ingresando su ID, nombre, fecha de ingreso y historial clínico.
Agregar Médico: Permite registrar un nuevo médico ingresando su ID, nombre, especialidad y estado de disponibilidad.
Agregar Cita: Permite crear una cita médica asociando un paciente y un médico, ingresando la fecha y el nivel de urgencia.
Mostrar Citas Ordenadas por Fecha: Ordena y muestra las citas en función de la fecha (asegúrate de usar el formato "YYYY-MM-DD").
Guardar y Salir: Guarda los datos en el archivo datos_hospital.txt y finaliza la ejecución.

Notas Adicionales
Formato de fechas: Es importante ingresar las fechas en el formato "YYYY-MM-DD" para que la ordenación funcione correctamente.
Si el archivo datos_hospital.txt no existe, el programa iniciará sin datos previos.
Puedes extender la funcionalidad del programa, añadiendo opciones para actualizar o eliminar citas, pacientes o médicos.
Conclusión
Este proyecto es un ejemplo práctico de cómo aplicar conceptos de programación orientada a objetos, manejo de archivos y estructuras de datos en C++ para crear una aplicación funcional de gestión hospitalaria. Se han seguido principios de diseño como SOLID para garantizar una arquitectura modular y fácil de mantener.
