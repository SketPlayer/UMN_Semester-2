#include <stdio.h>

void input(int matrix[3][3]) {
	int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void output(int matrix[3][3]) {
	int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void penjumlahan(int matrix1[3][3], int matrix2[3][3], int hasil[3][3]) {
	int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            hasil[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void perkalian(int matrix1[3][3], int matrix2[3][3], int hasil[3][3]) {
	int i,j,k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (k = 0; k < 3; k++) {
                hasil[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transpose(int matrix[3][3], int hasil[3][3]) {
	int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            hasil[i][j] = matrix[j][i];
        }
    }
}

int main() {
    int matrix1[3][3], matrix2[3][3], hasil[3][3];
    int pilihan;

    printf("Masukkan Matrix Pertama (3x3)\n");
    input(matrix1);
    printf("\nMasukkan Matrix Kedua (3x3)\n");
    input(matrix2);
    printf("\n");
    printf("1. Perkalian Dua Buah Matrix\n");
    printf("2. Penjumlahan Dua Buah Matrix\n");
    printf("3. Transpose Dua Buah Matrix\n");
    printf("4. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);
    
    if (pilihan == 1)
    {
    	perkalian(matrix1, matrix2, hasil);
    	output(hasil);
	}
    
    else if (pilihan == 2)
    {
    	penjumlahan(matrix1, matrix2, hasil);
    	output(hasil);
	}
	
	else if (pilihan == 3)
    {
    	printf("Transpose Matrix Pertama\n");
    	transpose(matrix1, hasil);
    	output(hasil);
    	printf("Transpose Matrix Kedua\n");
    	transpose(matrix2, hasil);
    	output(hasil);
	}
	
	else if (pilihan == 4)
    {
    	return 0;
	}
    
    return 0;
}

