#include <stdio.h>

int main(){
    float area, a, b, c, r;
    printf("\nSet side a: ");scanf("%f", &a);
    printf("\nSet side b: ");scanf("%f", &b);
    printf("\nSet side c: ");scanf("%f", &c);
    printf("\nSet radius: ");scanf("%f", &r);

    area = (a+b+c)*r/2.0;

    printf("\nArea: %.2f", area);
    
    return 0;
}