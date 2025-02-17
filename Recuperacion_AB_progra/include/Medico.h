#ifndef MEDICO_H
#define MEDICO_H

#include <string>


class Medico {
private:
    std::string id;
    std::string nombre;
    std::string especialidad;
    bool disponible;

public:
    Medico(std::string _id, std::string _nombre, std::string _especialidad);

    std::string getId() const;
    std::string getNombre() const;
    std::string getEspecialidad() const;
    bool verificarDisponibilidad() const;
    void establecerDisponibilidad(bool estado);
};

#endif