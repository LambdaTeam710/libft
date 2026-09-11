#include "libft.h"

char	*ft_strdup(const char	*s)
{
	size_t len;
	char	*s2;

	if (!s)
	{
		return (NULL);
	}

	len = ft_strlen(s);
	s2 = malloc(len + 1);
	if (!s2)
	{
		return (NULL);
	}
	ft_memcpy(s2, s, (len + 1));
	return (s2);
}
