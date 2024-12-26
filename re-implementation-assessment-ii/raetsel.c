
# include <stdio.h>

int main(void)
{
	int a = 6;
	int b = 1;
	printf("a = %i, b = %i\n", a, b);
	{
	int b = 5;
	printf("a = %i, b = %i\n", a, b);
		{
		int a=1;
		int b=3;
		printf("a = %i, b = %i\n", a, b);
			{
			int a=2;
			int b=4;
			printf("a = %i, b = %i\n", a, b);
			}
		{
		printf("a = %i, b = %i\n", a, b);
		}
		}
		{
		printf("a = %i, b = %i\n", a, b);
			{
			int a=4;
			printf("a = %i, b = %i\n", a, b);
			}
		printf("a = %i, b = %i\n", a, b);
		}
	}
	return 0;
}

