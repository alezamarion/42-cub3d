/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:54:20 by azamario          #+#    #+#             */
/*   Updated: 2022/08/13 03:57:11 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map(char *path_to_file)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	*tmp;
	char	**map;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd); //substituir
		if (!line)
			break ;
		tmp = buffer;
		buffer = ft_strjoin(tmp, line);
		ft_super_free((void *)&tmp);
		ft_super_free((void *)&line);	
	}
	map = ft_split(buffer, '\n');
	ft_super_free((void *)&buffer);
	close(fd);
	return (map);
}