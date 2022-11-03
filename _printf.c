#include "main.h"

#include <stdlib.h>
#include <stdarg.h>

#define MAX_BUF 1024
/**
 * _printf - prints the input on the shell buffer
 * @format: requested format
 *
 * Return: a length of the string outputed
 */
int _printf(const char *format, ...)
{
	int value, i;
	va_list args;
	char *result;

	if (!format || args == NULL)
		return (-1);
	if (format[0] == '%' && !format[1])
		return (-1);
	result = malloc(MAX_BUF);
	if (!result)
		return (-1);
	for (i = 0; i < MAX_BUF; i++)
		result[i] = '\0';
	va_start(args, format);
	value = get_formater(result, format, args);
	while (*result)
	{
		_write(*result);
		result++;
	}
	va_end(args);
	return (value);
}
