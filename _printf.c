#include "main.h"

/**
 * _printf - Copia de la funcion printf
 * @format: Formato que debe imprimir y prosezar _printf
 *
 * Return: Numeros de caracteres que tiene cada fomrato
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *s = va_arg(args, char*);
			int iter;

			for (iter = 0; s[iter] != '\0'; iter++)
			{
				write(1, &s[iter], 1);
				count++;
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			char por = va_arg(args, int);

			write(1, "%", 1);
			count++;
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);
	return (count);
}

