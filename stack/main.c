#include <stdio.h>
#include "stack.c"

#define MAX     100

int main(){
        char exp[MAX+1];
        printf("Enter the equation flag\n");
        char e;
        scanf("%c", &e);

        printf("Now enter a expression wiht maximum of 100 caracteres\n");
        scanf("%s[^\n]", exp);
        scanf("\n");

        infix_to_postfix_equation(exp, e);
        //printf("FOI ATE AQUI\n");

        printf("Postfix version: %s\n", exp);

        evaluate_postfix_equation(exp, e);
        printf("Result = %s\n", exp);
        /* This proves functionality of evaluation to postfix equation
        char exp[11];
        exp[0] = '1';
        exp[1] = '0';
        exp[2] = ',';
        exp[3] = '2';
        exp[4] = ',';
        exp[5] = '^';
        exp[6] = '1';
        exp[7] = '0';
        exp[8] = ',';
        exp[9] = '*';
        exp[10] = '\0';
        // 10,2,^10,*\0 string
        // extend for infix notation:
        // (10^2) * 10 == 1000
        evaluate_postfix_equation(exp, ',');
        printf("%s\n", exp);
        */
        return 0;
}