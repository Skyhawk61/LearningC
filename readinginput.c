//
//  readinginput.c
//  
//
//  Created by Michael Svensson on 2016-08-11.
//
//

#include "readinginput.h"
int main()
{
//
// Define variables
//
    int weight;
    int age;
    int x;
//
    float length;
    float bmi;
//
    char name;
//
    long lngSum;
    long lngTemp;
    long CheckNumber;
//
// Set constants
//
    char advice1[] = "You are very overweighted and ranked as obese - beware";
    char advice2[] = "You are overweighted - start training";
    char advice3[] = "You have normal weight continue do what you are doing";
    char advice4[] = "Your weight is to low - start eating more";
//
// Ask for name
//
    printf("Enter your name: ");
    scanf("%s", &name );
//
// Ask for weight
//
    printf("Enter your weight: ");
    scanf("%d", &weight );
//
// Ask for length
//
    printf("Enter your length: ");
    scanf("%f", &length );
//
// Calculate BMI (weight/length* length))
//
    bmi = weight/(length*length);
//
// Show BMI value on screen
//
    printf("Your bmi is %f\n", bmi );
//
// Show status of weight according to BMI value
//
    if (bmi > 30) {
        printf("%s\n", advice1); /* Obese */
    }
    if (bmi >= 26 && bmi <= 30) {
        printf("%s\n", advice2); /* Overweight */
    }
    if (bmi >= 19 && bmi < 26) {
        printf("%s\n", advice3); /* Normal */
    }
    if (bmi < 19) {
        printf("%s\n", advice4); /* Anorectic */
    }
//
// Test if, else if and else
//
    if (bmi > 30) {
        printf("FATTO\n");
    } else if (bmi < 19){
        printf("SKINNY\n");
    }
    else
        printf("NORMAL\n");
//
// Rocket science testing for
//
//
    for (x = 10; x >= 0; x=x-1) {
        printf("%d\n", x);
    }
    printf("TJABOOOOOOOOOM!!!!!\n");
//
// Rocket science testing while
//
    x=0;
    while (x < 11) {
        printf("%d\n", x);
        x=x+1;
    }
//
// räkna ut checksiffran i personnr
    printf("Enter first 9 digits of social security number: ");
    scanf("%d", &name );

    lngSum = 0;
    for (int lngPos = 0; lngPos < strNumber.Length; lngPos++)
    {
        lngTemp = long.Parse(strNumber.Substring(lngPos, 1)) * (((lngPos + 1) % 2) + 1);
        if (lngTemp > 9)
        {
            lngTemp = lngTemp - 9;
        }
        lngSum = lngSum + lngTemp;
    }
    CheckNumber = 10 - (lngSum % 10);
    return CheckNumber;
}

//
    getchar();
    return 0;
}
