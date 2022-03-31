#ifndef STACK_H
#define STACK_H

#include "linkedlist.c"

typedef linked_list stack; 
//LIFO - Last In First Out
// All below operations can be done in O(1) time complexity:
// push
// pop
// top
// is_empty

static void     push(stack* stack, int data);
static void     pop(stack* stack);
static node*    top(stack* stack);
static bool     is_empty(stack* stack);

// takes O(n) time and O(n) extra space
static void     reverse_string(char* string);
// OBS: you can use a anolog logic for reverse a linked list in a extravagant but simple way
// i not gonna do this specific function because a alrady know how to reverse a linked list

//check for balanced parentheses, curly braces and brackets 
static bool     is_balanced(char* string);

// Evaluating expression problems of Infix operations
// 1) Parentheses and so on (), {}, [] - is deal by balanced parentheses function  
// 2) Exponents - right to left 
// 3) Multiplication and Division - left to right
// 4) Addition and Subtraction - left to right
// a lot to deal with!

// Example of Infix: a + b * c
//Solutions: 
//      Polish notation 
//      Prefix:         + a * b c
//
//      Reverse Polish notation
//      Postfix:        a b c * +
//
static char     opposite_of_my_close_char(char c);
static void     change_all_specifiers_to_parentheses(char* string);
static bool     has_higher_prec(char x, char y);
static void     infix_to_postfix_equation(char* string, char equation_flag);

static bool     is_operator(char c);

//somenthing that i learn for Competitive Programing
static int      fast_power(int a, int b);
static int      perform_operation(char c, int x, int y);
static void     evaluate_postfix_equation(char* string, char equation_flag);

#endif
