/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:32:18 by vivaccar          #+#    #+#             */
/*   Updated: 2024/06/25 12:37:34 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./ft_printf/libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <stdbool.h>

# define PIPE '|'
# define DOLLAR '$'
# define REDIRECT_IN '<'
# define REDIRECT_OUT '>'

# define S_QTE 39
# define D_QTE 34

enum e_status{
	GENERAL,
	IN_S_QUOTE,
	IN_D_QUOTE,
};

enum e_type{
	W_SPACE = 3,
	WORD,
	PIPELINE,
	ENV,
	REDIR_IN,
	REDIR_OUT,
	D_REDIR_OUT,
	HERE_DOC,
	S_QUOTE,
	D_QUOTE
};

typedef struct s_token{
	enum e_status	status;
	enum e_type		type;
	struct s_token	*prev;
	struct s_token	*next;
	char			*data;
}					t_token;

typedef struct s_token_list{
	t_token		*first;
	t_token		*last;
}				t_token_list;

// TOKENS.C
void			tokenizer(t_token_list *token_list, char *line);
void			print_token_list(t_token_list *token_list);
int				is_type_word(char c);
enum e_status	append_quotes(t_token_list *token_list, char c, enum e_status status);
enum e_status	change_status(t_token_list *token_list, char c, enum e_status status, enum e_type type);

//APPEND.C
void			append_token(t_token_list *token_list, char *str, enum e_status status, enum e_type type);
int				append_word(t_token_list *token_list, char *line, enum e_status status, int i);
int				append_redir(t_token_list *token_list, char *line, enum e_status status, int i);

//SIGNALS.C
void			start_sigaction(void);
bool			check_syntax(char *line);

//FREE 
void			free_token_list(t_token_list *token_list);
void			free_env(t_token *token);
void			exit_line(char *line);
void			free_strings(char *s1, char *s2, char *s3);

//EXPAND.C
void			check_dollar(t_token_list *token_list);
char			*expand(char *data);
t_token			*is_expansible(t_token *tmp, t_token_list *token_list);
char			find_special(char *data);

//JOIN
void			join_spaces(t_token_list *token_list);
void			delete_node(t_token_list *token_list, t_token *tmp);
t_token			*join_nodes(t_token_list *token_list, t_token *token);
void			join_quotes(t_token_list *token_list);

//JOIN.C
t_token	**with_same_status(t_token_list *token_list);
void	join_tokens(t_token **array, t_token_list *token_list);
t_token *joined_token(t_token **array, t_token *actual);



#endif