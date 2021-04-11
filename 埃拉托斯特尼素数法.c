#include <stdio.h>

int getMax(int prime[], int index);

int main(void)
{
	int num, i, j;

	printf("Plase enter a number(greater than 1): ");
	do {
		scanf("%d", &num);
	} while (num < 2);

	int prime[num + 1];
	for (i = 0; i <= num; ++num) {
		prime[i] = i;
	}

	for (i = 2; ; ++i) {
		if (prime[i] != 0) {
			for (j = 2; i * j <= num; j++) {
				prime[i * j] = 0;
			}
			if (getMax(prime, num) <= i * i)
				break;
		}
		else
			prime[i] = 0;
	}

	printf("The prime number are:");
	for (i = 2; i <= num; ++i) {
		if (prime[i])
			printf("%d ", prime[i]);
	}

	return 0;
}

int getMax(int prime[], int index)
{
	int i;
	for (i = index; ; --i) {
		if (prime[i])
			return prime[index];
	}
}
