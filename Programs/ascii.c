#include <stdio.h>
#include <stdbool.h>

int main(){
	char a;
	bool check=true;
	while(check){
		printf("input char: ");
		scanf("%c", &a);
		printf("ascii of %c is %d\n", a ,(int)a);

		printf("do you want to continue? 1=no 0=yes");
		int i;
		scanf("%d",&i);
		if(i==1)
			check=false;
	}
	return 0;
}
