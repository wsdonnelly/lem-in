/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:38:19 by wdonnell          #+#    #+#             */
/*   Updated: 2022/05/19 14:51:29 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include "libft.h"

# define HASH	0x01	//0b00000001
# define ZERO	0x02	//0b00000010
# define MINUS	0x04	//0b00000100
# define PLUS	0x08	//0b00001000
# define SPACE	0x10	//0b00010000
# define DOT	0x20	//0b00100000
# define COLOR	0x40	//0b01000000
//color
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define EOC		"\x1b[0m"

typedef struct s_pformat
{
	uint8_t		flags;
	int			field_width;
	int			precision;
	char		length_modifier[3];
	int			length;
}				t_pformat;

typedef void					(*t_print_conversion)(t_pformat *cur, \
va_list ap);

int			ft_printf(const char *format, ...);
void		get_format_data(const char *format, t_pformat *cur, \
			int *j, va_list ap);
//util
int			write_char(char c, int len);
void		ft_putnbr_s(long long n);
int			num_digits_base(unsigned long long n, int base, int sum);
int			ft_num_digits_s(long long n);
long double	round_double(long double nb, int precision);

//printers
void		print_percent(t_pformat *cur, va_list ap);
void		print_char(t_pformat *cur, va_list ap);
void		print_str(t_pformat *cur, va_list ap);
void		print_pointer(t_pformat *cur, va_list ap);
void		print_di(t_pformat *cur, va_list ap);
void		print_binary(t_pformat *cur, va_list ap);
void		print_octal(t_pformat *cur, va_list ap);
void		print_unsigned(t_pformat *cur, va_list ap);
void		print_hex(t_pformat *cur, va_list ap);
void		print_hex_upper(t_pformat *cur, va_list ap);
void		print_float(t_pformat *cur, va_list ap);
void		print_banner(t_pformat *cur, va_list ap);
//prefix
void		print_prefix_signed(t_pformat *cur, int positive);

//modifier
void		get_modifier_s(t_pformat *cur, va_list ap, long long *nb);
void		get_modifier_u(t_pformat *cur, va_list ap, unsigned long long *nb);

static const t_print_conversion	g_dispatch[13] = {
	print_percent,
	print_char,
	print_str,
	print_pointer,
	print_di,
	print_di,
	print_binary,
	print_octal,
	print_unsigned,
	print_hex,
	print_hex_upper,
	print_float,
	print_banner
};

#endif
