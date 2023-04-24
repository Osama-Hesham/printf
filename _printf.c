#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - return number of characters
 * @format: input
 * Return: output
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += putchar(va_arg(args, int));
			else if (*format == 's')
				count += printf("%s", va_arg(args, char *));
			else if (*format == '%')
				count += putchar('%');
		}
		else
		{
			count += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return count;
}
