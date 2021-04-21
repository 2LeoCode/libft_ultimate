#include <libft.h>

int	ft_strisdigit(const char *s)
{
	while (ft_isdigit(*s))
		s++;
	return (!*s);
}
