#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>
#include <fstream>

using namespace std;

USUARIO usuarios[MAX_RG];
int posUsuarios = 0;
RESERVA reservas[MAX_RG];
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
void saveAll1();
void saveAll2();

//Manejo de archivos
int loadUsers();
void writeFile(const USUARIO &usuarios);
void agregarUsuario(USUARIO *u) {
    usuarios[posUsuarios] = *u;
    posUsuarios++;
}

USUARIO buscarUsuario(int id) {
    for (int i = 0; i < posUsuarios; i++) 
    {
        if (id == usuarios[i].id) 
        {
            return usuarios[i];
        }
    }
    USUARIO u;
    return u;
}

int obtPosUsuario(int id) 
{
    int posi = 0;
    for (int i = 0; i < posUsuarios; i++) 
    {
        if (usuarios[i].id == id) 
        {
            return i;
        }
    }
    return -1;
}

void editarUsuario(USUARIO *u, int id) {
    int posi = obtPosUsuario(id);
    strcpy(usuarios[posi].nombre, u -> nombre);
    strcpy(usuarios[posi].telefono, u -> telefono);
}

void eliminarUsuario(int id) {
    int posi = obtPosUsuario(id);
    for (int i = posi; i < posUsuarios; i++) {
        usuarios[i] = usuarios[i + 1];
    }
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
    posUsuarios = loadUsers();
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
//*PEDIR DATOS DEL USUARIO*/
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
    writeFile(u);
    cout << "\n=============Usuario agregado.==============" << endl;
}

//Mostrar datos de usuario
void mostrarDatosUsuario() {
    for (int i = 0; i < posUsuarios; i++) 
    {
        showDataUsuario(usuarios[i]);
    }
    if(posUsuarios == 0)
    {
        cout << "Sin Datos \n";
        return;
    }
}

//Buscar Por ID
void buscarxIDUsuario() {
    int id;
    cout << "Ingrese ID del usuario a buscar: ";
    cin >> id;
    if (obtPosUsuario(id) == -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }
    USUARIO u;
    u = buscarUsuario(id);
    showDataUsuario(u);
}

//ShowDataUsuario
void showDataUsuario(USUARIO &u) {
    cout << "=================================" << endl;
    cout << "ID: " << u.id << endl;
    cout << "Nombre: " << u.nombre << endl;
    cout << "Telefono: " << u.telefono << endl;
    cout << "=================================" << endl;
}

//Editar Datos Usuario
void editarDatosUsuario() {
    int id;
    cout << "Ingrese ID del usuario a editar: ";
    cin >> id;
    if (obtPosUsuario(id)== -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }
    USUARIO u = buscarUsuario(id);
    showDataUsuario(u);
        cout << "===== Datos actuales =======" << endl;
        cout << "Nombre: ";
        scanf(" %[^\n]", u.nombre);
        cout << "Teléfono: ";
        cin >> u.telefono;
        editarUsuario(&u, id);
        cout << "======= Usuario Actualizado =======\n ";
        saveAll1();
    }

    //Eliminar Datos Usuario
    void eliminarDatoUsuario() {
    int id;
    cout << " ================================================== " << endl;
    cout << "Ingrese ID del usuario a eliminar:\n ";
    cin >> id;
    if (obtPosUsuario(id) == -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }
    eliminarUsuario(id);
    saveAll1();
    cout << "=============Usuario eliminado.==============" << endl;
}

//Reservas
int loadReservations();
void writeFile(const RESERVA &reservas);

void agregarReserva(RESERVA *r) {
    reservas[posReservas] = *r;
    posReservas++;
}

RESERVA buscarReserva(int id) {
    for (int i = 0; i < posReservas; i++)
     {
        if (id == reservas[i].id) 
        {
            return reservas[i];
        }
    }
    RESERVA r;
    return r;
}
int obtPosReserva(int id) 
{
    int posi = 0;
    for (int i = 0; i < posReservas; i++) 
    {
        if (reservas[i].id == id) {
            return i;
        }
    }
    return -1;
}
void editarReserva(RESERVA *r, int id) {
    int posi = obtPosReserva(id);
    strcpy(reservas[posi].fecha, r->fecha);
    strcpy(reservas[posi].hora, r->hora);
    strcpy(reservas[posi].comida, r->comida);
    reservas[posi].id = r->id;
    reservas[posi].mesa = r->mesa;
    reservas[posi].CantPersonas = r->CantPersonas;
}

void eliminarReserva(int id) {
    int posi = obtPosReserva(id);
    for (int i = posi; i < posReservas; i++) 
    {
        reservas[i] = reservas[i + 1];
    }
    posReservas--;
}
//Pedir Datos Reserva
void pedirDatosReserva() {
    RESERVA reservas;
    cout << "Datos de la reserva\n";
    cout << "Ingrese ID de la reserva: " << endl;
    cin >> reservas.id;
    if(obtPosReserva(reservas.id) != -1)
    {
        cout << "El ID de la reserva ya existe. No se puede agregar la reserva." << endl;
        return;
    }
    cout << "Ingrese ID del usuario: " << endl;
    cin >> reservas.usuario_id;
    if (obtPosUsuario(reservas.usuario_id) == -1) {
        cout << "El ID del Usuario no coincide con ningun Usuario ya agregado, por favor, agregue un usuario nuevo." << endl;
        return;
    }
    cout << "Ingrese la cantidad de personas que asistiran: \n";
    cin >> reservas.CantPersonas;
    cout << "Ingrese numero de mesa que necesita (tenga en cuenta que cada mesa cuenta con 4 sillas): \n";
    cin >> reservas.mesa;
    cout << "Ingrese fecha (DD/MM/AA): " << endl;
    cin >> reservas.fecha;
    cout << "Ingrese hora (open: 6:30 AM - close: 12:30 PM): " << endl;
    cin >> reservas.hora;
    cout << "Ingrese comida: " << endl;
    scanf(" %[^\n]", reservas.comida);
    agregarReserva(&reservas);
    cout << "=================== Datos de reserva guardados =================\n " << endl;
    writeFile(reservas);
}

void mostrarDatosReserva() {
    for (int i = 0; i < posReservas; i++) 
    {
        showDataReserva(reservas[i]);
    }
    if (posReservas == 0) 
    {
        cout << "Sin Datos \n";
        return;
    }
}

void buscarxIDReserva() {
    int id;
    cout << "================================================\n";
    cout << "Ingrese ID de la reserva a buscar: " << endl;
    cin >> id;
    if (obtPosReserva(id) == -1) {
        cout << "Reserva no encontrada." << endl;
        return;
    }
    RESERVA r;
    r = buscarReserva(id);
    showDataReserva(r);
}

void showDataReserva(RESERVA &r) {
    cout << "=================================" << endl;
    cout <<" ......... Datos de la reserva ........" << endl;
    cout << "ID Reserva: " << r.id << endl;
    cout << "ID Usuario: " << r.usuario_id << endl;
    cout << "Cantidad de personas: " << r.CantPersonas << endl;
    cout << "Mesa: " << r.mesa << endl;
    cout << "Fecha: " << r.fecha << endl;
    cout << "Hora: " << r.hora << endl;
    cout << "Comida: " << r.comida << endl;
    cout << "=================================" << endl;
}

void editarDatosReserva() {
    int id;
    cout <<"==========================================" << endl << endl;
    cout << "Ingrese ID de la reserva a editar: " << endl;
    cin >> id;
    if(obtPosReserva(id) == -1) {
        cout << "Reserva no encontrada." << endl;
        return;
    }
    RESERVA r = buscarReserva(id);
        showDataReserva(r);
        cout << "Datos actuales: \n" ;
        cout << "Cantidad de personas: ";
        cin >> r.CantPersonas;
        cout << "Numero de mesas (tener en cuenta que cada mesa cuenta con 4 sillas): ";
        cin >> r.mesa;
        cout << "Fecha (DD/MM/AAAA): ";
        cin >> r.fecha;
        cout << "Hora (Formato 24 horas): ";
        cin >> r.hora;
        cout << "Comida: ";
        scanf(" %[^\n]", r.comida);
        editarReserva(&r, id);
        cout << "======= Registro Actualizado =======\n";
        saveAll2();
    }

void eliminarDatoReserva() {
    int id;
    cout << "========================================= " << endl;
    cout << "Ingrese ID de la reserva a eliminar: " << endl;
    cin >> id;
    if (obtPosReserva(id) == -1) {
        cout << "Reserva no encontrada." << endl;
        return;
    }
    eliminarReserva(id);
    saveAll2();
    cout << "========== Reserva eliminada =======" << endl;
    
}

int loadUsers() {
    ifstream archivo("usuarios.txt");
    if(archivo.fail()){
        return 0;
    }

    int i = 0;
    while (archivo >> usuarios[i].id) {
        archivo.ignore();
        archivo.getline(usuarios[i].nombre, 50);
        archivo.getline(usuarios[i].telefono, 15);
        i++;
    }
    archivo.close();
    return i;
}

void writeFile(const USUARIO &usuarios){
    ofstream archivo;
    archivo.open("usuarios.txt", ios::app);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << "Id: " << usuarios.id << endl;
    archivo << "Nombre del cliente: " << usuarios.nombre << endl;
    archivo << "Telefono del cliente: " << usuarios.telefono << endl;
    archivo.close();
}

int loadReservations() {
    ifstream archivo("reservas.txt");
    if(archivo.fail()){
        return 0;
    }
    int i = 0;
    while (archivo >> reservas[i].id) {
        archivo >> reservas[i].usuario_id;
        archivo >> reservas[i].mesa;
        archivo.ignore();
        archivo.getline(reservas[i].comida, 100);
        archivo.getline(reservas[i].fecha, 20);
        archivo.getline(reservas[i].hora, 20);
        archivo >> reservas[i].CantPersonas;
        i++;
    }
    archivo.close();
    return i;
}

void writeFile(const RESERVA &reservas){
    ofstream archivo;
    archivo.open("reservas.txt", ios::app);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << "ID de la reserva: " << reservas.id << endl;
    archivo << "ID del Cliente: " << reservas.usuario_id << endl;
    archivo << "Numero de mesas solicitadas: " << reservas.mesa << endl;
    archivo << "Comida solicitada: " << reservas.comida << endl;
    archivo << "Fecha de la reserva solicitada: " << reservas.fecha << endl;
    archivo << "Hora de la reserva: " << reservas.hora << endl;
    archivo << "Cantidad de personas que asistiran: " << reservas.CantPersonas << endl;
    archivo.close();
}

void saveAll1(){
    ofstream archivo;
    archivo.open("usuarios.txt", ios::trunc | ios::out);
    for (int i = 0; i < posUsuarios; i++) {
        archivo << "Nombre del cliente: " <<usuarios[i].nombre << endl;
        archivo << "Telefono del cliente: " <<usuarios[i].telefono << endl;
        archivo << "ID del cliente: " <<usuarios[i].id << endl;
    }
    archivo.close();
}

void saveAll2(){
    ofstream archivo;
    archivo.open("reservas.txt", ios::trunc | ios::out);
    for (int i = 0; i < posReservas; i++) {
        archivo << "ID de la reserva: " << reservas[i].id << endl;
        archivo << "ID del cliente " << reservas[i].usuario_id << endl;
        archivo << "Numero de mesas solicitadas: " << reservas[i].mesa << endl;
        archivo << "Comida solicitada: " << reservas[i].comida << endl;
        archivo << "fecha de la reserva: " << reservas[i].fecha << endl;
        archivo << "hora de la reserva: " << reservas[i].hora << endl;
        archivo << "Cantidad de personas: " << reservas[i].CantPersonas << endl;
    }
    archivo.close();
}