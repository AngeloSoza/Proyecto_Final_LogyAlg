#include <iostream>
#include <string>

using namespace std;

const int NUM_MESAS = 14;
const int SILLAS_POR_MESA = 4;

struct Reserva {
    string nombre;
    int mesa;
    int numSillas;
};

Reserva reservas[NUM_MESAS];

void mostrarMesasDisponibles() {
    cout << "Mesas disponibles:" << endl;
    for (int i = 0; i < NUM_MESAS; i++) {
        if (reservas[i].nombre.empty()) {
            cout << "Mesa " << i + 1 << " - Disponible" << endl;
        }
    }
}

void hacerReserva() {
    char nombre[100];
    int mesa;
    int numSillas;

 mostrarMesasDisponibles();

    cout << "A que nombre desea hacer la reserva?";
    scanf(" %[^\n]", nombre); 
    cout << "Ingrese el numero de mesa deseada (1-" << NUM_MESAS << "): ";
    cin >> mesa;
    mesa--; 

    if (reservas[mesa].nombre.empty()) {
        cout << "Ingrese el numero de sillas requeridas (1-" << SILLAS_POR_MESA << "): ";
        cin >> numSillas;

        if (numSillas <= SILLAS_POR_MESA) {
            reservas[mesa] = {nombre, mesa + 1, numSillas};
            cout << "Reserva realizada con exito. Mesa " << mesa + 1 << " Reservada para " << nombre << endl;
        } else {
            cout << "Error: numero de sillas requeridas excede la capacidad de la mesa." << endl;
        }
    } else {
        cout << "Error: mesa no disponible." << endl;
    }
}

void mostrarReservas() {
    cout << "Reservas actuales:" << endl;
    for (int i = 0; i < NUM_MESAS; i++) {
        if (!reservas[i].nombre.empty()) {
            cout << "Mesa " << reservas[i].mesa << " - " << reservas[i].nombre << " (" << reservas[i].numSillas << " sillas)" << endl;
        }
    }
}

int MesasR() {
    int opcion;

    do {
        cout << " Sistema de reserva del restaurante: " << endl;
        cout << "---------------------------" << endl;
        cout << "1. Mostrar mesas disponibles" << endl;
        cout << "2. Hacer reserva" << endl;
        cout << "3. Mostrar reservas actuales" << endl;
        cout << "4. Salir\n" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarMesasDisponibles();
                break;
            case 2:
                hacerReserva();
                break;
            case 3:
                mostrarReservas();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Error: opción no válida." << endl;
        }
    } while (opcion!= 4);

    return 0;
}