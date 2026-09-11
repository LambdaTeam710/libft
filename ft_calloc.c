#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
		{
			return (NULL);
		}
		ft_bzero(ptr, 1);
		return (ptr);
	}

	if (size > SIZE_MAX / nmemb)
	{
		return (NULL);
	}
	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, total);
	return (ptr);
}

