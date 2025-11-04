#include <stdio.h>
#include <stdlib.h>

enum hand {rock, paper, scissors};

enum hand hand_of_char(char c);
void print_hand(enum hand h);

int main(void) {
char spiller1_input, spiller2_input;

// Tag imod input fra brugerne
printf("Spiller 1, indtast dit valg (r/p/s): \n");
scanf(" %c", &spiller1_input);

printf("Spiller 2, indtast dit valg (r/p/s): \n");
scanf(" %c", &spiller2_input);

enum hand spiller1 = hand_of_char(spiller1_input);
enum hand spiller2 = hand_of_char(spiller2_input);

// Udskriv hænderne
printf("Spiller1: \n");
print_hand(spiller1);
printf("\nSpiller2: \n");
print_hand(spiller2);
printf("\n");

//Regn ud om spiller 1 har vundet
int spiller1_vandt = ( spiller1 == scissors && spiller2 == paper ) ||
                     ( spiller1 == paper && spiller2 == rock ) ||
                     ( spiller1 == rock && spiller2 == scissors );

int uafgjort = ( spiller1 == spiller2 );

// Skriv på skærmen hvem der vandt eller om det blev uafgjort
if (spiller1_vandt) {
    printf("Spiller 1 vandt!\n");
} else if (uafgjort) {
    printf("Uafgjort!\n");
} else {
    printf("Spiller 2 vandt!\n");
}

    return 0;
}

void print_hand(enum hand h) {
    switch (h) {
        case rock:
            printf("Sten");
            break;
        case paper:
            printf("Saks");
            break;
        case scissors:
            printf("Papir");
            break;
        default:
            printf("Ugyldigt valg!");
            exit(EXIT_FAILURE);
    }
}

enum hand hand_of_char(char c) {
    enum hand h;

    switch (c) {
        case 'r':
            h = rock;
            break;
        case 'p':
            h = paper;
            break;
        case 's':
            h = scissors;
            break;
        default:
            printf("Ugyldigt valg! Brug 'r', 'p' eller 's'.\n");
            exit(EXIT_FAILURE);
    }
    return h;
}
