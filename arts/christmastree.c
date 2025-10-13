#include <stdio.h>

void tronco(int k, int log){
    int i, j;

    for(i = 0;i <= log;i++){
        for(j = 0;j <= k;j++){
            printf(" ");
        }
        printf("+\n");
        
    }
}

void copa(int size, int log) {
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
    tronco(k, log);
}

int main()
{
	int size_copa, size_tronco;

    printf("\nSet tree size: ");scanf("%d", &size_copa);
    printf("\nSet log size: ");scanf("%d", &size_tronco);
	
	copa(size_copa-2, size_tronco-1);

    printf("\nMERRY CHRISTMAS, UHU!\n");

	return 0;
}
