#include <libft.h>int	ft_putllong_fd(long long nb, int fd){	unsigned long long	u;	int					ret;	u = (unsigned long long)nb;	ret = 0;	if (nb < 0)	{		if (nb == LLONG_MIN)			u = (unsigned long long)LLONG_MAX + 1ULL;		else			u = (unsigned long long)(-nb);		if (write(fd, "-", 1) == -1)			return (-1);		ret++;	}	if (u < 10)		return (ret + ft_putchar_fd(u + '0', fd));	ret += ft_putllong_fd((long long)(u / 10ULL), fd);	ret += ft_putllong_fd((long long)(u % 10ULL), fd);	return (ret);}