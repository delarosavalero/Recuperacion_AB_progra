cmake_minimum_required(VERSION 3.10)
project(Recuperacion_AB_progra)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Establecer la ruta del proyecto
set(PROJECT_ROOT "C:\Users\danie\OneDrive\Escritorio\Recuperacion_AB_progra")

# Añadir el directorio de includes
include_directories(${PROJECT_ROOT}/include)

# Obtener todos los archivos fuente
file(GLOB SOURCES
    "${PROJECT_ROOT}/src/*.cpp"
)

# Crear el ejecutable
add_executable(hospital ${SOURCES})
