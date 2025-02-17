#ifndef CITAMEDICA_HPP
#define CITAMEDICA_HPP

#include <string>
#include "Paciente.hpp"
#include "Medico.hpp"

class CitaMedica {
private:
    int idCita;
    Paciente paciente;
    Medico medico;
    std::string fecha;
    int urgencia; // Un valor numérico para la urgencia (cuanto menor, mayor urgencia)
    bool activa;  // Estado activa o cancelada de la cita
public:
    CitaMedica(int idCita, const Paciente& paciente, const Medico& medico, const std::string& fecha, int urgencia);
    int obtenerIdCita() const;
    Paciente obtenerPaciente() const;
    Medico obtenerMedico() const;
    std::string obtenerFecha() const;
    int obtenerUrgencia() const;
    bool estaActiva() const;
    void cancelar();
};

#endif 
