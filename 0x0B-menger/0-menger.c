#include "menger.h"

/**
 * menger - print sponge
 * @level: int representing level
 *
 * Return: void
 */
void menger(int level)
{
	int i, j, x, y, size;
	char hash;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			hash = '#';
			while (x > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					hash = ' ';
				}
				x = x / 3;
				y = y / 3;
			}
			printf("%c", hash);
		}
		printf("\n");
	}
}
