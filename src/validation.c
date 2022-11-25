/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:00:11 by joeduard          #+#    #+#             */
/*   Updated: 2022/11/25 16:36:54 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_map(char **map)
{
	int i = 0;
	
	printf("\n-------- Mapa: ---------\n");
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

static void	print_file(char **file)
{
	int i = 0;
	
	printf("\n-------- Arquivo: ---------\n");
	while (file[i])
	{
		printf("%s", file[i]);
		i++;
	}
	printf("\n");
}

static int	is_texture(char *file, int *identifier)
{
	if (!ft_strncmp(file, "NO", 2))
		*identifier = 0;
	else if (!ft_strncmp(file, "SO", 2))
		*identifier = 1;
	else if (!ft_strncmp(file, "WE", 2))
		*identifier = 2;
	else if (!ft_strncmp(file, "EA", 2))
		*identifier = 3;
	else
		return (0);
	return (1);
}

static char *get_texture(char *file)
{
	while (*file == ' ')
		file++;
	return (file);
}

static void save_texture(char *file, int identifier, t_game *game)
{
	if (identifier == 0)
		game->param.no = get_texture(file + 2);
	if (identifier == 1)
		game->param.so = get_texture(file + 2);
	if (identifier == 2)
		game->param.we = get_texture(file + 2);
	if (identifier == 3)
		game->param.ea = get_texture(file + 2);			
}

////////////////
////colors//////

static int isOutOfRange(int n)
{
    return n < 0 || n > 255;
}

static char *getNextOctet(char *s)
{
    while (*s != ',')
        s++;
    return (s);
}

static int get_colors(char *file)
{
    int color;
    int r;
    int g;
    int b;

    r = ft_atoi(file);
    file = getNextOctet(file);
    g = ft_atoi(file);
    file = getNextOctet(file);
    b = ft_atoi(file);
    if (isOutOfRange(r) || isOutOfRange(g) || isOutOfRange(b)) {
        printf("Invalid color range\n");
        return (0);
    }
    color = (r << 16) + (g << 8) + b;
    printf("%d\n", color);
    return (color);
}

static void save_colors(char *file, int identifier, t_game *game)
{
	if (identifier == 4)
		game->param.groun_collor = get_colors(file + 1);
	if (identifier == 5)
		game->param.celling_collor = get_colors(file + 2);		
}

static int	is_color(char *file, int *identifier)
{
	if (!ft_strncmp(file, "F", 1))
		*identifier = 4;
	else if (!ft_strncmp(file, "C", 1))
		*identifier = 5;
	else
		return (0);
	return (1);
}

static void	save_file_info(char **file, t_game *game)
{
	int i;
	int	identifier;
	
	i = 0;
	while (file[i])
	{
		if (is_texture(file[i], &identifier))
			save_texture(file[i], identifier, game);
		else if (is_color(file[i], &identifier))
		 	save_colors(file[i], identifier, game);
		// else
		// 	get_map();
		i++;
	}
	printf("celling_color: %d\n", game->param.celling_collor);
	printf("ground_color: %d\n\n", game->param.groun_collor);

 }





t_bool	print_error(char *error)
{
	ft_putstr_fd(error, 2);
	return (false);
}

t_bool	validation(t_game *game, int argc, char **argv)
{
	if (WIN_WIDTH < 800 || WIN_HEIGHT < 600)
		return (print_error(E_RESINVAL));
	(void)argc;
	// if (argc < 2)
	// 	return (print_error(E_NOMAP));
	// if (argc > 2)
	// 	return (print_error(E_MANYARG));
	ft_bzero(&game->map, sizeof(t_map));
	game->map.map = read_map(argv[1]);
	print_map(game->map.map);
	if (!is_valid_map(game->map.map, argv[1], game))
	{
		free_map(game->map.map);
		return (print_error(E_MAPINVAL));
	}

	game->map.file = read_map(argv[2]);
	print_file(game->map.file);	
	save_file_info(game->map.file, game);




	return (true);
}
