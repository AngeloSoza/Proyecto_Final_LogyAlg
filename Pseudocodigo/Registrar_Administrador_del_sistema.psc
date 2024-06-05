Algoritmo Registrar_Administrador_del_sistema
	Definir CLAVE, CONTRA Como Entero;
	Escribir "Bienvenido al sistema de registro, digite su Usuario y su contraseña";
	Leer CLAVE;
	Leer  CONTRA;
	Si CLAVE = 4545 y CONTRA = 89245 Entonces
		Escribir "Bienvenido administrador del sistema";
	SiNo
		Si CLAVE = 2525 Y CONTRA = 54298 Entonces
			Escribir  "Bienvenido usuario";
		SiNo
			Escribir "Clave o Contraseña es incorrecta";
		FinSi
	FinSi
FinAlgoritmo
