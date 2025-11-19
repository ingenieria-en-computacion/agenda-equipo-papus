#include <stdio.h>
#include "agenda.h"

int main() {

    Agenda agenda;
    iniciar_agenda(&agenda);

    int opcion;
    Contacto c;
    char buscar[30];

    do {
        printf("\n===== MENU AGENDA =====\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar agenda\n");
        printf("3. Buscar por nombre\n");
        printf("4. Buscar por telefono\n");
        printf("5. Ordenar A-Z\n");
        printf("6. Ordenar Z-A\n");
        printf("7. Guardar en archivo\n");
        printf("8. Cargar desde archivo\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                leer_contacto(&c);
                agregar_contacto(&agenda, c);
                break;

            case 2:
                imprimir_agenda(agenda);
                break;

            case 3:
                printf("Nombre a buscar: ");
                scanf("%s", buscar);
                int pos;
                pos = buscar_contacto(&agenda, buscar);
                if (pos >= 0) mostrar_contacto(agenda.contactos[pos]);
                else printf("No encontrado\n");
                break;

            case 4:
                printf("Telefono a buscar: ");
                scanf("%s", buscar);
                pos = buscar_contacto_x_telefono(&agenda, buscar);
                if (pos >= 0) mostrar_contacto(agenda.contactos[pos]);
                else printf("No encontrado\n");
                break;

            case 5:
                ordenar_contactos(&agenda);
                break;

            case 6:
                ordenar_contactos_inv(&agenda);
                break;

            case 7:
                guardar_contactos("agenda.txt", agenda);
                printf("Guardado.\n");
                break;

            case 8:
                cargar_contactos("agenda.txt", &agenda);
                printf("Contactos cargados.\n");
                break;
        }

    } while(opcion != 0);

    return 0;
}
