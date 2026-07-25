#include <stdio.h>


void copa(int h){
    int i,j;
	printf("\n");
    for(i = 1; i <= h; i++)
    {
		printf("\t");
        for(j = 0; j < (h-i); j++){
            printf(" ");
        }
        for(j = 0; j < 2*i-1; j++){
            printf("*");
        }
        printf("\n");
    }
}
void caule(int h){
	int i,j;
	for(i = 0;i < h/3; i++){
		printf("\t");
		for(j = 0;j < h-1; j++){
			printf(" ");
		}
		printf("##\n");
	}
}

int main()
{
	int altura;

    printf("\nSet tree size: ");scanf("%d", &altura);
	
	copa(altura);
	caule(altura);

    printf("\n\tMERRY CHRISTMAS, UHU!\n");

	return 0;
}
