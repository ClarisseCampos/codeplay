#include <stdio.h>
// a = b*h/2
void inputData(double * base, double * height){
    printf("\nSet triangle base: "); scanf("%lf", base);
    printf("\nSet triangle height: "); scanf("%lf", height);
}
double genericalT_area(double base, double height){
    return base*height/2.0;
}
int main(){
    double area, base, height;
    inputData(&base, &height);

    area = genericalT_area(base,height);

    printf("\nArea: %.2f", area);
    return 0;
}