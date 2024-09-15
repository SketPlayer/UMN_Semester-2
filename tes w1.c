#include <stdio.h>
#include <string.h>

int main() {
	char kata[100];
	int pilihan;
	int i;
	
    printf("Masukkan kata : ");
	scanf("%[^\n]%*c", kata);
	
	printf("1. Uppercase\n");
    printf("2. Lowercase\n");
    printf("3. Switching\n");
    printf("4. Keluar\n");
    printf("\nPilihan : ");
    scanf("%d", &pilihan);
    
    if (pilihan == 1)
	{

	    int length = strlen(kata);
	    char *ptr = kata;
	    for (i = 0; i < length; i++, ptr++) {
	        if (*ptr >= 'a' && *ptr <= 'z') {
	            *ptr = *ptr + ('A' - 'a');
        	}
    }
    printf("%s\n", kata);
	}
    
    else if (pilihan == 2)
	{

	    int length = strlen(kata);
	    char *ptr = kata;
	    for (i = 0; i < length; i++, ptr++) {
	        if (*ptr >= 'A' && *ptr <= 'Z') {
	            *ptr = *ptr + ('a' - 'A');
        	}
    }
    printf("%s\n", kata);
	}
	
	else if (pilihan == 3)
	{

	    int length = strlen(kata);
	    char *ptr = kata;
	    for (i = 0; i < length; i++, ptr++) {
	        if (*ptr >= 'A' && *ptr <= 'Z') {
	            *ptr = *ptr + ('a' - 'A');
        	}
        	else if (*ptr >= 'a' && *ptr <= 'z') {
	            *ptr = *ptr + ('A' - 'a');
        	}
    }
    printf("%s\n", kata);
	}
	
	else if (pilihan == 4);
	{
		return 0;
	}
	
    return 0;
}

