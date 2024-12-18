#include "main.h"
#include "stdio.h"

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

	if (s == NULL)
		return (write(1, "(null)", 6));

	for (i = 0; s[i] != '\0'; i++)
	{
		write(1, &s[i], 1);
		count++;
	}
	return (count);
}

/**
 * aux_por - Funcion que ejecuta el controlador %
 *
 * Return: 1 porque solo immprime un caracter %
 */

int aux_por(void)
{
	char por = '%';

	return (write(1, &por, 1));
}

/**
 * aux_id - Funcion que ejecuta el controlador i y d
 * @args: Lista argas
 *
 * Return: Count que es la cantidad de caracteres del numero
 */

int aux_id(va_list args)
{
	long num = va_arg(args, int);
	int count = 0, i, i2;
	char tmp[128];

	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	for (i = 0; num > 0;)
	{
		tmp[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	for (i2 = i - 1; i2 >= 0; i2--)
	{
		write(1, &tmp[i2], 1);
		count++;
	}
	return (count);

}

/**
 * _printf - Copia de la funcion printf
 * @format: Formato que debe imprimir y prosezar _printf
 *
 * Return: Numeros de caracteres que tiene cada fomrato
 */

int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

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
			count += aux_por();
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else if (format[i] == '%' && format[i + 1] == 'i')
		{
			count += aux_id(args);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			count += aux_id(args);
			i++;
		}
		else
		{
			count += write(1, &format[i], 1);
		}
	}
	va_end(args);
	return (count);
}
