#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "agenda.h"

// Inicia la agenda
void iniciar_agenda(Agenda *agenda)
{
    agenda->num_contactos = 0;
}

// Agrega un contacto
void agregar_contacto(Agenda *agenda, Contacto c)
{
    if (agenda->num_contactos < MAX_CONTACTOS)
    {
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
    else
    {
        printf("La agenda está llena.\n");
    }
}

// Buscar por nombre
int buscar_contacto(Agenda *agenda, char *nombre)
{
    for (int i = 0; i < agenda->num_contactos; i++)
    {
        if (strcmp(nombre, agenda->contactos[i].nombre) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Buscar por teléfono
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[])
{
    for (int i = 0; i < agenda->num_contactos; i++)
    {
        if (strcmp(telefono, agenda->contactos[i].telefono) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Orden ascendente por nombre
void ordenar_contactos(Agenda *a)
{
    int i, j;
    Contacto temp;
    for (i = 0; i < a->num_contactos; i++)
    {
        for (j = 0; j < a->num_contactos - i - 1; j++)
        {
            if (strcmp(a->contactos[j].nombre, a->contactos[j + 1].nombre) > 0)
            {
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j + 1];
                a->contactos[j + 1] = temp;
            }
        }
    }
}

// Orden descendente
void ordenar_contactos_inv(Agenda *a)
{
    int i, j;
    Contacto temp;
    for (i = 0; i < a->num_contactos; i++)
    {
        for (j = 0; j < a->num_contactos - i - 1; j++)
        {
            if (strcmp(a->contactos[j].nombre, a->contactos[j + 1].nombre) < 0)
            {
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j + 1];
                a->contactos[j + 1] = temp;
            }
        }
    }
}

// Mostrar un contacto
void mostrar_contacto(Contacto c)
{
    printf("Nombre: %s %s\n", c.nombre, c.apellido);
    printf("Nacimiento: %d de %d\n", c.dia_nac, c.mes_nac);
    printf("Telefono: %s (tipo: %d)\n", c.telefono, c.tipo_tel);
    printf("---------------------------------\n");
}

// Leer contacto desde teclado
void leer_contacto(Contacto *c)
{
    printf("Nombre: ");
    scanf("%s", c->nombre);

    printf("Apellido: ");
    scanf("%s", c->apellido);

    printf("Mes de nacimiento (0-11): ");
    scanf("%d", (int *)&c->mes_nac);

    printf("Dia de nacimiento: ");
    scanf("%d", &c->dia_nac);

    printf("Telefono: ");
    scanf("%s", c->telefono);

    printf("Tipo de telefono (0=CASA,1=MOVIL,2=OFICINA,3=OTRO): ");
    scanf("%d", (int *)&c->tipo_tel);
}

// Imprimir agenda completa
void imprimir_agenda(Agenda agenda)
{
    if (agenda.num_contactos == 0)
    {
        printf("Agenda vacía.\n");
        return;
    }

    for (int i = 0; i < agenda.num_contactos; i++)
    {
        mostrar_contacto(agenda.contactos[i]);
    }
}

// Cargar contactos desde un archivo
void cargar_contactos(char *filename, Agenda *agenda)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    Contacto c;

    while (fscanf(f, "%[^|]|%[^|]|%d|%d|%[^|]|%d\n",
                    c.nombre,
                    c.apellido,
                    &c.dia_nac,
                    (int *)&c.mes_nac,
                    c.telefono,
                    (int *)&c.tipo_tel) == 6)
    {
        agregar_contacto(agenda, c);
    }

    fclose(f);
}

// Guardar contactos en archivo
void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(filename, "w");

    for (int i = 0; i < agenda.num_contactos; i++){
        Contacto c = agenda.contactos[i];

        fprintf(f, "%s|%s|%d|%d|%s|%d\n",
            c.nombre,
            c.apellido,
            c.dia_nac,
            c.mes_nac,
            c.telefono,
            c.tipo_tel
        );
    }

    fclose(f);
}
