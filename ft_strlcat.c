#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
	{
		return (src_len);
	}

	while (dst_len < dstsize && dst[dst_len] != '\0')
	{
		dst_len++;
	}

	if (dstsize <= dst_len)
	{
		return (dstsize + src_len);
	}

	i = 0;
	while (src[i] != '\0' && (i + dst_len < dstsize - 1))
	{
		dst[i + dst_len] = src[i];
		i++;
	}

	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}
