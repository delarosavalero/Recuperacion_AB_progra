#ifndef GESTIONHOSPITALARIA_HPP
#define GESTIONHOSPITALARIA_HPP

#include <vector>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"

class GestionHospitalaria {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<CitaMedica> citas;
public:
    GestionHospitalaria();

    // Gestión de Pacientes
    void agregarPaciente(const Paciente& paciente);
    bool eliminarPaciente(int idPaciente);
    bool actualizarPaciente(int idPaciente, const std::string& nombre, const std::string& fechaIngreso, const std::string& historialClinico);
    Paciente* buscarPacientePorId(int idPaciente);
    std::vector<Paciente> buscarPacientePorNombre(const std::string& nombre);

    // Gestión de Médicos
    void agregarMedico(const Medico& medico);
    bool eliminarMedico(int idMedico);
    bool actualizarMedico(int idMedico, const std::string& nombre, const std::string& especialidad, bool disponible);
    Medico* buscarMedicoPorId(int idMedico);
    std::vector<Medico> buscarMedicoPorEspecialidad(const std::string& especialidad);

    // Gestión de Citas
    void agregarCita(const CitaMedica& cita);
    bool cancelarCita(int idCita);
    bool actualizarCita(int idCita, const std::string& nuevaFecha, int nuevaUrgencia);
    CitaMedica* buscarCitaPorId(int idCita);
    std::vector<CitaMedica> obtenerCitasOrdenadasPorFecha();
    std::vector<CitaMedica> obtenerCitasOrdenadasPorUrgencia();

    // Manejo de Archivos
    bool guardarDatosEnArchivo(const std::string& nombreArchivo);
    bool cargarDatosDesdeArchivo(const std::string& nombreArchivo);

    // Generación de Reportes
    std::vector<Paciente> obtenerPacientesPorFechaIngreso(const std::string& fechaInicio, const std::string& fechaFin);
    std::vector<CitaMedica> obtenerCitasPendientesPorMedico(int idMedico);
};

#endif 
