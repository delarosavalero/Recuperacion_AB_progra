#include "Medico.hpp"

Medico::Medico(int id, const std::string& nombre, const std::string& especialidad, bool disponible)
    : id(id), nombre(nombre), especialidad(especialidad), disponible(disponible) {}

int Medico::obtenerId() const { return id; }
std::string Medico::obtenerNombre() const { return nombre; }
std::string Medico::obtenerEspecialidad() const { return especialidad; }
bool Medico::estaDisponible() const { return disponible; }

void Medico::establecerNombre(const std::string& nombre) { this->nombre = nombre; }
void Medico::establecerEspecialidad(const std::string& especialidad) { this->especialidad = especialidad; }
void Medico::establecerDisponibilidad(bool disponible) { this->disponible = disponible; }
