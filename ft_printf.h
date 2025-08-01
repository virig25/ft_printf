#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>

# define HEX_UPP "0123456789ABCDEF"
# define HEX_DOWN "0123456789abcdef"

int	ft_printf(const char *format, ...);
static int ft_control(char s, va_list args);
int ft_putchar(char a);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_puthex (long n, char *base);
int ft_putptr (void *ptr);

#endif