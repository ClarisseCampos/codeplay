#include <stdio.h>
#include <math.h>
//a = a*b*sin(teta)/2
//compilar com: gcc areaTheorem.c -o output -lm
void inputData(double *a, double *b, double *theta){
    printf("\nSet side a: ");scanf("%lf", a);
    printf("\nSet side b: ");scanf("%lf", b);
    printf("\nSet angle between a-b: ");scanf("%lf", theta);
}
double areaTheorem(double a, double b, double theta){
    theta *= acos(-1.0)/180;
    return a*b*(sin(theta))/2.0;
}
int main(){
    double area,a,b,theta;
    inputData(&a,&b,&theta);

    area = areaTheorem(a,b,theta);

    printf("\nArea: %.2f", area);
    return 0;
}