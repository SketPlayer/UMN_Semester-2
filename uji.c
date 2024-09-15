#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Angka {
    int num;
    struct Angka *next;
} Angka;

int isEmpty(Angka *queue){
    if (queue == NULL) return 1;
    return 0;
}

void enqueue(Angka **head, Angka **tail, int num) {
    Angka *data = (Angka*) malloc(sizeof(Angka));
    data->num = num;
    data->next = NULL;
    
    if (isEmpty(*head)) *head = data;
    else (*tail)->next = data;
    *tail = data;
}

int dequeue(Angka **head, Angka **tail) {
    if(isEmpty(*head)){
        printf("Queue kosong\n\n");
        return 0;
    }
    
    Angka *trash = *head;
    *head = trash->next;
    free(trash);
    return 0;
}

Angka *front(Angka *queue){
    if(queue == NULL) return NULL;
    return queue;
}

void printQueue(Angka *head) {
    printf("Isi Queue: ");
    while (head != NULL) {
        printf("%d ", head->num);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int num, i;
    Angka *head, *tail;
    head = tail = NULL;

    while (1) {
    printf("Masukkan angka: ");
    scanf("%d", &num);

    if (isEmpty(head)) {
        for (i = 0; i < num; i++) {
            enqueue(&head, &tail, num);
        }
    } else {
        if (num < front(head)->num) {
            for (i = 0; i < num; i++) {
                dequeue(&head, &tail);
            }
        } else {
            for (i = 0; i < front(head)->num; i++) {
                enqueue(&head, &tail, front(head)->num);
            }
        }
    }

    printQueue(head);
    printf("\n");
}

    return 0;
}

