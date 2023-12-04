#ifndef CLASE_H
#define CLASE_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    int id;
    double salarioBase;
    double bonos;
    double deducciones;

public:
    Empleado(string _nombre, int _id, double _salarioBase, double _bonos, double _deducciones)
        : nombre(_nombre), id(_id), salarioBase(_salarioBase), bonos(_bonos), deducciones(_deducciones) {}

    void modificarNombre(const string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    void modificarSalarioBase(double nuevoSalarioBase) {
        salarioBase = nuevoSalarioBase;
    }

    void modificarBonos(double nuevosBonos) {
        bonos = nuevosBonos;
    }

    void modificarDeducciones(double nuevasDeducciones) {
        deducciones = nuevasDeducciones;
    }

    double calcularSalarioNeto() const {
        return salarioBase + bonos - deducciones;
    }

    void mostrarInformacion() const {
        cout << "ID: " << id << ", Nombre: " << nombre
             << ", Salario Base: " << salarioBase
             << ", Bonos: " << bonos
             << ", Deducciones: " << deducciones
             << ", Salario Neto: " << calcularSalarioNeto() << endl;
    }

    int getId() const {
        return id;
    }
};

class SistemaNomina {
private:
    list<Empleado> empleados;

public:
    void agregarEmpleado(const Empleado& empleado) {
        empleados.push_back(empleado);
    }

    void eliminarEmpleado(int idEmpleado) {
        for (list<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ) {
            if (it->getId() == idEmpleado) {
                it = empleados.erase(it);
            } else {
                ++it;
            }
        }
    }

    void modificarEmpleado(int idEmpleado) {
        for (list<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
            if (it->getId() == idEmpleado) {
                string nuevoNombre;
                double nuevoSalarioBase, nuevosBonos, nuevasDeducciones;

                cout << "Nuevo nombre del empleado: ";
                cin >> nuevoNombre;
                it->modificarNombre(nuevoNombre);

                cout << "Nuevo salario base: ";
                cin >> nuevoSalarioBase;
                it->modificarSalarioBase(nuevoSalarioBase);

                cout << "Nuevos bonos: ";
                cin >> nuevosBonos;
                it->modificarBonos(nuevosBonos);

                cout << "Nuevas deducciones: ";
                cin >> nuevasDeducciones;
                it->modificarDeducciones(nuevasDeducciones);

                cout << "Datos del empleado actualizados." << endl;
                return;
            }
        }
        cout << "Empleado no encontrado" << endl;
    }

    void mostrarTodosLosEmpleados() const {
        for (list<Empleado>::const_iterator it = empleados.begin(); it != empleados.end(); ++it) {
            it->mostrarInformacion();
        }
    }
};

bool verificarContrasena(const string& contrasena) {
    return contrasena == "12345";
}

#endif // CLASE_H

