#include "libft.h"

char	*ft_strrchr(const char	*s, int	c)
{
	size_t	len;
	int	i;

	len = ft_strlen(s);
	if ((unsigned char) c == '\0')
	{
		return ((char *) &s[len]);
	}

	i = (len - 1);
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char) c)
		{
			return ((char *) &s[i]);
		}
		i--;
	}
	return (NULL);
}
