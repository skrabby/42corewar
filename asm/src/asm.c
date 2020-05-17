#include "asm.h"
#include "error.h"

void	error_exit(char *error) {
	ft_printf("%s", error);
	exit (1);	
}

char*	change_extension(char *filename, char *from, char *to) {
	char	*filebody;
	char	*s;

	filebody = ft_strndup(filename, ft_strlen(filename) - ft_strlen(from));
	s = ft_strjoin(filebody, to);
	free(filebody);
	return(s);
}

t_parser	*init_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser *)ft_memalloc(sizeof(t_parser))))
		error_exit(MALLOC_ERR);
	parser->fd = fd;
	parser->row = 0;
	parser->name = NULL;
	parser->comment = NULL;
	parser->tokens = NULL;
	return (parser);
}

void		to_byte_code(char *filename) {
	int			fd;
	char		*new_fn;
	t_parser	*parser;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_exit(OPEN_FILE_ERR);
	parser = init_parser(fd);
	parse(parser);
	new_fn = change_extension(filename, ".s", ".cor");
	if ((fd = open(new_fn, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1)
		error_exit("FILE CREATE ERROR");
	ft_printf("%s has been successfully created\n", new_fn);
	free(new_fn);
}

int			check_extension(char *name, char *ext)
{
	return ft_strstr(name + (ft_strlen(name) - ft_strlen(ext)), ext) ? 1 : 0;
}

int			main(int argc, char **argv)
{
	if (argc == 2 && check_extension(argv[1], ".s"))
		to_byte_code(argv[1]);
	else
		ft_printf("USAGE INSTRUCTION HERE");
}
