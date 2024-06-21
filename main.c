/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:38:50 by vivaccar          #+#    #+#             */
/*   Updated: 2024/06/21 17:34:24 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"


int	main(int ac, char **av, char **env)
{
	char	*line;
	t_token_list token_list;

	token_list = (t_token_list){0};
	(void) av;
	(void) ac;
	(void) env;
	start_sigaction();
	while (1)
	{
		line = readline("minishell --> ");
		if (!line)
		{
			ft_printf(1, "exit\n");
			free(line);
			exit(0);
		}
		if (!check_syntax(line))
			continue ;
		tokenizer(&token_list, line);
		free(line);
	}
}
