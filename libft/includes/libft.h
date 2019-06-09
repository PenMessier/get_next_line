/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frenna <frenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:21:32 by frenna            #+#    #+#             */
/*   Updated: 2019/05/02 11:29:59 by frenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Copies the character c (an unsigned char) to the first n characters
** of the string pointed to, by the argument str.
*/
void				*ft_memset(void *str, int c, size_t n);

/*
** Copies n bytes, each with a value of zero, into string str.
*/
void				ft_bzero(void *str, size_t n);

/*
** Copies the values of n bytes from the location pointed to by src
** directly to the memory block pointed to by dest.
*/
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int ch, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);

/*
** Returns length of an array of chars.
*/
size_t				ft_strlen(const char *str);

/*
** Returns a pointer to a null-terminated byte string,
** which is a duplicate of the string pointed to by src.
*/
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/*
** Locates the first occurrence of ch (converted to a char) in the string
** pointed to by str.  The terminating null character is considered to be part
** of the string; therefore if ch is `\0', the functions locate the
** terminating `\0'.
*/
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);

/*
** Finds the first occurrence of the null-terminated string ned
** in the null-terminated string hay.
** If ned is an empty string, hay is returned;
** if ned occurs nowhere in hay,
** NULL is returned; otherwise a pointer to the first character
** of the first occurrence of ned is returned.
*/
char				*ft_strstr(const char *hay, const char *ned);

/*
** Finds the first occurrence of the null-terminated string ned
** in the null-terminated string h, where the search is limited
** to the first len characters of h. If ned is an empty string,
** h is returned; if ned occurs nowhere in h,
** NULL is returned; otherwise a pointer to the first character
** of the first occurrence of ned is returned.
*/
char				*ft_strnstr(const char *h, const char *ned, size_t len);

/*
** Compares two null-terminated byte strings.
** The comparison is done lexicographically.
*/
int					ft_strcmp(const char *s1, const char *s2);

/*
** Compares up to n characters of the null-terminated string s1
** to those of the s2. The comparison is done lexicographically.
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** Converts the string argument str to an integer (type int).
*/
int					ft_atoi(const char *s);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);

/*
** Allocates with malloc() and returns a “fresh” memory area. The memory
** allocated is initialized to 0.
** If the allocation fails, the function returns NULL.
*/
void				*ft_memalloc(size_t size);

/*
** Takes as a parameter the address of a memory area
** that needs to be freed with free(), then puts the pointer to NULL.
*/
void				ft_memdel(void **ap);

/*
** Allocates (with malloc()) and returns a “fresh” string ending with ’\0’.
** Each character of the string is initialized at ’\0’.
** If the allocation fails the function returns NULL.
*/
char				*ft_strnew(size_t size);

/*
** Takes as a parameter the address of a string that
** need to be freed with free(), then sets its pointer to NULL.
*/
void				ft_strdel(char **as);

/*
** Sets every character of the string to the value ’\0’.
*/
void				ft_strclr(char *s);

/*
** Applies the function f to each character of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
*/
void				ft_striter(char *s, void (*f)(char*));

/*
** Applies the function f to each character of the string passed as argument,
** and passing its index as first argument.
** Each character is passed by address to f to be modified if necessary.
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** Applies the function f to each character of the string given as argument
** to create a new string resulting from the successive applications of f.
*/
char				*ft_strmap(const char *s, char (*f)(char));

/*
** Applies the function f to each character of the string passed as argument
** by giving its index as first argument to create a new string
** resulting from the successive applications of f.
*/
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/*
** Lexicographical comparison between s1 and s2. If the 2 strings
** are identical the function returns 1, or 0 otherwise.
*/
int					ft_strequ(const char *s1, const char *s2);

/*
** Lexicographical comparison between s1 and s2 up to n characters
** or until a ’\0’ is reached. If the 2 strings
** are identical the function returns 1, or 0 otherwise.
*/
int					ft_strnequ(const char *s1, const char *s2, size_t n);

/*
** Allocates (with malloc()) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren’t refering
** to a valid substring, the behavior is undefined.
** allocation fails, the function returns NULL.
*/
char				*ft_strsub(const char *s, unsigned int start, size_t len);

/*
** Allocates (with malloc(3)) and returns a “fresh” substring
** ending with ’\0’, result of the concatenation of s1 and s2.
** If the allocation fails the function returns NULL.
*/
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);

/*
** Allocates (with malloc()) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtaine
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
*/
char				**ft_strsplit(const char *s, char c);

/*
** Allocate (with malloc()) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument.
*/
char				*ft_itoa(int n);

/*
** Outputs the character c to the standard output.
*/
void				ft_putchar(char c);

/*
** Outputs the string s to the standard output.
*/
void				ft_putstr(char const *s);

/*
** Outputs the string s to the standard output followed by a ’\n’.
*/
void				ft_putendl(char const *s);

/*
** Outputs the integer n to the standard output.
*/
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);

/*
** Allocates (with malloc()) and returns a “fresh” link.
** The variables content and content_size of the new link are initialized
** by copy of the parameters of the function. If the parameter
** content is nul, the variable content is initialized to NULL
** and the variable content_size is initialized to 0 even if
** the parameter content_size isn’t. The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
** Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc())
** resulting from the successive applications of f.
*/
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Counts words in the string pointed to by str,
** using the character c as a delimiter.
*/
int					ft_count_words(const char *str, char c);

/*
** Returns an array of integers from min to max.
*/
int					*ft_range(int min, int max);

/*
** Swaps two variables.
*/
void				ft_swap(int *a, int *b);

/*
** Sorts an array of integers using the bubble sort algorithm.
*/
void				ft_bubble_sort(int *arr, int n);

/*
** Checks if an array of integers is sorted.
*/
int					ft_is_sorted(int *arr, int n);

#endif
