#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/stack.h"

int bracket_open(char c) {
    return c == '(' || c == '[' || c == '{';
}

int bracket_close(char c) {
    return c == ')' || c == ']' || c == '}';
}

int bracket_match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}


int is_balanced(char exp[]) {
    int len = strlen(exp);
    stack* s = stack_new(len);
    int result = 1;
    int i = 0;
    while (result && i < len) {
        if (bracket_open(exp[i])) {
            push(s, exp[i]);
        } else if (bracket_close(exp[i])) {
            result = !stack_isempty(s) && bracket_match(top(s), exp[i]);
            if (result) {
                pop(s);
            }
        }
        i++;
    }
    result = result && stack_isempty(s);
    stack_destroy(s);
    return result;
}


void test (char* exp) {
    printf("%s\n %s\n\n", exp, is_balanced(exp)?"Balanceado":"No balanceado");
}


int main(int argc, char** argv) {

    printf("\nPruebas balance con {}, [] y ()\n");
    test("{[(3-2)*(3+4)]*(6-3)}");
    
    return 0;
}