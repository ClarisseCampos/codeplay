#include <unistd.h>
#include <stdio.h>

char charchoose(int i){
    switch(i%4){
        case 0: return '|';
        case 1: return '/';
        case 2: return '-';
        default: return '\\';
    }
}

int main() {
    int i,j;
    for(i = 0, j = 1; i <= 100; i+=10, j++){
        printf("Loading [%c]: %d%%\r",charchoose(j),i);
        fflush(stdout);
        usleep(150000);
    }
    
    return 0; 
}
