#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Kurung {
    char node;
    struct Kurung *next;
}Kurung;

int isEmpty(Kurung *stack){
	if (stack == NULL) return 1;
	return 0;
}

void push(Kurung **stack, char node){
    Kurung *data = (Kurung*) malloc(sizeof(Kurung));
    data->node = node;
    data->next = *stack;
    *stack = data;
}

char pop(Kurung **stack){
    if(*stack == NULL){
        printf("Stack kosong");
        return '\0';
    }
    Kurung *trash = *stack;
    char node = trash->node;
    *stack = trash->next;
    free(trash);
    return node;
}

Kurung *top(Kurung *stack){
    if (stack == NULL) return NULL;
    return stack;
}

void checking(char *str){
    Kurung *stack = NULL;
    int i, len = strlen(str);
    char temp;
    for (i = 0; i < len; i++){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&stack, str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            temp = pop(&stack);
            if ((temp == '(' && str[i] != ')') ||
                (temp == '[' && str[i] != ']') ||
                (temp == '{' && str[i] != '}')) {
                printf("Invalid parenthesis expression\n\n");
                return;
            }
        } else if (str[i] != ' ' && str[i] != '\n') {
            printf("Invalid parenthesis expression\n\n", str[i]);
            return;
        }
    }
    if (isEmpty(stack)){
        printf("Valid parenthesis expression\n\n");
    } else {
        printf("Invalid parenthesis expression\n\n");
    }
}

int main() {
    char str[100] = "";
    while(1) {
        printf("Masukkan Pola: ");
        fgets(str, 100, stdin);
        if (strcmp(str, "-1\n") == 0) {
            break;
        }
        checking(str);
    }
    return 0;
}

