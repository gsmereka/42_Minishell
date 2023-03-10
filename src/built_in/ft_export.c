/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:02:54 by gsmereka          #+#    #+#             */
/*   Updated: 2023/03/04 19:43:18 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int		is_valid(char *str, t_data *data);
static t_env	*is_repeated(char *str, t_data *data);
static void		add_new_environment_variable(char *str, t_data *data);
static void		att_variable(t_env *new_var, char *str);

void	ft_export(char **args, t_data *data)
{
	t_env	*new_var;
	int		i;

	i = 1;
	if (!args || !args[i])
		return ;
	while (args[i])
	{
		if (is_valid(args[i], data))
		{
			new_var = is_repeated(args[i], data);
			if (new_var)
				att_variable(new_var, args[i]);
			if (!new_var)
				add_new_environment_variable(args[i], data);
		}
		i++;
	}
	att_virtual_envp(data);
}

static void	add_new_environment_variable(char *str, t_data *data)
{
	int		j;
	char	*key;
	char	*value;

	j = 0;
	while (str[j] != '=')
		j++;
	key = ft_calloc(j + 1, sizeof(char));
	ft_strlcpy(key, str, j + 1);
	value = ft_strdup(&str[j + 1]);
	dict_add_back(&data->dict_envp, key, value);
	free(key);
	free(value);
}

static t_env	*is_repeated(char *str, t_data *data)
{
	t_env	*variable;

	variable = data->dict_envp;
	while (variable)
	{
		if (ft_strncmp(variable->key, str, ft_strlen(variable->key)) == 0)
			return (variable);
		variable = variable->next;
	}
	return (NULL);
}

static void	att_variable(t_env *new_var, char *str)
{
	int		j;
	char	*key;
	char	*value;

	j = 0;
	while (str[j] != '=')
		j++;
	key = ft_calloc(j + 1, sizeof(char));
	ft_strlcpy(key, str, j + 1);
	value = ft_strdup(&str[j + 1]);
	free(new_var->key);
	free(new_var->value);
	new_var->key = key;
	new_var->value = value;
}

// Utilizo a verifica????o do parsing dos nomes de variaveis,
// segundo o manual do bash "A word consisting solely of letters,
// numbers, and underscores, and beginning with a letter or underscore.
// Names are used as shell variable and function names. Also referred to as an identifier."
static int	is_valid(char *str, t_data *data)
{
	int		i;

	if (!ft_isalpha(str[0]) && str[1] != '_')
	{
		ft_export_error_msg(1, str, data);
		return (0);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		if (!ft_isalnum(str[i]) && str[i] != '_')
		{
			ft_export_error_msg(1, str, data);
			return (0);
		}
		i++;
	}
	return (0);
}
