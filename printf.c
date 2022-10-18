/*
 * Authors: Francis Ofori Anane and ..........add your name
 * Date: 18/10/2022
 */

#include <stdlib>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * set_size - Set a byte size from list of arguments.
 * @str: The length of argument list.
 *
 * Return: The size of of argument paramters.
*/

int set_size(char *str, ...)
{
	/*store the buffer size of the whole arguments*/
	int buffer_size;

	/*Format specifiers*/
	char c = 'c', s = 's', d = 'd', i = 'i', o = 'o', u = 'u', x = 'x', X = 'X', p = 'p';

	/*Argument parameters*/

	va_list ap;

	if (str == NULL)
		exit(1);

	/*Initialize argument list*/
	va_start(ap, str);

	buffer_size = sizeof(str);

	for (index = 0; index < strlen(str); index++)
	{
		if (str[index] == '%')

			switch(str[index + 1])
			{
			case c:
				buffer_size += sizeof(va_arg(ap, char));
				break;

			case s:
                                buffer_size += sizeof(va_arg(ap, char*));
                                break;
			case d:
				buffer_size += sizeof(va_arg(ap, int));
				break;
			case i:
				buffer_size += sizeof(va_arg(ap, int));
				break;
			case u:
				buffer_size += sizeof(va_arg(ap, unsigned int));
				break;
			}
	}

	return (buffer_size);
}

/**
 * _printf - Print output according to a specified format.
 *
 * @format: The specified format string
 *
 * Return: The length of characters printed out.
 */

_printf(const char *format, ...)
{
	/*interators*/
	int index, index2;

	/*Format characters*/
	char c = 'c', s = 's', d = 'd', i = 'i', o = 'o', u = 'u', x = 'x', X = 'X', p = 'p';

	/*store the length argument of characters*/
	int length = 0;

	/* Allocates memory for list of arguments*/
	char *whole_buffer, *data_to_print;

	/*Argument parameters*/
	va_list ap;

	if (format == NULL)
		exit(1);


	whole_buffer = malloc(set_size(format));

	va_start(ap, format);

	for (index = 0; index < strlen(format); index++)

		whole_buffer[index] = format[index];

	for (index2 = 0; index2 < strlen(format); index2++)
	{
		if (format[index2] == '%' && format[index2 + 1] == c)

			whole_buffer[index] = va_arg(ap, char);

		else if (format[index2] == '%' && format[index2 + 1] == s)

			whole_buffer[index] = va_arg(ap, char*);

		else if ((format[index2] == '%') && (format[index2 + 1] == d || format[index2 + 1] == d))

			whole_buffer[index] = va_arg(ap, int);
	}

}
