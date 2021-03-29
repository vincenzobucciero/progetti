#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

#define MAXUTENTI 30


/*Function che permette l'inserimento di un contatto nella rubrica da parte dell'utente*/
int inserimento(struct utente contatto[]) //Function inserimento che prende in input la variabile contatto inerente alla struct utente dichiarata nell'header.h
                                        // e che restituisce in output il corretto inserimento del contatto in rubrica
{
    char scelta; //variabile utilizzata nell'if per la possibilità tra "si" e "no"
    char nome[20], cognome[20], numero_telefonico[20]; //Variabili all'interno delle quali verrano inserite le informazioni del contatto
    int i, chiam_eff, chiam_ric;


            printf("Sei sicuro di voler inserire un contatto?  "); //Si permette all'utente di scegliere tra due opzioni, "si" o "no"
            scanf(" %c", &scelta);
            fflush(stdin);
            system("cls"); //Funzione che permette di pulire lo schermo alla prossima esecuzione
                if (scelta=='s' || scelta =='S'){ //Possibilità di scelta tra un "Si" o "No"
                    printf("Inserisci il nome:  "); //Da qui inserisco tutte le credenziali necessarie per l'inserimento del contatto nella rubrica
                        scanf(" %s", &nome);
                    printf("Inserisci il cognome:  ");
                        scanf(" %s", &cognome);
                    printf("Inserisci il numero telefonico:  ");
                        scanf(" %s", &numero_telefonico);
                    printf("Inserisci le chiamate effettuate da questo numero:  ");
                        scanf(" %d", &chiam_eff);
                    printf("Inserisci le chiamate ricevute da questo numero:  ");
                        scanf(" %d", &chiam_ric);

                            for(i=0;i<MAXUTENTI;i++){ //Con questo ciclo for vado semplicemente a copiare le informazioni prima date, nella struct utente
                                if(contatto[i].inseriti==0){
                                    strcpy(contatto[i].nome, nome); //Poichè si tratta di un array di caratteri e quindi di una stringa, uso la strcpy
                                    strcpy(contatto[i].cognome, cognome); //per copiare le informazioni inserite all'interno della struct che poi conterrà tutti i contatti
                                    strcpy(contatto[i].numero_telefonico, numero_telefonico);
                                    contatto[i].chiamate_eff=chiam_eff; //Poichè le chiam_eff e le chiam_ric sono variabili intere, basta solo assegnarle
                                    contatto[i].chiamate_ric=chiam_ric;
                                    contatto[i].inseriti=1; //Aumento il contatore delle persone inserite in rubrica
                                    printf("Il contatto e' stato aggiunto con successo!\n"); //Avremo come risultato l'immissione corretta del contatto in rubrica
                                    return 1;
                                }

                            }
                            printf("Non c'e' abbastanza spazio nella rubrica, cancella prima qualche contatto.\n"); //Se la rubrica risulta essere già piena, si visualizza l'errore e si consiglia di cancellare prima qualche contatto

                }

                    else if ( scelta == 'n' || scelta == 'N') //Nel caso in cui si scelga il "No" si ritorna alla scelta dell'operazione
                        printf("Scegli un altra operazione:  ");
                        return 0;

			system("pause"); //Funzione che mette in pausa il programma e solo se viene premuto un pulsante dall'utente, il programma va avanti
}




/*Function che permette di eliminare un contatto dalla rubrica dato il nome e cognome del contatto stesso*/
int cancellazione(struct utente contatto[]) //Function cancellazione che prende in input la variabile contatto inerente alla struct utente dichiarata nell'header.h
{                                           //e restituisce in output la corretta cancellazione del contatto dalla rubrica

    int i;
    char nome_da_canc[20], cogn_da_canc[20]; //Variabili a cui assegno il nome e il cognome da cancellare per poi confrontarli con quelli presenti nell'archivio
		system("cls");
            printf("Inserisci il nome del contatto da cancellare:  ");
                scanf(" %s", &nome_da_canc);
            printf("Inserisci il cognome del contatto da cancellare:  ");
                scanf(" %s", &cogn_da_canc);

                for(i=0;i<MAXUTENTI;i++){ //Utilizzo del ciclo for per scorrere tutta la rubrica

				/*Utilizzo la strcmp per verificare se coincidaono il nome e il cognome inseriti dall'utente con quelli presenti nell'archivio*/
                if((strcmp(nome_da_canc,contatto[i].nome)&&(strcmp(cogn_da_canc,contatto[i].cognome)))==0){
                    strcpy(contatto[i].nome, ""); //Se corrispondono allora tramite la strcpy li vado a sostituire con ""
                    strcpy(contatto[i].cognome, "");
                    contatto[i].inseriti=0; //Qui azzero il contatore della persona corrispondente, in maniera tale che quando si va a stampare la rubrica, non risulti nulla
                    printf("Cancellazione completata con successo!");   //Cancellazione eseguita correttamente
                    return 1;
                }
                }
                printf("La ricerca non ha prodotto risultati"); //Se non corrispondo, la ricerca ha esito negativo
                    return 0;
                    system("pause");    //Funzione che mette in pausa il programma e solo se viene premuto un pulsante dall'utente, il programma va avanti
}


/*Function che permette di visualizzare un numero date le informazioni del contatto*/
int visualizza_numero(struct utente contatto[],int n, char *chiave, char *nome)
/*Function che prende in input la variabile contatto inerente alla struct utente dichiarate nell'header.h, n che equivale alla define MAXUTENTI,
  chiave che è l'elemtno da ricercare, nome che è il nome del contatto in rubrica, e restituisce in output il numero corrispondente al nome e cognome di un contatto presente in rubrica*/
{
	//Utilizzo della ricerca binaria ricorsiva (Versione Vero-Falso)
    int mediano;

        if(n == 0) //Se il numero dei contatti in rubrica è 0 allora ritornerà 0
            return 0;

                mediano = (n-1)/2;

                    if((strcmp(chiave,contatto[mediano].cognome) == 0)){ //Qui abbiamo la soluzione del caso banale, cioè se l'algoritmo trova tramite la strcmp
                    													//nome e cognome, allora ritornerà 1, cioè il numero telefonico corrispondente

                        printf("NUMERO DI TELEFONO CORRISPONDENTE  ----->  %s\n", contatto[mediano].numero_telefonico);
                        return 1;
                    }

                        else {
                                if(strcmp(chiave,contatto[mediano].cognome) < 0)
                                return visualizza_numero(contatto,mediano,chiave,nome);

                                    else
                                         return visualizza_numero(contatto+mediano+1, n-mediano-1, chiave,nome);
                            }


}

/*Function che permette di visualizzare il numero di chiamate ricevute ed effettuate da un contatto*/
int visualizza_chiamate(struct utente contatto[], char chiave[])
/*Function che prende in input la variabile contatto inerente all struct utente dichiarata nell'header.h e una chiave da trovare
  e restituisce in output il numero di chiamate ricevute ed effettuate da un contatto presente in rubrica*/
{
    int i;
		system("cls");
            for(i=0;i<MAXUTENTI;i++){ //Ciclo for che mi scorre tutta la rubrica
                if(strcmp(contatto[i].numero_telefonico,chiave)==0){ //Verifico tramite la strcmp se il numero inserito dall'utente appartiene alla rubrica
                    printf("Le informazioni riguardanti il numero inserito sono:\n");//Se appartiene, allora verranno visulaizzate tutte le informazioni riguardanti quel numero
                    printf("Nome: %s\n",contatto[i].nome);
                    printf("Cognome: %s\n",contatto[i].cognome);
                    printf("Chiamate ricevute: %d\n",contatto[i].chiamate_ric);
                    printf("Chiamate effettuate: %d\n",contatto[i].chiamate_eff);

                    return 1;
                }
            }
            printf("In rubrica non esiste questo numero.\n"); //Se non appartiene alla rubrica, appare un messaggio di errore
            return 0;
            system("pause");
}




/*Procedura che permette l'ordinamento dei contatti presenti in rubrica a seconda del cognome*/
void ordina_rubrica(struct utente contatto[]) //Prende in input la variabile contatto inerente alla struct utente dichiarata nell'header.h
                                            //e mostra in output la rubrica ordinata per cognomi
{
    struct utente temp; //Stabilisco una variabile temporanea
    int i,j;

            for(i=0;i<MAXUTENTI-1;i++){ //Due cicli for per individuare i due cognomi rappresentati dai due contatori i e j
                for(j=i+1;j<MAXUTENTI;j++){
                    if(strcmp(contatto[i].cognome,contatto[j].cognome)>0){ //Qui vado a confrontare i cognomi dei contatti presenti in rubrica
                             if(strcmp(contatto[i].nome,contatto[j].nome)>0) //Nel caso in cui due contatti dovessere avere lo stesso cognome, passo a confrontare i nomi
                        temp= contatto[i];
                        contatto[i]= contatto[j];
                        contatto[j]=temp;
                    }
                }
            }
}

/*Function che stampa la rubrica contenente i contatti*/
int stampa_rubrica(struct utente contatto[])
{
    int i;
    system("cls");
        printf("Nella rubrica sono presenti i seguenti contatti (ORDINATI PER COGNOME):\n");
        for(i=0;i<MAXUTENTI;i++){
                if(contatto[i].inseriti){
                        printf("\n");
                        printf("Nome: %s\n",contatto[i].nome);
                        printf("Cognome: %s\n",contatto[i].cognome);
                        printf("Numero di telefono: %s\n",contatto[i].numero_telefonico);
                        printf("Numero di chiamate ricevute: %d\n",contatto[i].chiamate_ric);
                        printf("Numero di chiamate effettuate: %d\n",contatto[i].chiamate_eff);
                        printf("-----------------------------\n");

            }
        }
        system("pause");    //Funzione che mette in pausa il programma e solo se viene premuto un pulsante dall'utente, il programma va avanti

}
