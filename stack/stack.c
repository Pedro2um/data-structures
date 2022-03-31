#ifndef STACK_C
#define STACK_C

// Headeach and pain in 04:57 UTC-3 31/03/2022 

#include "stack.h"
#include <string.h>

#define  MY_OPEN_CHARS(x)    ( ((x)==('{')) ||  ((x)==('(')) || ((x)==('[')) )?true:false    
#define  MY_CLOSE_CHARS(x)   ( ((x)==('}')) ||  ((x)==(')')) || ((x)==(']')) )?true:false   
#define  MAX_NUM_DIGITS_IN_DECIMAL_BASE         6           
#define  MAX_STRING_CHARS                       100

void     push(stack* stack, int data){
        if(stack == NULL){
                printf("STACK POINTER IS NULL\n");
                assert(0);
        }
        insert_node_at_head(stack, data);
}
void     pop(stack* stack){
        if(stack == NULL){
                printf("STACK POINTER IS NULL\n");
                assert(0);
        }
        if(top(stack) != NULL) delete_head_node(stack);
        else {
                printf("WARNING, TOP OF STACK IS EMPTY\n");
                return;
        }
}
node*    top(stack* stack){
        if(stack == NULL){
                printf("STACK POINTER IS NULL\n");
                assert(0);
        }
        return stack->head;
}
bool     is_empty(stack* stack){
        if(stack == NULL){
                printf("STACK POINTER IS NULL\n");
                assert(0);
        }
        if(top(stack) == NULL) return true;
        return false;
}
void     reverse_string(char* string){
        stack* temp_stack = malloc(sizeof(stack));
       
        if(temp_stack == NULL){
                printf("ERRO IN MALLOC IN FUNCTION REVERSE STRING\n");
                assert(0);
        }
        else if(string == NULL){
                printf("ERRO, POINTER TO STRING IS NULL IN FUNCTION REVERSE STRING\n");
                assert(0);
        }
        int i;
        for(i = 0; string[i] != '\0'; i++){
                push(temp_stack, string[i]);
        }
        
        for(i = 0; !is_empty(temp_stack) && string[i] != '\0'; i++){
                
                if(top(temp_stack) == NULL) break;
                string[i] = top(temp_stack)->data;
                pop(temp_stack);
        }
        
}

//only works for ) ,  }  and  ]
char opposite_of_my_close_char(char c) {
                if(c == ')') return '(';
                else if(c == '}') return '{';
                else if(c == ']') return '[';
}

bool     is_balanced(char* string){

         stack* temp_stack = malloc(sizeof(stack));
       // printf("ola\n");
        if(temp_stack == NULL){
                printf("ERRO IN MALLOC IN FUNCTION REVERSE STRING\n");
                assert(0);
        }
        else if(string == NULL){
                printf("ERRO, POINTER TO STRING IS NULL IN FUNCTION REVERSE STRING\n");
                assert(0);
        }

        int i = 0;


        for(i = 0; string[i] != '\0'; i++){
                //push only open
                if( MY_OPEN_CHARS(string[i]) ) {
                        push(temp_stack, string[i]);
                }
                else if( MY_CLOSE_CHARS(string[i]) ){
                        if(is_empty(temp_stack)){
                                return false;
                        }
                        if(top(temp_stack)->data != opposite_of_my_close_char(string[i]) ){
                                return false;
                        }
                        else {
                                pop(temp_stack);
                        }
                }
        }

        if(!is_empty(temp_stack)) return false;
        return true; // obs: empty string and string without any () or {} or [], is balanced

}

bool is_operator(char c){
        if( c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
                return true;
        }
        return false;
}

int fast_power(int a, int b){
        int ans = 1;
        while(b > 0){
                if(b&1) ans *= a;
                a *= a;
                b >>= 1;
        }
        return ans;
}

int  perform_operation(char c, int x, int y){
        if(c == '+'){
                return x+y;
        }
        else if(c == '-'){
                return x-y;
        }
        else if(c == '*'){
                return x*y;
        }
        else if(c == '/'){
                return x/y;
        }
        else if(c == '^'){
                return fast_power(x, y);
        }
        else {
                assert(0);
        }
}

/*      
        Considering a perfect expression made by infix_to_postfix function, no erro handling, only positive numbers.
        Every operand (num) should have a equation_flag after it.
        SHOULD NOT HAVE EQUATION FLAG AFTER OPERATOR! 
        OPERATORS -> ( +  , -  , +  , /  , ^ )
*/ 
void    evaluate_postfix_equation(char* string, char equation_flag){
        
        stack* temp_stack = malloc(sizeof(stack));

        if(temp_stack == NULL){
                printf("EVALUATE POSTFIX EQUATION FUNCTION: ERROR IN MALLOC\n");
                assert(0);
        }
        else if(string == NULL){
                printf("EVALUATE POSTFIX EQUATION FUNCTION: ERROR, STRING PASS IS NULL\n");
                assert(0);
        }
        else if( is_operator(equation_flag) == true){
                printf("EVALUATE POSTFIX EQUATION FUNCTION: ERROR, EQUATION FLAG SHOULD NOT BE EQUAL OPERATORS!\n");
                assert(0);
        }

        char temp_string[MAX_NUM_DIGITS_IN_DECIMAL_BASE];

        int i = 0, j = 0;

        for(i = 0, j = 0; string[i] != '\0'; i++){

                if( is_operator(string[i]) == false && string[i] != equation_flag){

                        temp_string[j] = string[i];
                        j++;

                }
                else if(string[i] == equation_flag ){

                        int temp_num = atoi(temp_string);
                        printf("TEMP_NUM: %d\n", temp_num);
                        push(temp_stack, temp_num);
                        memset(temp_string, '\0', MAX_NUM_DIGITS_IN_DECIMAL_BASE);
                        j = 0;

                }
                else{
                         
                        int op2 = top(temp_stack)->data;
                        pop(temp_stack);

                        //printf("OP2: %d ", op2);

                        int op1 = top(temp_stack)->data;
                        pop(temp_stack);

                        //printf("OP1: %d ", op1);

                       // printf("OPERADOR: %c ", string[i]);

                        int result = perform_operation(string[i], op1, op2);
                        //printf("RESULTADO DA OPERACAO: %d\n", result);

                        push(temp_stack, result);

                }

        }

        memset(string, '\0', i);
        sprintf(string, "%d", top(temp_stack)->data);
        free(temp_stack);
}

//check if y has higher precision than x
bool    has_higher_prec(char x, char y){
        short int value_x=1, value_y=1;

        if(x == '^'){
                value_x = 3;
        }
        else if(x == '*' || x == '/'){
                value_x = 2;
        }


        if(y == '^'){
                value_y = 3;
        }
        else if(y == '*' || y == '/'){
                value_y = 2;
        }

        return (value_y > value_x);
       
        return false;
}

void change_all_specifiers_to_parentheses(char* string){
        for(int i = 0; string[i] != '\0'; i++){
                if(string[i] == '{' || string[i] == '['){
                        string[i] = '(';
                } 
                else if(string[i] == '}' || string[i] == ']'){
                        string[i] = ')';
                } 
        }
}

//last version, works for ANY balanced expression
void     infix_to_postfix_equation(char* string, char equation_flag){
        char* result = calloc( (MAX_STRING_CHARS+1), sizeof(char));
        if(result == NULL){
                printf("INFIX TO POSTFIX EQUATION FUNCTION: ERROR IN CALLOC OF RESULT STRING\n");
                assert(0);
        }
        stack* temp_stack = malloc(sizeof(stack));

        if(temp_stack == NULL){
                printf("INFIX TO POSTFIX EQUATION FUNCTION: ERROR IN MALLOC OF TEMPORARY STACK\n");
                assert(0);
        }
        else if(string == NULL){
                printf("INFIX TO POSTFIX EQUATION FUNCTION: ERROR, STRING PASS IS NULL\n");
                assert(0);
        }
        else if( is_operator(equation_flag) == true){
                printf("INFIX TO POSTFIX EQUATION FUNCTION: ERROR, EQUATION FLAG SHOULD NOT BE EQUAL OPERATORS!\n");
                assert(0);
        }
        else if(!is_balanced(string)){
                printf("INFIX TO POSTFIX EQUATION FUNCTION: ERROR, STRING SHOULD BE BALANCED!\n");
                assert(0);
        }

        change_all_specifiers_to_parentheses(string);

        int i = 0, j = 0;
        for(i = 0, j = 0; string[i] != '\0'; i++){

                if(is_operator(string[i]) == false){

                        if( string[i] != '(' && string[i] != ')' && result[j] != equation_flag ){
                                result[j] = string[i];
                                j++;
                        } 

                }
                else if(string[i] == '('){
                        push(temp_stack, string[i]);
                }
                else if(string[i] == ')'){
                        while(!is_empty(temp_stack) && top(temp_stack)->data != '('){
                                
                                if(result[j] != equation_flag){
                                        result[j] = top(temp_stack)->data;
                                        j++;
                                }
                                pop(temp_stack);
                        }
                        // pop the opening parentheses
                        pop(temp_stack);
                }
                else {

                        if( is_operator(result[j]) == false && result[j] != '(' && result[j] != ')' ){
                                
                                result[j] = equation_flag;
                                j++;
                        }
                        
                        // if the operator that is in the stack has higher precision than the current operator
                        // we gonna put in to the resulting expression this operator, then pop him
                        // doing this until the below conditions are broken
                        while(  !is_empty(temp_stack) && (top(temp_stack)->data != '(') && has_higher_prec(string[i], top(temp_stack)->data) ){

                                if(top(temp_stack)->data != '(' && top(temp_stack)->data != ')'){
                                        
                                        result[j] = top(temp_stack)->data;
                                        j++;
                                }
                                pop(temp_stack);
                        }
                        // put the current operator in to the stack
                       
                        push(temp_stack, string[i]);
                }

        }

        // if we finished the whole original string but the stack is not empty,
        // that means, we should put the flag in case of the previous char of the resulting string isn't a operator
        // then put the operator in to the resulting string
        // doing this until the condition is broke
        while(!is_empty(temp_stack)){
                if( !is_operator(result[j-1]) && result[j-1] != equation_flag ){
                        
                        result[j] = equation_flag;
                        j++;
                }
                
                if( top(temp_stack)->data != '(' && top(temp_stack)->data != ')'){

                        result[j] = top(temp_stack)->data;
                        j++;
 
                } 
                pop(temp_stack);
        }

        // set all chars of our original string to \0
        // then copy the result for her
        memset(string, '\0', MAX_STRING_CHARS);
        strcpy(string, result);

        free(result);
        delete_linked_list(temp_stack);
}

#endif
