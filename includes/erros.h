/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:52:59 by joeduard          #+#    #+#             */
/*   Updated: 2022/10/26 17:41:54 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRO_H
#define ERRO_H

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

#endif