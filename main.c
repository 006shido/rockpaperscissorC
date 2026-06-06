#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;

    srand(time(NULL));

    printf("=== Rock Paper Scissors ===\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");

    printf("Enter your choice (1-3): ");
    scanf("%d", &user);

    computer = rand() % 3 + 1;

    printf("\n");

    // Display of choices
    char *choices[] = {"", "Rock", "Paper", "Scissors"};

    printf("You chose: %s\n", choices[user]);
    printf("Computer chose: %s\n", choices[computer]);

    // Determination of winner
    if (user == computer) {
        printf("Result: Draw!\n");
    }
    else if (
        (user == 1 && computer == 3) ||
        (user == 2 && computer == 1) ||
        (user == 3 && computer == 2)
    ) {
        printf("Result: You Win!\n");
    }
    else {
        printf("Result: Computer Wins!\n");
    }

    return 0;
}
