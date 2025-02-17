#include "CitaMedica.hpp"

CitaMedica::CitaMedica(int idCita, const Paciente& paciente, const Medico& medico, const std::string& fecha, int urgencia)
    : idCita(idCita), paciente(paciente), medico(medico), fecha(fecha), urgencia(urgencia), activa(true) {}

int CitaMedica::obtenerIdCita() const { return idCita; }
Paciente CitaMedica::obtenerPaciente() const { return paciente; }
Medico CitaMedica::obtenerMedico() const { return medico; }
std::string CitaMedica::obtenerFecha() const { return fecha; }
int CitaMedica::obtenerUrgencia() const { return urgencia; }
bool CitaMedica::estaActiva() const { return activa; }
void CitaMedica::cancelar() { activa = false; }
