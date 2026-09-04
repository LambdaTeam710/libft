#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>


typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;


size_t	ft_strlen(const	char *s);
int	ft_isalpha(int	c);
int	ft_isdigit(int	c);
int	ft_isalnum(int	c);
int	ft_isascii(int	c);
int	ft_isprint(int	c);
int	ft_toupper(int	c);
int	ft_tolower(int	c);
char	*ft_strchr(const char	*s, int	c);
char	*ft_trrchr(const char	*s, int	c);
int	ft_strncmp(const char	*s1, const char	*s2, size_t	n);

#endif
