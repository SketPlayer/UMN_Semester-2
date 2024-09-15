#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
    int num;
    struct Angka *next;
} Angka;

int isEmpty(Angka *queue){
	if (queue == NULL) return 1;
	return 0;
}

void enqueue(Angka **head, Angka **tail, int num) {
	Angka *data = (Angka*) malloc(sizeof(Angka));
    int i;
	data->num = num++;
    data->next = NULL;
    
    if (isEmpty(*head)) *head = data;
	else (*tail)->next = data;
	*tail = data;
}

int dequeue(Angka *queue) {
    int i;
    if(isEmpty(*head)){
		printf("Queue kosong\n");
		return -1;
	}
	
	Angka *trash = *head;
	*head = trash->next;
	free(trash);
}


Angka *front(Angka *queue){
	if(queue == NULL) return NULL;
	return queue;
}


int main() {
    int num, i;
    Angka *head, *tail;
    head = tail = NULL;

    while (1) {
        printf("Masukkan angka: ");
        scanf("%d", &num);
	

    return 0;
}

