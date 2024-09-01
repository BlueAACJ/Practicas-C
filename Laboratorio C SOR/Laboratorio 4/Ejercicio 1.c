#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Estructura para pasar parámetros al hilo01
struct ParametrosHilo01 {
	char palabra[100]; // Almacena la palabra a verificar
};

// Estructura para pasar parámetros al hilo02
struct ParametrosHilo02 {
	int numero; // Almacena el número a verificar
};

bool esCadena(const char *input) {
	// Verifica si la entrada contiene solo caracteres alfabéticos o espacios
	for (int i = 0; i < strlen(input); i++) {
    	if (!isalpha(input[i]) && !isspace(input[i])) {
        	return false;
    	}
	}
	return true;
}


bool esEntero(const char *cadena) {
	int i = 0;
	if (cadena[0] == '-' || cadena[0] == '+') {
    	i = 1;
	}

	for (; cadena[i] != '\0'; i++) {
    	if (!isdigit(cadena[i])) {
        	return false;
    	}
	}
	return true;
}

void *hilo01(void *arg) {
	struct ParametrosHilo01 *params = (struct ParametrosHilo01 *)arg;
	char palabra[100];
	strcpy(palabra, params->palabra);
	int len = strlen(palabra);
	int esPalindromo = 1;

	for (int i = 0; i < len / 2; i++) {
    	if (palabra[i] != palabra[len - i - 1]) {
        	esPalindromo = 0;
        	break;
    	}
	}

	if (esPalindromo) {
    	printf("La palabra \"%s\" es un palíndromo.\n", palabra);
	} else {
    	printf("La palabra \"%s\" no es un palíndromo.\n", palabra);
	}

	return NULL;
}

void *hilo02(void *arg) {
	struct ParametrosHilo02 *params = (struct ParametrosHilo02 *)arg;
	int numero = params->numero;
	int sumaDivisores = 0;

	for (int i = 1; i < numero; i++) {
    	if (numero % i == 0) {
        	sumaDivisores += i;
    	}
	}

	if (sumaDivisores == numero) {
    	printf("%d es un número perfecto.\n", numero);
	} else {
    	printf("%d no es un número perfecto.\n", numero);
	}

	return NULL;
}

int main(void) {
	pthread_t hiloPalindromo, hiloPerfecto;

	char input[100], entradaUsuario[100];
	bool cadenaValida = false;
    	bool entradaValida = false;

	// Parámetros para hilo01 (palíndromo)
	struct ParametrosHilo01 paramsHilo01;

	do {
    	printf("Ingresa una cadena: ");
    	fgets(input, sizeof(input), stdin);

    	// Elimina el salto de línea que agrega fgets
    	size_t len = strlen(input);
    	if (len > 0 && input[len - 1] == '\n') {
        	input[len - 1] = '\0';
    	}

    	cadenaValida = esCadena(input);

    	if (!cadenaValida) {
        	printf("La entrada no es una cadena válida. Intenta nuevamente.\n");
    	}
	} while (!cadenaValida);

	printf("Cadena válida ingresada: %s\n",input);

	strcpy(paramsHilo01.palabra, input);

	// Parámetros para hilo02 (número perfecto)


	struct ParametrosHilo02 paramsHilo02;

	do {
    	printf("Ingresa un número entero: ");
    	fgets(entradaUsuario, sizeof(entradaUsuario), stdin);

    	// Elimina el salto de línea que agrega fgets
    	size_t longitudEntrada = strlen(entradaUsuario);
    	if (longitudEntrada > 0 && entradaUsuario[longitudEntrada - 1] == '\n') {
        	entradaUsuario[longitudEntrada - 1] = '\0';
    	}

    	entradaValida = esEntero(entradaUsuario);

    	if (!entradaValida) {
        	printf("La entrada no es un número entero válido. Intenta nuevamente.\n");
    	}
	} while (!entradaValida);

	int input1 = atoi(entradaUsuario); // Convierte la cadena en un número entero

	printf("Número entero ingresado: %d\n", input1);

	paramsHilo02.numero = input1;

	if (pthread_create(&hiloPalindromo, NULL, hilo01, (void *)&paramsHilo01) != 0) {
    	printf("Error creando el hilo 01.\n");
    	exit(1);
	}

	if (pthread_create(&hiloPerfecto, NULL, hilo02, (void *)&paramsHilo02) != 0) {
    	printf("Error creando el hilo 02.\n");
    	exit(1);
	}

	pthread_join(hiloPalindromo, NULL);
	pthread_join(hiloPerfecto, NULL);

	return 0;
}
