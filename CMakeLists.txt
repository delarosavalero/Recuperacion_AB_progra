cmake_minimum_required(VERSION 3.10)
project(Recuperacion_AB_progra )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Definir rutas de directorios
include_directories(${PROJECT_SOURCE_DIR}/include)
#set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
#set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


# Lista de archivos fuente
#set(SOURCES
#    ${SRC_DIR}/main.cpp
#    ${SRC_DIR}/Paciente.cpp
#    ${SRC_DIR}/Medico.cpp
#    ${SRC_DIR}/CitaMedica.cpp
#     ${SRC_DIR}/GestionHospitalaria.cpp
#)

# Crear el ejecutable
add_executable(Recuperacion_AB_progra #${SOURCES}
	src/main.cpp
	src/Paciente.cpp 
	src/Medico.cpp 
	src/CitaMedica.cpp 
	src/GestionHospitalaria.cpp 

)

# Incluir el directorio de cabeceras
#target_include_directories(hospital PRIVATE ${INCLUDE_DIR})





