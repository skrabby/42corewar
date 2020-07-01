#ifndef ERROR_H

# define ERROR_H
# define MALLOC_ERR			"[ERROR] Failed to allocate memory"
# define OPEN_FILE_ERR		"[ERROR] Failed to open a file"
# define CREATE_FILE_ERR	"[ERROR] Failed to create a file"
# define READ_FILE_ERR		"[ERROR] Failed to read a file"

void	error_exit(char *error);
void	token_error(char *token, unsigned row);
void	lexical_error(char *token, unsigned row);
void	argument_error(char *arg, unsigned row);
void	operator_error(char *token, unsigned row);
void	label_error(char *label, t_mention *mentions);

#endif