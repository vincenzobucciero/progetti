#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    int operazione; //Variabile che utilizzo nello switch per differenziare i vari casi
    char nome[20], cognome[20], numero_telefonico[20];



    printf("              ---BENEVENUTO NELLA TUA RUBRICA---            \n\n");

	printf("        **RICORDA CHE LA RUBRICA ATTUALMENTE E' VUOTA**");
            do {
                printf("\n\n");
                //Stampo a schermo le varie operazione che l'utente può eseguire
                printf("Quale azioni vuoi eseguire?\n");
                printf("Premi <1> per inserire un contatto nella rubrica\n");
                printf("Premi <2> per cancellare un contatto dalla rubrica\n");
                printf("Premi <3> per cercare un numero telefonico\n");
                printf("Premi <4> per vedere le chiamate da e verso un numero in rubrica\n");
                printf("Premi <5> per visualizzare i contatti presenti in rubrica\n");
                printf("Premo <0> per uscire dalla rubrica!\n");

                scanf(" %d", &operazione);

                    switch (operazione) //Uso del costrutto switch per permettere la scelta dell'operazione che si vuole eseguire
                    {
                        case 1: printf("----> INSERIMENTO CONTATTO <----\n"); //Si va ad aggiungere un contatto nella rubrica
                                if(inserimento(contatto)){ //Richiamo della function inserimento
                                    ordina_rubrica(contatto); //Richiamo della function di ordinamento in modo tale che sia automattizato, nel momento in cui
                                    						//viene inserito un contatto. automaticamente viene ordinato
                                    }
                            break; //Interrompo il caso 1 con un break


                        case 2: cancellazione(contatto); //Si va a cancellare un contatto presente in rubrica
                            break; //Interrompo il caso 2 con un break

                        case 3: system("cls"); //Funzione che mi permette di pulire lo schermo
                        		/*Per cercare un numero chiedo prima i dati del contatto all'utente*/
								printf("Per cercare un numero, ho bisogno dei dati del contatto  \n");
                                fflush(stdin); //Utilizzo della fflush
								printf("Inserisci il nome del contatto:  ");    //Si chiede all'utente di inserire il nome del contatto
                                scanf(" %s", &nome);
                                printf("Inserisci il cognome del contatto:  "); //Si chiede all'utente di inserire il cognome del contatto
                                scanf(" %s", &cognome);
                                visualizza_numero(contatto,MAXUTENTI,cognome,nome); //Richiamo della function
                                system("pause"); //Mette in pausa il programma fin quando l'utente non preme un pulsante

                            break; //Interrompo il caso 3 con un break

                        case 4: system("cls");
								//Si visualizzano le chiamate effettuate e ricevute da un contatto presente in rubrica
								printf("Inserisci il numero di telefono:  ");
                                scanf(" %s", &numero_telefonico);
                                visualizza_chiamate(contatto, numero_telefonico);
                                system("pause");
                            break; //Interrompo il caso 4 con un break


                        case 5: stampa_rubrica(contatto); //Si va a stampare la rubrica contenente i contatti
                            break;

                        case 0: printf("Arrivederci"); //Ultimo caso in cui si voglia uscire dalla rubrica
                                exit(0);
                            break;

}
} while (operazione!=27); //Il ciclo deve continuare fin quando non si preme il tasto ESC che nel codice ASCII equivale a 27
}
