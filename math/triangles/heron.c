#include <stdio.h>
#include <math.h>
//semiperimeter:a+b+c/2
//area: sqrt(p*(p-a)*(p-b)*(p-c))
// compile with: gcc heron.c -o output -lm
void inputData(double *a, double *b, double *c){
    printf("\nSet side a: ");scanf("%lf", a);
    printf("\nSet side b: ");scanf("%lf", b);
    printf("\nSet side c: ");scanf("%lf", c);
}
double heronT_area(double a, double b, double c){
    double smp = (a+b+c)/2.0;
    return sqrt(smp*(smp - a)*(smp - b)*(smp - c));
}
int main(){
    double area, a, b, c;

    inputData(&a,&b,&c);

    area = heronT_area(a,b,c);

    printf("\nArea: %.2f", area);
    
    return 0;
}