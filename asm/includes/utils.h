#ifndef UTILS_H

# define UTILS_H
# include "asm.h"

int		is_whitespace(char c);
int		is_delimiter(char c);
char	*strjoin_free(bool s1_b, bool s2_b, char *s1, char *s2);
int		is_register(const char *token);

#endif