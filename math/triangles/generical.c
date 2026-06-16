#include <stdio.h>
// a = b*h/2
int main(){
    float area, base, height;

    printf("\nSet triangle base: "); scanf("%f", &base);
    printf("\nSet triangle height: "); scanf("%f", &height);

    height = base*height/2.0;

    printf("\nArea of the triangle: %.2f", height);
    return 0;
}