#include <stdio.h>
// a = a*b*c/4*r
int main(){
    float area,a,b,c,r;

    printf("\nSet side a: ");scanf("%f", &a);
    printf("\nSet side b: ");scanf("%f", &b);
    printf("\nSet side c: ");scanf("%f", &c);
    printf("\nSet set radius: ");scanf("%f", &r);

    area = (a*b*c)/(4.0*r);

    printf("\nArea: %.2f", area);
    return 0;
}