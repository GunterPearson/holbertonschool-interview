#include "palindrome.h"

/**
 * is_palindrome - check to see if # is palindrome
 * @n: unsigned int
 * Return: 1 or 0
 */
int is_palindrome(unsigned long n)
{
	static unsigned long v, rev;

	if (n > 0)
	{
		v = n % 10;
		rev = (rev * 10) + v;
		is_palindrome(n / 10);
	}
	if (rev == n)
		return (1);
	else
		return (0);
}
