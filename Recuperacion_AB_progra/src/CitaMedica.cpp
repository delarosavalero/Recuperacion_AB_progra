#include "CitaMedica.h"

CitaMedica::CitaMedica(std::string _id, Paciente* _paciente, Medico* _medico,
    std::string _fechaHora, int _nivelUrgencia)
    : id(_id), paciente(_paciente), medico(_medico),
    fechaHora(_fechaHora), nivelUrgencia(_nivelUrgencia), completada(false) {}

std::string CitaMedica::getId() const {
    return id;
}

Paciente* CitaMedica::getPaciente() const {
    return paciente;
}

Medico* CitaMedica::getMedico() const {
    return medico;
}

std::string CitaMedica::getFechaHora() const {
    return fechaHora;
}

int CitaMedica::getNivelUrgencia() const {
    return nivelUrgencia;
}

bool CitaMedica::estaCompletada() const {
    return completada;
}

void CitaMedica::marcarComoCompletada() {
    completada = true;
}

void CitaMedica::reprogramarCita(std::string nuevaFechaHora) {
    fechaHora = nuevaFechaHora;
}

void CitaMedica::actualizarUrgencia(int nuevoNivel) {
    nivelUrgencia = nuevoNivel;
}