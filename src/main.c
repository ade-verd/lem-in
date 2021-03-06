/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:27:33 by ade-verd          #+#    #+#             */
/*   Updated: 2018/07/29 15:46:09 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	t_map	*map;

	ft_map_init(&map);
	if (ac > 1)
		ft_read_args(&map, ac, av);
	ft_deal_help_debug(map);
	ft_read_fd(&map);
	ft_check_validity(map);
	find_issues(map, map->start, 0);
	if (!ft_count_issues(map))
		ft_error(&map, "No issue", 0);
	ft_sort_issues(map);
	ft_select_issues(map);
	ft_sort_selected_issues(map);
	ft_display_context(map);
	solve(map);
	ft_map_del(&map);
	return (EXIT_SUCCESS);
}
