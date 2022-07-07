//50F339
#include <stdio.h>
int main(void) {
        int itemsLeft[] = {5,5,5};
        float itemPrice[] = {0.75, 1.25, 0.5};
        float moneyMade = 0;
        char items[][9] = {"cola", "candybar", "popcorn"};
        float cashInput;
        int userChoice;
        float change;
        printf("Welcome to the Vending Machine!\nEnter your choice by # and input cash amount, repeatedly (^d to end).\n");
        while(1) {
                // printing the options and their respective quantity + price
                for (int i = 0; i < 3; i++) {
			printf("[%d] %d %s left: cost is $%.2f\n", i, itemsLeft[i], items[i], itemPrice[i]);
                }
                printf("Money made so far is $%.2f\n", moneyMade);
                // value to check for valid inputs later
                int check = scanf("%d %f", &userChoice, &cashInput);
                // check for ^D input or input errors before proceeding
                if (check == EOF) {
                	break;
                }
                else if (cashInput < 0 || check < 2) {
                    	printf("malformed expression\n");
                    	return 1;
                }
                else if (userChoice > 2 || userChoice < 0 || itemsLeft[userChoice] < 1) {
                    	printf("invalid item\n");
                    	return 2;
                }
                else if (cashInput < itemPrice[userChoice]) {
                    	printf("Not enough money\n");
                    	return 3;
                }
                else {
                    	change = cashInput - itemPrice[userChoice];
                    	printf("%s is dispensed and $%.2f returned\n", items[userChoice], change);
                    	moneyMade += itemPrice[userChoice];
		    	itemsLeft[userChoice]--;
                }
        }
        // successful run msg
        printf("Thanks for your patronage!\n");
        return 0;
}

