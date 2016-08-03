// **** Include libraries here ****
// Standard libraries

//CMPE13 Support Library
#include "BOARD.h"
#include "Stack.h"

// Microchip libraries
#include <xc.h>
#include <plib.h>
#include <stdio.h>
#include <string.h>
// User libraries

// **** Set macros and preprocessor directives ****

// **** Define global, module-level, or external variables here ****

// **** Declare function prototypes ****
/*
 * Function prototype for ProcessBackspaces() - This function should be defined
 * below main after the related comment.
 */
int ProcessBackspaces(char *rpn_sentence);

// If this code is used for testing, rename main to something we can call from our testing code. We
// also skip all processor configuration and initialization code.
#ifndef LAB4_TESTING

int main()
{
    BOARD_Init();
#else

int their_main(void)
{
#endif // LAB4_TESTING

    /******************************** Your custom code goes below here *******************************/
    printf("Welcome to Dustin's RPN Calculator\n");
    char *token;
    char input[60];
    struct Stack inputFeed;

    float in1, in2, res;
    int test1, test2, test3;
    while (1) {
        //Begin of Calculator loop
        StackInit(&inputFeed);
        printf("Please enter the numbers and operators: \n");
        //READ IN THE INPUTS
        fgets(input, 61, stdin);
        //PARSE THE INPUTS
        char *temp = strtok(input, "\r\n");
        token = strtok(temp, " ");
        while (token != NULL) {
            //printf("token: %s\n", token);
            //CHECK IF ITS AN INT AND IF IT IS PUSH
            if (atof(token) > 0 || *token == '0') {
                StackPush(&inputFeed, (float) atof(token));
            } else if (*token == '+') {
                test1 = StackPop(&inputFeed, &in1);
                test2 = StackPop(&inputFeed, &in2);
                res = in1 + in2;

                test3 = StackPush(&inputFeed, res);
                if (test1 == STANDARD_ERROR || test2 == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator");
                    break;
                } else if (test3 == STANDARD_ERROR) {
                    printf("ERROR: No more room on Stack");
                    break;
                }
            } else if (*token == '-') {
                test1 = StackPop(&inputFeed, &in1);
                test2 = StackPop(&inputFeed, &in2);
                res = in1 - in2;
                test3 = StackPush(&inputFeed, res);
                if (test1 == STANDARD_ERROR || test2 == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator");
                    break;
                } else if (test3 == STANDARD_ERROR) {
                    printf("ERROR: No more room on Stack");
                    break;
                }
            } else if (*token == '*') {
                test1 = StackPop(&inputFeed, &in1);
                test2 = StackPop(&inputFeed, &in2);
                res = in1*in2;
                test3 = StackPush(&inputFeed, res);
                if (test1 == STANDARD_ERROR || test2 == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator");
                    break;
                } else if (test3 == STANDARD_ERROR) {
                    printf("ERROR: No more room on Stack");
                    break;
                }
            } else if (*token == '/') {
                test1 = StackPop(&inputFeed, &in1);
                test2 = StackPop(&inputFeed, &in2);
                res = in1 / in2;
                test3 = StackPush(&inputFeed, res);
                if (test1 == STANDARD_ERROR || test2 == STANDARD_ERROR) {
                    printf("ERROR: Not enough operands before operator");
                    break;
                } else if (test3 == STANDARD_ERROR) {
                    printf("ERROR: No more room on Stack");
                    break;
                }
            } else {
                printf("ERROR: Invalid Character in the RPN String");
                break;
            }
            token = strtok(NULL, " ");
        }

        if (StackGetSize(&inputFeed) > 1) {
            printf("ERROR: Invalid RPN calculation: more or less than one item in the stack");
        }
        StackPop(&inputFeed, &res);
        printf("Answer: %f\n", (double) res);

    }
    /*    while (1) {
            fgets(inputFeed, 61, stdin);
            token = strtok(inputFeed, delim);
            if (inputFeed.currentItemIndex > 2) {
                if (strlen(token) == 1) {

                    if (strcmp(token, "*") == 0) {
                        StackPush(inputFeed, (float) StackPop() * StackPop());
                    }
                }
            }

        }*/



    /*************************************************************************************************/

    // You can never return from main() in an embedded system (one that lacks an operating system).
    // This will result in the processor restarting, which is almost certainly not what you want!
    while (1);
}

/**
 * Extra Credit: Define ProcessBackspaces() here - This function should read through an array of
 * characters and when a backspace character is read it should replace the preceding character with
 * the following character. It should be able to handle multiple repeated backspaces and also
 * strings with more backspaces than characters. It should be able to handle strings that are at
 * least 256 characters in length.
 * @param rpn_sentence The string that will be processed for backspaces. This string is modified in
 *                     place.
 * @return Returns the size of the resultant string in `rpn_sentence`.
 */
int ProcessBackspaces(char *rpn_sentence)
{
    return 0;
}



