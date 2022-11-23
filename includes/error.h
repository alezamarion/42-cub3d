/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:52:59 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/23 13:32:39 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// Criar MACRO DE ERROS

//Validations
# define E_RESINVAL "Error\nResolution below minimum of 1024x768\n"
# define E_NOMAP "Error\nThe map was not specified!\n"
# define E_MANYARG "Error\nThere are many arguments\n"
# define E_MAPINVAL "Error\nThis map is not valid!\n"

// MLX
# define E_MLX "Error\nMLX_INIT FAILURE\n"
# define E_MLX_WIN "Error\nMLX_WIN FAILURE\n"
# define E_MLX_NEW_IMG "Error\nMLX_NEW_IMG_FAILURE\n"
# define E_MLX_IMG "Error\nMLX_IMG_FAILURE\n"
# define E_MLX_ADDR "Error\nMLX_ADDR_FAILURE\n"
# define E_MLX_XPM "Error\nMLX_XPM_FAILURE\n"
# define MLX_ERROR "MLX_ERROR: Could not initialize or create window"

#endif