#include <stdio.h>
#include <stdlib.h>

int main()
{
#if 0
    int a = 6;
    a -= a *= a += 3;
    printf("a = %d\n", a);
    printf("size of a = %d\n", sizeof(a));
#endif

/*  int a = 1, b = 2, c = 3, d = 4;
    int m = 1, n = 1;

    (m = a < b) || (n = c > d);

    printf("m = %d\nn = %d\n", m, n);
*/
    int a;
    float f = 3.9;

    a = (int)f;
    printf("a = %d\nf = %f", a, f);
    
    exit(0);
}