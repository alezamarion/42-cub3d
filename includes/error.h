/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:52:59 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/28 00:29:15 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// Criar MACRO DE ERROS

//Validations
# define E_RESINVAL "Error\nResolution must be 800x600\n"
# define E_NOMAP "Error\nThe map was not specified!\n"
# define E_MANYARG "Error\nThere are many arguments\n"
# define E_MAPINVAL "Error\nThis map is not valid!\n"
# define E_FILEELEMENT "Error\nThis file element is not valid!\n"
# define E_INPUTNVAL "Error\nInput file not valid!\n"
# define E_INVNUMCOLOR "Error\nInvalid number of arguments of color identifier\n"
# define E_INVCHARMAP "Error\nInvalid character on map\n"
# define E_INVALINP "Error\nInvalid number of players\n"
# define E_NOPLAYER "Error\nThere is no player\n"
# define E_NOMINCHAR "Error\nNo minimun characteres!\n"
# define E_NOCOLORP "Error\nNo color provided\n"
# define E_WRONGEXT "Error\nWrong file extention\n"

// MLX
# define E_MLX "Error\nMLX_INIT FAILURE\n"
# define E_MLX_WIN "Error\nMLX_WIN FAILURE\n"
# define E_MLX_NEW_IMG "Error\nMLX_NEW_IMG_FAILURE\n"
# define E_MLX_IMG "Error\nMLX_IMG_FAILURE\n"
# define E_MLX_ADDR "Error\nMLX_ADDR_FAILURE\n"
# define E_MLX_XPM "Error\nMLX_XPM_FAILURE\n"

#endif