//Registrar combos en un sistema de reservas de un restaurante
#include <iostream>
#include <string.h>
#include "variables.h"

using namespace std;

void RegCombos()
{
    char combo;
    string descripcion;
    int precio;

    cout << "--------- Bienvenido al menu de combos -----------" << endl;
    cout << "Ingrese el combo: ";
    cout << "A. Combo 1" << endl;
    cout << "B. Combo 2" << endl;
    cout << "C. Combo 3" << endl;
    cout << "D. Combo 4" << endl;
    cout << "E. Combo 5" << endl;
    cout << "F. Combo 6" << endl;
    cout << "G. Combo 7" << endl;
    cout << "H. Combo 8" << endl;
    cout << "I. Combo 9" << endl;
    cout << "J. Combo 10" << endl;
    cout << "K. Combo 11" << endl;
    cout << "L. Combo 12" << endl;
    cout << "M. Combo 13" << endl;
    cout << "N. Combo 14" << endl;

    cin >> combo;

    switch (combo)
    {
    case 'A':
        descripcion = "Combo 1";
        precio = 68;
        break;
    case 'B':
        descripcion = "Combo 2";
        precio = 125;
        break;
    case 'C':
        descripcion = "Combo 3";
        precio = 75;
        break;
    case 'D':
        descripcion = "Combo 4";
        precio = 95;
        break;
    case 'E':
        descripcion = "Combo 5";
        precio = 75;
        break;
    case 'F':
        descripcion = "Combo 6";
        precio = 90;
        break;
    case 'G':
        descripcion = "Combo 7";
        precio = 125;
        break;
    case 'H':
        descripcion = "Combo 8";
        precio = 125;
        break;
    case 'I':
        descripcion = "Combo 9";
        precio = 115;
        break;
    case 'J':
        descripcion = "Combo 10";
        precio = 90;
        break;
    case 'K':
        descripcion = "Combo 11";
        precio = 95;
        break;
    case 'L':
        descripcion = "Combo 12";
        precio = 125;
        break;
    case 'M':
        descripcion = "Combo 13";
        precio = 90;
        break;
    case 'N':
        descripcion = "Combo 14";
        precio = 95;
        break;
    
    default:
        cout << "Opcion no valida" << endl;
        break;
    }

    cout << "Combo: " << descripcion << endl;
    cout << "Precio: " << precio << endl;
    cout << "Descripcion:\n " << descripcion << endl;
    cout << "Reserva realizada con exito." << endl;

}