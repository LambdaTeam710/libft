#include "libft.h"

static size_t	count_digits(long num)
{
	size_t	counter;

	if (num == 0)
		return (1);
	counter = 0;
	while (num > 0)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*str;
	size_t	i;

	num = n;
	if (num == 0)
	{
		len = count_digits(num);
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		str[len] = '\0';
		str[0] = 48;
		return (str);
	}

	if (num < 0)
	{
		num = -num;
		len = count_digits(num) + 1;
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		str[len] = '\0';
		i = len - 1;
		while (num > 0)
		{
			str[i] = num % 10 + '0';
			num = num / 10;
			i--;
		}
		str[0] = '-';
		return (str);
	}
	else 
	{
		len = count_digits(num);
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		str[len] = '\0';
		i = len - 1;
		while (num > 0)
		{
			str[i] = num % 10 + '0';
			num = num / 10;
			i--;
		}
		return (str);
	}
}
