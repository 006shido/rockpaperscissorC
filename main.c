#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int mode;
    char playAgain;

    srand(time(NULL));

    char *choices[] = {"", "Rock", "Paper", "Scissors"};

    printf("================================\n");
    printf("    ROCK PAPER SCISSORS GAME\n");
    printf("================================\n");

    do {

        int playerScore = 0;
        int computerScore = 0;

        printf("\nChoose Game Mode:\n");
        printf("1. Best of 3\n");
        printf("2. Best of 5\n");
        printf("Enter choice: ");

        while (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2)) {
            while (getchar() != '\n');
            printf("Invalid choice. Enter 1 or 2: ");
        }

        int roundsNeeded = (mode == 1) ? 2 : 3;
        int maxRounds = (mode == 1) ? 3 : 5;
        int round = 1;

        while (playerScore < roundsNeeded &&
               computerScore < roundsNeeded) {

            int playerChoice;
            int computerChoice = rand() % 3 + 1;

            printf("\n================================\n");
            printf("          ROUND %d/%d\n", round, maxRounds);
            printf("================================\n");

            printf("1. Rock\n");
            printf("2. Paper\n");
            printf("3. Scissors\n");
            printf("Enter your choice: ");

            while (scanf("%d", &playerChoice) != 1 ||
                   playerChoice < 1 ||
                   playerChoice > 3) {

                while (getchar() != '\n');
                printf("Invalid input! Enter 1, 2 or 3: ");
            }

            printf("\nYou Chose      : %s\n", choices[playerChoice]);
            printf("Computer Chose : %s\n", choices[computerChoice]);

            if (playerChoice == computerChoice) {

                printf("\nResult : Draw!\n");

            } else if (
                (playerChoice == 1 && computerChoice == 3) ||
                (playerChoice == 2 && computerChoice == 1) ||
                (playerChoice == 3 && computerChoice == 2)
            ) {

                playerScore++;
                printf("\nResult : You Win This Round!\n");

            } else {

                computerScore++;
                printf("\nResult : Computer Wins This Round!\n");
            }

            printf("\nCurrent Score\n");
            printf("----------------------------\n");
            printf("You      : %d\n", playerScore);
            printf("Computer : %d\n", computerScore);

            round++;
        }

        printf("\n================================\n");

        if (playerScore > computerScore) {

            printf("CONGRATULATIONS! YOU WON THE MATCH!\n");

        } else {

            printf("COMPUTER WON THE MATCH!\n");
        }

        printf("Final Score: You %d - %d Computer\n",
               playerScore, computerScore);

        printf("================================\n");

        printf("\nPlay Again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}
