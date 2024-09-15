#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nama[100];
    char jurusan[30];
    int nim;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *createNewNode(int nim, char *nama, char *jurusan) {
    Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    newNode->nim = nim;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(Mahasiswa *head) {
    Mahasiswa *temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("Data ke %d\n", i);
        printf("NIM    : %d\n", temp->nim);
        printf("Nama   : %s\n", temp->nama);
        printf("Jurusan: %s\n\n", temp->jurusan);
        temp = temp->next;
        i++;
    }
}

void insertNewNode(Mahasiswa **head, Mahasiswa **tail) {
    int nim;
    char nama[100], jurusan[30];
    printf("Masukkan NIM: ");
    scanf("%d", &nim);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", nama);
    printf("Masukkan Jurusan: ");
    scanf(" %[^\n]", jurusan);

    Mahasiswa *node = createNewNode(nim, nama, jurusan);
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
    printf("Data berhasil dimasukkan ke linked list.\n");
}

void deleteAllData(Mahasiswa **head) {
    while (*head != NULL) {
        Mahasiswa *trash = *head;
        *head = (*head)->next;
        free(trash);
    }
    printf("Seluruh data berhasil dihapus dari linked list.\n");
}

void deleteFirstData(Mahasiswa **head) {
    if (*head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    Mahasiswa *trash = *head;
    *head = (*head)->next;
    free(trash);
    printf("Data pertama berhasil dihapus dari linked list.\n");
}

void deleteDataByNim(Mahasiswa **head, int nim) {
    if (*head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }

    Mahasiswa *temp = *head, *prev = NULL;
    while (temp != NULL && temp->nim != nim) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data dengan NIM %d tidak ditemukan pada linked list.\n", nim);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Data dengan NIM %d berhasil dihapus dari linked list.\n", nim);
}

int main() {
    Mahasiswa *head = NULL, *tail = NULL;
    int choice, nim;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert new node\n");
        printf("2. Print linked list\n");
        printf("3. Delete all data\n");
        printf("4. Delete first data\n");
        printf("5. Delete data by NIM\n");
        printf("Choose: \n");
        scanf("%d", &choice);
        
        if (choice == 1) {
        	insertNewNode (*head, *tail);
		}
	}

