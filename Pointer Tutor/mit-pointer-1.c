#include <stdio.h>

int main(){

	int arr[] = {1,2,3,4,5};
	int *ptr = arr;
	for(int i=0; i<5; i++)
	{
		printf("Value at arr[%d] = %d, Adress = %p\n",i,*(ptr+i),(void*)(ptr+i) );
	}
	*(ptr+1)=100;
	for(int i=0; i<5; i++)
        {
                printf("NEW: Value at arr[%d] = %d, Adress = %p\n",i,*(ptr+i),(void*)(ptr+i) );
        }

}
