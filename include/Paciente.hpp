#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>

class Paciente {
private:
    int id;
    std::string nombre;
    std::string fechaIngreso;
    std::string historialClinico;
public:
    Paciente(int id, const std::string& nombre, const std::string& fechaIngreso, const std::string& historialClinico);
    int obtenerId() const;
    std::string obtenerNombre() const;
    std::string obtenerFechaIngreso() const;
    std::string obtenerHistorialClinico() const;
    void establecerNombre(const std::string& nombre);
    void establecerFechaIngreso(const std::string& fecha);
    void establecerHistorialClinico(const std::string& historial);
};

#endif 
