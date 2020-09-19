/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:17:49 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/19 16:07:27 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "config.h"

t_bool		check_extension(char *name, char *ext)
{
	return (ft_strstr(name + (ft_strlen(name) - ft_strlen(ext)), ext) ?
	true : false);
}

char		*change_extension(char *filename, char *from, char *to)
{
	char	*filebody;
	char	*s;

	filebody = ft_strndup(filename, ft_strlen(filename) - ft_strlen(from));
	s = ft_strjoin(filebody, to);
	free(filebody);
	return (s);
}

t_parser	*init_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser *)ft_memalloc(sizeof(t_parser))))
		error_exit(MALLOC_ERR);
	parser->fd = fd;
	parser->row = 0;
	parser->str_parse = false;
	parser->body_size = 0;
	parser->pos = 0;
	parser->op_pos = 0;
	parser->name = NULL;
	parser->comment = NULL;
	parser->tokens = NULL;
	parser->labels = NULL;
	parser->body = NULL;
	return (parser);
}

void		assemble(char *filename)
{
	int			fd;
	char		*new_fn;
	t_parser	*parser;
	t_token		*cur;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_exit(OPEN_FILE_ERR);
	parser = init_parser(fd);
	parse(parser);
	cur = parser->tokens;
	process_description(parser, &cur);
	process_body(parser, &cur);
	process_mentions(parser);
	new_fn = change_extension(filename, ".s", ".cor");
	if ((fd = open(new_fn, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		error_exit(CREATE_FILE_ERR);
	write_bytes(fd, parser);
	debug(parser);
	ft_printf("\033[0;32m%s\033[0m has been successfully created\n", new_fn);
	free(new_fn);
	free_helper(parser);
}

int			main(int argc, char **argv)
{
	if (argc == 2 && check_extension(argv[1], ".s"))
		assemble(argv[1]);
	else
		ft_printf(USAGE_INSTRUCTION);
}
