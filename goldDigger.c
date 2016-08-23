//
//  goldDigger.c
//  
//
//  Created by Michael Svensson on 2016-08-16.
//
//

#include "goldDigger.h"
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
    int mode;
    int highest;
    int xrandom;
    int xprevious;
    int correct;
    int xguess;
    int numberOfDigits;
    int xseries;
    float xx;
    float xxx;
    float pocenten;
    time_t t;
    //
    // Initialze random number generator
    //
    srand((unsigned) time(&t));
    //
    // Initiate generated correct guesses and how many buckets
    //
    numberOfDigits = 3;
    correct = 0;
    //
    // Explain rules
    //
    printf(" \n");
    printf("******************************************************\n");
    printf("*  Hello, here are the golden rules:                 *\n");
    printf("*                                                    *\n");
    printf("*  Three buckets, one with gold two with sand        *\n");
    printf("*  With change mode selection is changed every time  *\n");
    printf("*  So first 1 of 3, then changed                     *\n");
    printf("*                                                    *\n");
    printf("*  Otherwise original choice used (1 of 3):          *\n");
    printf("*                                                    *\n");
    printf("******************************************************\n");
    printf(" \n");
    //
    //
    // Ask for how many draws user wants
    //
    printf("How many draws do you want? ");
    scanf("%d", &n);
    //
    // Ask for change mode or not change mote
    //
    mode = 0;
    printf("Do you want change mode (0=no, 1=yes)? ");
    scanf("%d", &mode);
    while ((mode != 0) && (mode !=1)) {
        printf(" \n");
        printf("Are you stupid?????? \n");
        printf(" \n");
        printf("Answer 0 for no or 1 for yes! \n");
        printf("Try again! \n");
        printf(" \n");
        printf("Do you want change mode (0=no, 1=yes)? ");
        scanf("%d", &mode);
    }
    //
    // Declare and initiate an array for summary of generated gold numbers
    //
    int arrayGold[numberOfDigits];
    for (i=0; i <= numberOfDigits; i=i+1) {
        arrayGold[i] = 0;
    }
    //
    // Declare and initiate an array for storing longest series
    //
    int arrayHighest[numberOfDigits];
    for (i=0; i <= numberOfDigits; i=i+1) {
        arrayHighest[i] = 0;
    }
    xprevious=0;
    //
    //
    // Generate random number to keyboard
    //
    for(i = 0 ; i < n ; i=i+1 )
    {
        xrandom = rand() % numberOfDigits;
        printf("%d\n", xrandom);
        xguess = rand() % numberOfDigits;
        arrayGold[xrandom] = arrayGold[xrandom] + 1;
    //
        if (xrandom == xprevious) {
            xseries = xseries + 1;
        } else {
            if (xseries > arrayHighest[xprevious]) {
                arrayHighest[xprevious]=xseries;
                xseries = 0;
            } else {
                xseries = 0;
            }
            xprevious=xrandom;
        }
    //
        // Add success in nochange mode
        if (mode == 0) {
            if (xguess == xrandom) {
                correct = correct + 1;
            }
        }
        // Change mode - change your option
        if (mode == 1) {
            if (xguess == 0) {
                xguess = 2;
                if (xrandom == 1) {
                    xguess = 1;
                }
            }
            if (xguess == 1) {
                xguess = 0;
                if (xrandom == 2) {
                    xguess = 2;
                }
            }
            if (xguess == 2) {
                xguess = 0;
                if (xrandom == 1) {
                    xguess = 1;
                }
            }
            // Sum if correct
            if (xguess == xrandom) {
                correct = correct + 1;
            }
        }
    // end for
            }
    //
    // Show statistics of generated numbers
    //
    i = 0;
    printf(" \n");
    printf("*******************************************************\n");
    printf("*                                                     *\n");
    printf("*  SUMMARY: Where randomized gold was hidden          *\n");
    printf("*                                                     *\n");
    if (mode == 0) {
        printf("*  RUNNING MODE: Original selection                   *\n");
    } else {
        printf("*  RUNNING MODE: Change selection                     *\n");
    }
    printf("*  NUMBER OF DRAWS: %d                               *\n", n);
    printf("*                                                     *\n");
    for (i = 0; i < numberOfDigits; i=i+1) {
        printf("*  Bucket %d had gold %d times that is ", i, arrayGold[i]);
        xx = arrayGold[i];
        xxx = n;
        pocenten = (xx / xxx) * 100;
        printf(" %.1f", pocenten);
        printf("%%");
        printf("          *\n");
    }
    xx = correct;
    xxx = n;
    pocenten = (xx / xxx) * 100;
    printf("*                                                     *\n");
    printf("*  NUMBER OF CORRECT GUESSES: %d THAT IS %.1f", correct, pocenten);
    printf("%%");
    printf("        *\n");
    printf("*                                                     *\n");
    for (i = 0; i < numberOfDigits; i=i+1) {
        printf("*  Bucket %d had longest serie %d  ", i, arrayHighest[i]);
        printf("                     *\n");
    }
    printf("*                                                     *\n");
    printf("*******************************************************\n");
    printf(" \n");
    printf(" \n");
    //
    //
    getchar();
    return 0;
}
