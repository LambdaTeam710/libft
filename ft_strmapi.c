#include "libft.h"

char	*ft_strmapi(char const	*s, char	(*f)(unsigned int, char))
{
	unsigned int	i;
	size_t	s_len;
	char	*new;

	if (!s || !f)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	new = malloc(s_len + 1);
	if (!new)
	{
		return (NULL);
	}
	i = 0;
	while (i < (unsigned int)s_len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[s_len] = '\0';
	return (new);
}
