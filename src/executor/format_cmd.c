/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:11:02 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/07 15:54:33 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

//  < arquivo_1 > arquivo_2 ---- Podem existir Comandos Que não existem.
static t_token	*find_the_command(t_token *token);
static void	set_cmd_composition(t_token *token, t_cmd *cmd);

t_token	*format_cmd(t_token *token, t_cmd *cmd, t_data *data)
{
	t_token	*cmd_token;

	cmd_token = find_the_command(token);
	set_cmd_composition(cmd_token, cmd);
	// check_inputs(token, cmd, data);
	// check_outputs(token, cmd, data);
}

static void	set_cmd_composition(t_token *token, t_cmd *cmd)
{
	int	args_amount;
	int	index;

	cmd->name = ft_strdup(token->content);
	// args_amount = count_args(token);
	if (!args_amount)
		return ;
	cmd->args = ft_calloc(args_amount + 1, sizeof(char *));
	index = 0;
	while (index < args_amount)
	{
		cmd->args[index] = ft_strdup(token->content);
		index++;
		token = token->next;
	}
}

static t_token	*find_the_command(t_token *token)
{
	while (token)
	{
		if (ft_strncmp(token->content, "<", ft_strlen(token->content)) == 0)
			token = token->next->next;
		else if (ft_strncmp(token->content,
				"<<", ft_strlen(token->content)) == 0)
			token = token->next->next;
		else if (ft_strncmp(token->content,
				">", ft_strlen(token->content)) == 0)
			return (NULL);
		else if (ft_strncmp(token->content,
				">>", ft_strlen(token->content)) == 0)
			return (NULL);
		else if (ft_strncmp(token->content,
				"|", ft_strlen(token->content)) == 0)
			return (NULL);
		else
			break ;
	}
	return (token);
}