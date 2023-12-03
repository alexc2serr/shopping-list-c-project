/*
     * Hacer un programa en c que pida dos arrays separados con comas tal que asi: array uno de caracteres naranjas,limones,caramelos,patatas,huevos y otro especificando las cantidades de cada uno tal que asi 4,3,2,3,1 los arrays tendran una dimension varaible segun los datos que quiera introducir el usuario y se tiene que comprobar que tienen la misma cantidad de elemntos el array de caracteres que el de integros.
     * una vez pedidos los dos arrays el programa imprimira la lista de productos es decir array 1 con sus cantidades al lado es decir imprimira esto 3 naranjas, 4 limones, 3 caramelos, 2 patatas y 3 huevos.
     * una vez impreso esto tienes que crear una funcion externa que ordene los arrays de manera descendente en la cantidad y los imprima igual que en el anterior pero de orden descendente es decir 2 naranjas, 3 limones, 4 huevos y 5patatas, etc
     * luego tienes que crear otra funcion que haga lo mismo pero en orden descendente y por ultimo una ultima funcion que los ordene en orden alfabetico segun los productos que el usuario haya introducido
     *
     * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nombre[50];
    int cantidad;
} Producto;

void pedirArrays(Producto **productos, int *numProductos);
void imprimirArrays(Producto *productos, int numProductos);
void ordenarPorCantidadDesc(Producto *productos, int numProductos);
void ordenarPorNombreAsc(Producto *productos, int numProductos);
void imprimirArraysOrdenados(Producto *productos, int numProductos, char orden);

int main() {
    Producto *productos;
    int numProductos;

    pedirArrays(&productos, &numProductos);

    printf("Lista original:\n");
    imprimirArrays(productos, numProductos);

    printf("\nLista ordenada por cantidad (descendente):\n");
    ordenarPorCantidadDesc(productos, numProductos);
    imprimirArraysOrdenados(productos, numProductos, 'd');

    printf("\nLista ordenada por nombre (ascendente):\n");
    ordenarPorNombreAsc(productos, numProductos);
    imprimirArraysOrdenados(productos, numProductos, 'a');

    free(productos);

    return 0;
}

void pedirArrays(Producto **productos, int *numProductos) {
    char inputNombres[500];
    char inputCantidades[500];

    printf("Introduce los nombres de los productos separados por comas: ");
    fgets(inputNombres, sizeof(inputNombres), stdin);
    // Eliminar el carácter de nueva línea al final
    inputNombres[strcspn(inputNombres, "\n")] = '\0';
    for (int i = 0; i <strlen(inputNombres); i++) {
        printf("%c", inputNombres[i]);
    }


    printf("\nIntroduce las cantidades de los productos separadas por comas: ");
    fgets(inputCantidades, sizeof(inputCantidades), stdin);
    // Eliminar el carácter de nueva línea al final
    inputCantidades[strcspn(inputCantidades, "\n")] = '\0';
    for (int i = 0; i < strlen(inputCantidades) ; i++) {
        printf("%c", inputCantidades[i]);
    }


    // Contar el número de productos (basado en las comas)
    *numProductos = 0;
    char *token = strtok(inputNombres, ",");
    while (token != NULL) {
        (*numProductos)++;
        token = strtok(NULL, ",");
    }
    printf("\n");
    printf("\n");

    // Asignar memoria para el array de productos
    *productos = (Producto *)malloc(*numProductos * sizeof(Producto));

    char * iNombres = inputNombres;
    char * iCantidades = inputCantidades;

    // Obtener cada nombre y cantidad y almacenar en el array de productos
    for (int i = 0; i < *numProductos; i++) {
        sscanf(iNombres, "%[^,]", (*productos)[i].nombre);
        sscanf(iCantidades, "%d", &(*productos)[i].cantidad);

        // Necesitas conocer la longitud de la información leída para poder avanzar
        iNombres += strlen((*productos)[i].nombre) + 1;
        iCantidades += (int)log10((*productos)[i].cantidad) + 2;
    }

}

void imprimirArrays(Producto *productos, int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        printf("%d %s", productos[i].cantidad, productos[i].nombre);
        if (i < numProductos - 1) {
            printf(", ");
        }
    }
    printf(".\n");


}

void ordenarPorCantidadDesc(Producto *productos, int numProductos) {
    for (int i = 0; i < numProductos - 1; i++) {
        for (int j = 0; j < numProductos - i - 1; j++) {
            if (productos[j].cantidad < productos[j + 1].cantidad) {
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

void ordenarPorNombreAsc(Producto *productos, int numProductos) {
    for (int i = 0; i < numProductos - 1; i++) {
        for (int j = 0; j < numProductos - i - 1; j++) {
            if (strcmp(productos[j].nombre, productos[j + 1].nombre) > 0) {
                Producto temp = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = temp;
            }
        }
    }
}

void imprimirArraysOrdenados(Producto *productos, int numProductos, char orden) {
    if (orden == 'd') {
        for (int i = 0; i < numProductos; i++) {
            printf("%d %s", productos[i].cantidad, productos[i].nombre);
            if (i < numProductos - 1) {
                printf(", ");
            }
        }
    } else if (orden == 'a') {
        for (int i = 0; i < numProductos; i++) {
            printf("%d %s", productos[i].cantidad, productos[i].nombre);
            if (i < numProductos - 1) {
                printf(", ");
            }
        }
    }
    printf(".\n");
}



/*
#include <stdio.h>
#include <string.h>

int main() {
    // Definir variables
    char productos[1000], cantidades[1000];
    char *producto, *cantidad;

    // Pedir al usuario que introduzca la lista de productos
    printf("Introduce la lista de productos separados por comas: ");
    fgets(productos, sizeof(productos), stdin);

    // Reemplazar el carácter de nueva línea con null
    productos[strcspn(productos, "\n")] = '\0';

    // Pedir al usuario que introduzca la lista de cantidades
    printf("Introduce la lista de cantidades separadas por comas: ");
    fgets(cantidades, sizeof(cantidades), stdin);

    // Reemplazar el carácter de nueva línea con null
    cantidades[strcspn(cantidades, "\n")] = '\0';

    // Obtener el primer token (producto) y la primera cantidad
    producto = strtok(productos, ",");
    cantidad = strtok(cantidades, ",");

    // Imprimir los productos y cantidades intercalados
    while (producto != NULL && cantidad != NULL) {
        printf("%s %s, ", cantidad, producto);
        // Obtener el siguiente token (producto) y la siguiente cantidad
        producto = strtok(NULL, ",");
        cantidad = strtok(NULL, ",");
    }

    printf("\n");

    return 0;
}
*/
