#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Playlist {
    char singer[50];
    char title[50];
    char album[50];
    int year;
    struct Playlist *prev, *next;
} Playlist;

void printPlaylist(Playlist *head) {
    printf("\n%-30s%-30s%-30s%-30s\n", "Singer", "Song Title", "Album", "Released Year");
    while(head != NULL) {
        printf("%-30s%-30s%-30s%-30d", head->singer, head->title, head->album, head->year);
        head = head->next;
    }
    printf("\n");
}

void addPlaylist(Playlist **head) {
    Playlist *node = (Playlist*)malloc(sizeof(Playlist));
    printf("\nInput Singer : ");
    scanf(" %[^\n]", node->singer);
    printf("Album : ");
    scanf(" %[^\n]", node->album);
    printf("Title : ");
    scanf(" %[^\n]", node->title);
    printf("Released Year : ");
    scanf("%d", &node->year);
    node->next = NULL;
    if (*head == NULL) {
        node->prev = NULL;
        *head = node;
        printf("Data berhasil ditambahkan!\n\n");
        return;
    }
    Playlist *tail = *head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = node;
    node->prev = tail;
    printf("Data berhasil ditambahkan!\n\n");
}

void deletePlaylist(Playlist **head) {
    if (*head == NULL) {
        printf("\nPlaylist kosong\n\n");
        return;
    }
    Playlist *tail = *head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    if (tail->prev == NULL) {
        *head = NULL;
    } else {
        tail->prev->next = NULL;
    }
    printf("\nLagu %s berhasil dihapus dari list.\n\n", tail->title);
    free(tail);
}

void savePlaylist(Playlist *head) {
    FILE *fp;
    fp = fopen("playlist.txt", "w");
    while(head != NULL) {
        fprintf(fp, "%s*%s*%s*%d\n", head->singer, head->album, head->title, head->year);
        head = head->next;
    }
    fclose(fp);
}

void readPlaylist(Playlist **head) {
    FILE *fp;
    fp = fopen("playlist.txt", "r");
    if (fp == NULL) {
        printf("File playlist.txt tidak ditemukan\n");
        return;
    }
    char singer[50];
    char album[50];
    char title[50];
    int year;
    while(fscanf(fp, "%[^*]*%[^*]*%[^*]*%d\n", singer, album, title, &year) == 4) {
        Playlist *node = (Playlist*)malloc(sizeof(Playlist));
        strcpy(node->singer, singer);
        strcpy(node->album, album);
        strcpy(node->title, title);
        node->year = year;
        node->next = NULL;
        if (*head == NULL) {
			node->prev = NULL;
			*head = node;
		} else {
			Playlist *tail = *head;
			while(tail->next != NULL) {
				tail = tail->next;
			}
			tail->next = node;
			node->prev = tail;
		}
	}
	fclose(fp);
}

void freePlaylist(Playlist **head) {
    Playlist *curr = *head;
    Playlist *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}


int main() {
	Playlist *head = NULL;
	int choose = 0;
	readPlaylist(&head);
	while(1) {
		printf("1. Tampilkan data\n");
		printf("2. Tambah data\n");
		printf("3. Hapus data\n");
		printf("4. Exit\n");
		printf("Pilih : ");
		scanf("%d", &choose);
	if (choose == 1) {
		printPlaylist(head);
	}
	else if (choose == 2) {
		addPlaylist(&head);
		savePlaylist(head);
	}
	else if (choose == 3) {
		deletePlaylist(&head);
		savePlaylist(head);
	}
	else if (choose == 4) {
		freePlaylist(&head);
		return 0;
	}
	else {
		printf("\nInvalid\n\n");
	}
}
	
return 1;
}
