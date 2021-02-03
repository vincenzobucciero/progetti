# progetti

**SPIEGAZIONE DEL PROGETTO**

-Algoritmo per la simulazione di dinamica di ‘cellule’-

  Si consideri un array 2D 40x40. Ogni elemento dell’array è detto ‘cellula’. Una
  cellula può essere bianca o nera. Una cellula bianca viene visualizzata con uno spazio
  (blank ‘ ‘), una cellula nera con ‘X’. All’inizio vi è solo una cellula nera, al 60-simo
  posto della prima riga; tutte le altre cellule sono bianche. Sviluppare un algoritmo
  iterativo che, a partire dalla prima riga, a ogni passo aggiorna una sola riga
  dell’array, ovvero al secondo passo aggiorna la seconda riga, al terzo passo aggiorna
  la terza riga e così via, fino all’ultima riga. Al passo i-simo, la riga i-sima viene
  aggiornata considerando solo la riga (i-1)-sima, secondo la seguente regola:
  la cellula j della riga i-sima diventa nera se:
    a. nella riga (i-1)-sima la cellula j e la cellula j-1 sono nere e la cellula j+1 è
    bianca;
    b. nella riga (i-1)-sima le cellule j-1 e j+1 sono nere e la cellula j è bianca;
    c. nella riga (i-1)-sima la cellula j e la cellula j+1 sono nere e la cellula j-1 è
    bianca;
    d. nella riga (i-1)-sima la cellula j è nera e le cellule j+1 e j-1 sono bianche;
    e. nella riga (i-1)-sima la cellula j+1 è nera e le cellule j e j-1 sono bianche.
    
    
    
 .Visualizzare tutto l’array sia dopo il quarto passo, sia dopo l’ottavo passo, sia dopo il
 16-simo, il 32-simo, il 40-simo passo
