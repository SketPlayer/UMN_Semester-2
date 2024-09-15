#include <stdio.h>

int main()
{
	int nomor,a,b,c,d,hasil,x,y,digit,z,p,q;
	
	scanf("%d",&nomor);
	a = (nomor/1000); // digit pertama
	b = (nomor%1000)/100; // digit kedua
	c = (nomor%100)/10; // digit ketiga
	d = (nomor%10); // digit keempat
	
	hasil = a+b+c+d; // jumlah dari keempat digit
	x = hasil/10; // digit pertama dari jumlah
	y = hasil%10; // digit kedua dari jumlah
	digit = x+y; // hasil baru
	if(digit>=10)
    {
		z = digit/10; // jika hasil baru memiliki 2 digit maka lanjut
		p = digit%10;
		q = z+p; 
        printf("%d", q);
	}
    else
        printf("%d", digit);

  return 0;
}
