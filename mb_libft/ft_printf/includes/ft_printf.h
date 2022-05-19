/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:43:19 by mbeeler           #+#    #+#             */
/*   Updated: 2022/05/19 14:49:18 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft.h"
# include <stdarg.h>

typedef struct s_printer
{
	va_list	ap;
	int		hash;
	int		hash2;
	int		space;
	int		plus;
	int		dash;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		precision2;
	int		length;
	int		mod_l;
	int		mod_cap_l;
	int		mod_ll;
	int		mod_h;
	int		mod_hh;
	int		arg_len;
	int		neg;
	int		digits;
	int		sign;
	int		num_uneven;
}	t_printer;

int		ft_printf(const char *format, ...);
int		ft_type_conversion(const char **format, t_printer *args);
int		ft_set_color(const char **format);
void	ft_initialize_args(t_printer *args);
void	ft_cs_conversion(const char **format, t_printer *args);
void	ft_diopux_conversion(const char **format, t_printer *args);
void	ft_di_conversion(const char **format, t_printer *args);
void	ft_oux_conversion(const char **format, t_printer *args);
void	ft_p_conversion(const char **format, t_printer *args);
t_u64	ft_convert_number(t_printer *args, t_s64 num);
int		ft_get_sig_bytes(const char **format, t_printer *args, t_u64 n, int div);
void	ft_print_width_precision(const char **format, t_printer *args, t_u64 n);
void	ft_print_number(const char **format, t_printer *args, t_u64 n, int div);
void	ft_print_dash(t_printer *args, t_u64 n);
void	ft_efg_conversion(const char **format, t_printer *args);
void	ft_f_conversion(t_printer *args);
void	ft_e_conversion(t_printer *args);
void	ft_g_conversion(t_printer *args);
void	ft_print_g_as_e(char **result, t_printer *args, int i, int g);
t_f128	ft_convert_float(t_printer *args, t_f128 num);
char	*ft_printf_lftoa(long double n, t_printer *args);
char	*ft_f_conversion_number(t_u64 number_dec, t_u64 add_zero_num);
char	*ft_f_conversion_frac(t_u64 frac_dec, t_s16 offset, t_printer *args, \
		char *number);
char	*ft_fraction_bintoa(const char *binary, const char *fraction_div, \
		t_printer *args);
void	ft_print_width(const char *result, t_printer *args);
void	ft_print_hash_dash(t_printer *args, char *result);
void	ft_b_conversion(const char **format, t_printer *args);

#endif
