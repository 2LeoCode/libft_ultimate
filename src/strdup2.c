#include <libft.h>

char	*ft_strdup2(const char *s1, size_t len)
{
	void	*s;

	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	return ((char *)ft_memcpy(s, s1, len + 1));
}
