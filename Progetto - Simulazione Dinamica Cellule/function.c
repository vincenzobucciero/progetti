#include "header.h"



/*Function che permette di stampare la matrice 40x40*/

int stampa_matrice(char v1[40][40])
{
	int i=0, j;
	int n = 40; //Variabile che indica la quantità di righe della matrice
	int m = 40; //Variabile che indica la quantità delle colonne della matrice

    system("cls");//Funtion che permette di pulire lo schermo prima di cominciare a stampare

		for ( i = 0 ; i < n ; i++ ) //Ciclo for annidato che scorre tutte le righe e le colonne della matrice
		{
			for ( j = 0 ; j < m ; j++ )
			{
                    printf(" %c", v1[i][j]);    //Stampo la matrice
			}

			printf("\n");
		}

	  system("pause"); //Function che mette in pausa il programma fin quando l'utente premendo un qualsiasi tasto lo fa riprendere

	return 0;


}


/*Function che, stipulate determinate condizioni, permette di stampare la stessa matrice iniziale, ma
  con i valori delle cellule aggiornate, cioè, ad ogni passo i-esimo, viene aggiornata solo una riga alla volta.
  Ricordiamo che con la 'X' indico una cellula NERA, con un ' ' una cellula BIANCA */

int simulazione_cellule(char v1[40][40])
{
	int i, j;
	int righe = 40;
	int colonne = 40;



            /*Ciclo for annidato che permette di scorrere tutta la matrice. Il For piu' esterno va da 1 fino alla riga massima perchè devve sostanzialmete
             comicniare ad aggiornare dalla riga 1 poichè la riga 0 è già sistemata nella condizione iniziale della matrice.
             Il For interno invece comincia sempre da 1 ma termina a 39, cioè la colonna massima. */
			for (i=1;i<righe;i++)
			{
				for(j=0;j<39;j++) //Questi due cicli for mi permettono di controllare la riga precedente e le colonne precedenti e seguenti della cella di riferimento
				{

				    /*QUANDO SI SCRIVE v1[i-1][...] SI FA RIFERIMETO ALLA RIGA PRECEDENTE, POICHE SOLO TRAMITE LA CONDIZIONE DELLE CELLULE
                        NELLA RIGA PRECEDENTE, SI POSSONO VERIFICARE LE CONDIZIONI DELLA RIGA CORRENTE */

						if(v1[i-1][j]=='X' && v1[i-1][j-1]=='X' && v1[i-1][j+1]==' ') //CONDIZIONE A
                  		{
                    		v1[i][j]='X';
                  		}
                			if(v1[i-1][j]==' ' && v1[i-1][j-1]=='X' && v1[i-1][j+1]==' ') //CONDIZIONE B
                  			{
                    			v1[i][j]='X';
                  			}
                				if(v1[i-1][j]=='X' && v1[i-1][j-1]==' ' && v1[i-1][j+1]=='X') //CONDIZIONE C
                  				{
                    				v1[i][j]='X';
                  				}
                					if(v1[i-1][j]==' ' && v1[i-1][j-1]==' ' && v1[i-1][j+1]=='X') //CONDIZIONE D
                  					{
                    					v1[i][j]='X';
                  					}
                    					if(v1[i-1][j]==' ' && v1[i-1][j-1]==' ' && v1[i-1][j+1]=='X') //CONDIZIONE E
                  						{
                    						v1[i][j]='X';
                  						}
               }

                stampa_matrice(v1); //Richiamo della function stampa matrice, che in questo caso andrà a stampare sempre
                                    //la stessa matrice ma sempre con una riga aggiornata rispetto a quella precedente.

                }



	return 0;



}
