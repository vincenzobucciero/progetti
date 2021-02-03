#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

#define MAXUTENTI 30	//numero max di contatti nella rubrica

struct utente{
    char nome[20];
    char cognome[20];
    char numero_telefonico[20];
    int chiamate_eff;
    int chiamate_ric;
    int inseriti;
} contatto[MAXUTENTI] ;




int inserimento(struct utente contatto[]); //prototipo della function riguardante l'inserimento din un contatto nella rubrica

void ordina_rubrica(struct utente contatto[]); //prototipo della procedura (void) riguardante l'ordinamento per cognomi dei contatti in rubrica

int stampa_rubrica(struct utente contatto[]); //prototipo della function riguardante la stampa della rubrica contenente i contatti

int cancellazione(struct utente contatto[]); //prototipo della function riguardante la cancellazione di un contatto dalla rubrica

int visualizza_numero(struct utente contatto[], int n, char *chiave, char *nome); //prototipo della function riguardante la visualizzazione di un numero di un contatto

int visualizza_chiamate(struct utente contatto[], char chiave[]); //prototipo della function riguardante la visualizzazione delle chiamate in entrata e in uscita da e verso un numero




#endif // HEADER_H_INCLUDED
