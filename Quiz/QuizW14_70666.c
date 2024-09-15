#include <stdio.h>
#include <string.h>

// Nama_NIM_Quiz.zip

struct Student {
    char nama[35];
    char jurusan[20];
    int nilai;
} mahasiswa;

void openFile (struct Student mahasiswa[], int *num){
	FILE *fp = fopen("database_nilai.txt", "r");
	
	if (fp == NULL) {
		printf("Error: file not found");
	}
	
	while (!feof(fp)) {
		struct Student dataMahasiswa;
		fscanf(fp, "%[^😭]😭%[^😭]😭%d\n", dataMahasiswa.nama, dataMahasiswa.jurusan, &dataMahasiswa.nilai);
		
		mahasiswa[*num] = dataMahasiswa;
		(*num)++;
	}
	fclose(fp);
}

void shellSort(struct Student mahasiswa[], int num) {
    int i, j, gap;

    for (gap = num / 2; gap > 0; gap /= 2) {
        for (i = gap; i < num; i++) {
            struct Student temp = mahasiswa[i];

            for (j = i; j >= gap && strcmp(mahasiswa[j - gap].nama, temp.nama) > 0; j -= gap) {
                mahasiswa[j] = mahasiswa[j - gap];
            }

            mahasiswa[j] = temp;
        }
    }
}

int bubbleSortjojo(struct Student mahasiswa[], int num) {
    struct Student temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (strcmp(mahasiswa[j].nama, mahasiswa[j + 1].nama) > 0) {
                temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j + 1];
                mahasiswa[j + 1] = temp;
            }
        }
    }
}

int binarySearch(struct Student mahasiswa[], int num, char key[]) {
    int low, mid, high;

    low = 0;
    high = num - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        int compareResult = strcmp(mahasiswa[mid].nama, key);
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

int binarySearchjojo(struct Student mahasiswa[], int num, char key[]) {
    int low, mid, high;

    low = 0;
    high = num - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        int compareResult = strcmp(mahasiswa[mid].nama, key);
        if (compareResult == 0) {
            return mid;
        } else if (compareResult < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


void showMahasiswa (struct Student mahasiswa[], int num) {
    int i;

    printf("--------------------------------------------------------------------------------\n");
    printf("| %-3s | %-35s | %-20s | %-9s |\n", "No.", "Nama", "Jurusan", "Nilai");
    printf("--------------------------------------------------------------------------------\n");

	for (i = 0; i < num; i++) {
		printf("| %-3d | %-35s | %-20s | %-9d |\n", i + 1, mahasiswa[i].nama, mahasiswa[i].jurusan, mahasiswa[i].nilai);
	}
    printf("--------------------------------------------------------------------------------\n");
	printf("\n");
}

int main() {
    struct Student mahasiswa[100];
    int choice;
    int num = 0;
    int found = 0;

    openFile(mahasiswa, &num);

    while(1) {
        printf("Manajemen Nilai Mahasiswa\n");
        printf("1. Tampilkan semua mahasiswa\n");
        printf("2. Cari Mahasiswa\n");
        printf("3. Keluar program\n\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1){
            showMahasiswa(mahasiswa, num);
        }

        else if (choice == 2){
            char key[35];
            printf("Masukkan nama mahasiswa yang ingin dicari: ");
            scanf(" %[^\n]", key);
            printf("\n");

            bubbleSortjojo(mahasiswa, num);
            found = binarySearchjojo(mahasiswa, num, key);

            if (found != -1) {
                printf("\n");
                printf("Mahasiswa ditemukan!\n");
                printf("Nama    : %s\n", mahasiswa[found].nama);
                printf("Jurusan : %s\n", mahasiswa[found].jurusan);
                printf("Nilai   : %d\n\n", mahasiswa[found].nilai);
            } else {
				printf("Mahasiswa tidak ditemukan!\n\n");
			}
        }

        else if (choice == 3){
            printf("Terima kasih telah menggunakan aplikasi ini!\n\n");
            return 0;
        }

        else {
            printf("\nInvalid\n\n");
        }
    }
}