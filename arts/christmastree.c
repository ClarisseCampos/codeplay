#include <stdio.h>

void tronco(int k, int size){
    int i, j;
	size = size*0.3;
    for(i = 0;i <= size;i++){
        for(j = 0;j <= k;j++){
            printf(" ");
        }
        printf("+\n");
        
    }
}

void copa(int size) {
	int i, j, k, m;

	for(i = size; i >= -1; i--) {
        
		for(j = -1; j <= i; j++) {
			printf(" ");
		}
		for(k = 0; k <= (size-j); k++) {
			printf("*");
		}
		for(m = 0; m <= k; m++) {
			printf("*");
		}
		printf("\n");
	}
    tronco(k, size);
}

int main()
{
	int size_copa;

    printf("\nSet tree size: ");scanf("%d", &size_copa);
	
	copa(size_copa-2);

    printf("\n\tMERRY CHRISTMAS, UHU!\n");

	return 0;
}
