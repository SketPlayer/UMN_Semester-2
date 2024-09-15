#include <stdio.h>

int main()
{
	int row,column,size,sum,sum2,sum3,magic,matriks[10][10],cek[100];
	scanf("%d", &size); // Ukuran matriks atau persegi
	for(row = 0; row < size; row++)
    {
        for(column = 0; column < size; column++)
        {
            scanf("%d", &matriks[row][column]); // Angka dalam matriks atau persegi
        }
    }
    
    
    
    //DIAGONAL
   sum = 0;
   for (row = 0; row < size; row++)
   {
      for (column = 0; column < size; column++)
	  {
         if (row == column)
            sum = sum + matriks[row][column];
      }
   }

   //BARIS
   for (row = 0; row < size; row++)
   {
      sum2 = 0;
      for (column = 0; column < size; column++)
	  {
         sum2 = sum2 + matriks[row][column];
      }
      if (sum == sum2)
         magic = 1;
      else	{
         magic = 0;
         break;
      		}
   }

   //KOLOM
   for (row = 0; row < size; row++)
   {
      sum3 = 0;
      for (column = 0; column < size; column++)
	  {
         sum3 = sum3 + matriks[column][row];
      }
      if (sum == sum3)
         magic = 1;
      else 	{
         magic = 0;
         break;
      		}
   }

    	if (magic == 1)
      	{
      		if (1)
				{
				printf("\nBukan Magic Square");
				}
				else
				printf("\nMagic square");
    	}
      	else
      	printf("\nBukan Magic Square");
      
    return 0;
}
