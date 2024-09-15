#include <stdio.h>

struct Student {
    char name [50];
    char major [35];
    float gpa;
};

int main() {
    struct Student students[20];
    int num = 0;
    int choose,i;

    while (1) {
        printf("Welcome to simple student database (%d/20)\n", num);
        printf("1. Show all students\n");
        printf("2. Input new students\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choose);
        printf("\n");

        if (choose == 1) {
            printf("             List of Student Information             \n");
			printf("-----------------------------------------------------\n");
			printf("|No.|        Name         |     Major     |   GPA   |\n");
			printf("-----------------------------------------------------\n");

		for (i = 0; i < num; i++) {
    		printf("|%-3d| %-20s| %-14s| %-8.2f|\n", i+1, students[i].name, students[i].major, students[i].gpa);
		}

printf("\n");

        }
        else if (choose == 2) {
            if (num >= 20) {
                printf("Database is full.\n");
                printf("Press any key to continue\n\n");
            }
            else {
                struct Student new_student;
				
				printf("   Insert Student Information   \n");
				printf("--------------------------------\n");
				
                printf("Name	: ");
                scanf("%s", new_student.name);

                printf("Major	: ");
                scanf("%s", new_student.major);

                printf("GPA	: ");
                scanf("%f", &new_student.gpa);

                students[num] = new_student;
                num++;

				printf("Inserting data\n");
                printf("New student added\n");
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
