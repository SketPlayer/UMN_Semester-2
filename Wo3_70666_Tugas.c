#include <stdio.h>
#include <string.h>

typedef struct{
    char name [50];
    char major [35];
    int nim, tugas, uts, uas;
    float nilaiAkhir;
    char grade[3];
}Student;

int main() {
    Student students[100];
    int num = 0;
    int choose,i;

    while (1) {
        printf("Welcome to simple student database (%d/100)\n", num);
        printf("1. Show all students and save data\n");
        printf("2. Input students\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choose);
        printf("\n");

        if (choose == 1) {
            printf("                     List of Student Information                     \n");
			printf("---------------------------------------------------------------------\n");
			printf("|No.|          Nama           |       Jurusan       |      NIM      |\n");
			printf("---------------------------------------------------------------------\n");

		for (i = 0; i < num; i++) {
    		printf("|%-3d| %-20s| %-24s| %-14d|\n", i+1, students[i].name, students[i].major, students[i].nim);
		}
		printf("\n");
	
			FILE *fout = fopen("dataMahasiswa.txt", "w");
			fprintf(fout,"|No.|          Nama           |       Jurusan       |      NIM      |\n");
			fprintf(fout,"---------------------------------------------------------------------\n");
			for (i = 0; i < num; i++){
				fprintf(fout, "|%-3d| %-24s| %-20s| %-14d|\n", i+1, students[i].name, students[i].major, students[i].nim);
			}
			fclose(fout);
			
			FILE *fkeluar = fopen("nilaiMahasiswa.txt", "w");
			fprintf(fkeluar,"|No.|      NIM      | Tugas | UTS | UAS | Nilai Akhir | Grade |\n");
			fprintf(fkeluar,"---------------------------------------------------------------\n");
			for (i = 0; i < num; i++){
				fprintf(fkeluar, "|%-3d| %-14d| %-6d| %-4d| %-4d| %-12.2f| %-6s|\n", i+1, students[i].nim, students[i].tugas, students[i].uts,
													 				students[i].uas, students[i].nilaiAkhir, students[i].grade);
			}
			fclose(fkeluar);
		
        }
        else if (choose == 2) {
            if (num >= 100) {
                printf("Database is full.\n");
                printf("Press any key to continue\n\n");
            }
            else {
                Student dataMahasiswa;
				
				printf("   Insert Student Information   \n");
				printf("--------------------------------\n");
				
                printf("Nama	: ");
                scanf(" %[^\n]", dataMahasiswa.name);

                printf("Jurusan	: ");
                scanf(" %s", dataMahasiswa.major);

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

                students[num] = dataMahasiswa;
                num++;
                
				printf("\nInserting data\n");
                printf("Successfully added\n");
                printf("Press any key to continue\n\n");
            }
        }
        else if (choose == 3) {
            return 0;
        }
        else {
            printf("Invalid\n");
        }
    }
}
