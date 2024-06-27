//Registrar combos en un sistema de reservas de un restaurante
#include <iostream>
#include <string.h>

using namespace std;

void RegCombos()
{
    char combo;
    string descripcion;
    int precio;

    cout << "--------- Bienvenido al menu de combos -----------" << endl;
   
    cout << "A. Combo 1: Leche Agria, gallo pinto y totilla" << endl << endl;
    cout << "B. Combo 2: Cerdo frito, gallo pinto, totilla y cebollita" << endl << endl;
    cout << "C. Combo 3: Dos huevos enteros, gallo pinto y totilla" << endl << endl;
    cout << "D. Combo 4: Dos huevos rancheros, gallo pinto y totilla" << endl << endl;
    cout << "E. Combo 5: Dos huevos revueltos, gallo pinto y totilla" << endl << endl;
    cout << "F. Combo 6: Dos huevos revueltos con jamon, gallo pinto y totilla" << endl << endl;
    cout << "G. Combo 7: Dos huevos revueltos con chorizo, gallo pinto y totilla" << endl << endl;
    cout << "H. Combo 8: Chorizo criollo, gallo pinto, tortilla y cebollita." << endl << endl;
    cout << "I. Combo 9: Nacatamal de cerdo, pan y cafe" << endl << endl;
    cout << "J. Combo 10: Chorizo parrillero, gallo pinto, totilla y cebollita" << endl << endl;
    cout << "K. Combo 11: Tocino, dos huevos enteros, gallo pinto y totilla" << endl << endl;
    cout << "L. Combo 12: Chorizo parrillero, gallo pinto, dos huevos enteros, tortilla y cebollita" << endl << endl;
     cout << "Ingrese el combo: ";

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
    
    default:
        cout << "Opcion no valida" << endl;
        break;
    }

    cout << "Combo: " << descripcion << endl;
    cout << "Precio: " << precio << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Reserva realizada con exito." << endl;

}