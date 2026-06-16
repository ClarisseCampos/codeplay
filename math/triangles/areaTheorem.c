#include <stdio.h>
#include <math.h>
//a = a*b*sin(teta)/2
//compilar com: gcc areaTheorem.c -o output -lm
int main(){
    float area,a,b,theta;
    printf("\nSet side a: ");scanf("%f", &a);
    printf("\nSet side b: ");scanf("%f", &b);
    printf("\nSet angle between a-b: ");scanf("%f", &theta);

    theta = theta*(acos(-1.0)/180); // deg -> rad

    area = a*b*(sin(theta))/2.0;

    printf("\nArea: %.2f", area);
    return 0;
}