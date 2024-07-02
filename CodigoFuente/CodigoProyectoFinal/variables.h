#define MAX_RG 100 // Máximo de registros

typedef struct USUARIO {
    char nombre[50];
    int id;
    char telefono[15];
};

typedef struct RESERVA {
    int id;
    int usuario_id;
    int mesa;
    char comida[100];
    char fecha[20];
    char hora[20];
    int CantPersonas;
};
