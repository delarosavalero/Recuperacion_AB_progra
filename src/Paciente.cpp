#include "Paciente.hpp"

Paciente::Paciente(int id, const std::string& nombre, const std::string& fechaIngreso, const std::string& historialClinico)
    : id(id), nombre(nombre), fechaIngreso(fechaIngreso), historialClinico(historialClinico) {}

int Paciente::obtenerId() const { return id; }
std::string Paciente::obtenerNombre() const { return nombre; }
std::string Paciente::obtenerFechaIngreso() const { return fechaIngreso; }
std::string Paciente::obtenerHistorialClinico() const { return historialClinico; }

void Paciente::establecerNombre(const std::string& nombre) { this->nombre = nombre; }
void Paciente::establecerFechaIngreso(const std::string& fecha) { this->fechaIngreso = fecha; }
void Paciente::establecerHistorialClinico(const std::string& historial) { this->historialClinico = historial; }
