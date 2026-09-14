#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total;
	char	*new;

	if (!s1 || !s2)
	{
		return (NULL);
	}

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total = s1_len + s2_len;
	new = malloc(total + 1);
	if (!new)
	{
		return (NULL);
	}

	ft_memcpy(new, s1, s1_len);
	ft_memcpy(new + s1_len, s2, s2_len);
	new[total] = '\0';
	return (new);
}
