#include <stdio.h>
#define SQRT3 1.73205
// a = l^2 * sqrt(3) / 4
void inputData(double * side){
    printf("\nSet triangle side: "); scanf("%lf", side);
}
double equilateralT_area(double side){
    return side*side*SQRT3/4.0;
}
int main(){
    double side, area;
    inputData(&side);

    area = equilateralT_area(side);

    printf("\nArea: %.2f", area);
    
    return 0;
}