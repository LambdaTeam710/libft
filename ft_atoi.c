#include "libft.h"

int	ft_atoi(const char	*nptr)
{
	int	i;
	long	result;
	int	sign;
	
	i = 0;
	sign = 1;
	result = 0;

	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}

	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
	{
		i++;
	}

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}

	return ((result * sign));
}
