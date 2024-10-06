#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    file = fopen(argv[1], "r");
    int a , b , c ,d;
    fscanf(file, "%d %d %d %d", &a , &b, &c , &d);
    fclose(file);
    FILE *kptr;
    kptr = fopen("answer.txt","w"); // write mode
    fprintf(kptr , "%d/%d\n", (a*d+b*c) , b*d);
    fclose(kptr);
    return 0;
}
