/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:20:09 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/06 15:29:36 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW 			"\x1b[33m"
# define CYAN				"\x1b[36m"
# define BLUE				"\x1b[34m"
# define EOC				"\x1b[0m"
# define BOLD				"\033[1m"
# define ULINE				"\033[4m"

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef union
{
	long double				fnum;
	struct
	{
		unsigned long long	mantissa : 64;
		unsigned int		exponent : 15;
		unsigned int		sign : 1;
	}						p;
}							t_union;

typedef struct				s_prec
{
	char					*s1;
	char					*s2;
	char					*tmp;
	char					*tmp2;
	int						isfive;
	int						wasnine;
	int						i;
}							t_prec;

typedef struct				s_multstr
{
	int						*result;
	char					*s;
	int						len1;
	int						len2;
	int						i_n1;
	int						i_n2;
	int						n1;
	int						n2;
	int						carry;
	int						sum;
	int						i;
	int						j;
}							t_multstr;

typedef struct				s_flags
{
	int						is_minus;
	int						is_plus;
	int						is_firstnum;
	int						is_zero;
	int						first_num;
	int						is_point;
	int						is_secondnum;
	int						is_space;
	int						is_grid;
	int						is_lderror;
	int						second_num;
	int						is_longfloat;
	int						floatzero;
	char					symb_space;
	char					symb_zero;
	char					type;
}							t_flags;

typedef struct				s_ldouble
{
	long double				nb;
	char					*mantstr;
	int						i;
	int						is_full;
	int						pow;
	int						multpow;
	int						count_e;
	int						count_z;
	int						strlen;
	char					*m;
	char					*base;
	char					*tmp;
}							t_ldouble;

typedef struct				s_args
{
	char					*str;
	char					symb;
}							t_args;

int							ft_printf(const char *s, ...);
int							ft_fprintf(int fd, const char *s, ...);
long long					ft_mod_ll(long long numb, int base);
int							ft_len_int_ll(long long numb, int base);
int							modul(long long numb);
void						ft_div_ll(long long *numb, int base);
long long					ft_mod_ll(long long numb, int base);
char						*ft_itoa_base_ll(long long numb, int base);
char						*ft_itoa_base_small_lu(unsigned long long numb,
							int base);
char						*ft_itoa_base_lu(unsigned long long numb, int base);
t_flags						*create_struct_of_flags(void);
t_args						*create_struct_of_args(void);
char						*read_str(t_flags *flags, const char *s,
							va_list arg, int *countnull);
void						put_x(char *nb, t_args *args, char symb);
void						paste_ox_to_string(t_args *args);
void						grid_type_x(char *nb, t_flags *flags, t_args *args,
							int i);
void						grid_type_o(char *nb, t_flags *flags, t_args *args,
							int i);
void						grid_type_bigx(char *nb, t_flags *flags,
							t_args *args,
							int i);
void						final_nbstr(char *nb, t_flags *flags, t_args *args);
void						final_charstr(char *nb, t_flags *flags,
							t_args *args);
void						final_charsymb(char nb, t_flags *flags,
							t_args *args);
void						final_percent(char nb, t_flags *flags,
							t_args *args);
void						is_plusflag(char *nb, t_flags *flags, t_args *args,
							int i);
void						is_secondnum_sign(char *nb, t_flags *flags,
							t_args *args, int i);
void						is_minus_nb(char *nb, t_flags *flags, t_args *args,
							int i);
void						is_secondnum_nb(char *nb, t_flags *flags,
							t_args *args);
void						is_firstnum_nb(char **nb, t_flags *flags,
							t_args *args);
void						is_minus_char(t_flags *flags, t_args *args);
void						is_firstnum_char(char nb, t_flags *flags,
							t_args *args);
void						is_firstsecond_str(char **nb, t_flags *flags,
							t_args *args);
int							char_checker(char *str, char c);
char						*check_last_let_for_l(char *s, va_list arg,
							t_flags *flags);
char						*check_last_let_for_p(char *str, va_list arg,
							t_flags *flags);
char						*check_last_let_for_z(char *str, va_list arg,
							t_flags *flags);
char						*check_last_let_for_h(char *str, va_list arg,
							t_flags *flags);
char						*check_last_let_for_dioux(char *str,
							va_list arg, t_flags *flags);
char						*read_types(char const **str);
char						*get_str_numb(char *str, va_list arg,
							t_flags *flags, t_args *args);
void						adapt_flags(t_flags *flags, char *nb);
void						secondnb_handle(t_args *args, t_flags *flags);
void						is_gridflag(char *nb, t_flags *flags, t_args *args);
char						*ft_floatnb(long double nb, t_flags *flags);
void						newstr(char **str, char *add);
void						newnb(char ***nb, char *tmp, t_flags *flags);
void						newnbtwo(char **nb, char *tmp);
void						newargsstr(t_args *args, char *s1, char *s2);
char						*handle_float(long double nb, t_flags *flags);
void						handle_zero(t_ldouble *ld, t_union uf,
							t_flags *flags);
char						*multiply(char *num1, char *num2);
void						mult_pow(t_ldouble *ld);
char						*return_result_for_h(char *str,
							va_list arg, t_flags *flags, int flag);
char						*return_result_for_l(char *str, va_list arg,
							t_flags *flags, int flag);
void						get_final_char(char *s, va_list arg, t_flags *flags,
							t_args *args);
void						return_result_for_c(int **countnull,
							t_flags **flags,
							char **print, t_args **args);
void						clear_f_a(t_flags *flags, t_args *args);
void						change_style(const char **s, t_args *args,
							char **print);
void						clear_and_create_var(t_flags **flags,
							t_args **args);
void						create_var(t_flags **flags, t_args **args,
							char **print);
void						read_symb(const char *s, t_args *args, va_list arg);
void						ld_optimize(t_ldouble *ld);
void						putpoint(char **s, int pad, int is_full);
void						round_number(t_prec *p, int pow);
void						handle_precision(char **s, t_flags *flags,
							t_ldouble *ld);
void						eflag_handler(t_flags *flags, t_ldouble *ld);
int							count_zero(long double nb, t_ldouble *ld);
void						eflag_adapt(t_flags *flags, t_ldouble *ld);
void						eflag_full(char **s, t_ldouble *ld, t_flags *flags,
							t_prec *p);
void						gflag_more(char **s, t_prec *p, t_ldouble *ld,
							t_flags *flags);
void						gflag_less(char **s, t_prec *p, t_ldouble *ld,
							t_flags *flags);
void						check_star_for_first(const char ***s,
							t_flags *flags, va_list arg);
void						check_star_for_second(const char **s,
							t_flags *flags, va_list arg);
char						*r_handler(char *s);

#endif
