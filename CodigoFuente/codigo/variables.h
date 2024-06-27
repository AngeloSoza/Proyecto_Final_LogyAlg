#ifndef VARIABLES_H // #ifndef significa "if not defined" (si no está definido) y sirve para evitar que se incluya el archivo más de una vez
#define VARIABLES_H

#define MAX_REGISTERS 100 // maximo de registros que se pueden usar

typedef struct {
    char nombres[50];
    char apellidos[50];
    char id[20]; // Cambiado de char a char[10] para permitir más de un carácter
    char telefono[10];
    int cantPersonas;
    char fecha[10];
} USUARIO;

#endif // VARIABLES_H
