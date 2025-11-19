#ifndef __AGENDA_H__
#define __AGENDA_H__

#include <stdio.h>

#define MAX_CONTACTOS 100

// Tipos de teléfono
enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};

// Meses del año CORREGIDOS
enum Mes {
    ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO,
    JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

// Estructura del contacto (Persona)
struct Persona {
    char nombre[30];
    char apellido[30];
    enum Mes mes_nac;
    int dia_nac;
    char telefono[15];
    enum TipoTelefono tipo_tel;
};

typedef struct Persona Contacto;

// Estructura de la agenda
typedef struct Agenda {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;


// ----------- PROTOTIPOS -----------------

void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);

int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);

void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);

void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);

void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda agenda);

#endif // __AGENDA_H__
