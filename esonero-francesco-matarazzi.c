#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Francesco Matarazzi matricola: 333592
int main (void)
{
  char plainText[128]; // M
  char key[128]; // K
  int userSelection;

  printf("Hello, enter the text you want to encrypt (128 char max)\n");
  fgets(plainText, 128, stdin);
  int plainTextLenght = strlen(plainText); // variabile creata per comodità per non chiamare sempre strlen()

  printf("Press number [1] to insert your key, otherwise press [2] to generate a random key\n");
  scanf("%d", &userSelection);
  char c;
  while((c= getchar()) != '\n' && c != EOF); // necessario per pulire il buffer
  time_t t;

  switch (userSelection) {
    case 1: // l'utente vuole inserire  la  chiave
      printf("Enter a [%d] digits key\n", (plainTextLenght - 1));
      do {
        fgets(key, 128, stdin);
        if (strlen(key) < plainTextLenght) {
          printf("Key is too short! Please insert new key. \n");
        }
      } while (strlen(key) < plainTextLenght);
    break;

    case 2: // la chiave viene generata automaticamente
      srand((unsigned) time(&t));
      for (int r = 0; r < plainTextLenght; r++ ) {
        key[r]=  rand() % 128;
      }
    break;

    default: // se l'utente immette un carattere diverso da 1 e 2 stamperà errore
      printf("ERROR, your choise must be between 1 and 2\n");
      return 0;
  }

  char encrypted[128]; // array di char per salvare il risultato dello xor
  for (int i = 0; i < plainTextLenght; i++) {
    encrypted[i]= plainText[i] ^ key[i];
  }

  char outputText[128]; // array di char per salvare il testo decodificato
  printf("your output text is: ");
  for (int i = 0; i < plainTextLenght; i++){
    outputText[i]= encrypted[i] ^ key[i];
    printf("%c", outputText[i]);
  }
  printf("\n");
  printf("---------------\n");
  printf("first plain text is: %s\n", plainText);
  printf("---------------\n");
  printf("your key is: %s\n", key);
  printf("---------------\n");

  // stampo i valori esadecimali uno alla volta
  for (int j = 0; j < strlen(encrypted); j++) {
    printf("%X",encrypted[j]);
  }
  return 0;
}
