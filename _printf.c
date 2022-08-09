#include "main.h"
#include <stdarg.h>

/**
 * _printf - function that produces output according to format
 * @format: format string containing character and specifiers
 * Description: this function calls the get_print() function that
 * determines which function to call depending on the conversation
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	const char *p;
	va_list data;

	register int count = 0;

	va_start(data, format);
	
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}


		}
		else
			count += _putchar(*p);
	}

	_putchar(-1);
	va_end(data);

	return (count);

}
