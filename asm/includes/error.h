/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:24:49 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 17:39:23 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H
# define MALLOC_ERR			"\033[1;31m[ERROR]\033[0m Failed to allocate memory"
# define OPEN_FILE_ERR		"\033[1;31m[ERROR]\033[0m Failed to open a file"
# define CREATE_FILE_ERR	"\033[1;31m[ERROR]\033[0m Failed to create a file"
# define READ_FILE_ERR		"\033[1;31m[ERROR]\033[0m Failed to read a file"

# include "asm.h"

void	error_exit(char *error);
void	token_error(char *token, unsigned row);
void	lexical_error(char *token, unsigned row);
void	argument_error(char *arg, unsigned row);
void	operator_error(char *token, unsigned row);
void	label_error(char *label, t_mention *mentions);

#endif
