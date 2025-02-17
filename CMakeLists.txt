cmake_minimum_required(VERSION 3.10)
project(Recuperacion_AB_progra LANGUAGES CXX)

# Establecer el estándar de C++ a C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Agregar los archivos fuente
set(SOURCES
    src/main.cpp
    src/Paciente.cpp
    src/Medico.cpp
    src/CitaMedica.cpp
    src/GestionHospitalaria.cpp
)

# Crear el ejecutable
add_executable(hospital ${SOURCES})
