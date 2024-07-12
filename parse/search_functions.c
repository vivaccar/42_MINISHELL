/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:13:59 by vivaccar          #+#    #+#             */
/*   Updated: 2024/07/12 15:40:40 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*get_next_redir(t_token *token)
{
	if (token->next)
		token = token->next;
	else 
		return (NULL);
	while (token && !is_redir(token) && token->type != PIPELINE)
		token = token->next;
	if (token && token->type == PIPELINE)
		return (NULL);
	return(token);
}

bool	last_redir(t_token *token)
{
	if (token->type != REDIR_IN && token->type != REDIR_OUT && token->type != D_REDIR_OUT && token->type != HERE_DOC)
		return (false);
	token = get_next_redir(token);
	if (!token)
		return (true);
	return (false);
}

t_token	*find_last_or_pipe(t_token *token, int flag)
{
	while (token->next)
	{
		if (token->type == PIPELINE)
			return (token);
		token = token->next;
	}
	if (flag == 1)
		return (token);
	return (NULL);
}

t_token	*get_previous_redir(t_token *token)
{
	if (token->prev)
		token = token->prev;
	else
		return (NULL);
	while (token && token->type != PIPELINE)
	{
		if (token->type == REDIR_IN || token->type == D_REDIR_OUT || token->type == REDIR_OUT || token->type == HERE_DOC)
			return (token);
		token = token->prev;
	}
	return (NULL);
}