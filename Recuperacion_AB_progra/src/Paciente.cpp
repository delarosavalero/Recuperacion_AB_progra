#include "Paciente.h"
#include <iostream>
#include <fstream>

Paciente::Paciente(std::string _id, std::string _nombre, std::string _fechaNacimiento)
    : id(_id), nombre(_nombre), fechaNacimiento(_fechaNacimiento) {}

std::string Paciente::getId() const {
    return id;
}

std::string Paciente::getNombre() const {
    return nombre;
}

std::string Paciente::getFechaNacimiento() const {
    return fechaNacimiento;
}

std::string Paciente::getHistoriaMedica() const {
    return historiaMedica;
}

void Paciente::actualizarInformacionPersonal(std::string nuevoNombre, std::string nuevaFechaNacimiento) {
    nombre = nuevoNombre;
    fechaNacimiento = nuevaFechaNacimiento;
}

void Paciente::agregarRegistroMedico(std::string registro) {
    historiaMedica += registro + "\n";
}

void Paciente::buscarPorNombre(const std::string& nombre) const {
    if (this->nombre.find(nombre) != std::string::npos) {
        this->mostrarPaciente();
    }
}