#include <stdio.h>

float recursive1(int a, int b);
float recursive2(int c);
float recursive3(int d);

int main()
{
    float input;
    scanf("%f", &input);
    float hasil = recursive3(input);
    printf("%f", hasil);
    
    return 0;
}
float recursive1(int a, int b)
  {
    if(b == 1)
    {
        return a; // base
    }
        else
        return a * recursive1(a,b-1); // recursion
  }
float recursive2(int c)
  {
    if(c == 1)
    {
        return 1; // base
    }
        else
        return c * recursive2(c-1); // recursion
  }
float recursive3(int d)
  {
    if(d == 1)
    {
        return 1; // base
    }
        else
        return recursive3(d-1)+(recursive2(d)/recursive1(d,d)); // recursion
  }
