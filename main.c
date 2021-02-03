#include <stdio.h>
#include <stdlib.h>
#include "header.h"


//All'interno del main sono andato ad inserire la condizione iniziale della matrice per poi stamparla

int main()
{
	int i=0, j;
	int righe = 40, colonne = 40; //Variabili che indicano il numero di righe e colonne della matrice
	char v1[40][40];       //Dichiarazione della matrice


        for (i=0;i<righe;i++) //Ciclo for annidato che permette lo scorrimento di tutta la matrice
			{
				for(j=0;j<40;j++)
				{
					v1[i][j] = ' '; //Stampo in tutte le posizioni della matrice un ' ' che indica che la cellula in quella posizione è BIANCA
				}
			}

			v1[0][19] = 'X'; //TRANNE IN QUESTA POSZIONE, v1[0][19], CHE RAPPRESENTA LA CONDIZIONE INIZIALE DELLA MATRICE, QUI VIENE STAMPATA UNA 'X',
                            //CHE INDICA CHE LI LA CELLULA E' NERA

			stampa_matrice(v1); //Richiamo della function stampa matrice, che stamperà la trice iniziale


		simulazione_cellule(v1); //Richiamo della function simulazione cellule che permetterà invece di stampare, sempre dopo comando dell'utente,
                                //la stessa matrice ma aggiornata di una riga.

}

