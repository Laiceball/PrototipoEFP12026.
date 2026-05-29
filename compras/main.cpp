#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <windows.h>
#include "usuario.h"
#include "menu_general.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string nombreUsuario, contrasena;
    int opcionLogin;

    do {
        cout << "\n=== SISTEMA DE GESTIÓN INTEGRADO ===" << endl;
        cout << "1. Registrar nuevo usuario" << endl;
        cout << "2. Iniciar sesión" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcionLogin;
        cin.ignore();

        switch(opcionLogin) {
            case 1: {
                cout << "Ingrese nombre de usuario: ";
                getline(cin, nombreUsuario);
                cout << "Ingrese contraseña: ";
                getline(cin, contrasena);
                Usuario::registrarUsuario(nombreUsuario, contrasena);
                break;
            }
            case 2: {
                bool sesionExitosa = false;
                int intentos = 0;

                while (!sesionExitosa && intentos < 3) {
                    cout << "Ingrese nombre de usuario: ";
                    getline(cin, nombreUsuario);
                    cout << "Ingrese contraseña: ";
                    getline(cin, contrasena);

                    if (Usuario::iniciarSesion(nombreUsuario, contrasena)) {
                        sesionExitosa = true;
                        cout << "\n¡Bienvenido " << nombreUsuario << "!" << endl;
                        mostrarMenuGeneral();
                    } else {
                        intentos++;
                        cout << " Usuario o contraseña incorrectos. ";
                        if (intentos < 3) {
                            cout << "Intentos restantes: " << 3 - intentos << endl;
                        } else {
                            cout << "Has excedido el número de intentos." << endl;
                        }
                    }
                }
                break;
            }
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << " Opción no válida. Intente nuevamente." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (opcionLogin != 3);

    return 0;
}
