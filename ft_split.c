#include "libft.h"

static int	word_count(const char	*s, char	c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static int	word_len(const char	*s, char	c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*word_make(const char	*s, int	start, int	len)
{
	char	*new_word;

	new_word = ft_substr(s, start, len);
	return (new_word);
}
//char	**ft_split(const char	*s, char	c);
//{
//}
