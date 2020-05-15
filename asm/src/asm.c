#include "asm.h"
#include <errno.h>

void	to_byte_code(char *filename) {
	return ;
}

int		check_extension(char *filename, char *extension)
{
	int len = ft_strlen(filename);
	return ft_strstr(filename + (len - 2), extension) ? 1 : 0;
}

int		main(int argc, char **argv)
{
	if (argc == 2 && check_extension(argv[1], ".s"))
		to_byte_code(argv[1]);
	else
		ft_printf("USAGE INSTRUCTION HERE");
}
