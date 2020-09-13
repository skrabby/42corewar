/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:40:09 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:40:09 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
** Constants for error messages
*/
# define READ_ERROR "Error: Can't read source file\n"
# define INVALID_HEADER_ERROR "Error: Invalid magic header in champion file\n"
# define INVALID_FILE_ERROR "Error: File has mistake\n"
# define INTERNAL_ERROR "Error: Internal error occurred, can't init memory\n"
# define CHAMP_CODE_ERROR "Error: Invalid code size\n"
# define DOUBLE_INDEX_ERROR "Error: Two champions have same id\n"
# define MANY_CHAMPS_ERROR "Error: Too many champions\n"
# define CODE_SIZE_ERROR

#endif
