#include <stdio.h>

//int main()
//{
//	int change,outpay;
	
//	scanf("%d", &outpay);
//	change = outpay%25;
//	printf("%d", change);

 // return 0;


int main()
{
	int change,outpay;
	
	scanf("%d", &outpay);
	outpay == change;
	if (outpay%25==0)
	{
		change = outpay;
	}
	else
		while (outpay%25!=0)
		{
			outpay += 1;
			change = outpay;
		}
	printf("%d", change);
	

  return 0;
}
