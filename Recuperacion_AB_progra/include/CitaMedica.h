#ifndef CITA_MEDICA_H
#define CITA_MEDICA_H

#include <string>
#include "Paciente.h"
#include "Medico.h"

class CitaMedica {
private:
    std::string id;
    Paciente* paciente;
    Medico* medico;
    std::string fechaHora;
    int nivelUrgencia;
    bool completada;

public:
    CitaMedica(std::string _id, Paciente* _paciente, Medico* _medico,
        std::string _fechaHora, int _nivelUrgencia);

    std::string getId() const;
    Paciente* getPaciente() const;
    Medico* getMedico() const;
    std::string getFechaHora() const;
    int getNivelUrgencia() const;
    bool estaCompletada() const;

    void marcarComoCompletada();
    void reprogramarCita(std::string nuevaFechaHora);
    void actualizarUrgencia(int nuevoNivel);
};

#endif // CITA_MEDICA_H