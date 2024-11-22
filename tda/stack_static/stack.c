#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct _stack {
    t_elem* values;
    int maxsize;
    int count;
} stack;

// crear un pila nueva
stack* stack_new(int maxsize){
    stack* s = (stack*) malloc(sizeof(stack));
    s->values = (t_elem*) malloc(maxsize * sizeof(t_elem));
    s->maxsize = maxsize;
    s->count = 0;
    return s;    
}

// liberar la memoria de una pila vacía
void stack_free(stack* s){    
  if (!stack_isempty(s)) {
    printf("Stack not empty\n");
    exit(1);
  }
  free(s->values);
  free(s);    
}

// agregar un elemento a la pila
void push(stack* s, t_elem elem){
    if (stack_isfull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->values[s->count] = elem;
    s->count++;    
}

// quitar un elemento de la pila
t_elem pop(stack* s){
    if (stack_isempty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    s->count--;
    return s->values[s->count];        
}

// obtener el elemento al tope de la pila
t_elem top(stack* s){
    if (stack_isempty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->values[s->count - 1];    
}

// consultar si la pila está vacía
int stack_isempty(stack* s){
    return (s->count == 0);        
}

// consultar si la pila está llena
int stack_isfull(stack* s){
    return (s->count == s->maxsize);    
}

// obtener la cantidad de elementos en la pila
int stack_length(stack* s){
    return s->count;        
}

// obtener el tamaño máximo de la pila
int stack_maxsize(stack* s){
    return s->maxsize;    
}

// Eliminar todos los elementos de la pila y liberar la memoria
void stack_destroy(stack* s){
    free(s->values);
    free(s);        
}