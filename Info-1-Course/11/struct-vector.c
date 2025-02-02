#include <stdio.h>

const int Max_Post = 1000;


typedef struct {
    unsigned int number, times;
    double pieceprice;
} OnePost;

/* Read OnePost and return the number of Post, End is number == 0 */

int read(OnePost p[]){
    int i=0;

    do{
        printf("Number, Times, Pieceprice?  ");
        scanf("%u %u %lf", &p[i].number, &p[i].times, &p[i].pieceprice);
    } while (p[i++].number >0);
    return i-1;
}

int main(){
    OnePost Order[Max_Post];
    int num_post;

    num_post = read(Order);

    printf("All in All %i Posts\n", num_post);
}
