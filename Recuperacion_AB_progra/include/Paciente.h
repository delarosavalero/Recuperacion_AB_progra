#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente {
private:
    std::string id;
    std::string nombre;
    std::string fechaNacimiento;
    std::string historiaMedica;

public:
    Paciente(std::string _id, std::string _nombre, std::string _fechaNacimiento);

    // Métodos get y set
    std::string getId() const;
    std::string getNombre() const;
    std::string getFechaNacimiento() const;
    std::string getHistoriaMedica() const;
    void actualizarInformacionPersonal(std::string nuevoNombre, std::string nuevaFechaNacimiento);
    void agregarRegistroMedico(std::string registro);
};

#endif 