#include <stdio.h>

void hitung(int pay,int paid)
  {
  	scanf("%d ", &pay); // Uang yang harus dibayar
  	scanf("%d", &paid); // Uang yang dibayar atau dipakai
  	int outpay = paid - pay; // Menghitung Kembalian
  	int change = bulat(outpay);
  	printf("\n%d", change);
  	while (change==0);
  	{
	  	if (change >= 50000) // Pecahan 50 ribu
	  	  {
	  	  	int sum = change/50000;
	  	  	printf("\n%d 50000", sum);
	  	  	change = change - (sum*50000);
		  }
		if (change >= 20000) // Pecahan 20 ribu
		  {
	  	  	int sum = change/20000;
	  	  	printf("\n%d 20000", sum);
	  	  	change = change - (sum*20000);
		  }
		if (change >= 10000) // Pecahan 10 ribu
	  	  {
	  	  	int sum = change/10000;
	  	  	printf("\n%d 10000", sum);
	  	  	change = change - (sum*10000);
		  }
		if (change >= 1000) // Pecahan seribu
	  	  {
	  	  	int sum = change/1000;
	  	  	printf("\n%d 1000", sum);
	  	  	change = change - (sum*1000);
		  }
		if (change >= 500) // Pecahan 500
	  	  {
	  	  	int sum = change/500;
	  	  	printf("\n%d 500", sum);
	  	  	change = change - (sum*500);
		  }
		if (change >= 100) // Pecahan seratus
	  	  {
	  	  	int sum = change/100;
	  	  	printf("\n%d 100", sum);
	  	  	change = change - (sum*100);
		  }
		if (change >= 50) // Pecahan 50
	  	  {
	  	  	int sum = change/50;
	  	  	printf("\n%d 50", sum);
	  	  	change = change - (sum*50);
		  }
		if (change >= 25) // Pecahan 25
	  	  {
	  	  	int sum = change/25;
	  	  	printf("\n%d 25", sum);
	  	  	change = change - (sum*25);
		  }
    }
  }
int bulat(int sisa) // Pembulatan kembalian
  {
  	int change = sisa;
  	if (change%25==0)
	{
		sisa = change;
	}
	else
	{while (change%25!=0)
		{
			change += 1;
			sisa = change;
		}
	}
	return change;
  }
int main()
{
	int bayar,dibayar;
	hitung(bayar,dibayar);

	return 0;
}
