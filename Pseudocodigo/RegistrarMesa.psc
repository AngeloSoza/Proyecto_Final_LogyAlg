Proceso RegistrarMesa
	Definir mesarequerida Como Entero;
	Definir cantPersonas Como Entero;
	Escribir 'Hay 14 mesas disponibles en el Restaurante El Ternero';
	Escribir 'Escriba el numero de la mesa que desea ocupar';
	Leer mesarequerida;
	Si mesarequerida<=12 Entonces
		Escribir 'Mesa disponible';
	SiNo
		Escribir 'Mesa ocupada, por favor escoja otra';
	FinSi
	Escribir 'Cada mesa del restaurante posee 4 sillas y se identifican por el numero que poseen en el centro de la misma.';
	Escribir 'Digite la cantidad de personas que acudirán al restaurante';
	Leer cantPersonas;
	Si cantPersonas<=4 Entonces
		Escribir 'Perfecto, Bienvenido a Restaurantes El Ternero';
	SiNo
		Escribir 'La cantidad de personas excede el limite de la mesa';
	FinSi
FinProceso
