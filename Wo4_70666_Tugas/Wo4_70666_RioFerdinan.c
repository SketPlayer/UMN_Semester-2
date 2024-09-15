#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Mahasiswa {
	char nama[100];
	int nim;
	struct Mahasiswa *next;
}Mahasiswa;

Mahasiswa *createNewNode(int nim, char *nama){
	Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
	newNode->nim = nim;
	strcpy(newNode->nama, nama);
	newNode->next = NULL;
	return newNode;
}

void printLinkedList(Mahasiswa *head) {
	Mahasiswa *temp;
	temp = head;
	int i = 1;
	if(head == NULL){
        printf("\nLinked List kosong");
    }
	else {
	while(temp != NULL){
		printf("\nData ke %d, NIM	: %d, Nama	: %s", i, temp->nim, temp->nama);
		temp = temp->next;
		i++;
		}
	}
	printf("\n\n");
}

void insertNewNode(Mahasiswa **head, Mahasiswa **tail){
    int nim;
    char nama[100];
    printf("\nMasukkan NIM: ");
    scanf("%d", &nim);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", nama);
    Mahasiswa *newNode = createNewNode(nim, nama);
    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
    printf("Data berhasil ditambahkan\n\n");
}

void deleteAllData(Mahasiswa **head){
	if(*head == NULL){
        printf("\nLinked List kosong\n\n");
    }
    else {
    while(*head != NULL){
        Mahasiswa *trash = *head;
        *head = (*head)->next;
        free(trash);
    	}
    printf("\nSemua data berhasil dihapus\n\n");
	}
}

void deleteFirstData(Mahasiswa **head){
    if(*head == NULL){
        printf("\nLinked List kosong\n\n");
    }
    else{
        Mahasiswa *trash = *head;
        *head = (*head)->next;
        free(trash);
        printf("\nData pertama berhasil dihapus\n\n");
    }
}

void deleteByNIM(Mahasiswa **head){
	int nim;
    if(*head == NULL){
        printf("\nLinked List kosong\n\n");
    }
    else{
    	printf("\nMasukkan NIM: ");
		scanf("%d", &nim);
        Mahasiswa *trash, *temp;
        trash = *head;
        while(trash != NULL && trash->nim != nim){
            temp = trash;
            trash = trash->next;
        }
        if(trash == NULL){
            printf("Data dengan NIM %d tidak ada\n\n", nim);
        }
        else{
            if(trash == *head){
                *head = (*head)->next;
            }
            else{
                temp->next = trash->next;
            }
            free(trash);
            printf("Data dengan NIM %d berhasil dihapus\n\n", nim);
        }
    }
}

int main() {
	int choose, nim;
	Mahasiswa *head, *tail;
	head = NULL;
	tail = NULL;
	
	while (1){
	printf("1. Insert new node\n");
	printf("2. Print linked list\n");
	printf("3. Delete all data\n");
	printf("4. Delete first data\n");
	printf("5. Delete data by NIM\n");
	printf("6. Exit\n");
	printf("Pilihan Anda : ");
	scanf("%d", &choose);
	
	if (choose == 1){
		insertNewNode(&head, &tail);
	}
	else if (choose == 2){
		printLinkedList(head);
	}
	else if (choose == 3){
		deleteAllData(&head);
	}
	else if (choose == 4){
		deleteFirstData(&head);
	}
	else if (choose == 5){
		deleteByNIM(&head);
	}
	else if (choose == 6){
		return 0;
	}
	else{
		printf("\nInvalid\n\n");
		}
	}
return 1;
}
