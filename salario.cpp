#include <iostream>
#include <string>
#include "clase.h"
#include "iostream"

using namespace std;

int main() {
    string contrasena;
    cout << "Contraseña: ";
    cin >> contrasena;

    if (!verificarContrasena(contrasena)) {
        cout << "Contraseña incorrecta" << endl;
        return 1;
    }

    SistemaNomina sistema;
    int opcion;
    do {
        cout << "1. Agregar empleado\n";
        cout << "2. Eliminar empleado\n";
        cout << "3. Mostrar los empleados\n";
        cout << "4. Modificar empleado\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int id;
                double salarioBase, bonos, deducciones;
                cout << "Nombre del empleado: ";
                cin >> nombre;
                cout << "ID del empleado: ";
                cin >> id;
                cout << "Salario base del empleado: ";
                cin >> salarioBase;
                cout << "Bonos del empleado: ";
                cin >> bonos;
                cout << "Deducciones del empleado: ";
                cin >> deducciones;
                Empleado nuevoEmpleado(nombre, id, salarioBase, bonos, deducciones);
                sistema.agregarEmpleado(nuevoEmpleado);
                break;
            }
            case 2: {
                int id;
                cout << "ID del empleado a eliminar: ";
                cin >> id;
                sistema.eliminarEmpleado(id);
                break;
            }
            case 3: {
                sistema.mostrarTodosLosEmpleados();
                break;
            }
            case 4: {
                int id;
                cout << "ID del empleado a modificar: ";
                cin >> id;
                sistema.modificarEmpleado(id);
                break;
            }
            case 5: {
                cout << "Saliendo del sistema" << endl;
                break;
            }
            default: {
                cout << "Opción incorrecta, intente otra vez" << endl;
            }
        }
    } while (opcion != 5);

    return 0;
}
