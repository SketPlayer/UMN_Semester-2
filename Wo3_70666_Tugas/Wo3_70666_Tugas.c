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
    int j = 0;
    int num = 0;
    int choose,i;

    while (1) {
        printf("Welcome to simple student database\n");
        printf("1. Input students\n");
        printf("2. Show Data Mahasiswa\n");
        printf("3. Show Nilai Mahasiswa\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choose);
        printf("\n");

        if (choose == 1) {
            if (num >= 100) {
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
		
		        fprintf(fout, "%s#%s#%d\n", students[num - 1].name, students[num - 1].major, students[num - 1].nim);
		        fclose(fout);
		
		        fprintf(fkeluar, "%d#%d#%d#%d#%.2f#%s\n", students[num - 1].nim, students[num - 1].tugas, students[num - 1].uts,
		                students[num - 1].uas, students[num - 1].nilaiAkhir, students[num - 1].grade);
		        fclose(fkeluar);
		
		        printf("Successfully added\n");
		        printf("Press any key to continue\n\n");
		        
            }
        }
        
        else if (choose == 2) {
        	j = 0;
            FILE *fin = fopen("dataMahasiswa.txt", "r");
            if(fin == NULL){
		        printf("Error: file not found");
		        return 1;
		    }
			while(!feof(fin)){
				Student dataMahasiswa;
				fscanf(fin, "%[^#]#%[^#]#%d\n", dataMahasiswa.name, dataMahasiswa.major, &dataMahasiswa.nim);
				students[j] = dataMahasiswa;
				j++;
			}
			fclose(fin);
		
		    printf("|No.|          Nama           |       Jurusan       |      NIM      |\n");
		    printf("---------------------------------------------------------------------\n");
		    for (i = 0; i < j; i++){
		        printf("|%-3d| %-24s| %-20s| %-14d|\n", i+1, students[i].name, students[i].major, students[i].nim);
		    }
		    
        }
        
        else if (choose == 3) {
        	j = 0;
        	FILE *fp = fopen("nilaiMahasiswa.txt", "r");
            if(fp == NULL){
		        printf("Error: file not found");
		        return 1;
		    }
			while(!feof(fp)){
				Student dataMahasiswa;
				fscanf(fp, "%d#%d#%d#%d#%f#%s\n", &dataMahasiswa.nim, &dataMahasiswa.tugas, &dataMahasiswa.uts,
													&dataMahasiswa.uas, &dataMahasiswa.nilaiAkhir, dataMahasiswa.grade);
				students[j] = dataMahasiswa;
				j++;
			}
			fclose(fp);
		    
		    printf("|No.|      NIM      | Tugas | UTS | UAS | Nilai Akhir | Grade |\n");
			printf("---------------------------------------------------------------\n");
			for (i = 0; i < j; i++){
				printf("|%-3d| %-14d| %-6d| %-4d| %-4d| %-12.2f| %-6s|\n", i+1, students[i].nim, students[i].tugas, students[i].uts,
													 				students[i].uas, students[i].nilaiAkhir, students[i].grade);
			}
			
		}
        
        else if (choose == 4) {
            return 0;
        }
        else {
            printf("Invalid\n");
        }
    }
}
