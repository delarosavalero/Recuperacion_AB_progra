#include "Medico.h"

Medico::Medico(std::string _id, std::string _nombre, std::string _especialidad)
    : id(_id), nombre(_nombre), especialidad(_especialidad), disponible(true) {}

std::string Medico::getId() const {
    return id;
}

std::string Medico::getNombre() const {
    return nombre;
}

std::string Medico::getEspecialidad() const {
    return especialidad;
}

bool Medico::verificarDisponibilidad() const {
    return disponible;
}

void Medico::establecerDisponibilidad(bool estado) {
    disponible = estado;
}