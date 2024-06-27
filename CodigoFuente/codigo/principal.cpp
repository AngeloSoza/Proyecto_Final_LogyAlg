#include <iostream>
#include "Usuarios.cpp"
#include "combos.cpp"
#include "mesa.cpp"
#include <locale.h> 

using namespace std;

void menuprincipal();

int main()
{
    setlocale(LC_ALL, "spanish");
    menuprincipal();
    return 0;
}

void menuprincipal(){
    int opcion;
    cout << "Bienvenido al menú principal" << endl;
    cout << "Que desea realizar? " << endl;
    cout << "1.Registrar Usuario" << endl;
    cout << "2.Registrar Mesa" << endl;
    cout << "3.Registrar Combo\n" << endl;
    cout << "Selecione una opcion: ";
    cin >> opcion;

    do{
        switch(opcion){
        case 1:
            principal();
            break;
        case 2: 
            MesasR();
            break;
        case 3:
            RegCombos();
            break;
        default:
            cout << "Opción no válida" << endl;
        break;
    
    }

} while (opcion != 3);
}