#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int a = 2; int b = 5;
    srand(time(NULL));
    a = rand();
    int c = (a++, a+5);
    printf("%d, hello\n", c); 
    char v = getchar();
    // exit(0);
    
    switch (v){
    case 'a':
        printf("fir\n");
        break;
    case 'b':
        printf("sec\n");
        break;
    default:
        printf("def\n");
        break;
    }
    return 0;
}
