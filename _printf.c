#include "main.h"

/**
 *
 *
 *
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		write(1, &format[i], 1);
		switch (
	}

	va_end(args);
	return (i);
}

int main(void)
{
	_printf("Hola tengo 25 anos\n");
	return (0);
}
