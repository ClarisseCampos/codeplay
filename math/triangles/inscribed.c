#include <stdio.h>
//  Area do triângulo inscrito em uma circunferência
// a = (a*b*c)/(4.0*r);

void inputData(double *a ,double *b ,double *c ,double *r){
    printf("\nSet side a: ");scanf("%lf", a);
    printf("\nSet side b: ");scanf("%lf", b);
    printf("\nSet side c: ");scanf("%lf", c);
    printf("\nSet set radius: ");scanf("%lf", r);
}
double inscribedT_area(double a ,double b ,double c ,double r){
    return (a*b*c)/(4.0*r);
}
int main(){
    double area, a,b,c,r;

    inputData(&a,&b,&c,&r);

    area = inscribedT_area(a,b,c,r);

    printf("\nArea: %.2f", area);

    return 0;
}