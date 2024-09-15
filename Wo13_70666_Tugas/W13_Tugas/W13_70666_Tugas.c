#include <stdio.h>
#include <string.h>

typedef struct{
    char name [50];
    char major [35];
    int nim, tugas, uts, uas;
    float nilaiAkhir;
    char grade[3];
}Student;

void openFile (Student students[], int *num){
	FILE *fin = fopen("dataMahasiswa.txt", "r");
	FILE *fp = fopen("nilaiMahasiswa.txt", "r");
	
	if (fin == NULL || fp == NULL) {
		printf("Error: file not found");
	}
	
	while (!feof(fin) && !feof(fp)) {
		Student dataMahasiswa;
		fscanf(fin, "%[^#]#%[^#]#%d\n", dataMahasiswa.name, dataMahasiswa.major, &dataMahasiswa.nim);
		fscanf(fp, "%d#%d#%d#%d#%f#%s\n", &dataMahasiswa.nim, &dataMahasiswa.tugas, &dataMahasiswa.uts,
				&dataMahasiswa.uas, &dataMahasiswa.nilaiAkhir, dataMahasiswa.grade);
		
		students[*num] = dataMahasiswa;
		(*num)++;
	}
	fclose(fin);
	fclose(fp);
}

void inputStudents(Student students[], int *num) {
	if ((*num) >= 100) {
        printf("Database is full.\n");
        printf("Press any key to continue\n\n");
    }
    else {
    	FILE *fout = fopen("dataMahasiswa.txt", "a");
    	FILE *fkeluar = fopen("nilaiMahasiswa.txt", "a");
    	
        Student dataMahasiswa;
		
		printf("   Insert Student Information   \n");
		printf("--------------------------------\n");
		
        printf("Nama	: ");
        scanf(" %[^\n]", dataMahasiswa.name);

        printf("Jurusan	: ");
        scanf(" %[^\n]", dataMahasiswa.major);

        printf("NIM	: ");
        scanf(" %d", &dataMahasiswa.nim);
        
        printf("Tugas	: ");
		scanf(" %d", &dataMahasiswa.tugas);

		printf("UTS	: ");
		scanf(" %d", &dataMahasiswa.uts);
		
		printf("UAS	: ");
		scanf(" %d", &dataMahasiswa.uas);
		
		dataMahasiswa.nilaiAkhir = (dataMahasiswa.tugas * 0.3) + (dataMahasiswa.uts * 0.3) + (dataMahasiswa.uas * 0.4);
			if (dataMahasiswa.nilaiAkhir >= 95) {
			    strcpy(dataMahasiswa.grade, "A+");
			}
			else if (dataMahasiswa.nilaiAkhir >= 85.00 && dataMahasiswa.nilaiAkhir <= 94.99) {
			    strcpy(dataMahasiswa.grade, "A");
			}
			else if (dataMahasiswa.nilaiAkhir >= 80.00 && dataMahasiswa.nilaiAkhir <= 84.99) {
			    strcpy(dataMahasiswa.grade, "A-");
			}
			else if (dataMahasiswa.nilaiAkhir >= 75.00 && dataMahasiswa.nilaiAkhir <= 79.99) {
			    strcpy(dataMahasiswa.grade, "B+");
			}
			else if (dataMahasiswa.nilaiAkhir >= 70.00 && dataMahasiswa.nilaiAkhir <= 74.99) {
			    strcpy(dataMahasiswa.grade, "B");
			}
			else if (dataMahasiswa.nilaiAkhir >= 65.00 && dataMahasiswa.nilaiAkhir <= 69.99) {
			    strcpy(dataMahasiswa.grade, "C");
			}
			else if (dataMahasiswa.nilaiAkhir >= 60.00 && dataMahasiswa.nilaiAkhir <= 64.99) {
			    strcpy(dataMahasiswa.grade, "C-");
			}
			else if (dataMahasiswa.nilaiAkhir >= 55.00 && dataMahasiswa.nilaiAkhir <= 59.99) {
			    strcpy(dataMahasiswa.grade, "D");
			}
			else {
			    strcpy(dataMahasiswa.grade, "E");
			}

        students[*num] = dataMahasiswa;
        (*num)++;
        

        printf("\nInserting data\n");

        fprintf(fout, "%s#%s#%d\n", students[(*num) - 1].name, students[(*num) - 1].major, students[(*num) - 1].nim);
        fclose(fout);

        fprintf(fkeluar, "%d#%d#%d#%d#%.2f#%s\n", students[(*num) - 1].nim, students[(*num) - 1].tugas, students[(*num) - 1].uts,
                students[(*num) - 1].uas, students[(*num) - 1].nilaiAkhir, students[(*num) - 1].grade);
        fclose(fkeluar);

        printf("Successfully added\n");
        printf("Press any key to continue\n\n");
        
    }
}

void showStudents(Student students[], int num) {
	int i;

	printf("|No.|          Nama           |       Jurusan       |      NIM      | Tugas | UTS | UAS | Nilai Akhir | Grade |\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	for (i = 0; i < num; i++) {
		printf("|%-3d| %-24s| %-20s| %-14d| %-6d| %-4d| %-4d| %-12.2f| %-6s|\n", i + 1, students[i].name,
				students[i].major, students[i].nim, students[i].tugas, students[i].uts, students[i].uas,
				students[i].nilaiAkhir, students[i].grade);
	}
	printf("\n");
}

void shellSort(Student students[], int num) {
    int i, j, gap;

    for (gap = num / 2; gap > 0; gap /= 2) {
        for (i = gap; i < num; i++) {
            Student temp = students[i];

            for (j = i; j >= gap && students[j - gap].nim > temp.nim; j -= gap) {
                students[j] = students[j - gap];
            }

            students[j] = temp;
        }
    }
}

 int binarySearch(Student students[], int num, int key){
    int low, mid, high;

    low = 0;
    high = num - 1;

    while (low <= high){
        mid = (low + high) / 2;
        
        if(students[mid].nim == key) return mid;
        if(key < students[mid].nim) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
 }

int main() {
    Student students[100];
    int num = 0;
    int choose;
	int found = 0;

	openFile(students, &num);

    while (1) {
        printf("Welcome to simple student database\n");
        printf("1. Input students\n");
        printf("2. Show All Students\n");
        printf("3. Exit\n");
        printf("4. Show Student Details\n");
        printf("Choose: ");
        scanf("%d", &choose);
        printf("\n");

        if (choose == 1) {
			inputStudents(students, &num);
        }
        
        else if (choose == 2) {
		    showStudents(students, num);
		}
        
        else if (choose == 3) {
            return 0;
        }

		else if (choose == 4) {
			shellSort(students, num);
			showStudents(students, num);
			int key;
			printf("Input NIM (Student ID) : ");
			scanf("%d", &key);

			found = binarySearch(students, num, key);

			if (found != -1) {
				printf("|No.|          Nama           |       Jurusan       |      NIM      | Tugas | UTS | UAS | Nilai Akhir | Grade |\n");
				printf("-------------------------------------------------------------------------------------------------------------\n");
				printf("|%-3d| %-24s| %-20s| %-14d| %-6d| %-4d| %-4d| %-12.2f| %-6s|\n", found + 1, students[found].name,
				students[found].major, students[found].nim, students[found].tugas, students[found].uts, students[found].uas,
				students[found].nilaiAkhir, students[found].grade);
				printf("\n");
			} else {
				printf("Student not found\n");
			}
		}

        else {
            printf("Invalid\n");
        }
    }
}
