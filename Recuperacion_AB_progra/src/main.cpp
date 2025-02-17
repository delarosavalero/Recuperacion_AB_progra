﻿#include <iostream>
#include "Paciente.h"
#include "Medico.h"
#include "CitaMedica.h"
#include <vector>

int main() {
    // Crear algunos pacientes
    Paciente* paciente1 = new Paciente("P001", "Juan Perez", "1990-05-15");
    paciente1->agregarRegistroMedico("Alergico a la penicilina");

    Paciente* paciente2 = new Paciente("P002", "Maria Gomez", "1985-11-22");
    paciente2->agregarRegistroMedico("Diabetes tipo 2");

    // Crear algunos médicos
    Medico* medico1 = new Medico("M001", "Dr. Garcia", "Cardiologia");
    Medico* medico2 = new Medico("M002", "Dra. Martinez", "Neurologia");

    // Crear algunas citas médicas
    std::vector<CitaMedica*> citas;

    CitaMedica* cita1 = new CitaMedica("C001", paciente1, medico1, "2025-02-15 10:00", 3);
    CitaMedica* cita2 = new CitaMedica("C002", paciente2, medico2, "2025-02-16 14:30", 5);

    citas.push_back(cita1);
    citas.push_back(cita2);
        
    // Mostrar información de las citas
    for (const auto& cita : citas) {
        std::cout << "------------------------" << std::endl;
        std::cout << "Cita ID: " << cita->getId() << std::endl;
        std::cout << "Paciente: " << cita->getPaciente()->getNombre() << std::endl;
        std::cout << "Medico: " << cita->getMedico()->getNombre() << std::endl;
        std::cout << "Fecha y Hora: " << cita->getFechaHora() << std::endl;
        std::cout << "Nivel de Urgencia: " << cita->getNivelUrgencia() << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    // Liberar memoria
    delete paciente1;
    delete paciente2;
    delete medico1;
    delete medico2;
    for (auto cita : citas) {
        delete cita;
    }

    return 0;
}