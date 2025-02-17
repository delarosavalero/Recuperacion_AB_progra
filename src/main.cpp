#include <iostream>
#include "GestionHospitalaria.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"

int main() {
    GestionHospitalaria gh;

    // Agregar algunos pacientes
    Paciente p1(1, "Juan Perez", "2024-10-01", "Historial: Ninguna complicación.");
    Paciente p2(2, "Maria Lopez", "2024-10-05", "Historial: Diabetes.");
    gh.agregarPaciente(p1);
    gh.agregarPaciente(p2);

    // Agregar algunos médicos
    Medico m1(1, "Dr. Smith", "Cardiología", true);
    Medico m2(2, "Dr. Gomez", "Endocrinología", true);
    gh.agregarMedico(m1);
    gh.agregarMedico(m2);

    // Agregar una cita médica
    CitaMedica c1(1, p1, m1, "2024-10-10", 1);
    gh.agregarCita(c1);

    // Mostrar citas ordenadas por fecha
    std::cout << "Citas ordenadas por fecha:" << std::endl;
    auto citasPorFecha = gh.obtenerCitasOrdenadasPorFecha();
    for (auto& c : citasPorFecha) {
        std::cout << "Cita ID: " << c.obtenerIdCita() << "  Fecha: " << c.obtenerFecha() << std::endl;
    }

    // Guardar datos en archivo
    if (gh.guardarDatosEnArchivo("datos_hospital.txt")) {
        std::cout << "Datos guardados exitosamente." << std::endl;
    }
    else {
        std::cout << "Error al guardar datos." << std::endl;
    }

    std::cout << "Presiona una tecla para salir..." << std::endl;
    system("pause");
    return 0;
}

