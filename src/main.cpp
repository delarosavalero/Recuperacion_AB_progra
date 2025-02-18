#include <iostream>
#include <limits>
#include "GestionHospitalaria.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include "CitaMedica.hpp"

int main() {
    GestionHospitalaria gh;

    // Intentar cargar datos previos desde el archivo (si existe)
    if (gh.cargarDatosDesdeArchivo("datos_hospital.txt")) {
        std::cout << "Datos cargados desde el archivo exitosamente.\n";
    }
    else {
        std::cout << "No se pudo cargar datos o el archivo no existe.\n";
    }

    bool salir = false;
    while (!salir) {
        std::cout << "\n--- MENU PRINCIPAL ---\n"
            << "1. Agregar Paciente\n"
            << "2. Agregar Medico\n"
            << "3. Agregar Cita\n"
            << "4. Mostrar Citas Ordenadas por Fecha\n"
            << "5. Guardar y Salir\n"
            << "Opcion: ";

        int opcion;
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer

        switch (opcion) {
        case 1: {
            // Agregar Paciente
            int id;
            std::string nombre, fechaIngreso, historial;
            std::cout << "ID del paciente: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Nombre del paciente: ";
            std::getline(std::cin, nombre);
            std::cout << "Fecha de ingreso (YYYY-MM-DD): ";
            std::getline(std::cin, fechaIngreso);
            std::cout << "Historial clinico: ";
            std::getline(std::cin, historial);

            Paciente p(id, nombre, fechaIngreso, historial);
            gh.agregarPaciente(p);
            std::cout << "Paciente agregado.\n";
            break;
        }
        case 2: {
            // Agregar Medico
            int id;
            std::string nombre, especialidad;
            int disp; // 1 para sí, 0 para no
            std::cout << "ID del medico: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Nombre del medico: ";
            std::getline(std::cin, nombre);
            std::cout << "Especialidad: ";
            std::getline(std::cin, especialidad);
            std::cout << "¿Esta disponible? (1 = Sí, 0 = No): ";
            std::cin >> disp;
            std::cin.ignore();

            Medico m(id, nombre, especialidad, disp == 1);
            gh.agregarMedico(m);
            std::cout << "Medico agregado.\n";
            break;
        }
        case 3: {
            // Agregar Cita
            int idCita, idPaciente, idMedico, urgencia;
            std::string fecha;
            std::cout << "ID de la cita: ";
            std::cin >> idCita;
            std::cout << "ID del paciente: ";
            std::cin >> idPaciente;
            std::cout << "ID del medico: ";
            std::cin >> idMedico;
            std::cout << "Fecha de la cita (YYYY-MM-DD): ";
            std::cin >> fecha;
            std::cout << "Nivel de urgencia (valor numerico, menor = mas urgente): ";
            std::cin >> urgencia;
            std::cin.ignore();

            Paciente* p = gh.buscarPacientePorId(idPaciente);
            Medico* m = gh.buscarMedicoPorId(idMedico);
            if (p && m) {
                CitaMedica c(idCita, *p, *m, fecha, urgencia);
                gh.agregarCita(c);
                std::cout << "Cita agregada.\n";
            } else {
                std::cout << "No se encontro el paciente o el medico.\n";
            }
            break;
        }
        case 4: {
            // Mostrar Citas Ordenadas por Fecha
            std::cout << "Iniciando ordenacion de citas...\n";
            auto citasOrdenadas = gh.obtenerCitasOrdenadasPorFecha();
            std::cout << "Ordenacion completada.\n";
            if (citasOrdenadas.empty()) {
                std::cout << "No hay citas para mostrar.\n";
            } else {
                std::cout << "\nCitas ordenadas por fecha:\n";
                for (auto& c : citasOrdenadas) {
                    std::cout << "Cita ID: " << c.obtenerIdCita()
                              << "  Fecha: " << c.obtenerFecha() << "\n";
                }
            }
            break;
        }
        case 5: {
            // Guardar datos y salir
            if (gh.guardarDatosEnArchivo("datos_hospital.txt"))
                std::cout << "Datos guardados exitosamente.\n";
            else
                std::cout << "Error al guardar datos.\n";
            salir = true;
            break;
        }
        default:
            std::cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    }

    std::cout << "Presiona una tecla para salir...\n";
    system("pause");
    return 0;
}


