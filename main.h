#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct operator
 * @format: format.
 * @fn: function associated.
 */
struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format format_t - Struct operator
 * @format: format.
 * @format_t: function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *index, va_list arg, char buffer[],
		int width, int size, int precision, int flags);

int print_char(va_list arg, char buffer[],
		int flags, int width, int size, int precision);
int print_string(va_list arg, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list arg, char buffer[],
		int width, int size, int precision, int flags);

int print_int(va_list arg, char buffer[],
		int width, int precision, int size, int flags);
int print_binary(va_list arg, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list arg, char buffer[],
		int width, int precision, int size, int flags);
int print_octal(va_list arg, char buffer[],
		int width, int precision, int size, int flags);
int print_hexadecimal(va_list arg, char buffer[],
		int width, int flags, int size, int precision);
int print_hex_upper(va_list arg, char buffer[],
		int width, int flags, int size, int precision);
int print_hex(va_list arg, char map_to[], char buffer[],
		int flag_ch, int width, int size, int flags, int precision);

int print_non_printable(va_list arg, char buffer[], int flags,
		int width, int precision, int size);
int print_pointer(va_list arg, char buffer[],
		int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list arg);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list arg);

int print_reverse(va_list arg, char buffer[], int flags,
		int width, int precision, int size);
int print_rot13(va_list arg, char buffer[], int flags,
		int width, int precision, int size);

int is_printable(char c);
int append_hex(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_num(long int num, int size);
long int convert_size_unsignd(unsigned long int num, int size);

int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int write_unsignd(int is_negative, int index, char buffer[],
		int flags, int width, int precision, int size);
int write_pointer(char buffer[], int index, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_num(int index, char buffer[], int flags, int width,
		int precision, int length, char padd, char extra_c);
int write_number(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size);

#endif
