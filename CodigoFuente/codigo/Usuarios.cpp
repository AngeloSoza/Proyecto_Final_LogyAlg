#include <iostream>
#include <string.h>
#include "variables.h"

using namespace std;

USUARIO usuarios[MAX_REGISTERS]; // arreglo de estructuras de tipo USUARIO
int pos = 0;

// funcion para agregar un usuario
int obtPos(const char* id);
void AgregarUsuario(USUARIO *u);
void editarUsuario(const char* id, USUARIO *u);
void eliminarUsuario(const char* id);
USUARIO buscarUsuario(const char* id);
int menu();
void principal();
void pedirDatos();
void mostrarDatos();
void showData(USUARIO &u);
void buscarxID();
void editarDatos();
void eliminarDatos();

void agregarUsuario(USUARIO *u){
    usuarios[pos]= *u;
    pos ++;
}

USUARIO buscarUsuario(const char* id){
    for (int i = 0; i < pos; i++)
    {
        if (strcmp(id, usuarios[i].id) == 0)
        {
            return usuarios[i];
        }
    }
    USUARIO u;
    return u;
}

int obtPos(const char* id){
    for (int i = 0; i < pos; i++)
    {
        if (strcmp(id, usuarios[i].id) == 0)
        {
            return i;
        }
    }
    return -1;
}

void editarUsuario(const char* id, USUARIO *u){
    int pos = obtPos(id);
    strcpy(usuarios[pos].nombres, u->nombres);
    strcpy(usuarios[pos].apellidos, u->apellidos);
    strcpy(usuarios[pos].telefono, u->telefono);
}

void eliminarUsuario(const char* id){
    int pos = obtPos(id);
    for (int i = pos; i < pos; i++)
    {
        usuarios[i] = usuarios[i+1];
    }
    pos --;
}

int menu(){
    int op;
    cout << "Menu de opciones: \n\n";
    cout << "1. Agregar usuario\n";
    cout << "2. Editar usuario\n";
    cout << "3. Eliminar usuario\n";
    cout << "4. Buscar usuario\n";
    cout << "5. Mostrar todo\n";
    cout << "6. Salir\n\n";
    cout << "Digite la opcion: ";
    cin >> op;
    return op;
}

void principal(){
    int opcion;
    do{
        opcion = menu();
        switch(opcion){
            case 1:
                pedirDatos();
                break;
            case 2:
                editarDatos();
                break;
            case 3:
                eliminarDatos();
                break;
            case 4:
                buscarxID();
                break;
            case 5:
                mostrarDatos();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, por favor intente de nuevo." << endl;
        }
    } while(opcion != 6);
}

void pedirDatos(){
    USUARIO usuario;
    cout << "Ingrese nombres: ";
    scanf(" %[^\n]", usuario.nombres); 
    cout << "Ingrese apellidos: ";
    scanf(" %[^\n]", usuario.apellidos);
    cout << "Ingrese ID (cedula): ";
    cin >> usuario.id;
    cout << "Ingrese telefono: ";
    cin >> usuario.telefono;
    cout << "Ingrese cantidad de personas: ";
    cin >> usuario.cantPersonas;
    cout << "Ingrese fecha de reserva (dd-mm-aaaa): ";
    cin >> usuario.fecha;
    agregarUsuario(&usuario);
    cout << "============= USUARIO AGREGADO =============== \n";
}

void mostrarDatos(){
    for (int i = 0; i < pos; i++)
    {
        showData(usuarios[i]);
    }
    if(pos == 0){
        cout << "============ NO HAY REGISTROS ============\n";
        return;
    }
}

void buscarxID(){
    char id[20];
    cout << "Ingrese el ID del cliente a buscar (cedula): ";
    cin >> id;
    if (obtPos(id) == -1){
        cout << "============ EL USUARIO NO EXISTE ============\n";
        return;
    }
    USUARIO u;
    u = buscarUsuario(id);
    showData(u);
}

void showData(USUARIO &u){
    cout << " ============================================ \n";
    cout << u.nombres << endl;
    cout << u.apellidos << endl;
    cout << u.telefono << endl;
    cout << u.cantPersonas << endl;
    cout << u.fecha << endl;
    cout << " ============================================ \n";
}

void editarDatos()
{
    char id[20];
    cout << "Ingrese el ID del usuario a editar\n";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "============ NO SE ENCONTRO REGISTRO    ============\n";
        return;
    }
    USUARIO u = buscarUsuario(id);
    showData(u);
    cout << "Datos actuales del usuario:" << endl;
    cout << "Nombres: ";
    scanf(" %[^\n]", u.nombres);
    cout << "Apellidos: ";
    scanf(" %[^\n]", u.apellidos);
    cout << "Telefono: ";
    cin >> u.telefono;
    cout << "Cantidad de personas: ";
    cin >> u.cantPersonas;
    cout << "Fecha de la reserva: ";
    cin >> u.fecha;
    editarUsuario(id, &u);
    cout << "============ USUARIO ACTUALIZADO ============\n";
}

void eliminarDatos()
{
    char id[20];
    cout << "Usuario a eliminar";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "============ NO SE ENCONTRO REGISTRO ============\n";
        return;
    }
    eliminarUsuario(id);
    cout << "============ USUARIO ELIMINADO ============\n";
}
