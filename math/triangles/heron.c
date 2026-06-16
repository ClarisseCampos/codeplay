#include <stdio.h>
#include <math.h>
//semiperimeter:a+b+c/2
//area: sqrt(p*(p-a)*(p-b)*(p-c))
// compile with: gcc heron.c -o output -lm
int main(){
    float area, smp, a, b, c;
    printf("\nSet side a: ");scanf("%f", &a);
    printf("\nSet side b: ");scanf("%f", &b);
    printf("\nSet side c: ");scanf("%f", &c);

    smp = (a+b+c)/2.0;
    area = sqrt(smp*(smp - a)*(smp - b)*(smp - c));

    printf("\nArea: %.2f", area);
    
    return 0;
}