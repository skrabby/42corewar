/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:24:49 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/19 16:38:05 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H
# define MALLOC_ERR			"\033[1;31m[ERROR]\033[0m Can't allocate memory\n"
# define OPEN_FILE_ERR		"\033[1;31m[ERROR]\033[0m Can't open a file\n"
# define CREATE_FILE_ERR	"\033[1;31m[ERROR]\033[0m Can't create a file\n"
# define READ_FILE_ERR		"\033[1;31m[ERROR]\033[0m Can't read a file\n"
# define CHAMPION_NO_CMD	"\033[1;31m[ERROR]\033[0m Champion no commands\n"
# define EMPTY_FILE			"\033[1;31m[ERROR]\033[0m Empty file found\n"

# include "asm.h"

void	error_exit(char *error);
void	token_error(char *token, unsigned row);
void	lexical_error(char *token, unsigned row);
void	argument_error(char *arg, unsigned row);
void	operator_error(char *token, unsigned row);
void	label_error(char *label, t_mention *mentions);

#endif
