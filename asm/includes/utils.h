/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:24:58 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 15:24:41 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H
# include "asm.h"

int		is_whitespace(char c);
int		is_delimiter(char c);
char	*strjoin_free(t_bool s1_b, t_bool s2_b, char *s1, char *s2);
int		is_register(const char *token);

#endif
