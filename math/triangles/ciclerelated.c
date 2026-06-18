#include <stdio.h>

void inputData(double *a ,double *b ,double *c ,double *r){
    printf("\nSet side a: ");scanf("%lf", a);
    printf("\nSet side b: ");scanf("%lf", b);
    printf("\nSet side c: ");scanf("%lf", c);
    printf("\nSet set radius: ");scanf("%lf", r);
}
double inscribedT_area(double a ,double b ,double c ,double r){
    return (a*b*c)/(4.0*r);
}
double circumscribedT_area(double a ,double b ,double c ,double r){
    return (a+b+c)*r/2.0;
}

int main(){
    int option;
    double area, a, b, c, r;
    printf("\n === MENU ===");
    printf("\n1)Area of the inscribed triangle\n2)Area of the circunscribed triangle\nSelect option: ");
    scanf("%d", &option);

    inputData(&a,&b,&c,&r);
    if(option == 1){
        area = inscribedT_area(a,b,c,r);
    }else{
        area = circumscribedT_area(a,b,c,r);
    }

    printf("\nArea: %.2f\n", area);

    return 0;
}