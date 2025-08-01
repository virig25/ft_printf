#include "ft_printf.h"

int ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

static int ft_control(char s, va_list args)
{	
	int count = 0;
    if (s == 'c')
		count += ft_putchar((char)va_arg(args, int));
    else if (s == '%')
        count += ft_putchar('%');
	else if(s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if(s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s == 'x' || s == 'X')
		count += ft_puthex(va_arg(args, long), HEX_DOWN);
	else if(s == 'p')
		count += ft_putptr(va_arg(args, void*));
	else if(s == 'u')
		count += ft_putunbr(va_arg(args, unsigned int)); 
	return(count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_control(*format, args);
		}
		else 
    		count += ft_putchar(*format);
		format++;
	}

	va_end(args);
	return (count);
}
