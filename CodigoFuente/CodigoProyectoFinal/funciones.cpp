#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>
#include <fstream>

using namespace std;

USUARIO usuarios[MAX_RG];
RESERVA reservas[MAX_RG];
int posUsuarios = 0;
int posReservas = 0;

// CRUD
int obtPosUsuario(int id);
void agregarUsuario(USUARIO *u);
void editarUsuario(USUARIO *u, int id);
void eliminarUsuario(int id);
USUARIO buscarUsuario(int id);

// Funciones para reservas
void agregarReserva(RESERVA *r);
RESERVA buscarReserva(int id);
int obtPosReserva(int id);
void editarReserva(RESERVA *r, int id);
void eliminarReserva(int id);

int menu();
void principal();
void pedirDatosUsuario();
void mostrarDatosUsuario();
void showDataUsuario(USUARIO &u);
void buscarxIDUsuario();
void editarDatosUsuario();
void eliminarDatoUsuario();
void pedirDatosReserva();
void mostrarDatosReserva();
void showDataReserva(RESERVA &r); 
void buscarxIDReserva();
void editarDatosReserva();
void eliminarDatoReserva();
void guardarUsuarios();
void cargarUsuarios();
void guardarReservas();
void cargarReservas();
void saveAll();


void agregarUsuario(USUARIO *u) {
    usuarios[posUsuarios] = *u;
    posUsuarios++;
}

USUARIO buscarUsuario(int id) {
    for (int i = 0; i < posUsuarios; i++) {
        if (id == usuarios[i].id) {
            return usuarios[i];
        }
    }
    USUARIO u;
    return u;
}

int obtPosUsuario(int id) {
    for (int i = 0; i < posUsuarios; i++) {
        if (usuarios[i].id == id) {
            return i;
        }
    }
    return -1;
}

void editarUsuario(USUARIO *u, int id) {
    int posi = obtPosUsuario(id);
    strcpy(usuarios[posi].nombre, u->nombre);
    strcpy(usuarios[posi].telefono, u->telefono);
}

void eliminarUsuario(int id) {
    int posi = obtPosUsuario(id);
    for (int i = posi; i < posUsuarios - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }
    USUARIO u;
    usuarios[posUsuarios - 1] = u;
    posUsuarios--;
}

int menu(){
    
    int opcion;
    cout << "Menu:" << endl;
    cout << "1. Agregar usuario\n" << endl;
    cout << "2. Mostrar usuarios\n" << endl;
    cout << "3. Buscar usuario por ID\n" << endl;
    cout << "4. Editar usuario\n" << endl;
    cout << "5. Eliminar usuario\n" << endl;
    cout << "6. Agregar reserva\n" << endl;
    cout << "7. Mostrar reservas\n" << endl;
    cout << "8. Buscar reserva por ID\n" << endl;
    cout << "9. Editar reserva\n" << endl;
    cout << "10. Eliminar reserva\n" << endl;
    cout << "0. Salir\n" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;

}

void principal() {
    int opcion;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                pedirDatosUsuario();
                break;
            case 2:
                mostrarDatosUsuario();
                break;
            case 3:
                buscarxIDUsuario();
                break;
            case 4:
                editarDatosUsuario();
                break;
            case 5:
                eliminarDatoUsuario();
                break;
            case 6:
                pedirDatosReserva();
                break;
            case 7:
                mostrarDatosReserva();
                break;
            case 8:
                buscarxIDReserva();
                break;
            case 9:
                editarDatosReserva();
                break;
            case 10:
                eliminarDatoReserva();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 0);
}

//Reservas
void agregarReserva(RESERVA *r) {
    reservas[posReservas] = *r;
    posReservas++;
}

RESERVA buscarReserva(int id) {
    for (int i = 0; i < posReservas; i++) {
        if (id == reservas[i].id) {
            return reservas[i];
        }
    }
    RESERVA r;
    return r;
}

int obtPosReserva(int id) {
    for (int i = 0; i < posReservas; i++) {
        if (reservas[i].id == id) {
            return i;
        }
    }
    return -1;
}

void editarReserva(RESERVA *r, int id) {
    int posi = obtPosReserva(id);
    reservas[posi].mesa = r->mesa;
    strcpy(reservas[posi].comida, r->comida);
}

void eliminarReserva(int id) {
    int posi = obtPosReserva(id);
    for (int i = posi; i < posReservas - 1; i++) {
        reservas[i] = reservas[i + 1];
    }
    RESERVA r;
    reservas[posReservas - 1] = r;
    posReservas--;
}

void pedirDatosUsuario() {
    USUARIO u;
    cout << " ===============================================" << endl;
    cout << "\nIngrese ID: ";
    cin >> u.id;
    cout << "\nIngrese Nombre: ";
    scanf(" %[^\n]", u.nombre);
    cout << "Ingrese Telefono: ";
    cin >> u.telefono;
    agregarUsuario(&u);
    guardarUsuarios();
    cout << "\n=============Usuario agregado.==============" << endl;
}

void mostrarDatosUsuario() {
    for (int i = 0; i < posUsuarios; i++) {
        showDataUsuario(usuarios[i]);
    }
}

void showDataUsuario(USUARIO &u) {
    cout << "=================================" << endl;
    cout << "ID: " << u.id << endl;
    cout << "Nombre: " << u.nombre << endl;
    cout << "Telefono: " << u.telefono << endl;
    cout << "=================================" << endl;
}

void buscarxIDUsuario() {
    int id;
    cout << "Ingrese ID del usuario a buscar: ";
    cin >> id;
    USUARIO u = buscarUsuario(id);
    if (u.id != 0) {
        showDataUsuario(u);
    } else {
        cout << "==== Usuario no encontrado ======" << endl;
    }
}

void editarDatosUsuario() {
    int id;
    cout << "Ingrese ID del usuario a editar: ";
    cin >> id;
    USUARIO u = buscarUsuario(id);
    if (u.id != 0) {
        cout <<" ================================= " << endl;
        cout << "Datos actuales:" << endl;
        showDataUsuario(u);
        cout << "Ingrese nuevos datos:" << endl;
        cout << "Nombre: ";
        scanf(" %[^\n]", u.nombre);
        cout << "Teléfono: ";
        cin >> u.telefono;
        editarUsuario(&u, id);
        cargarUsuarios();
        cout << "======= Usuario Actualizado =======\n ";
        saveAll();
    } else {
        cout << "Usuario no encontrado." << endl;
    }
}

void eliminarDatoUsuario() {
    int id;
    cout << " ================================================== " << endl;
    cout << "Ingrese ID del usuario a eliminar:\n ";
    cin >> id;
    eliminarUsuario(id);
    saveAll();
    cout << "=============Usuario eliminado.==============" << endl;
    
}

void pedirDatosReserva() {
    RESERVA r;
    cout << " ============================================================ " << endl;
    cout << "Ingrese ID de la reserva: " << endl;
    cin >> r.id;
    cout << "Ingrese ID del usuario: " << endl;
    cin >> r.usuario_id;
    cout << "Ingrese la cantidad de personas que asistiran: \n";
    cin >> r.CantPersonas;
    cout << "Ingrese numero de mesa que necesita (tenga en cuenta que cada mesa cuenta con 4 sillas): \n";
    cin >> r.mesa;
    cout << "Ingrese fecha (DD/MM/AA) " << endl;
    cin >> r.fecha;
    cout << "Ingrese comida: " << endl;
    scanf(" %[^\n]", r.comida);
    cout << "=================== Datos de reserva guardados =================\n " << endl;
    agregarReserva(&r);
    guardarReservas();
}

void mostrarDatosReserva() {
    for (int i = 0; i < posReservas; i++) {
        cout << "Datos de la reserva " << endl;
        showDataReserva(reservas[i]);
    }
}

void showDataReserva(RESERVA &r) {
    cout << "=================================" << endl;
    cout <<" ......... Datos del usuario ........" << endl;
    cout << "ID Reserva: " << r.id << endl;
    cout << "ID Usuario: " << r.usuario_id << endl;
    cout << "Cantidad de personas: " << r.CantPersonas << endl;
    cout << "Mesa: " << r.mesa << endl;
    cout << "Fecha: " << r.fecha << endl;
    cout << "Comida: " << r.comida << endl;
    cout << "=================================" << endl;
}

void buscarxIDReserva() {
    int id;
    cout << "================================================\n";
    cout << "Ingrese ID de la reserva a buscar: " << endl;
    cin >> id;
    RESERVA r = buscarReserva(id);
    if (r.id != 0) {
        showDataReserva(r);
    } else {
        cout << "============ Reserva no encontrada. =============" << endl;
    }
}

void editarDatosReserva() {
    int id;
    cout <<"==========================================" << endl << endl;
    cout << "Ingrese ID de la reserva a editar: " << endl;
    cin >> id;
    RESERVA r = buscarReserva(id);
    if (r.id != 0) {
        cout << "Datos actuales:" << endl;
        showDataReserva(r);
        cout << "Ingrese nuevos datos:" << endl;
        cout << "Cantidad de personas: ";
        cin >> r.CantPersonas;
        cout << "Numero de mesas (tener en cuenta que cada mesa cuenta con 4 sillas): ";
        cin >> r.mesa;
        cout << "Fecha (dd/mm/aa): ";
        cin >> r.fecha;
        cout << "Comida: ";
        scanf(" %[^\n]", r.comida);
        editarReserva(&r, id);
        cargarReservas();
        cout << "======= Reserva Actualizada =======\n";
        saveAll();
    } else {
        cout << "========== Reserva no encontrada. ==============\n";
    }
}

void eliminarDatoReserva() {
    int id;
    cout << "========================================= " << endl;
    cout << "Ingrese ID de la reserva a eliminar: " << endl;
    cin >> id;
    eliminarReserva(id);
    cout << "========== Reserva eliminada =======" << endl;
    saveAll();

}

//guardar en un archivo .txt

void guardarUsuarios() {
    ofstream archivo("usuarios.txt", ios::app);
    for (int i = 0; i < posUsuarios; i++) {
        archivo << usuarios[i].id << endl;
        archivo << usuarios[i].nombre << endl;
        archivo << usuarios[i].telefono << endl;
    }
    archivo.close();
}

void cargarUsuarios() {
    ifstream archivo("usuarios.txt", ios::app); //para que guarden los datos en el archivo, tengo que mandar el archivo cargarUsuarios a 
    USUARIO u;
    while (archivo >> u.id) {
        archivo >> u.nombre;
        archivo >> u.telefono;
        agregarUsuario(&u);
    }
    archivo.close();
}

void guardarReservas() {
    ofstream archivo("reservas.txt", ios::app);
    for (int i = 0; i < posReservas; i++) {
        archivo << reservas[i].id << endl;
        archivo << reservas[i].usuario_id << endl;
        archivo << reservas[i].CantPersonas << endl;
        archivo << reservas[i].mesa << endl;
        archivo << reservas[i].fecha << endl;
        archivo << reservas[i].comida << endl;
    }
    archivo.close();

}

void cargarReservas() {
    ifstream archivo("reservas.txt", ios::app);
    RESERVA r;
    while (archivo >> r.id) {
        archivo >> r.usuario_id;
        archivo >> r.CantPersonas;
        archivo >> r.mesa;
        archivo >> r.fecha;
        archivo >> r.comida;
        agregarReserva(&r);
    }
    archivo.close();
}

void saveAll(){
    ofstream archivo;
    archivo.open("usuarios.txt", ios::trunc | ios::out);
    for (int i = 0; i < posUsuarios; i++) {
        archivo << usuarios[i].id << endl;
        archivo << usuarios[i].nombre << endl;
        archivo << usuarios[i].telefono << endl;
    }
    archivo.close();
}