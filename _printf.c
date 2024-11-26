#include "main.h"

/**
 * aux_c - Funcion que ejecuta el controlador %c
 * @args: Utiliza la lista args
 *
 * Return: uno porque imprime solo un caracter para que cuente count
 */

int aux_c(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * aux_s - Funcion que ejecuta el controlador %s
 * @args: utiliza la lista args
 *
 * Return: Returna la cantidad de caracteres del string
 * almacenados en la variable count
 */

int aux_s(va_list args)
{
	char *s = va_arg(args, char*);
	int count = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
		count++;
	}
	return (count);
}

/**
 * aux_por - Funcion que ejecuta el controlador %
 * @args: Utiliza la lista args
 *
 * Return: 1 porque solo immprime un caracter %
 */

int aux_por(va_list args)
{
	char por = '%';

	write(1, &por, 1);
	return (1);
}

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
			count += aux_c(args);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			count += aux_s(args);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			count += aux_por(args);
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
