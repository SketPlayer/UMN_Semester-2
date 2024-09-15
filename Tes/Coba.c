#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Barang {
	char nama[30];
	char kategori[30];
	int harga;
	struct Barang *prev, *next;
} Barang;

void readBarang(Barang **head){
    char nama[30];
    char kategori[30];
    int harga;
    FILE *fp;
    fp = fopen("barang.txt", "r");
    if (fp == NULL){
        printf("File Barang tidak ditemukan\n");
        return;
    }
    else {
       while(fscanf(fp, "%[^*]*%[^*]*%d\n", nama, kategori, &harga) != EOF) {
            Barang *node = (Barang*)malloc(sizeof(Barang));
            strcpy(node->nama, nama);
            node->harga = harga;
            strcpy(node->kategori, kategori);
            node->next = NULL;
            
            if (*head == NULL) {
                node->prev = NULL;
                *head = node;
            } else {
                Barang *tail = *head;
                while(tail->next != NULL) {
                    tail = tail->next;
                }
                tail->next = node;
                node->prev = tail;
            }
        }
    }
    fclose(fp);
}


void printBarang(Barang **head){
	Barang *temp = *head;
	if (temp == NULL){
		printf("Daftar Barang kosong\n");
		return;
	}
	while(temp != NULL) {
		printf("Nama: %s\n", temp->nama);
		printf("Kategori: %s\n", temp->kategori);
		printf("Harga: %d\n\n", temp->harga);
		temp = temp->next;
	}
}

void tambahBarang(Barang **head){
	Barang *node = (Barang*)malloc(sizeof(Barang));
	printf("\nMasukkan Nama Barang Baru: ");
	scanf(" %[^\n]", node->nama);
	printf("Masukkan Harga Barang Baru: ");
	scanf("%d", &node->harga);
	printf("Masukkan Kategori Barang Baru: ");
	scanf(" %[^\n]", node->kategori);
	node->next = NULL;
	if (*head == NULL) {
		node->prev = NULL;
		*head = node;
		printf("Barang Baru berhasil ditambahkan\n\n");
	}
	else {
        Barang *tail = *head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = node;
        node->prev = tail;
        printf("Barang Baru berhasil ditambahkan\n\n");
    }
}

void hapusBarang(Barang **head){
	if (*head == NULL){
		printf("\nDaftar Barang Kosong\n\n");
		return;
	}
	else {
		char nama[30];
		printf("Masukkan Nama Barang yang Ingin Dihapus: ");
		scanf(" %[^\n]", nama);
		
		Barang *temp = *head;
		
		while(temp != NULL && strcmp(temp->nama, nama) != 0){
		temp = temp->next;
		}
		if (temp != NULL){
			if (temp == *head){
				*head = temp->next;
			}
			if (temp->prev != NULL){
				temp->prev->next = temp->next;
			}
			if (temp->next != NULL){
				temp->next->prev = temp->prev;
			}
			printf("\nBarang berikut telah dihapus dari daftar:\n");
			printf("Nama: %s\n", temp->nama);
			printf("Kategori: %s\n", temp->kategori);
			printf("Harga: %d\n\n", temp->harga);
			free(temp);
		}
		else {
		printf("\nBarang dengan nama '%s' tidak ditemukan\n\n", nama);
		}
	}
}

void cariBarang(Barang **head){
    if (*head == NULL){
        printf("\nDaftar Barang Kosong\n\n");
        return;
    }
    else {
        char kategori[30];
        printf("Masukkan kategori barang: ");
        scanf(" %[^\n]", kategori);

        Barang *temp = *head;
        while(temp != NULL){
            if(strcmp(temp->kategori, kategori) == 0){
                printf("\n%s (%s) - %d", temp->nama, temp->kategori, temp->harga);
            }
            temp = temp->next;
        }
        printf("\n\n");
    }
}

void saveBarang(Barang *head){
	FILE *fp;
	fp = fopen("barang.txt", "w");
	while(head != NULL) {
		fprintf(fp, "%s*%s*%d\n", head->nama, head->kategori, head->harga);
		head = head->next;
	}
	fclose(fp);
}

int main(){
	int pilihan = 0;
	Barang *head = NULL, *tail = NULL;
	readBarang(&head);
	while(1){
		printf("======================================\n");
		printf("Sistem penjualan barang\n");
		printf("======================================\n\n");
		printf("Menu:\n");
		printf("1. Tampilkan Data Barang\n");
		printf("2. Cari Barang\n");
		printf("3. Tambah Barang Baru\n");
		printf("4. Hapus Barang\n");
		printf("0. Keluar\n\n");
		printf("Pilihan Anda: ");
		scanf("%d", &pilihan);
		
		if (pilihan == 0) {
			return 0;
		}
		else if (pilihan == 1) {
			printBarang(&head);
		}
		else if (pilihan == 2) {
			cariBarang(&head);
		}
		else if (pilihan == 3) {
			tambahBarang(&head);
			saveBarang(head);
		}
		else if (pilihan == 4) {
			hapusBarang(&head);
			saveBarang(head);
		}
		else {
			printf("\nInvalid\n");
		}
	}
}
