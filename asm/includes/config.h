/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:24:40 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/19 16:06:29 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define DEBUG_MODE				false
# define USAGE_INSTRUCTION		"Usage: ./asm [champion.s]\n"
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define REG_CHAR				'r'
# define COMMAND_CHAR			'.'
# define COMMENT_CHAR			'#'
# define COMMENT_CHAR_ALT		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','
# define NAME_LENGTH            128
# define COMMENT_LENGTH         2048
# define COREWAR_EXEC_MAGIC		0xea83f3
# define MEM_SIZE				(4 * 1024)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define MAX_STATEMENT_SIZE		14

#endif
