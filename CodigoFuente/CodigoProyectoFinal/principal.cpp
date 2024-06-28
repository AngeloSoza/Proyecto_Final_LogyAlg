#include <iostream>
#include "funciones.cpp"
#include <locale.h>


using namespace std;

int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Spanish");
    principal();
    return 0;
}