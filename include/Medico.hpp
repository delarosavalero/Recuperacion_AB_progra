#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>

class Medico {
private:
    int id;
    std::string nombre;
    std::string especialidad;
    bool disponible;
public:
    Medico(int id, const std::string& nombre, const std::string& especialidad, bool disponible = true);
    int obtenerId() const;
    std::string obtenerNombre() const;
    std::string obtenerEspecialidad() const;
    bool estaDisponible() const;
    void establecerNombre(const std::string& nombre);
    void establecerEspecialidad(const std::string& especialidad);
    void establecerDisponibilidad(bool disponible);
};

#endif 
