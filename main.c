/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:38:50 by vivaccar          #+#    #+#             */
/*   Updated: 2024/06/13 13:35:03 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
	char	*line;
	char	**tokens;
	int		i = 0;

	while (1)
	{
		i = 0;
		line = readline("minishell --> ");
		printf("%s\n", line);
		tokens = ft_split(line, ' ');
		while (tokens[i])
		{
			printf("%s\n", tokens[i]);
			i++;
		}
		free(tokens);
	}
	free(line);
}