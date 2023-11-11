int ft_returns(const char *text, va_list args, int n)
{
	if (*text == 'c')
		return (ft_strlen(args));
if (*text == 's')
		return (ft_strlen(args));
	if (*text == 'p')
		ft_isp(args);
	if (*text == 'i' || *text == 'd')
		return (ft_strlen(args));
	if (*text == 'u')
		return (ft_strlen(args));
	if (*text == 'x' || *text == 'X')
		return (n);
	if (*text == '%')
		return (1);
	return (ft_strlen(args));
}