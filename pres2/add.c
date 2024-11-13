//#include <stdio.h>

int multiply(int a, int b)
{
	int tmp = 0;
	for(int i = 0; i < a * b; i++)
	{
		tmp += a;
	}

	return tmp;
}

int main()
{
	printf("%i\n", multiply(3, 4));
}
