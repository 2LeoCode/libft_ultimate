#include <libft.h>

char	*ft_substr2(const char *s, size_t len, unsigned start, size_t n)
{
	if (len < start)
		return (ft_strdup2("", 0));
	return (ft_strndup2(s + start, len - start, n));
}
