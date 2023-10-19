#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define FIELD_BUF_SIZE 50

/**
 * struct flags - a structure representing various parameters
 * flags_t - a type definition for a structure parameters
 *
 * @plus_flag: A flag for the plus sign
 * @space_flag: A flag for the space character
 * @hashtag_flag: A flag for the hashtag character
 * @zero_flag: A flag for the zero character
 * @minus_flag: A flag for the minus sign
 *
 * Description: This structure holds various flags and parameters that are used
 * in a printf-like function to format and print data in different ways.
**/

typedef struct flags
{
	unsigned int plus_flag          : 1;
	unsigned int space_flag         : 1;
	unsigned int hashtag_flag       : 1;
	unsigned int zero_flag          : 1;
	unsigned int minus_flag         : 1;
} flags_t;

/**
 * struct parameters - a structure representing various parameters
 * parameters_t - a type definition for a structure parameters
 * @unsign: An unsigned integer flag
 * @width: The width of the output
 * @precision: The precision of the output
 * @h_modifier: A flag for the 'h' modifier
 * @l_modifier: A flag for the 'l' modifier
 *
 * @plus_flag: A flag for the plus sign
 * @space_flag: A flag for the space character
 * @hashtag_flag: A flag for the hashtag character
 * @zero_flag: A flag for the zero character
 * @minus_flag: A flag for the minus sign
 *
 * Description: This structure holds various flags and parameters that are used
 * in a printf-like function to format and print data in different ways.
**/

typedef struct parameters
{
	unsigned int unsign             : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier         : 1;
	unsigned int l_modifier         : 1;

	unsigned int plus_flag          : 1;
	unsigned int space_flag         : 1;
	unsigned int hashtag_flag       : 1;
	unsigned int zero_flag          : 1;
	unsigned int minus_flag         : 1;
} parameters_t;

/**
 * struct specifier - a structure representing a format specifier
 *			and its corresponding function
 * specifier_t - a type definition for a structure specifier
 * @specifier: The format specifier as a string
 * @f: A pointer to the function that handles
 *	the corresponding format specifier
 *
 * Description: This structure is used to map a format
 *		specifier to its corresponding function
 *		in a printf-like function.
**/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameters_t *);
} specifier_t;

/**
 * struct printHandler - a structure representing a print handler
 * print_handler - a type definition for a structure printHandler
 * @specifier: The format specifier as a character
 * @f: A pointer to the function that handles
 *	the corresponding format specifier
 *
 * Description: The 'c' member is a character
 *	that contains the format specifier,
 * and 'f' is a pointer to the function that handles that format specifier.
**/

typedef struct printHandler
{
	const char *specifier;
	int (*f)(va_list ap, flags_t *f);
} print_handler;

int _printf(const char *format, ...);
char *converter(unsigned long int num, int base, int lowercase);
int (*function_selector(const char *p))(va_list, flags_t *);
int hexadecimal_print(va_list l, flags_t *f);
int hexadecimal_uppercase_print(va_list l, flags_t *f);
int binary_print(va_list l, flags_t *f);
int octal_print(va_list l, flags_t *f);
int special_string_print(va_list l, flags_t *f);
int reverse_string_print(va_list l, flags_t *f);
int rot13_encode_print(va_list l, flags_t *f);
int percent_symbol_print(va_list l, flags_t *f);
int integer_print(va_list l, flags_t *f);
int string_print(va_list l, flags_t *f);
int character_print(va_list l, flags_t *f);
int unsigned_integer_print(va_list l, flags_t *f);
int decimal_print(va_list l, flags_t *f);
int pointer_address_print(va_list l, flags_t *f);
int unknown_print(va_list l, flags_t *f);

int _putchar(char c);
int _puts(char *str);
void init_params(parameters_t *params);
int get_flag(const char *p, parameters_t *params);
const char *get_width(const char *p, parameters_t *params, va_list ap);
const char *get_precision(const char *p, parameters_t *params, va_list ap);
const char *get_modifier(const char *p, parameters_t *params);
int get_specifier(const char *p);
int print_from_to(const char *start, const char *p);
int (*get_print_func(const char *p))(va_list, flags_t *);


#endif /* MAIN_H */
