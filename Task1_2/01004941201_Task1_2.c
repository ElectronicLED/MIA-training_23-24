#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int start;

    scanf("%d",&start);

    for(int i=start; i>0;i--){

        printf("%d\n",i);
        sleep(1);
    }

    printf("Blast off to the moon!\n");



    return 0;
}
