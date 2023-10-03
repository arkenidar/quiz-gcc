/*
Traccia:
Lo scopo di oggi è realizzare un piccolo gioco di domanda/risposta in C, il
numero e le domande sono a vostra scelta. Il gioco dovrà funzionare in modo tale
da:
- Presentare una rapida introduzione all’utente con lo scopo del programma
- Mostrare all’utente un menu di scelta iniziale tra: A) Iniziare una nuova
partita; B) Uscire dal gioco
- Ricevere in input la scelta dell’utente
- Creare o meno una nuova partita in base all’input utente
- Ricevere in input nome dell’utente in caso di nuova partita
- Presentare un set di domande all’utente a risposta multipla (almeno 3 risposte
a domanda)
- Valutare la risposta utente per ogni domanda ed aggiornare una variabile
«punteggio in caso di risposta esatta»
- Scrivere a schermo a fine partita il punteggio totalizzato dal giocatore
corrente
- Presentare nuovamente il testo per la scelta tra: A) Iniziare una nuova
partita; B) Uscire dal gioco
*/

// Io ho usato Microsoft VisualStudio Code come IDE (compilazione, esecuzione, debugger).
// Io ho usato MSYS+MinGW per il compilatore "GNU GCC" in Windows.

// https://code.visualstudio.com/docs/cpp/config-mingw
// https://code.visualstudio.com/docs/editor/debugging

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chiedi_testo(char* string_buffer, int size){
  char *fgets_result = NULL;
  while (strlen(string_buffer) <= 1 && fgets_result == NULL) {
    fgets_result =
        fgets(string_buffer, size, stdin);
  }
  size_t lenght = strlen(string_buffer);
  if (lenght >= 1 && string_buffer[lenght - 1] == '\n')
    string_buffer[lenght - 1] = '\0';
}

void partita() {
  puts("Partita!");

  puts("??? Inserisci il tuo nome in quanto utente...");
  char nome_utente[21] = "";

  while(strlen(nome_utente)==0)
  chiedi_testo(nome_utente,
      sizeof(nome_utente) / sizeof(char));

  printf("Ciao utente '%s' \n", nome_utente);

  // inserisci qui la partita

  int punteggio = 0;

  struct quiz_entry{
    char* question;
    char* answers[3];
    int correct_answer_index;
  };

  struct quiz_entry quiz_set[] = {
    {.question="domanda 1: quale kernel usa Google Android?", .correct_answer_index=1, .answers={
      "Linux kernel",
      "FreeBSD kernel",
      "Minix kernel" } },

    {.question="domanda 2: quale API famosa è usata per WebGL?", .correct_answer_index=2, .answers={
      "OpenGL API",
      "OpenGL-ES API",
      "Vulkan API" } }
  };

  int quiz_size = sizeof(quiz_set)/sizeof(struct quiz_entry);
  for( int quiz_entry_index = 0;
    quiz_entry_index < quiz_size;
    quiz_entry_index += 1)
  {
    struct quiz_entry entry = quiz_set[quiz_entry_index];
    puts("--------------------------");
    puts(entry.question);
    for(int i=0; i<3; i++)
      puts(entry.answers[i]);
    puts("??? answer with 1 or 2 or 3 !");
    char answer[3]; chiedi_testo(answer, 3);

    printf("risposta appena data: '%s' \n", answer);

    if(answer[0]=='1' && entry.correct_answer_index==1)
      punteggio += 1;
    if(answer[0]=='2' && entry.correct_answer_index==2)
      punteggio += 1;
    if(answer[0]=='3' && entry.correct_answer_index==3)
      punteggio += 1;

    puts("--------------------------");
  }

  printf("Punteggio '%s': %d su %d ! \n", nome_utente, punteggio, quiz_size);

  puts("Fine partita.\n");
}

void menu() {
  char scelta_utente[21] = "";
  while (true) {
    puts("??? Inserisci la tua scelta nel menu delle azioni utente...");
    puts("1) Iniziare una nuova partita");
    puts("2) Uscire dal gioco");

    chiedi_testo(scelta_utente, sizeof(scelta_utente)/sizeof(char));
    
    if ( 0 == strcmp(scelta_utente, "2") )
      break;

    if ( 0 == strcmp(scelta_utente, "1") )
      partita();
  }
}

int main() {
  puts("Inizio: Quiz a punti. Scritto in linguaggio C.");
  menu();
  puts("Uscita...");
}
