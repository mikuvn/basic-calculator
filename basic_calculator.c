#include <stdio.h>
#include <math.h>

// Prototypes
void firstInput(double *ans, double *lastAns);
int operator(char op);
void printDecimal(double x);
void divHandler();

double addition(double x, double y);
double subtraction(double x, double y);
double multiplication(double x, double y);
double division(double x, double y);
double power(double x, double y);

// global var
double answer, lastAnswer;

int main(void) {
    // Input variables, constantly redefined.
    double x; // input cal
    int operation;
    char op;

    // Logic variables.
    int firstCheck = 1;
    int equalsEntered = 0;

    printf("This is a basic calculator program, valid operators are:\n\n\t+ | add\n\t- | subtract\n\t* | multiply\n\t/ | divide\n\t^ | exponent\n\t= | answer (enter to end program)\n\t# | clear answer\n\n");
    printf("Variables and fractional values do not work (properly at least), order of operation is not followed...\nOperation done in the order entered from left to right.\n\n");

    // Gets starting number, important for when first operation value is =, will return number as is.
    firstInput(&answer, &lastAnswer);

    // Loop that keeps tracks of the answer and inputs.
    while (equalsEntered == 0) {
        scanf(" %c", &op);
        operation = operator(op);
        if (operation == -1) {
            lastAnswer = 0;
            answer = 0;
            printf("Answer cleared...\n");
            firstInput(&answer, &lastAnswer);
        }
        else if (operation == 0) {
            equalsEntered = 1; // When "=" is entered, loop stops and returns answer as is.
        }
        else {
            // operation using the last recorded answer, sends prints answer which can be used with other operators afterward.
            scanf("%lf", &x);
            if (operation == 1) {
                answer = addition(lastAnswer, x);
                printDecimal(answer);
            }
            else if (operation == 2) {
                answer = subtraction(lastAnswer, x);
                printDecimal(answer);
            }
            else if (operation == 3) {
                answer = multiplication(lastAnswer, x);
                printDecimal(answer);
            }
            else if (operation == 4) {
                answer = division(lastAnswer, x);
                if (x != 0) {
                    printDecimal(answer);
                }
                else if (x == 0) {
                    firstInput(&answer, &lastAnswer);
                }
            }
            else if (operation == 5) {
                answer = power(lastAnswer, x);
                if ((lastAnswer == 0) && (x < 0)) {
                    firstInput(&answer, &lastAnswer);
                }
                else {
                    printDecimal(answer);
                }
            }
            // takes answer and records it to last answer to use in later computation.
            lastAnswer = answer;
        }
    }
    // at the end of the loop (loop ends when '=' is entered), prints the most recent answer computed.
    printDecimal(answer);

    return 0;
}

// Functions
// gets the first input, used when clearing answer, returns values using pointers.
void firstInput(double *ans, double *lastAns) {
    double x;
    scanf("%lf", &x);
    *ans = x;
    *lastAns = x;
}
// switch statement that checks what operator was entered, returns a value which equates to operation logic (what operation to use).
int operator(char op) {
    switch (op) {
        case '#': {
            return -1;
            }
        case '=': {
            return 0;
            }
        case '+': {
            return 1;
            }
        case '-': {
            return 2;
            }
        case '*': {
            return 3;
            }
        case '/': {
            return 4;
            }
        case '^': {
            return 5;
            }
        default: {
            printf("Invalid input... (Format is: [ans] [+,-,*,/,^] [number])\n");
        }
    }
}

// returns decimal value if decimal value exists up to the thousandths place, integer if otherwise.
void printDecimal(double x) {
    int y =(int)(x*1000);
    
    if (((y%1000) > 0) || ((y%1000) < 0)) {
        if (((y%100)) == 0) {
            printf("= %.1lf", x);
        }
        else if (((y%100) > 0) || ((y%100) < 0)) {
            if (((y%10) > 0) || ((y%10) < 0)) {
                printf("= %.3lf", x);
            }
            else {
                printf("= %.2lf", x);
            }
        }
        else {
            printf("= %.0lf", x);
        }
    }
    else {
        printf("= %d", (int)x);
    }
}

// arithmetic functions, used in conjuction with operator function.
double addition(double x, double y) {
    return (x + y);
}
double subtraction(double x, double y) {
    return (x - y);
}
double multiplication(double x, double y) {
    return (x * y);
}
double division(double x, double y) {
    if (y == 0) {
        printf("Error: divide by 0...\n");
        return x;
    }
    return (x / y);
}
double power(double x, double y) {
    if ((x == 0) && (y < 0)) {
        printf("Error: divide by 0...\n");
        return x;
    }
    else if ((y == 0)) {
        return 1;
    }
    return (pow(x, y));
}
