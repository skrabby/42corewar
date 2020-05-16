#include "asm.h"

void	error_exit(char *error) {
	ft_printf("%s", error);
	exit (1);	
}

char*	change_extension(char *filename, char *extension) {
	char *filebody;
	char *s;

	filebody = ft_strndup(filename, ft_strlen(filename) - 2);
	s = ft_strjoin(filebody, extension);
	free(filebody);
	return(s);
}

void	to_byte_code(char *filename) {
	int	fd;
	char *new_fn;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_exit("FILE OPEN ERROR");
	new_fn = change_extension(filename, ".cor");
	if ((fd = open(new_fn, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
		error_exit("FILE CREATE ERROR");
	free(new_fn);
}

int		check_extension(char *filename, char *extension)
{
	return ft_strstr(filename + (ft_strlen(filename) - ft_strlen(extension)), extension) ? 1 : 0;
}

int		main(int argc, char **argv)
{
	if (argc == 2 && check_extension(argv[1], ".s"))
		to_byte_code(argv[1]);
	else
		ft_printf("USAGE INSTRUCTION HERE");
}
