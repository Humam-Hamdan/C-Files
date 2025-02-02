 #include <stdio.h>
 
 int main(int argc, char* files[]) {
     
     enum {N=100};
     
     char s[N];
     
     FILE *part1, *part2, *all;
     part1 = fopen("part1.txt","w");
     part2 = fopen("part2.txt","w"); 
     all = fopen("whatever.txt","r");
     
     
     int i = 1;
     while ( fgets(s, N, all) != NULL ) {
         if (i%2) 
              fputs(s, part1);
         else
              fputs(s, part2);
         i++;
     }
     
     fclose(part1);
     fclose(part2);
     fclose(all);
 }
     
