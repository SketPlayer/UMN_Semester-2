#include <stdio.h>

int main()
{
  	int pay,paid,outpay,sum,money;
  	scanf("%d ", &pay);
  	scanf("%d", &paid);
  	outpay = paid - pay;
  	while (outpay==0);
  	{
	  	if (outpay >= 50000)
	  	  {
	  	  	sum = outpay/50000;
	  	  	printf("\n%d 50000", sum);
	  	  	outpay = outpay - (sum*50000);
		  }
		if (outpay >= 20000)
		  {
	  	  	sum = outpay/20000;
	  	  	printf("\n%d 20000", sum);
	  	  	outpay = outpay - (sum*20000);
		  }
		if (outpay >= 10000)
	  	  {
	  	  	sum = outpay/10000;
	  	  	printf("\n%d 10000", sum);
	  	  	outpay = outpay - (sum*10000);
		  }
		if (outpay >= 1000)
	  	  {
	  	  	sum = outpay/1000;
	  	  	printf("\n%d 1000", sum);
	  	  	outpay = outpay - (sum*1000);
		  }
		if (outpay >= 500)
	  	  {
	  	  	sum = outpay/500;
	  	  	printf("\n%d 500", sum);
	  	  	outpay = outpay - (sum*500);
		  }
		if (outpay >= 100)
	  	  {
	  	  	sum = outpay/100;
	  	  	printf("\n%d 100", sum);
	  	  	outpay = outpay - (sum*100);
		  }
		if (outpay >= 50)
	  	  {
	  	  	sum = outpay/50;
	  	  	printf("\n%d 50", sum);
	  	  	outpay = outpay - (sum*50);
		  }
		if (outpay >= 25)
	  	  {
	  	  	sum = outpay/25;
	  	  	printf("\n%d 25", sum);
	  	  	outpay = outpay - (sum*25);
		  }
    }
return 0;
}
