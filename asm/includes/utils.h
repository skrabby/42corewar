#ifndef UTILS_H

# define UTILS_H

int		is_whitespace(char c);
int		is_delimiter(char c);
char	*strjoin_free(int s1_b, int s2_b, char *s1, char *s2);
int		is_register(const char *token);

#endif