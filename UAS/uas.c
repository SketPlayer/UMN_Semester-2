#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Nama    : Rio Ferdinan
    NIM     : 00000070666
    Kelas   : D
    Nilai   : 
*/

struct Lagu {
    char title[40];
    char artist[20];
    char album[45];
    int year;
}music;

void openFile (struct Lagu music[], int *n){
	FILE *fp = fopen("database-musik.txt", "r");
	
	if (fp == NULL) {
		printf("File not found");
	}
	
	while (!feof(fp)) {
		struct Lagu dataLagu;
		fscanf(fp, "%[^*]*%[^*]*%[^*]*%d\n", dataLagu.title, dataLagu.artist, dataLagu.album, &dataLagu.year);
		
		music[*n] = dataLagu;
		(*n)++;
	}
	fclose(fp);
}

void showLagu (struct Lagu music[], int n) {
    int i;

    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-40s | %-20s | %-45s | %-7s |\n", "Title", "Artist", "Album", "Year");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");

	for (i = 0; i < n; i++) {
		printf("| %-40s | %-20s | %-45s | %-7d |\n", music[i].title, music[i].artist, music[i].album, music[i].year);
	}
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
}

void bubbleSortTahun(struct Lagu music[], int n){
    int i, j;

    for(i=1; i<n; i++){
        for(j=n-1; j>=1; j--){
            if(music[j].year < music[j-1].year){
                struct Lagu temp = music[j];
                music[j] = music[j-1];
                music[j-1] = temp;
            }
        }
    }
}

void bubbleSortJudul(struct Lagu music[], int n){
    int i, j;

    for(i=1; i<n; i++){
        for(j=n-1; j>=1; j--){
            if(strcmp(music[j].title, music[j-1].title) < 0){
                struct Lagu temp = music[j];
                music[j] = music[j-1];
                music[j-1] = temp;
            }
        }
    }
}

int binarySearch(struct Lagu music[], int n, char key[]) {
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        int compareResult = strcmp(music[mid].title, key);
        if (compareResult == 0) {
            return mid;
        } else if (compareResult > 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int binarySearchYear(struct Lagu music[], int n, int yearkey) {
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        int compareResult = music[mid].year < yearkey;
        if (compareResult == 0) {
            return mid;
        } else if (compareResult > 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main(){
    struct Lagu music[50];
    int choice, sortChoice, searchChoice;
    int n = 0;

    openFile(music, &n);
    showLagu(music, n);

    while(1){
        printf("Menu:\n");
        printf("1. Sort\n");
        printf("2. Search\n");
        printf("3. Exit\n\n");
        printf("Pilihan : ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\n");
            printf("Pilih sort berdasarkan:\n");
            printf("1. Judul\n");
            printf("2. Tahun Rilis\n\n");
            printf("Pilihan : ");
            scanf("%d", &sortChoice);

            if(sortChoice == 1){
                bubbleSortJudul(music, n);
                printf("\n");
                showLagu(music, n);
            }
            else if(sortChoice == 2){
                bubbleSortTahun(music, n);
                printf("\n");
                showLagu(music, n);
            }
            else {
                printf("Invalid\n\n");
                showLagu(music, n);
            }
        }

        else if(choice == 2){
            char key[40];
            int yearkey;
            int found = 0;
            printf("Pilih Search berdasarkan : \n");
            printf("1. Judul\n");
            printf("2. Tahun Rilis\n\n");
            printf("Pilihan : ");
            scanf("%d", &searchChoice);

            if(searchChoice == 1){
                printf("Masukkan judul yang ingin dicari: ");
                scanf(" %[^\n]", key);
                bubbleSortJudul(music, n);
                found = binarySearch(music, n, key);
                if(found != -1){
                    printf("\n");
                    printf("Data Ditemukan!\n");
                    printf("Judul   : %s\n", music[found].title);
                    printf("Artis   : %s\n", music[found].artist);
                    printf("Album   : %s\n", music[found].album);
                    printf("Tahun   : %d\n\n", music[found].year);
                    showLagu(music, n);
                }

                else {
                    printf("\n");
                    printf("Data TIDAK Ditemukan!\n\n");
                    showLagu(music, n);
                }
            }
            else if(searchChoice == 2){
                // printf("Masukkan tahun rilis lagu yang ingin dicari: ");
                // scanf("%d", yearkey);
                // bubbleSortTahun(music, n);
                // found = binarySearchYear(music, n, yearkey);
                // if(found != -1){
                //     printf("\n");
                //     printf("Data Ditemukan!\n");
                //     printf("Judul   : %s\n", music[found].title);
                //     printf("Artis   : %s\n", music[found].artist);
                //     printf("Album   : %s\n", music[found].album);
                //     printf("Tahun   : %d\n\n", music[found].year);
                //     showLagu(music, n);
                // }

                // else {
                //     printf("\n");
                //     printf("Data TIDAK Ditemukan!\n\n");
                //     showLagu(music, n);
                // }
            }
            else {
                printf("Invalid\n\n");
                showLagu(music, n);
            }
        }

        else if(choice == 3){
            printf("\n");
            printf("Program exited...\n");
            return 0;
        }

        else {
            printf("\n");
            printf("Invalid\n");
        }
    }
}