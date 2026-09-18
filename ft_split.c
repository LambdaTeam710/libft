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

static void	split_free(char	**array, int	created_count)
{
	while (created_count > 0)
	{
		free(array[created_count - 1]);
		created_count--;
	}
	free(array);
}

static char	**array_fill(char	**array, const char *s, char c)
{
	int	i;
	int	wi;
	int	length;
	char	*new;

	i = 0;
	wi = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			length = word_len(s + i, c);
			new = ft_substr(s, i, length);
			if (!new)
			{
				split_free(array, wi);
				return (NULL);
			}
			array[wi] = new;
			wi++;
			i = i + length;
		}
	}
	array[wi] = NULL;
	return (array);
}
char	**ft_split(const char	*s, char	c)
{
	char **array;
	int	counter;

	if (!s)
		return (NULL);
	counter = word_count(s, c);
	array = malloc((counter + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (array_fill(array, s, c));
}
