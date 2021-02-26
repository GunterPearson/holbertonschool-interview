#include "slide_line.h"

/**
* move_right - slides right
* @line: Pointer
* @size: size of array
* Return: 1 or 0
*/
int move_right(int *line, int size)
{
	int i, j, x = 0, temp;

	temp = line[size - 1];
	for (i = size - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] != 0)
			{
				if (temp == line[j])
				{
					temp = temp + line[j];
					line[j] = 0;
					break;
				}
				else if (temp == 0)
				{
					temp = line[j];
					line[i] = temp;
					line[j] = 0;
				}
				else
				{
					temp = line[i];
					x = 1;
					break;
				}
			}
		}
		line[i] = temp;
		if (x == 1)
		{
			temp = line[i - 1];
			x = 0;
		}
		else
			temp = 0;
	}
	return (1);
}

/**
 * move_left - slides left
 * @line: Pointer
 * @size: size of array
 * Return: 1 or 0
*/
int move_left(int *line, int size)
{
	int i, j;
	int temp = line[0], x = 0;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (line[j] != 0)
			{
				if (temp == line[j])
				{
					temp = temp + line[j];
					line[j] = 0;
					break;
				}
				else if (temp == 0)
				{
					temp = line[j];
					line[i] = temp;
					line[j] = 0;
				}
				else
				{
					temp = line[i];
					x = 1;
					break;
				}
			}
		}
		line[i] = temp;
		if (x == 1)
		{
			temp = line[i + 1];
			x = 0;
		}
		else
			temp = 0;
	}
	return (1);
}

/**
* slide_line - slide and merge
* @line: pointer
* @size: size of the array
* @direction: left or right
* Return: 1 or 0
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
		return (0);
	if (direction == SLIDE_LEFT)
		return (move_left(line, (int)size));
	if (direction == SLIDE_RIGHT)
		return (move_right(line, (int)size));
	return (0);
}
