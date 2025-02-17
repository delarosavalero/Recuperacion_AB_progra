#include "GestionHospitalaria.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

GestionHospitalaria::GestionHospitalaria() {}

// Gestión de Pacientes
void GestionHospitalaria::agregarPaciente(const Paciente& paciente) {
    pacientes.push_back(paciente);
}

bool GestionHospitalaria::eliminarPaciente(int idPaciente) {
    auto it = std::remove_if(pacientes.begin(), pacientes.end(), [idPaciente](const Paciente& p) {
        return p.obtenerId() == idPaciente;
        });
    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        return true;
    }
    return false;
}

bool GestionHospitalaria::actualizarPaciente(int idPaciente, const std::string& nombre, const std::string& fechaIngreso, const std::string& historialClinico) {
    for (auto& p : pacientes) {
        if (p.obtenerId() == idPaciente) {
            p.establecerNombre(nombre);
            p.establecerFechaIngreso(fechaIngreso);
            p.establecerHistorialClinico(historialClinico);
            return true;
        }
    }
    return false;
}

Paciente* GestionHospitalaria::buscarPacientePorId(int idPaciente) {
    for (auto& p : pacientes) {
        if (p.obtenerId() == idPaciente)
            return &p;
    }
    return nullptr;
}

std::vector<Paciente> GestionHospitalaria::buscarPacientePorNombre(const std::string& nombre) {
    std::vector<Paciente> resultado;
    for (auto& p : pacientes) {
        if (p.obtenerNombre().find(nombre) != std::string::npos)
            resultado.push_back(p);
    }
    return resultado;
}

// Gestión de Médicos
void GestionHospitalaria::agregarMedico(const Medico& medico) {
    medicos.push_back(medico);
}

bool GestionHospitalaria::eliminarMedico(int idMedico) {
    auto it = std::remove_if(medicos.begin(), medicos.end(), [idMedico](const Medico& m) {
        return m.obtenerId() == idMedico;
        });
    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        return true;
    }
    return false;
}

bool GestionHospitalaria::actualizarMedico(int idMedico, const std::string& nombre, const std::string& especialidad, bool disponible) {
    for (auto& m : medicos) {
        if (m.obtenerId() == idMedico) {
            m.establecerNombre(nombre);
            m.establecerEspecialidad(especialidad);
            m.establecerDisponibilidad(disponible);
            return true;
        }
    }
    return false;
}

Medico* GestionHospitalaria::buscarMedicoPorId(int idMedico) {
    for (auto& m : medicos) {
        if (m.obtenerId() == idMedico)
            return &m;
    }
    return nullptr;
}

std::vector<Medico> GestionHospitalaria::buscarMedicoPorEspecialidad(const std::string& especialidad) {
    std::vector<Medico> resultado;
    for (auto& m : medicos) {
        if (m.obtenerEspecialidad() == especialidad)
            resultado.push_back(m);
    }
    return resultado;
}

// Gestión de Citas
void GestionHospitalaria::agregarCita(const CitaMedica& cita) {
    citas.push_back(cita);
}

bool GestionHospitalaria::cancelarCita(int idCita) {
    for (auto& c : citas) {
        if (c.obtenerIdCita() == idCita) {
            c.cancelar();
            return true;
        }
    }
    return false;
}

bool GestionHospitalaria::actualizarCita(int idCita, const std::string& nuevaFecha, int nuevaUrgencia) {
    for (auto& c : citas) {
        if (c.obtenerIdCita() == idCita) {
            // Para simplificar, se cancela la cita antigua y se podría crear una nueva
            c.cancelar();
            return true;
        }
    }
    return false;
}

CitaMedica* GestionHospitalaria::buscarCitaPorId(int idCita) {
    for (auto& c : citas) {
        if (c.obtenerIdCita() == idCita)
            return &c;
    }
    return nullptr;
}

std::vector<CitaMedica> GestionHospitalaria::obtenerCitasOrdenadasPorFecha() {
    std::vector<CitaMedica> citasOrdenadas = citas;
    std::sort(citasOrdenadas.begin(), citasOrdenadas.end(), [](const CitaMedica& c1, const CitaMedica& c2) {
        return c1.obtenerFecha() < c2.obtenerFecha();
        });
    return citasOrdenadas;
}

std::vector<CitaMedica> GestionHospitalaria::obtenerCitasOrdenadasPorUrgencia() {
    std::vector<CitaMedica> citasOrdenadas = citas;
    std::sort(citasOrdenadas.begin(), citasOrdenadas.end(), [](const CitaMedica& c1, const CitaMedica& c2) {
        return c1.obtenerUrgencia() < c2.obtenerUrgencia();
        });
    return citasOrdenadas;
}

// Manejo de Archivos
bool GestionHospitalaria::guardarDatosEnArchivo(const std::string& nombreArchivo) {
    std::ofstream ofs(nombreArchivo);
    if (!ofs) return false;

    // Guardar pacientes
    ofs << pacientes.size() << "\n";
    for (auto& p : pacientes) {
        ofs << p.obtenerId() << ";" << p.obtenerNombre() << ";" << p.obtenerFechaIngreso() << ";" << p.obtenerHistorialClinico() << "\n";
    }

    // Guardar médicos
    ofs << medicos.size() << "\n";
    for (auto& m : medicos) {
        ofs << m.obtenerId() << ";" << m.obtenerNombre() << ";" << m.obtenerEspecialidad() << ";" << m.estaDisponible() << "\n";
    }

    // Guardar citas
    ofs << citas.size() << "\n";
    for (auto& c : citas) {
        ofs << c.obtenerIdCita() << ";"
            << c.obtenerPaciente().obtenerId() << ";"
            << c.obtenerMedico().obtenerId() << ";"
            << c.obtenerFecha() << ";"
            << c.obtenerUrgencia() << ";"
            << c.estaActiva() << "\n";
    }

    ofs.close();
    return true;
}

bool GestionHospitalaria::cargarDatosDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream ifs(nombreArchivo);
    if (!ifs) return false;

    pacientes.clear();
    medicos.clear();
    citas.clear();

    size_t numPacientes;
    ifs >> numPacientes;
    ifs.ignore();
    for (size_t i = 0; i < numPacientes; i++) {
        std::string linea;
        std::getline(ifs, linea);
        std::istringstream iss(linea);
        std::string token;
        int id;
        std::string nombre, fecha, historial;
        if (std::getline(iss, token, ';')) id = std::stoi(token);
        if (std::getline(iss, token, ';')) nombre = token;
        if (std::getline(iss, token, ';')) fecha = token;
        if (std::getline(iss, token, ';')) historial = token;
        pacientes.push_back(Paciente(id, nombre, fecha, historial));
    }

    size_t numMedicos;
    ifs >> numMedicos;
    ifs.ignore();
    for (size_t i = 0; i < numMedicos; i++) {
        std::string linea;
        std::getline(ifs, linea);
        std::istringstream iss(linea);
        std::string token;
        int id;
        std::string nombre, especialidad;
        bool disponible;
        if (std::getline(iss, token, ';')) id = std::stoi(token);
        if (std::getline(iss, token, ';')) nombre = token;
        if (std::getline(iss, token, ';')) especialidad = token;
        if (std::getline(iss, token, ';')) disponible = std::stoi(token);
        medicos.push_back(Medico(id, nombre, especialidad, disponible));
    }

    size_t numCitas;
    ifs >> numCitas;
    ifs.ignore();
    for (size_t i = 0; i < numCitas; i++) {
        std::string linea;
        std::getline(ifs, linea);
        std::istringstream iss(linea);
        std::string token;
        int idCita, idPaciente, idMedico, urgencia;
        std::string fecha;
        bool activa;
        if (std::getline(iss, token, ';')) idCita = std::stoi(token);
        if (std::getline(iss, token, ';')) idPaciente = std::stoi(token);
        if (std::getline(iss, token, ';')) idMedico = std::stoi(token);
        if (std::getline(iss, token, ';')) fecha = token;
        if (std::getline(iss, token, ';')) urgencia = std::stoi(token);
        if (std::getline(iss, token, ';')) activa = std::stoi(token);
        Paciente* ptrPaciente = buscarPacientePorId(idPaciente);
        Medico* ptrMedico = buscarMedicoPorId(idMedico);
        if (ptrPaciente && ptrMedico) {
            CitaMedica cita(idCita, *ptrPaciente, *ptrMedico, fecha, urgencia);
            if (!activa) cita.cancelar();
            citas.push_back(cita);
        }
    }

    ifs.close();
    return true;
}

// Generación de Reportes
std::vector<Paciente> GestionHospitalaria::obtenerPacientesPorFechaIngreso(const std::string& fechaInicio, const std::string& fechaFin) {
    std::vector<Paciente> resultado;
    // Suponiendo formato YYYY-MM-DD, se comparan las cadenas
    for (auto& p : pacientes) {
        if (p.obtenerFechaIngreso() >= fechaInicio && p.obtenerFechaIngreso() <= fechaFin) {
            resultado.push_back(p);
        }
    }
    return resultado;
}

std::vector<CitaMedica> GestionHospitalaria::obtenerCitasPendientesPorMedico(int idMedico) {
    std::vector<CitaMedica> resultado;
    for (auto& c : citas) {
        if (c.obtenerMedico().obtenerId() == idMedico && c.estaActiva()) {
            resultado.push_back(c);
        }
    }
    return resultado;
}
