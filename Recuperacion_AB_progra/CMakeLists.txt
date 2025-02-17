# CMakeList.txt: proyecto de CMake para Recuperacion_AB_progra, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (Recuperacion_AB_progra "Recuperacion_AB_progra.cpp" "Recuperacion_AB_progra.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Recuperacion_AB_progra PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
