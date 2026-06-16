#include <stdio.h>
#define SQRT3 1.73205
// a = l^2 * sqrt(3) / 4
int main(){
    float side, area;

    printf("\nSet triangle side: "); scanf("%f", &side);

    area = side*side*SQRT3/4.0;

    printf("\nArea: %.2f", area);
    
    return 0;
}