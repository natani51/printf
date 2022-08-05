#include <stdlib.h>

#include "main.h"

/**

 * hex_digit - converts a decimal less than 16 to its hexadecimal form

 * @c: The decimal passed

 * Return: The hexadecimal digit, otherwise '\0'

 */

char hex_digit(char c)

{

	char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',

		'a', 'b', 'c', 'd', 'e', 'f'

	};



	return (c >= 0 && c <= 15 ? *(digits + c) : '\0');

}

/**

 * cmp_nums - Compares the left number to the right number

 * @left: The left number passed

 * @right: The right number passed

 * Return: 1 if left is > right, -1 if left < right, otherwise 0

 */

char cmp_nums(char *left, char *right)

{

	char *n1 = left;

	char *n2 = right;

	int len1 = str_len(n1) - 1, len2 = str_len(n2) - 1, i = 0;



	for (i = 0; (*(n1 + i) == '0' && *(n1 + i + 1) != '\0') && i < len1; i++)

		;

	n1 = n1 + i;

	len1 = str_len(n1);

	for (i = 0; (*(n2 + i) == '0' && *(n2 + i + 1) != '\0') && i < len2; i++)

		;

	n2 = n2 + i;

	len2 = str_len(n2);

	if (len1 > len2)

	{

		return (1);

	}

	else if (len1 < len2)

	{

		return (-1);

	}

	else

	{

		for (i = 0; i < len1; i++)

		{

			if (*(n1 + i) > *(n2 + i))

				return (1);

			if (*(n1 + i) < *(n2 + i))

				return (-1);

		}

		return (0);

	}

}



/**

 * str_to_int - Converts a string to an int

 * @num: The string input to convert

 * Return: The converted number

 */

int str_to_int(char *num)

{

	int i = 1, len, exp = 1;

	int res = 0;



	len = str_len(num);

	for (i = len - 1; i >= 0; i--)

	{

		if (*(num + i) == '-')

			res *= -1;

		else if (is_digit(*(num + i)))

		{

			res += (*(num + i) - '0') * exp;

			exp *= 10;

		}

	}

	return (res);

}

/**

 * bin_to_int - Converts an array of bits to an int

 * @bin_str: The array of bits

 * Return: The array of bits' decimal equivalent

 */

int bin_to_int(char *bin_str)

{

	int len = str_len(bin_str);

	int i;

	int e = 1;

	int result = 0;



	for (i = len - 1; i >= 0 && *(bin_str + i) != '\0'; i--)

	{

		if (*(bin_str + i) == '0' || *(bin_str + i) == '1')

		{

			result += (*(bin_str + i) - '0') * e;

			e *= 2;

		}

	}

	return (result);

}

/**

 * long_to_oct - Converts a long integer to its octal representation

 * @num: The number input to convert

 * Return: The octal representation of the number

 */

char *long_to_oct(unsigned long num)

{

	int i = 0, size = num == 0 ? 2 : 21;

	unsigned long num1 = num;

	char *str;



	str = malloc(sizeof(char) * (size));

	if (str)

	{

		mem_set(str, size, 0);

		if (num == 0)

		{

			*(str + i) = '0';

			return (str);

		}

		for (i = 0; i <= size; i++)

		{

			*(str + i) = (num1 % 8) + '0';

			num1 /= 8;

		}

		rev_string(str);

		str = trim_start(str, '0', TRUE);

		str = num == 0 ? str_cat("0", "", FALSE) : str;

	}

	return (str);

}
