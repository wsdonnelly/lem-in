/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:16:26 by manuelbeele       #+#    #+#             */
/*   Updated: 2022/03/18 09:59:28 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "types.h"
# include "get_next_line.h"
# include "./ft_printf/includes/ft_printf.h"

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void		btree_apply_infix(t_btree *root, void (*applyf) (void *));
void		btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void		btree_apply_suffix(t_btree *root, void (*applyf) (void *));
t_btree		*btree_create_node(void *item);
void		btree_insert_data(t_btree **root, void *item, \
			int (*cmpf) (void *, void *));
int			ft_any(char **tab, int (*f) (char*));
int			ft_atoi(const char *str);
int			ft_count_if(char **tab, int (*f)(char*));
t_list		*ft_create_elem(void *data);
int			ft_fibonacci(int index);
int			ft_find_next_prime(int nb);
void		ft_foreach(int *tab, int length, void (*f)(int));
int			ft_is_prime(int nb);
int			ft_is_sort(int *tab, int length, int (*f) (int, int));
t_list		*ft_list_at(t_list *begin_list, unsigned int nbr);
void		ft_list_clear(t_list **begin_list);
t_list		*ft_list_last(t_list *begin_list);
void		ft_list_push_back(t_list **begin_list, void *data);
void		ft_list_push_front(t_list **begin_list, void *data);
t_list		*ft_list_push_params(int ac, char **av);
int			ft_list_size(t_list *begin_list);
int			*ft_map(int *tab, int length, int (*f) (int));
void		ft_print_words_tables(char **table);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char const *s);
int			*ft_range(int min, int max);
int			ft_sqrt(int nb);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_strlowcase(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strupcase(char *str);
void		ft_swap(int *a, int *b);
int			ft_ultimate_range(int **range, int min, int max);
char		**ft_split_whitespaces(char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
void		ft_memdelarray(void **ap);
void		ft_strdelarray(char **as);
char		*ft_itoa(int n);
void		ft_putendl(char const *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstclearelem(void *content, size_t content_size);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t		ft_strchrloc(const char *s, int c);
char		*ft_strmove(char *dst, const char *src, size_t len);
char		*ft_strndup(const char *s1, size_t len);
char		*ft_strnjoin(char const *s1, char const *s2, size_t len1, \
			size_t len2);
int			get_next_line(const int fd, char **line);
void		ft_strjoin_inplace(char **s1, char **s2);
void		ft_strpad_left_inplace(char **str, char c, int num);
char		*ft_strpad_left(const char *str, char c, int num);
void		ft_strpad_right_inplace(char **str, char c, int num);
char		*ft_strpad_right(const char *str, char c, int num);
void		ft_strtrim_char_left_inplace(char **s, char c);
char		*ft_strtrim_char_left(char const *s, char c);
void		ft_strtrim_char_right_inplace(char **s, char c);
char		*ft_strtrim_char_right(char const *s, char c);
char		*ft_lutoa_base(unsigned long n, int base);
char		*ft_lutoa(unsigned long n);
char		*ft_lutobin(unsigned long n);
t_u64		ft_bintolu(const char *str);
char		*ft_bintoa(const char *binary);
char		*ft_round_string(const char *num);
void		ft_round_string_inplace(char **num);
char		*ft_lutobin_size(unsigned long n, char size);

#endif
