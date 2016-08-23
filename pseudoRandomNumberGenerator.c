//
//  pseudoRandomNumberGenerator.c
//  
//
//  Created by Michael Svensson on 2016-08-15.
//
//

#include "pseudoRandomNumberGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
//
// Define variables
//
    int n;
    int i;
    int highest;
    int xrandom;
    int ret;
    char dicerule[] = "n";
    char diceyes[] = "y";
    time_t t;
//
// Initialze random number generator
//
    srand((unsigned) time(&t));
//
// Ask for how many digits user wants
//
    printf("How many random numbers do you want? ");
    scanf("%d", &n);
//
// Ask for highest value on digit
//
    printf("What is the highest value you want? ");
    scanf("%d", &highest);
    int numberOfDigits = highest + 1;
//
// Ask if dice-rule when highest value is six (the zero-value not included)
//
    if (highest == 6) {
        printf("Do you want dice-rule (zero value not included? y/n ");
        scanf("%s", dicerule);
    }
//
// Declare and initiate an array for summary of generated random numbers
//
    int arraySum[numberOfDigits];
    for (i=0; i <= highest; i=i+1) {
        arraySum[i] = 0;
    }
//
//
// Generate random number to keyboard
//
    for(i = 0 ; i < n ; i=i+1 )
    {
        xrandom = rand() % numberOfDigits;
        ret = strcmp(dicerule, diceyes);
        // Dice-rule dont print zeroes otherwise print all
        if (ret == 0 && xrandom > 0) {
            arraySum[xrandom] = arraySum[xrandom] + 1;
            printf("%d\n", xrandom);
        }
        if ((ret > 0) || (ret < 0)) {
            arraySum[xrandom] = arraySum[xrandom] + 1;
            printf("%d\n", xrandom);
        }
    }

//
// Show statistics of generated numbers
//
    i = 0;
    printf("SUMMARY\n");
    for (i = 0; i <= highest; i=i+1) {
        printf("%d = %d\n", i, arraySum[i]);
    }
//
//
    getchar();
    return 0;
}
